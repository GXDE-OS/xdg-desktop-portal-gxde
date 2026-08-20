// SPDX-FileCopyrightText: 2026 2026 CharOfString <root@charofstring.cc>
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "sessiontype.h"

#include <iostream>

namespace {

bool expectPlatform(const char *scenario, const QByteArray &expected) {
    PortalSession::selectQpaPlatform();
    const QByteArray actual = qgetenv("QT_QPA_PLATFORM");
    if (actual == expected) {
        return true;
    }

    return false;
}

}  // namespace

int main() {
    qputenv("XDG_SESSION_TYPE", "wayland");
    qunsetenv("WAYLAND_DISPLAY");
    qputenv("QT_QPA_PLATFORM", "dxcb;xcb;dwayland;wayland");
    if (!expectPlatform("Wayland session", "wayland")) {
        return 1;
    }

    qputenv("XDG_SESSION_TYPE", "x11");
    qputenv("WAYLAND_DISPLAY", "wayland-0");
    qputenv("QT_QPA_PLATFORM", "dxcb;xcb");
    if (!expectPlatform("X11 session", "dxcb;xcb")) {
        return 1;
    }

    qunsetenv("XDG_SESSION_TYPE");
    qputenv("WAYLAND_DISPLAY", "wayland-0");
    qputenv("QT_QPA_PLATFORM", "xcb;wayland");
    if (!expectPlatform("Wayland display fallback", "wayland")) {
        return 1;
    }

    qunsetenv("XDG_SESSION_TYPE");
    qunsetenv("WAYLAND_DISPLAY");
    qputenv("QT_QPA_PLATFORM", "offscreen");
    return expectPlatform("Unknown session", "offscreen") ? 0 : 1;
}

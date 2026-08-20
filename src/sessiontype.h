// SPDX-FileCopyrightText: 2026 CharOfString <root@charofstring.cc>
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#pragma once

#include <QByteArray>
#include <QtGlobal>

namespace PortalSession {

inline bool isWayland() {
    const QByteArray sessionType = qgetenv("XDG_SESSION_TYPE").toLower();
    if (!sessionType.isEmpty()) {
        return sessionType == QByteArrayLiteral("wayland");
    }

    return !qEnvironmentVariableIsEmpty("WAYLAND_DISPLAY");
}

inline void selectQpaPlatform() {
    if (isWayland()) {
        qputenv("QT_QPA_PLATFORM", QByteArrayLiteral("wayland"));
    }
}

}  // namespace PortalSession

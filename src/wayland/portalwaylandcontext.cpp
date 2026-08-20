// SPDX-FileCopyrightText: 2024-2026 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "portalwaylandcontext.h"
#include "screenshotportal.h"
#include "screencastportal.h"
#include "filechooser.h"
#include "wallpaper.h"
#include "notification.h"
#include "access.h"
#include "settings.h"

#include <QGuiApplication>
#include <qpa/qplatformintegration.h>
#include <private/qwaylandintegration_p.h>
#include <private/qguiapplication_p.h>
#include <QTimer>

using namespace QtWaylandClient;

PortalWaylandContext::PortalWaylandContext(QObject *parent)
    : QObject(parent)
    , QDBusContext()
    , m_screenCopyManager(new ScreenCopyManager(this))
    , m_treelandCaptureManager(new TreeLandCaptureManager(this))
    , m_fileChooser(new FileChooserPortal(this))
    , m_notification(new NotificationPortal(this))
    , m_access(new AccessPortal(this))
    , m_settings(new SettingsPortal(this))
{
    new ScreenshotPortalWayland(this);
    new ScreencastPortalWayland(this);
    new WallPaperPortal(this);
}

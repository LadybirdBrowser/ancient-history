/*
 * Copyright (c) 2022, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#define AK_DONT_REPLACE_STD
#include <AK/URL.h>
#include <LibGfx/Forward.h>
#include <AK/String.h>
#include <QString>
#include <QPoint>
#include <QUrl>

AK::String akstring_from_qstring(QString const&);
QString qstring_from_akstring(AK::String const&);
QUrl qurl_from_akurl(AK::URL const& akurl);
QPoint qpoint_from_intpoint(Gfx::IntPoint const& position);

void platform_init();

extern String s_serenity_resource_root;

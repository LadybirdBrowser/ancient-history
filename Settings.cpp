/*
 * Copyright (c) 2022, Filiph Sandström <filiph.sandstrom@filfatstudios.com>
 * Copyright (c) 2022, yeppiidev <yedoxstudios@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "Settings.h"

namespace Browser {

Settings::Settings()
{
    m_qsettings = new QSettings("Serenity", "Ladybird");
}

QString Settings::homepage()
{
    return m_qsettings->value("homepage", "https://www.serenityos.org/").toString();
}

QString Settings::new_tab_page()
{
    return m_qsettings->value("new_tab_page", "https://ladybird.serenityos.net/new-tab.html").toString();
}

bool Settings::always_show_tabs() 
{
    return m_qsettings->value("always_show_tabs", true).toBool();
}

void Settings::set_homepage(QString const& homepage)
{
    m_qsettings->setValue("homepage", homepage);
}

void Settings::set_new_tab_page(QString const& new_tab_page)
{
    m_qsettings->setValue("new_tab_page", new_tab_page);
}

void Settings::set_always_show_tabs(bool const& always_show_tabs)
{
    m_qsettings->setValue("always_show_tabs", always_show_tabs);
}

}

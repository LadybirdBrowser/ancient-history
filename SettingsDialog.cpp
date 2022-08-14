/*
 * Copyright (c) 2022, Filiph Sandström <filiph.sandstrom@filfatstudios.com>
 * Copyright (c) 2022, yeppiidev <yedoxstudios@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "Settings.h"
#include "SettingsDialog.h"
#include <QCloseEvent>
#include <QLabel>

extern Browser::Settings* s_settings;

SettingsDialog::SettingsDialog(QMainWindow* window)
    : m_window(window)
{
    m_layout = new QFormLayout;
    m_homepage = new QLineEdit;
    m_new_tab_page = new QLineEdit;
    m_always_show_tabs = new QCheckBox(QString("Always show tabs"));
    m_ok_button = new QPushButton("&Save");

    m_layout->addWidget(new QLabel("Homepage"));
    m_layout->addWidget(m_homepage);

    m_layout->addWidget(new QLabel("New tab page"));
    m_layout->addWidget(m_new_tab_page);

    m_layout->addWidget(m_always_show_tabs);
    m_layout->addWidget(m_ok_button);
    
    m_homepage->setText(s_settings->homepage());
    m_new_tab_page->setText(s_settings->new_tab_page());
    m_always_show_tabs->setChecked(s_settings->always_show_tabs());

    QObject::connect(m_ok_button, &QPushButton::released, this, [this] {
        close();
    });
    
    setWindowTitle("Settings");
    setFixedWidth(300);
    setLayout(m_layout);
    show();
    setFocus();
}

void SettingsDialog::closeEvent(QCloseEvent *event)
{
    save();
    event->accept();
}

void SettingsDialog::save()
{
    // FIXME: Validate data.
    s_settings->set_homepage(m_homepage->text());
    s_settings->set_new_tab_page(m_new_tab_page->text());
    s_settings->set_always_show_tabs(m_always_show_tabs->isChecked());
}

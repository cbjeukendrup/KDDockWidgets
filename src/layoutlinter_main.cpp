/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2020 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#include "Config.h"
#include "DockWidget.h"
#include "MainWindow.h"

#include <QApplication>
#include <QDebug>
#include <QString>

using namespace KDDockWidgets;

static bool lint(const QString &filename)
{
    DockWidgetFactoryFunc dwFunc = [] (const QString &dwName) {
        return static_cast<DockWidgetBase*>(new DockWidget(dwName));
    };

    MainWindowFactoryFunc mwFunc = [] (const QString &dwName) {
        return static_cast<MainWindowBase*>(new MainWindow(dwName));
    };

    KDDockWidgets::Config::self().setDockWidgetFactoryFunc(dwFunc);
    KDDockWidgets::Config::self().setMainWindowFactoryFunc(mwFunc);

    LayoutSaver restorer;
    return restorer.restoreFromFile(filename);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if (app.arguments().size() != 2) {
        qDebug() << "Usage: kddockwidgets_linter <layout json file>";
        return 1;
    }

    return lint(app.arguments().at(1)) ? 0 : 2;
}

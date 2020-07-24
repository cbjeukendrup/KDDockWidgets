/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2020 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#include "DockWidgetQuick.h"

/**
 * @file
 * @brief Represents a dock widget.
 *
 * @author Sérgio Martins \<sergio.martins@kdab.com\>
 */

using namespace KDDockWidgets;

class DockWidgetQuick::Private
{
public:
    Private(DockWidgetQuick *)

    {
    }
};

DockWidgetQuick::DockWidgetQuick(const QString &name, Options options)
    : DockWidgetBase(name, options)
    , d(new Private(this))
{
}

DockWidgetQuick::~DockWidgetQuick()
{
    delete d;
}

/* TODO_QUICK
bool DockWidget::event(QEvent *e)
{
    if (e->type() == QEvent::ParentChange) {
        onParentChanged();
    } else if (e->type() == QEvent::Show) {
        onShown(e->spontaneous());
    } else if (e->type() == QEvent::Hide) {
        onHidden(e->spontaneous());
    }

    return QWidget::event(e);
}

void DockWidget::closeEvent(QCloseEvent *e)
{
    onClosed(e);
}
*/

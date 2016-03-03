/*
 * Copyright (C) Kreogist Dev Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "knmainwindowcontainer.h"
#include <QTreeWidget>
#include <QHBoxLayout>
#include <QTreeWidgetItem>
KNMainWindowContainer::KNMainWindowContainer(QWidget *parent)
    :QWidget(parent)
    ,treeWidget(new QTreeWidget())
    ,mainLayout(new QHBoxLayout())
{
    //set treewidget's columnCount
    treeWidget->setColumnCount(1);
    //set treewidget's headerlaybel
    treeWidget->setHeaderLabel(tr("My Notes"));
    //add node to treeWidget
    QTreeWidgetItem *item1 = new QTreeWidgetItem(treeWidget,
                             QStringList(QString(tr("笔记"))));
    //add child node to item1
    QTreeWidgetItem *item1_1 = new QTreeWidgetItem(item1,
                                   QStringList(QString(tr("英语"))));
    item1->addChild(item1_1);

    //expand all nodes.
    //treeWidget->expandAll();

    //add treeWidget to mainLayout's left.
    mainLayout->addWidget(treeWidget);
    //set layout.
    this->setLayout(mainLayout);
}


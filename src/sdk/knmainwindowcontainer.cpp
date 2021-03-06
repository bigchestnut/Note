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
#include "knnotemodel.h"
#include "knnoteview.h"
#include <QTreeWidget>
#include <QHBoxLayout>
#include <QTreeWidgetItem>
KNMainWindowContainer::KNMainWindowContainer(QWidget *parent)
    :QWidget(parent)
    ,mainLayout(new QHBoxLayout())
    ,noteModel(new KNNoteModel(this))
    ,noteView(new KNNoteView(this))
{
    noteView->setModel(noteModel);
    //add Widget to mainLayout's left.
    mainLayout->addWidget(noteView);
    //set layout.
    this->setLayout(mainLayout);
}


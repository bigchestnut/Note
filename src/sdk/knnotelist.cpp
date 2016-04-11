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

#include "knnotelist.h"
#include "knnote.h"
#include <QList>
#include <QString>
#include <QVariant>
KNNoteList::KNNoteList()
{
    noteList.append(new KNNote());
    noteList.append(new KNNote());
    noteList.append(new KNNote());
    noteList.append(new KNNote());
    noteList.append(new KNNote());
    noteList.append(new KNNote());
    noteList.append(new KNNote());
}

int KNNoteList::rowCount()
{
    return noteList.count();
}

int KNNoteList::columnCount()
{
    return noteList.first()->columnCount();
}

QString KNNoteList::getColumnName(int offset)
{
    return noteList.first()->getColumnName(offset);
}

QVariant KNNoteList::getData(int row, int column)
{
    return noteList.value(row)->data(column);
}

bool KNNoteList::setData(int row, int column, QVariant value)
{
    return noteList.value(row)->setData(column,value.toString());
}


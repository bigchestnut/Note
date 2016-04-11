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

#include "knnotemodel.h"
#include "knnotelist.h"
#include <QDebug>
KNNoteModel::KNNoteModel(QObject *parent)
    : QAbstractTableModel(parent)
    , noteList(new KNNoteList())
{
}

void KNNoteModel::setNote(KNNoteList *noteList)
{
    /*tell orther related class that this model will reset data*/
    beginResetModel();
    this->noteList=noteList;
    endResetModel();
}

int KNNoteModel::rowCount(const QModelIndex &parent) const
{
    return noteList->rowCount();
}

int KNNoteModel::columnCount(const QModelIndex &parent) const
{
    return noteList->columnCount();
}

QVariant KNNoteModel::data(const QModelIndex &index, int role) const
{
    /* if index is not valid,return a null Qvariant */
    if (!index.isValid())
    {
        return QVariant();
    }
    if (role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }
    else if (role == Qt::DisplayRole)
    {
        int column =index.column();
        int row = index.row();
        return noteList->getData(row,column);
    }
    return QVariant();
}

QVariant KNNoteModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    /*judge if the role is displayable,if so call the noteAt() fuction return
    the section column's name,else return a null Qvariant*/
    if(role!=Qt::DisplayRole)
    {
        return QVariant();
    }
    if(role==Qt::DisplayRole&&orientation==Qt::Vertical)//vertical header
    {
        return section+1;//row number
    }
    return noteAt(section);
}

Qt::ItemFlags KNNoteModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    flags |= Qt::ItemIsEditable;
    return flags;//return new flags <!!with!!> editable
}

bool KNNoteModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid()&&role==Qt::EditRole)
    {
        int row=index.row();
        int column=index.column();
        if(noteList->setData(row,column,value))
        {
            emit dataChanged(index,index);

            return true;
        }
        return false;
    }
    return false;
}

QString KNNoteModel::noteAt(int offset) const
{
    return noteList->getColumnName(offset);
}

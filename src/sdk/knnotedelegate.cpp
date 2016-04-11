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

#include "knnotedelegate.h"
#include <QString>
#include <QDebug>
KNNoteDelegate::KNNoteDelegate(QObject *parent)
    :QStyledItemDelegate(parent)
{

}

QWidget *KNNoteDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    KNNoteEditor *editor = new KNNoteEditor();
    return editor;
}

void KNNoteDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString value = index.model()->data(index, Qt::DisplayRole).toString();
    qDebug()<<value;
    KNNoteEditor* noteEditor = static_cast<KNNoteEditor*>(editor);
    noteEditor->setData(1,value);
}

void KNNoteDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    KNNoteEditor* noteEditor = static_cast<KNNoteEditor*>(editor);
    QString newValue = noteEditor->getData(1);
    qDebug()<<newValue;
    model->setData(index,newValue,Qt::EditRole);
}

void KNNoteDelegate::updateEditorGeometry(KNNoteEditor *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
     editor->setGeometry(100,100,1000,600);
}


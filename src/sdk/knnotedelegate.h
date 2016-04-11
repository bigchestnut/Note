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

#ifndef KNNOTEDELEGATE_H
#define KNNOTEDELEGATE_H
#include <QStyledItemDelegate>
#include "knnoteeditor.h"
class KNNoteDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    KNNoteDelegate(QObject *parent=0);
    /*!
     * \brief createEditor create a widget,use it as the editor to edit data
     * \param parent
     * \param option
     * \param index
     * \return
     */
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    /*!
     * \brief setEditorData provide the orignal data for editor
     * \param editor
     * \param index
     */
    void setEditorData(QWidget *editor,
                       const QModelIndex &index) const;
    /*!
     * \brief setModelData set the edited data to model
     * \param editor
     * \param model
     * \param index
     */
    void setModelData(QWidget *editor,QAbstractItemModel *model,
                      const QModelIndex &index) const;
    /*!
     * \brief updateEditorGeometry make sure that the editor can show itself totally
     * \param editor
     * \param option
     * \param index
     */
    void updateEditorGeometry(KNNoteEditor *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const;
};

#endif // KNNOTEDELEGATE_H

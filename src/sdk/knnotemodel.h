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

#ifndef KNNOTEMODEL_H
#define KNNOTEMODEL_H

#include <QAbstractTableModel>
#include "knnote.h"
class KNNoteModel : public QAbstractTableModel
{
public:
    KNNoteModel(QObject *parent = 0);
    /*!
     * \brief setNoteList set noteList for the model.
     * \param noteList the noteList that you want to set.
     */
    void setNote(const KNNote &note);
    /*!
     * \brief rowCount count the number of rows
     * \param parent rows' parent note
     * \return the number of all rows
     */
    int rowCount(const QModelIndex &parent) const;
    /*!
     * \brief columnCount count the number of columns
     * \param parent column's parent
     * \return  the number of all c
     */
    int columnCount(const QModelIndex &parent) const;
    /*!
     * \brief data return data depending on the index
     * \param index the index of noteList
     * \param role the role of data
     * \return a KNNote of noteList
     */
    QVariant data(const QModelIndex &index, int role) const;
    /*!
     * \brief headerData return the name of column
     * \param section the postion of column
     * \param orientation column's order direction
     * \param role column's role
     * \return the name of column
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    QString noteAt(int offset) const;
    KNNote note;
};

#endif // KNNOTEMODEL_H

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

#ifndef KNNOTELIST_H
#define KNNOTELIST_H
#include "knnote.h"
#include <QList>
class KNNote;
class QString;
class QVariant;
class KNNoteList
{
public:
    KNNoteList();
    /*!
     * \brief rowCount
     * \return the number of all rows
     */
    int rowCount();
    /*!
     * \brief columnCount
     * \return the number of all columns
     */
    int columnCount();
    /*!
     * \brief getColumnName
     * \param offset
     * \return the name of this column
     */
    QString getColumnName(int offset);
    /*!
     * \brief getData return the data of this cell
     * \param row row number
     * \param column column number
     * \return the data of this cell
     */
    QVariant getData(int row,int column);

    bool setData(int row,int column,QVariant value);
private:
    //a list of all note points
    QList<KNNote *> noteList;
};

#endif // KNNOTELIST_H

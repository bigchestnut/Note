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

#ifndef KNNOTE_H
#define KNNOTE_H
#include <QString>
#include <QVariant>
class KNNote
{
public:
    KNNote();
    void setTitle(QString title);
    void setContent(QString content);
    /*!
     * \brief columnCount
     * \return the number of all columns
     */
    int columnCount();
    /*!
     * \brief data
     * \param column
     * \return the value of this column
     */
    QVariant data(int column);
    /*!
     * \brief getColumnName
     * \param offset
     * \return the name of this column
     */
    QString getColumnName(int offset);
    /*!
     * \brief setData
     * \param column
     * \param value
     * \return
     */
    bool setData(int column,QString value);
private:
    /*!
     * \brief title the title of this note
     */
    QString title;
    /*!
     * \brief content the content of this note
     */
    QString content;
};

#endif // KNNOTE_H

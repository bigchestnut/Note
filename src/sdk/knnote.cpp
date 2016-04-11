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

#include "knnote.h"
#include <QString>
KNNote::KNNote()
{
    setTitle("挥洒的");
    setContent("阿斯科利放假阿斯利康感觉!");
}

void KNNote::setTitle(QString title)
{
    this->title=title;
}

void KNNote::setContent(QString content)
{
    this->content=content;
}

int KNNote::columnCount()
{
    return 2;
}

QVariant KNNote::data(int column)
{
    switch (column) {
    case 0:
        return this->title;
        break;
    case 1:
        return this->content;
        break;
    default:
        return QVariant();
        break;
    }
}

QString KNNote::getColumnName(int offset)
{
    switch (offset) {
    case 0:
        return "标题";
        break;
    case 1:
        return "内容";
        break;
    default:
        return "";
        break;
    }
}

bool KNNote::setData(int column, QString value)
{
    switch (column) {
    case 0:
    {
        setTitle(value);
        return true;
        break;
    }
    case 1:
    {
        setContent(value);
        return true;
        break;
    }
    default:
        return false;
        break;
    }
}



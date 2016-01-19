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

#include "knmainwindow.h"

#include "knpluginmanager.h"

KNPluginManager::KNPluginManager(QObject *parent) :
    QObject(parent),
    m_mainWindow(nullptr)
{

}
KNMainWindow *KNPluginManager::mainWindow() const
{
    return m_mainWindow;
}

void KNPluginManager::onActionArgumentsAvaliable(QStringList arguments)
{
    ;
}

void KNPluginManager::setMainWindow(KNMainWindow *mainWindow)
{
    //Check whether we have set main window before.
    if(m_mainWindow==nullptr)
    {
        //Save the main window object.
        m_mainWindow = mainWindow;
        //Set the main window to global.
        //            knGlobal->setMainWindow(m_mainWindow);
    }
}

void KNPluginManager::loadPlugins()
{
    ;
}

void KNPluginManager::launchApplication()
{
    //Check main window pointer.
    if(m_mainWindow==nullptr)
    {
        return;
    }
    //Show main window.
    m_mainWindow->show();
}



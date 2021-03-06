/* === This file is part of Tomahawk Player - <http://tomahawk-player.org> ===
 *
 *   Copyright 2010-2011, Leo Franchi <lfranchi@kde.org>
 *
 *   Tomahawk is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Tomahawk is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Tomahawk. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DATABASECOMMAND_LOADDYNAMICPLAYLISTENTRIES_H
#define DATABASECOMMAND_LOADDYNAMICPLAYLISTENTRIES_H

#include <QObject>
#include <QVariantMap>

#include "Typedefs.h"
#include "DatabaseCommand.h"
#include "DatabaseCommand_LoadPlaylistEntries.h"
#include "Playlist.h"

class DatabaseCommand_LoadDynamicPlaylistEntries : public DatabaseCommand_LoadPlaylistEntries
{
    Q_OBJECT

public:
    explicit DatabaseCommand_LoadDynamicPlaylistEntries( QString revision_guid, QObject* parent = 0 )
    : DatabaseCommand_LoadPlaylistEntries( revision_guid, parent )
    {
//        qDebug() << "loaded with:" << revision_guid << guid();
    }

    virtual void exec( DatabaseImpl* );
    virtual bool doesMutates() const { return false; }
    virtual QString commandname() const { return "loaddynamicplaylist"; }

signals:
    // used if loading an ondemand playlist
    void done( QString,
                     bool,
                     QString,
                     QList< QVariantMap>,
                     bool );
    // used when loading a static playlist
    void done( QString,
               QList< QString >,
               QList< QString >,
               QString,
               QList< QVariantMap>,
               bool,
               QMap< QString, Tomahawk::plentry_ptr >,
               bool );

private:
};

#endif // DATABASECOMMAND_LOADDYNAMICPLAYLIST_H

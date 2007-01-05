/* ============================================================
 * Authors: Caulier Gilles <caulier dot gilles at kdemail dot net>
 * Date  : 2006-18-12
 * Description : A list view to display digiKam Tags.
 *
 * Copyright 2006 by Gilles Caulier
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation;
 * either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * ============================================================ */
 
#ifndef TALBUMLISTVIEW_H
#define TALBUMLISTVIEW_H

// Qt includes.

#include <qlistview.h>

// Local includes.

#include "digikam_export.h"

class QListViewItem;
class QDropEvent;
class QMouseEvent;

namespace Digikam
{
class TAlbum;

class DIGIKAM_EXPORT TAlbumCheckListItem : public QCheckListItem
{
public:

    TAlbumCheckListItem(QListView* parent, TAlbum* album);

    TAlbumCheckListItem(QCheckListItem* parent, TAlbum* album);

    TAlbum *m_album;

protected:
    
    virtual void stateChange(bool val);
};

// ------------------------------------------------------------------------

class DIGIKAM_EXPORT TAlbumListView : public QListView
{
    Q_OBJECT

public:

    TAlbumListView(QWidget* parent);

    void emitSignalItemStateChanged(TAlbumCheckListItem *item);

signals:

    void signalItemStateChanged(TAlbumCheckListItem *item);

protected:

    void contentsMousePressEvent(QMouseEvent *e);
    void contentsMouseReleaseEvent(QMouseEvent *e);
    void contentsMouseMoveEvent(QMouseEvent *e);

    bool acceptDrop(const QDropEvent *e) const;
    void contentsDropEvent(QDropEvent *e);

    QDragObject* dragObject();
    void startDrag();
    TAlbumCheckListItem* dragItem() const;

private:

    bool mouseInItemRect(QListViewItem* item, int x) const;

private:

    QPoint               m_dragStartPos;    

    TAlbumCheckListItem *m_dragItem;
};

}  // NameSpace Digikam
 
#endif  // TALBUMLISTVIEW_H

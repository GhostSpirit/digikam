/* ============================================================
 *
 * This file is a part of digiKam project
 * http://www.digikam.org
 *
 * Date        : 2004-09-16
 * Description : Camera interface
 *
 * Copyright (C) 2004-2005 by Renchi Raju <renchi@pooh.tam.uiuc.edu>
 * Copyright (C) 2006-2009 by Gilles Caulier <caulier dot gilles at gmail dot com>
 * Copyright (C) 2006-2009 by Marcel Wiesweg <marcel dot wiesweg at gmx dot de>
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

#ifndef CAMERAUI_H
#define CAMERAUI_H

// Qt includes

#include <QDateTime>
#include <QString>
#include <QImage>
#include <QKeyEvent>
#include <QCloseEvent>

// KDE includes

#include <kxmlguiwindow.h>
#include <kurl.h>

// Local includes

#include "gpiteminfo.h"

namespace Digikam
{

class Album;
class CameraIconItem;
class CollectionLocation;
class CameraUIPriv;

class CameraUI : public KXmlGuiWindow
{
    Q_OBJECT

public:

    CameraUI(QWidget* parent, const QString& cameraTitle,
             const QString& model, const QString& port,
             const QString& path, const QDateTime lastAccess);
    ~CameraUI();

    bool isBusy() const;
    bool isClosed() const;

    bool cameraDeleteSupport();
    bool cameraUploadSupport();
    bool cameraMkDirSupport();
    bool cameraDelDirSupport();

    bool autoRotateJpegFiles() const;

    /** Get status of JPEG conversion files to lossless format during download.*/
    bool convertLosslessJpegFiles() const;
    QString losslessFormat();

    QString cameraTitle() const;

Q_SIGNALS:

    void signalLastDestination(const KUrl&);
    void signalWindowHasMoved();

public Q_SLOTS:

    void slotDownload(bool onlySelected, bool deleteAfter, Album *pAlbum=0);

protected:

    void closeEvent(QCloseEvent* e);
    void moveEvent(QMoveEvent *e);

private:

    void setupActions();
    void setupConnections();
    void setupUserArea();
    void setupStatusBar();
    void setupAccelerators();
    void setupCameraController(const QString& model, const QString& port, const QString& path);

    void readSettings();
    void saveSettings();
    bool createAutoAlbum(const KUrl& parentURL, const QString& sub,
                         const QDate& date, QString& errMsg);
    void addFileExtension(const QString& ext);

    bool dialogClosed();
    void finishDialog();
    void showToolBars();
    void hideToolBars();
    void refreshFreeSpace();
    void refreshCollectionFreeSpace();

private Q_SLOTS:

    void slotClose();
    void slotCancelButton();
    void slotProcessUrl(const QString& url);

    void slotConnected(bool val);
    void slotBusy(bool val);
    void slotErrorMsg(const QString& msg);
    void slotInformation();
    void slotCapture();
    void slotCameraInformation(const QString&, const QString&, const QString&);
    void slotCameraFreeSpaceInfo(unsigned long kBSize, unsigned long kBAvail);
    void slotCollectionLocationStatusChanged(const CollectionLocation& location, int oldStatus);

    void slotFolderList(const QStringList& folderList);
    void slotFileList(const GPItemInfoList& fileList);
    void slotThumbnail(const QString&, const QString&, const QImage&);

    void slotIncreaseThumbSize();
    void slotDecreaseThumbSize();
    void slotZoomSliderChanged(int size);
    void slotThumbSizeChanged(int size);

    void slotToggleFullScreen();
    void slotEscapePressed();

    void slotUpload();
    void slotUploadItems(const KUrl::List&);
    void slotDownloadSelected();
    void slotDownloadAll();
    void slotDownloadAndDeleteAll();
    void slotDeleteSelected();
    void slotDownloadAndDeleteSelected();
    void slotDeleteAll();
    void slotToggleLock();

    void slotFileView();
    void slotFileView(CameraIconItem* item);

    void slotUploaded(const GPItemInfo&);
    void slotDownloaded(const QString&, const QString&, int);
    void slotDownloadComplete(const QString& sourceFolder, const QString& sourceFile,
                              const QString& destFolder, const QString& destFile);
    void slotSkipped(const QString&, const QString&);
    void slotDeleted(const QString&, const QString&, bool);
    void slotLocked(const QString&, const QString&, bool);

    void slotNewSelection(bool);
    void slotItemsSelected(CameraIconItem* item, bool selected);

    void slotExifFromFile(const QString& folder, const QString& file);
    void slotExifFromData(const QByteArray& exifData);

    void slotFirstItem();
    void slotPrevItem();
    void slotNextItem();
    void slotLastItem();

    void slotDonateMoney();
    void slotContribute();
    void slotEditKeys();
    void slotShowMenuBar();
    void slotConfToolbars();
    void slotNewToolbarConfig();
    void slotSetup();
    void slotRawCameraList();
    void slotComponentsInfo();

    void slotThemeChanged();
    void slotChangeTheme(const QString& theme);

    void slotSidebarTabTitleStyleChanged();

private:

    CameraUIPriv* const d;
};

}  // namespace Digikam

#endif /* CAMERAUI_H */

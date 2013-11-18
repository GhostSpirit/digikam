/* ============================================================
 *
 * This file is a part of digiKam project
 * http://www.digikam.org
 *
 * Date        : 2004-11-17
 * Description : a tab to display metadata information of images
 *
 * Copyright (C) 2004-2012 by Gilles Caulier <caulier dot gilles at gmail dot com>
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

#ifndef IMAGEPROPERTIESMETADATATAB_H
#define IMAGEPROPERTIESMETADATATAB_H

// Qt includes

#include <QWidget>

// KDE includes

#include <kurl.h>
#include <ktabwidget.h>

// Local includes

#include "digikam_export.h"
#include "dmetadata.h"

namespace Digikam
{

class DIGIKAM_EXPORT ImagePropertiesMetaDataTab : public KTabWidget
{
    Q_OBJECT

public:

    explicit ImagePropertiesMetaDataTab(QWidget* const parent);
    ~ImagePropertiesMetaDataTab();

    void setCurrentURL(const KUrl& url=KUrl());
    void setCurrentData(const DMetadata& metadata=DMetadata(),
                        const QString& filename=QString());

    void loadFilters();

    void readSettings(const KConfigGroup& group);
    void writeSettings(KConfigGroup& group);

private:

    class Private;
    Private* const d;
};

}  // namespace Digikam

#endif /* IMAGEPROPERTIESMETADATATAB_H */

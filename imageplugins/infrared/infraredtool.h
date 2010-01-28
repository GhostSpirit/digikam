/* ============================================================
 *
 * This file is a part of digiKam project
 * http://www.digikam.org
 *
 * Date        : 2005-02-22
 * Description : a digiKam image editor plugin for simulate
 *               infrared film.
 *
 * Copyright (C) 2005-2010 by Gilles Caulier <caulier dot gilles at gmail dot com>
 * Copyright (C) 2006-2010 by Marcel Wiesweg <marcel dot wiesweg at gmx dot de>
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

#ifndef INFRAREDTOOL_H
#define INFRAREDTOOL_H

// Local includes

#include "editortool.h"

using namespace Digikam;

namespace DigikamInfraredImagesPlugin
{

class InfraredToolPriv;

class InfraredTool : public EditorToolThreaded
{
    Q_OBJECT

public:

    InfraredTool(QObject* parent);
    ~InfraredTool();

private Q_SLOTS:

    void slotResetSettings();

private:

    void readSettings();
    void writeSettings();
    void prepareEffect();
    void prepareFinal();
    void putPreviewData();
    void putFinalData();
    void renderingFinished();

private:

    InfraredToolPriv* const d;
};

}  // namespace DigikamInfraredImagesPlugin

#endif /* INFRAREDTOOL_H */

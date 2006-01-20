/* ============================================================
 * Author: Gilles Caulier <caulier dot gilles at free.fr>
 * Date  : 2004-07-09
 * Description : Blur image filter for ImageEditor
 * 
 * Copyright 2004-2006 by Gilles Caulier
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

// Qt includes.

#include <qlayout.h>
#include <qlabel.h>
#include <qwhatsthis.h>

// KDE includes.

#include <kaboutdata.h>
#include <knuminput.h>
#include <kcursor.h>
#include <klocale.h>
#include <kapplication.h>
#include <kdebug.h>

// Digikam includes.

#include "imageiface.h"
#include "dimggaussianblur.h"

// Local includes.

#include "imageeffect_blur.h"

namespace DigikamImagesPluginCore
{

ImageEffect_Blur::ImageEffect_Blur(QWidget* parent)
                : Digikam::CtrlPanelDlg(parent, i18n("Apply Gaussian Blur on Photograph"), 
                                        "gaussianblur")
{
    setHelp("blursharpentool.anchor", KApplication::kApplication()->aboutData()->appName());
    
    QWidget *gboxSettings = new QWidget(m_imagePreviewWidget);
    QGridLayout* gridSettings = new QGridLayout( gboxSettings, 1, 2, marginHint(), spacingHint());
    QLabel *label = new QLabel(i18n("Smoothness:"), gboxSettings);
    
    m_radiusInput = new KIntNumInput(gboxSettings);
    m_radiusInput->setRange(0, 20, 1, true);
    m_radiusInput->setValue(0);
    QWhatsThis::add( m_radiusInput, i18n("<p>A smoothness of 0 has no effect, "
                                         "1 and above determine the Gaussian blur matrix radius "
                                         "that determines how much to blur the image."));

    gridSettings->addWidget(label, 0, 0);
    gridSettings->addWidget(m_radiusInput, 0, 1);
    
    m_imagePreviewWidget->setUserAreaWidget(gboxSettings);
        
    // -------------------------------------------------------------
    
    connect(m_radiusInput, SIGNAL(valueChanged (int)),
            this, SLOT(slotTimer()));
}

ImageEffect_Blur::~ImageEffect_Blur()
{
}

void ImageEffect_Blur::renderingFinished(void)
{
    m_radiusInput->setEnabled(true);
}

void ImageEffect_Blur::resetValues(void)
{
    m_radiusInput->blockSignals(true);
    m_radiusInput->setValue(0);
    m_radiusInput->blockSignals(false);
} 

void ImageEffect_Blur::prepareEffect()
{
    m_radiusInput->setEnabled(false);
    
    Digikam::DImg img = m_imagePreviewWidget->getOriginalRegionImage();
        
    m_threadedFilter = dynamic_cast<Digikam::DImgThreadedFilter *>
                       (new Digikam::DImgGaussianBlur(&img, this, m_radiusInput->value()));    
}

void ImageEffect_Blur::prepareFinal()
{
    m_radiusInput->setEnabled(false);

    Digikam::ImageIface iface(0, 0);
    uchar *data     = iface.getOriginalImage();
    int w           = iface.originalWidth();
    int h           = iface.originalHeight();
    bool sixteenBit = iface.originalSixteenBit();
    bool hasAlpha   = iface.originalHasAlpha();
    Digikam::DImg orgImage = Digikam::DImg(w, h, sixteenBit, hasAlpha ,data);
    delete [] data;
    m_threadedFilter = dynamic_cast<Digikam::DImgThreadedFilter *>
                       (new Digikam::DImgGaussianBlur(&orgImage, this, m_radiusInput->value()));
}

void ImageEffect_Blur::putPreviewData(void)
{
    Digikam::DImg imDest = m_threadedFilter->getTargetImage();
    m_imagePreviewWidget->setPreviewImage(imDest);
}

void ImageEffect_Blur::putFinalData(void)
{
    Digikam::ImageIface iface(0, 0);
    Digikam::DImg imDest = m_threadedFilter->getTargetImage();
    iface.putOriginalImage(i18n("Gaussian Blur"), imDest.bits());
}

}  // NameSpace DigikamImagesPluginCore

#include "imageeffect_blur.moc"

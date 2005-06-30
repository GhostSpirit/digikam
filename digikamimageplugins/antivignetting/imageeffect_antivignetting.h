/* ============================================================
 * File  : imageeffect_antivignetting.h
 * Author: Gilles Caulier <caulier dot gilles at free.fr>
 * Date  : 2004-12-25
 * Description : a digiKam image plugin to reduce 
 *               vignetting on an image.
 * 
 * Copyright 2004-2005 by Gilles Caulier
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

#ifndef IMAGEEFFECT_ANTIVIGNETTING_H
#define IMAGEEFFECT_ANTIVIGNETTING_H

// KDE includes.

#include <kdialogbase.h>

class QPushButton;
class QLabel;
class QTabWidget;
class QTimer;

class KIntNumInput;
class KDoubleNumInput;
class KProgress;

namespace Digikam
{
class ImageWidget;
}

namespace DigikamAntiVignettingImagesPlugin
{
class AntiVignetting;

class ImageEffect_AntiVignetting : public KDialogBase
{
    Q_OBJECT
    
public:

    ImageEffect_AntiVignetting(QWidget *parent);
    ~ImageEffect_AntiVignetting();

protected:

    void closeEvent(QCloseEvent *e);
    
private:

    enum RunningMode
    {
    NoneRendering=0,
    PreviewRendering,
    FinalRendering
    };
    
    int                   m_currentRenderingMode;
    
    QWidget              *m_parent;
    
    QPushButton          *m_helpButton;

    QLabel               *m_maskPreviewLabel;
    
    QTimer               *m_timer;
        
    KIntNumInput         *m_brightnessInput;
    KIntNumInput         *m_contrastInput;
    KIntNumInput         *m_gammaInput;
    
    KDoubleNumInput      *m_densityInput;
    KDoubleNumInput      *m_powerInput;
    KDoubleNumInput      *m_radiusInput;
    
    KProgress            *m_progressBar;
    
    AntiVignetting       *m_antivignettingFilter;
    
    Digikam::ImageWidget *m_previewWidget;

private:
    
    void abortPreview(void);
    void customEvent(QCustomEvent *event);
        
private slots:

    void slotHelp();
    void slotEffect();
    void slotOk();
    void slotCancel();
    void slotUser1();
    void slotTimer();   
    void slotResized();    
};

}  // NameSpace DigikamAntiVignettingImagesPlugin

#endif /* IMAGEEFFECT_ANTIVIGNETTING_H */

/* ============================================================
 * File  : unsharp.h
 * Author: Gilles Caulier <caulier dot gilles at free.fr>
 * Date  : 2004-08-27
 * Description : Unsharped mask image filter for ImageEditor
 * 
 * Copyright 2004 by Gilles Caulier
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published bythe Free Software Foundation;
 * either version 2, or (at your option)
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * ============================================================ */

#ifndef DESPECKLE_H
#define DESPECKLE_H

// KDE include.

#include <kdialogbase.h>

class QPushButton;
class QSpinBox;
class QSlider;

class KProgress;
class KDoubleSpinBox;

namespace Digikam
{
class ImagePreviewWidget;
}

namespace DigikamUnsharpFilterImagesPlugin
{

class UnsharpDialog : public KDialogBase
{
    Q_OBJECT

public:

    UnsharpDialog(QWidget* parent);
    ~UnsharpDialog();

protected:

    void closeEvent(QCloseEvent *e);
   
    
private:

    QWidget         *m_parent;
    QPushButton     *m_helpButton;
    
    KDoubleSpinBox  *m_radiusInput;
    KDoubleSpinBox  *m_amountInput;
    QSpinBox        *m_thresholdInput;
    
    QSlider         *m_radiusSlider;
    QSlider         *m_amountSlider;
    QSlider         *m_thresholdSlider;
    
    KProgress       *m_progressBar;
        
    bool             m_cancel;
    
    Digikam::ImagePreviewWidget *m_imagePreviewWidget;

    void unsharp(uint* data, int w, int h, double radius, 
                 double amount, int threshold);
                 
    inline void blur_line (double *ctable, double *cmatrix, int cmatrix_length,
                           uchar *cur_col, uchar *dest_col, int y, long bytes);  
                           
    int gen_convolve_matrix (double radius, double **cmatrix_p);    
    
    double* gen_lookup_table (double *cmatrix, int cmatrix_length);
       
private slots:

    void slotHelp();
    void slotUser1();
    void slotEffect();
    void slotOk();
    void slotCancel();
    
    void slotSliderRadiusChanged(int v);
    void slotSpinBoxRadiusChanged(double v);
    void slotSliderAmountChanged(int v);
    void slotSpinBoxAmountChanged(double v);
};

}  // NameSpace DigikamUnsharpFilterImagesPlugin

#endif /* DESPECKLE_H */

#ifndef KEXIFDATA_H
#define KEXIFDATA_H

extern "C" {
#include <libexif/exif-data.h>
}

#include <qstring.h>
#include <qimage.h>
#include <qvaluevector.h>

class KExifIfd;

class KExifData {

public:

    enum {
        NOEXIF=0,
        NOTHUMBNAIL,
        ERROR,
        SUCCESS };

    KExifData();
    ~KExifData();

    int readFromFile(const QString& filename);
    int readFromData(char* data, int size);
    int getThumbnail(QImage& thumb);
    QString KExifData::getUserComment();

    QValueVector<KExifIfd> ifdVector;

    void saveFile(const QString& filename);
    void KExifData::saveExifComment(QString& filename, QString& comment);

private:

    ExifData *mExifData;
    QString   mExifByteOrder;
    QString   mUserComment;
    QImage mThumbnail;

};

#endif

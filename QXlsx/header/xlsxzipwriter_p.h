﻿// xlsxzipwriter_p.h

#ifndef QXLSX_ZIPWRITER_H
#define QXLSX_ZIPWRITER_H

#include <QtGlobal>
#include <QString>
#include <QIODevice>

#include "xlsxglobal.h"

#include "zip.h"

QT_BEGIN_NAMESPACE_XLSX

class ZipWriter
{
public:
    explicit ZipWriter(const QString &filePath);
    explicit ZipWriter(QIODevice *device);
    ~ZipWriter();

    void addFile(const QString &filePath, QIODevice *device);
    void addFile(const QString &filePath, const QByteArray &data);
    bool error() const;
    void close();

private:
    HZIP m_writer;
    ZRESULT m_result;
};

QT_END_NAMESPACE_XLSX

#endif // QXLSX_ZIPWRITER_H

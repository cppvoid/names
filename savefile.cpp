#include "savefile.h"
#include "qruntimeerror.h"

#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QCoreApplication>

SaveFile::SaveFile(const QString& filePath)
    : m_filePath(QCoreApplication::applicationDirPath() + "/" + filePath)
{
}

QStringList SaveFile::getData() const
{
    QFile file(m_filePath);

    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        throw QRuntimeError("cannot open " + m_filePath);
    }

    QStringList lines;
    QTextStream stream(&file);

    while(!stream.atEnd())
    {
        lines << stream.readLine();

        qDebug() << "readed line in file " << m_filePath << ": " << lines.back();
    }

    return lines;
}

void SaveFile::override(const QStringList& list) const
{
    QFile file(m_filePath);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        throw QRuntimeError("cannot open " + m_filePath);
    }

    QTextStream stream(&file);

    for(const auto& i : list)
    {
        stream << i << "\n";
    }
}

#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <QString>
#include <QStringList>

class SaveFile
{
public:
    SaveFile(const QString& filePath);

    QStringList getData() const;

    void override(const QStringList& list) const;

private:
    QString m_filePath;
};

#endif // SAVEFILE_H

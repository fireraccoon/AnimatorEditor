#ifndef SPRITERANIMATIONREADER_H
#define SPRITERANIMATIONREADER_H

#include "graphicsstateitem.h"

#include <QFile>
#include <QXmlStreamWriter>



class SpriterAnimationReader
{
public:
    SpriterAnimationReader(const QString filepath);
    ~SpriterAnimationReader();

    ///
    /// \brief reads the file
    /// \return
    ///
    QStringList read();


private:
    QXmlStreamReader reader;
    QString mFileName;

};

#endif // SPRITERANIMATIONREADER_H

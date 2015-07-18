#include "spriteranimationreader.h"

#include <QDebug>


SpriterAnimationReader::SpriterAnimationReader(const QString filepath){
    mFileName = filepath;
}

SpriterAnimationReader::~SpriterAnimationReader(){

}

QStringList SpriterAnimationReader::read(){

    QStringList anim;


    QFile xmlFile(mFileName);
    xmlFile.open(QIODevice::ReadOnly);
    reader.setDevice(&xmlFile);




    while(!reader.atEnd()){

        reader.readNextStartElement();

        if(reader.name() == "animation"){

            QString s = reader.attributes().value("name").toString();
            if(s != "")
                anim.append(s);
        }
    }
    if (reader.hasError())
    {
           qDebug() << "XML error: " << reader.error();
    }

                qDebug() << "ICI ";
    return anim;
}


#include "Audio.h"
#include <QtGui>

Audio::Audio(QWidget *parent):MyWidget(parent)
{
}


Audio::~Audio(void)
{
}

void Audio::domWriteElement( QDomDocument &doc,QDomElement xmlElement, QDomElement &xmlElementRt )
{
	xmlElementRt = doc.createElement("Audio");
	xmlElement.appendChild(xmlElementRt);
}

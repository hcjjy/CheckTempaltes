#include "Video.h"
#include <QtGui>

Video::Video(QWidget * parent):MyWidget(parent)
{

}


Video::~Video(void)
{
}

void Video::domWriteElement( QDomDocument &doc,QDomElement xmlElement, QDomElement &xmlElementRt )
{
	xmlElementRt = doc.createElement("Video");
	xmlElement.appendChild(xmlElementRt);
}

void Video::domReadElement( QDomNode node,QTreeWidgetItem *item )
{

}

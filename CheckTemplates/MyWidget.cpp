#include "MyWidget.h"
#include <QDomDocument>
#include <QDomElement>
#include <QtGui>
MyWidget::MyWidget( QWidget * parent /*= NULL*/ )
	:QWidget(parent)
{

}

MyWidget::~MyWidget( void )
{

}

void MyWidget::domWriteElement( QDomDocument &doc,QDomElement xmlElement, QDomElement &xmlElementRt )
{

}

void MyWidget::domReadElement( QDomNode node ,QTreeWidgetItem *item)
{

}

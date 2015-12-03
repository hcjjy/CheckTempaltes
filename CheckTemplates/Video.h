#pragma once
#include <QtGui/QWidget>
#include "MyWidget.h"
#include <QDomDocument>
#include <QDomElement>
class QTreeWidgetItem;
class Video :
	public MyWidget
{
public:
	Video(QWidget *parent = NULL);
	virtual ~Video(void);
	virtual void domWriteElement(QDomDocument &doc,QDomElement xmlElement,
		QDomElement &xmlElementRt);
	virtual void domReadElement(QDomNode node,QTreeWidgetItem *item);
};


#pragma once
#include <QtGui/QWidget>
#include <QDomDocument>
#include <QDomElement>
class QTreeWidgetItem;
class MyWidget :
	public QWidget
{
public:
	MyWidget(QWidget * parent = NULL);
	virtual ~MyWidget(void);
public:
	virtual void domWriteElement(QDomDocument &doc,QDomElement xmlElement,
		QDomElement &xmlElementRt);
	virtual void domReadElement(QDomNode node,QTreeWidgetItem *item);
};


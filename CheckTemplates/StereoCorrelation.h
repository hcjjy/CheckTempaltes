#pragma once
#include <QtGui/QWidget>
#include "MyWidget.h"
#include <QDomDocument>
#include <QDomElement>
class StereoCorrelation :
	public MyWidget
{
public:
	StereoCorrelation(QWidget *parent = NULL);
	virtual ~StereoCorrelation(void);
	virtual void domWriteElement(QDomDocument &doc,QDomElement xmlElement,
		QDomElement &xmlElementRt);
};


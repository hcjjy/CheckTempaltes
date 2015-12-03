#pragma once
#include "MyWidget.h"
#include <QDomDocument>
#include <QDomElement>
class Audio:
	public MyWidget
{
public:
	Audio(QWidget *parent = NULL);
	virtual ~Audio(void);
	virtual void domWriteElement(QDomDocument &doc,QDomElement xmlElement,
		QDomElement &xmlElementRt);
};


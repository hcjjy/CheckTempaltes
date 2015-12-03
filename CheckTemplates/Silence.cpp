#include "Silence.h"
#include <QtGui>

Silence::Silence( QWidget *parent /*= NULL*/ ):
	MyWidget(parent)
{
	m_pGroupBox = new QGroupBox(this);
	m_pGroupBox->setTitle("静音检测");

	m_pLevelLabel = new QLabel("幅度阀值",this);
	m_pLevel = new QSpinBox(this);
	m_pLevel->setRange(-80,-60);
	m_pLevel->setValue(-60);

	m_pDurationLabel = new QLabel("时间阀值",this);
	m_pDuration = new QSpinBox(this);
	m_pDuration->setRange(1,1000);
	m_pDuration->setValue(125);

	m_pLevelPreinfo = new QLabel("幅度阀值：",this);
	m_pLevelLastinfo = new QLabel("范围[-80,-60]",this);
	m_pDurationPreinfo = new QLabel("时间阀值：",this);
	m_pDurationLastinfo = new QLabel("范围1 - 1000",this);
}

Silence::~Silence(void)
{
}

void Silence::setLevelValue(int value)
{
	m_pLevel->setValue(value);
}

void Silence::setDurationValue(int value)
{
	m_pDuration->setValue(value);
}

int Silence::getLevelValue() const
{
	return m_pLevel->value();
}

int Silence::getDurationValue() const
{
	return m_pDuration->value();
}

void Silence::resizeEvent( QResizeEvent *event )
{
	m_pGroupBox->setGeometry(0,0,width(),height());

	m_pLevelLabel->setGeometry(40,60,m_pLevelLabel->width(),20);
	m_pLevel->setGeometry(160,60,m_pLevel->width(),20);
	m_pDurationLabel->setGeometry(40,85,m_pDurationLabel->width(),20);
	m_pDuration->setGeometry(160,85,m_pDuration->width(),20);

	m_pLevelPreinfo->setGeometry(40,160,m_pLevelPreinfo->width(),20);
	m_pLevelLastinfo->setGeometry(170,160,m_pLevelLastinfo->width(),20);
	m_pDurationPreinfo->setGeometry(40,180,m_pDurationPreinfo->width(),20);
	m_pDurationLastinfo->setGeometry(170,180,m_pDurationLastinfo->width(),20);
}

void Silence::domWriteElement( QDomDocument &doc,QDomElement xmlElement, 
							QDomElement &xmlElementRt )
{
	xmlElementRt = doc.createElement("Slience");
	
	QDomElement xmlElementRtChild1 = doc.createElement("Level");
	QDomElement xmlElementRtChild2 = doc.createElement("Duration");

	QDomText xmlText1 = doc.createTextNode(QString::number(getLevelValue()));
	QDomText xmlText2 = doc.createTextNode(QString::number(getDurationValue()));

	xmlElement.appendChild(xmlElementRt);
	
	xmlElementRt.appendChild(xmlElementRtChild1);
	xmlElementRt.appendChild(xmlElementRtChild2);

	xmlElementRtChild1.appendChild(xmlText1);
	xmlElementRtChild2.appendChild(xmlText2);
}

void Silence::domReadElement( QDomNode node,QTreeWidgetItem *item )
{
	QDomNode childNode;
	for (childNode = node.firstChild();!childNode.isNull();
		childNode=childNode.nextSibling())
	{
		if(childNode.nodeName()=="Level")
		{
			setLevelValue(childNode.toElement().text().toInt());
		}
		if(childNode.nodeName()=="Duration")
		{
			setDurationValue(childNode.toElement().text().toInt());
		}
	}
	item->setCheckState(0,Qt::Checked);
}

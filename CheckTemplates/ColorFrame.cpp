#include "ColorFrame.h"
#include <QtGui>
ColorFrame::ColorFrame( QWidget *parent /*= NULL*/ ):MyWidget(parent)
{
	m_pGroupBox = new QGroupBox(this);
	m_pGroupBox->setTitle("彩帧检测");
	m_pPercentLabel =new QLabel("比例阀值",this);
	m_pPercent = new QDoubleSpinBox(this);
	m_pPercent->setRange(90,100);
	m_pPercent->setDecimals(1);
	m_pPercent->setSingleStep(0.1);
	m_pPercent->setValue(99.7);

	m_pDurationLabel = new QLabel("时间阀值",this);
	m_pDuration = new QSpinBox(this);
	m_pDuration->setRange(1,5);
	m_pDuration->setValue(1);

	m_pPercentPreinfo = new QLabel("比例阀值：",this);
	m_pPercentLastinfo = new QLabel("范围90% - 100%",this);

	m_pDurationPreinfo = new QLabel("时间阀值：",this);
	m_pDurationLastinfo = new QLabel("范围1 - 5",this);
}

ColorFrame::~ColorFrame(void)
{
}
void ColorFrame::setPercentValue( double value )
{
	m_pPercent->setValue(value);
}

void ColorFrame::setDurationValue( int value )
{
	m_pDuration->setValue(value);
}

double ColorFrame::getPercentValue() const
{
	return m_pPercent->value();
}

int ColorFrame::getDurationValue() const
{
	return m_pDuration->value();
}
void ColorFrame::resizeEvent( QResizeEvent *event )
{
	m_pGroupBox->setGeometry(0,0,width(),height());

	m_pPercentLabel->setGeometry(40,60,m_pPercentLabel->width(),20);
	m_pPercent->setGeometry(160,60,m_pPercent->width(),20);

	m_pDurationLabel->setGeometry(40,85,m_pDurationLabel->width(),20);
	m_pDuration->setGeometry(160,85,m_pDuration->width(),20);

	m_pPercentPreinfo->setGeometry(40,160,m_pPercentPreinfo->width(),20);
	m_pPercentLastinfo->setGeometry(170,160,m_pPercentLastinfo->width(),20);

	m_pDurationPreinfo->setGeometry(40,180,m_pDurationPreinfo->width(),20);
	m_pDurationLastinfo->setGeometry(170,180,m_pDurationLastinfo->width(),20);
}

void ColorFrame::domWriteElement( QDomDocument &doc,QDomElement xmlElement,
								QDomElement &xmlElementRt )
{
	xmlElementRt = doc.createElement("ColorFrame");
	QDomElement xmlElementRtChild1 = doc.createElement("Duration");
	QDomElement xmlElementRtChild2 = doc.createElement("Percent");

	QDomText xmlText1 = doc.createTextNode(QString::number(getDurationValue()));
	QDomText xmlText2 = doc.createTextNode(QString::number(getPercentValue()));

	xmlElement.appendChild(xmlElementRt);
	xmlElementRt.appendChild(xmlElementRtChild1);
	xmlElementRt.appendChild(xmlElementRtChild2);

	xmlElementRtChild1.appendChild(xmlText1);
	xmlElementRtChild2.appendChild(xmlText2);
}

void ColorFrame::domReadElement( QDomNode node,QTreeWidgetItem *item )
{
	QDomNode childNode;
	for (childNode = node.firstChild();!childNode.isNull();
		childNode=childNode.nextSibling())
	{
		if(childNode.nodeName()=="Duration")
		{
			setDurationValue(childNode.toElement().text().toInt());
		}
		else if(childNode.nodeName()=="Percent")
		{
			setPercentValue(childNode.toElement().text().toDouble());
		}
	}
	item->setCheckState(0,Qt::Checked);
}

#include "StereoSamePhase.h"
#include <QtGui>
StereoSamePhase::StereoSamePhase( QWidget* parent /*= NULL*/ )
	: MyWidget(parent)
{
	m_pGroupBox = new QGroupBox(this);
	m_pGroupBox->setTitle("立体声同相检测");

	m_pPercentLabel =new QLabel("比例",this);
	m_pPercent = new QDoubleSpinBox(this);
	m_pPercent->setRange(95,100);
	m_pPercent->setDecimals(1);
	m_pPercent->setSingleStep(0.1);
	m_pPercent->setValue(98.3);

	m_pPercentPreinfo = new QLabel("比例：",this);
	m_pPercentLastinfo = new QLabel("范围95% - 100%",this);
}



StereoSamePhase::~StereoSamePhase(void)
{
}

void StereoSamePhase::setPercentValue( double value )
{
	m_pPercent->setValue(value);
}

double StereoSamePhase::getPercentValue() const
{
	return m_pPercent->value();
}

void StereoSamePhase::resizeEvent(QResizeEvent* event)
{
	m_pGroupBox->setGeometry(0,0,width(),height());

	m_pPercentLabel->setGeometry(40,60,m_pPercentLabel->width(),20);
	m_pPercent->setGeometry(160,60,m_pPercent->width(),20);

	m_pPercentPreinfo->setGeometry(40,160,m_pPercentPreinfo->width(),20);
	m_pPercentLastinfo->setGeometry(170,160,m_pPercentLastinfo->width(),20);
}

void StereoSamePhase::domWriteElement( QDomDocument &doc,QDomElement xmlElement,
									QDomElement &xmlElementRt )
{
	xmlElementRt = doc.createElement("StereoSamePhase");

	QDomElement xmlElementRtChild1 = doc.createElement("Percent");

	QDomText xmlText1 = doc.createTextNode(QString::number(getPercentValue()));

	xmlElement.appendChild(xmlElementRt);

	xmlElementRt.appendChild(xmlElementRtChild1);

	xmlElementRtChild1.appendChild(xmlText1);
}

void StereoSamePhase::domReadElement( QDomNode node,QTreeWidgetItem *item )
{
	QDomNode childNode;
	for (childNode = node.firstChild();!childNode.isNull();
		childNode=childNode.nextSibling())
	{
		if(childNode.nodeName()=="Percent")
		{
			setPercentValue(childNode.toElement().text().toDouble());
		}
	}
	item->setCheckState(0,Qt::Checked);
}


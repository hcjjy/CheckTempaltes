#include "StereoInvertPhase.h"
#include <QtGui>

StereoInvertPhase::StereoInvertPhase( QWidget* parent /*= NULL*/ )
	: MyWidget(parent)
{
	m_pGroupBox = new QGroupBox(this);
	m_pGroupBox->setTitle("立体声反向检测");

	m_pDurationLabel = new QLabel("时间阀值",this);
	m_pDuration = new QDoubleSpinBox(this);
	m_pDuration->setRange(1,1000);
	m_pDuration->setDecimals(1);
	m_pDuration->setSingleStep(0.1);
	m_pDuration->setValue(1);

	m_pDurationPreinfo = new QLabel("时间阀值：",this);
	m_pDurationLastinfo = new QLabel("范围1 - 1000",this);
}


StereoInvertPhase::~StereoInvertPhase(void)
{

}

void StereoInvertPhase::setDurationValue( double value )
{
	m_pDuration->setValue(value);
}

double StereoInvertPhase::getDurationValue() const
{
	return m_pDuration->value();
}

void StereoInvertPhase::resizeEvent(QResizeEvent* event)
{
	m_pGroupBox->setGeometry(0,0,width(),height());

	m_pDurationLabel->setGeometry(40,85,m_pDurationLabel->width(),20);
	m_pDuration->setGeometry(160,85,m_pDuration->width(),20);

	m_pDurationPreinfo->setGeometry(40,180,m_pDurationPreinfo->width(),20);
	m_pDurationLastinfo->setGeometry(170,180,m_pDurationLastinfo->width(),20);
}

void StereoInvertPhase::domWriteElement( QDomDocument &doc,QDomElement xmlElement,
										QDomElement &xmlElementRt )
{
	xmlElementRt = doc.createElement("StereoInvertPhase");

	QDomElement xmlElementRtChild1 = doc.createElement("Duration");

	QDomText xmlText1 = doc.createTextNode(QString::number(getDurationValue()));

	xmlElement.appendChild(xmlElementRt);

	xmlElementRt.appendChild(xmlElementRtChild1);

	xmlElementRtChild1.appendChild(xmlText1);

}

void StereoInvertPhase::domReadElement( QDomNode node,QTreeWidgetItem *item )
{
	QDomNode childNode;
	for (childNode = node.firstChild();!childNode.isNull();
		childNode=childNode.nextSibling())
	{
		if(childNode.nodeName()=="Duration")
		{
			setDurationValue(childNode.toElement().text().toInt());
		}
	}
	item->setCheckState(0,Qt::Checked);
}

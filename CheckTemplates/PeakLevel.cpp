#include "PeakLevel.h"
#include <QtGui>

PeakLevel::PeakLevel( QWidget* parent /*= NULL*/ )
	: MyWidget(parent)
{
	m_pGroupBox = new QGroupBox(this);
	m_pGroupBox->setTitle("峰值检测");

	m_pPeakLevelLabel = new QLabel("峰值阀值",this);
	m_pPeakLevel = new QSpinBox(this);
	m_pPeakLevel->setRange(-20,0);
	m_pPeakLevel->setValue(-6);

	m_pDurationLabel = new QLabel("时间阀值",this);
	m_pDuration = new QSpinBox(this);
	m_pDuration->setRange(1,1000);
	m_pDuration->setValue(1);

	m_pPeakLevelPreinfo = new QLabel("峰值阀值：",this);
	m_pPeakLevelLastinfo = new QLabel("范围[-20,0]",this);
	m_pDurationPreinfo = new QLabel("时间阀值：",this);
	m_pDurationLastinfo = new QLabel("范围1 - 1000",this);
}
PeakLevel::~PeakLevel(void)
{

}

void PeakLevel::setPeakLevelValue(int value)
{
	m_pPeakLevel->setValue(value);
}

void PeakLevel::setDurationValue(int value)
{
	m_pDuration->setValue(value);
}

int PeakLevel::getPeakLevelValue() const
{
	return m_pPeakLevel->value();
}

int PeakLevel::getDurationValue() const
{
	return m_pDuration->value();
}

void PeakLevel::resizeEvent(QResizeEvent* event)
{
	m_pGroupBox->setGeometry(0,0,width(),height());

	m_pPeakLevelLabel->setGeometry(40,60,m_pPeakLevelLabel->width(),20);
	m_pPeakLevel->setGeometry(160,60,m_pPeakLevel->width(),20);
	m_pDurationLabel->setGeometry(40,85,m_pDurationLabel->width(),20);
	m_pDuration->setGeometry(160,85,m_pDuration->width(),20);

	m_pPeakLevelPreinfo->setGeometry(40,160,m_pPeakLevelPreinfo->width(),20);
	m_pPeakLevelLastinfo->setGeometry(170,160,m_pPeakLevelLastinfo->width(),20);
	m_pDurationPreinfo->setGeometry(40,180,m_pDurationPreinfo->width(),20);
	m_pDurationLastinfo->setGeometry(170,180,m_pDurationLastinfo->width(),20);
}

void PeakLevel::domWriteElement( QDomDocument &doc,QDomElement xmlElement,
								QDomElement &xmlElementRt )
{
	xmlElementRt = doc.createElement("PeakLevel");

	QDomElement xmlElementRtChild1 = doc.createElement("TruePeakLevel");
	QDomElement xmlElementRtChild2 = doc.createElement("Duration");

	QDomText xmlText1 = doc.createTextNode(QString::number(getPeakLevelValue()));
	QDomText xmlText2 = doc.createTextNode(QString::number(getDurationValue()));

	xmlElement.appendChild(xmlElementRt);

	xmlElementRt.appendChild(xmlElementRtChild1);
	xmlElementRt.appendChild(xmlElementRtChild2);

	xmlElementRtChild1.appendChild(xmlText1);
	xmlElementRtChild2.appendChild(xmlText2);

}

void PeakLevel::domReadElement( QDomNode node,QTreeWidgetItem *item )
{
	QDomNode childNode;
	for (childNode = node.firstChild();!childNode.isNull();
		childNode=childNode.nextSibling())
	{
		if(childNode.nodeName()=="TruePeakLevel")
		{
			setPeakLevelValue(childNode.toElement().text().toInt());
		}
		else if(childNode.nodeName()=="Duration")
		{
			setDurationValue(childNode.toElement().text().toInt());
		}
	}
	item->setCheckState(0,Qt::Checked);
}


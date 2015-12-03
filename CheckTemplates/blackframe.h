#pragma once
#include "MyWidget.h"
class QSpinBox;
class QLabel;
class QDoubleSpinBox;
class QGroupBox;
class QTreeWidgetItem;
class BlackFrame :
	public MyWidget
{
	Q_OBJECT
public:
	BlackFrame(QWidget *parent = NULL);
	~BlackFrame(void);
public:
	void setBrightSpotValue(int value);
	void setPercentValue(double value);
	void setDurationValue(int value);
	int getBrightSpotValue() const;
	double getPercentValue() const;
	int getDurationValue() const;
	virtual void domWriteElement(QDomDocument &doc,QDomElement xmlElement,
								 QDomElement &xmlElementRt);
	virtual void domReadElement(QDomNode node,QTreeWidgetItem *item);								
protected:
	virtual void resizeEvent(QResizeEvent *event);
private:
	QGroupBox *m_pGroupBox;
	QLabel *m_pBrightSpotLabel;
	QSpinBox *m_pBrightSpot;
	QLabel *m_pPercentLabel;
	QDoubleSpinBox *m_pPercent;
	QLabel *m_pDurationLabel;
	QSpinBox *m_pDuration;
	

	QLabel *m_pBrightSpotPreinfo;
	QLabel *m_pBrightSpotLastinfo;

	QLabel *m_pPercentPreinfo;
	QLabel *m_pPercentLastinfo;

	QLabel *m_pDurationPreinfo;
	QLabel *m_pDurationLastinfo;
};


#pragma once
#include "MyWidget.h"
class QLabel;
class QDoubleSpinBox;
class QSpinBox;
class QGroupBox;
class QTreeWidgetItem;
class ColorFrame :
	public MyWidget
{
	Q_OBJECT
public:
	ColorFrame(QWidget *parent = NULL);
	~ColorFrame(void);
public:
	void setPercentValue(double value);
	void setDurationValue(int value);
	double getPercentValue() const;
	int getDurationValue() const;
protected:
	virtual void resizeEvent(QResizeEvent *event);
	virtual void domWriteElement(QDomDocument &doc,QDomElement xmlElement,
								 QDomElement &xmlElementRt);
	virtual void domReadElement(QDomNode node,QTreeWidgetItem *item);
private:
	QGroupBox *m_pGroupBox;
	QLabel *m_pPercentLabel;
	QDoubleSpinBox *m_pPercent;
	QLabel *m_pDurationLabel;
	QSpinBox *m_pDuration;

	QLabel *m_pPercentPreinfo;
	QLabel *m_pPercentLastinfo;

	QLabel *m_pDurationPreinfo;
	QLabel *m_pDurationLastinfo;
};


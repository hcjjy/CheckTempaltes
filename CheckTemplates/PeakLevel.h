#ifndef PEAKLEVEL_H
#define PEAKLEVEL_H
#include "MyWidget.h"
class QSpinBox;
class QLabel;
class QGroupBox;
class QTreeWidgetItem;
class PeakLevel:
	public MyWidget
{
	Q_OBJECT
public:
	PeakLevel(QWidget* parent = NULL);
	~PeakLevel(void);
public:
	void setPeakLevelValue(int value);
	void setDurationValue(int value);
	int getPeakLevelValue() const;
	int getDurationValue() const;
protected:
	virtual void resizeEvent(QResizeEvent* event);
	virtual void domWriteElement(QDomDocument &doc,QDomElement xmlElement,
		QDomElement &xmlElementRt);
	virtual void domReadElement(QDomNode node,QTreeWidgetItem *item);
private:
	QGroupBox *m_pGroupBox;

	QLabel *m_pPeakLevelLabel;
	QSpinBox *m_pPeakLevel;
	QLabel *m_pDurationLabel;
	QSpinBox *m_pDuration;

	QLabel *m_pPeakLevelPreinfo;
	QLabel *m_pPeakLevelLastinfo;
	QLabel *m_pDurationPreinfo;
	QLabel *m_pDurationLastinfo;
};
#endif
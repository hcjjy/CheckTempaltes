#ifndef StereoInvertPhase_H
#define StereoInvertPhase_H
#include "MyWidget.h"
class QLabel;
class QDoubleSpinBox;
class QGroupBox;
class QTreeWidgetItem;
class StereoInvertPhase :
	public MyWidget
{
public:
	StereoInvertPhase(QWidget* parent = NULL);
	virtual ~StereoInvertPhase(void);
public:
	void setDurationValue(double value);
	double getDurationValue() const;
protected:
	virtual void resizeEvent(QResizeEvent *event);
	virtual void domWriteElement(QDomDocument &doc,QDomElement xmlElement,
		QDomElement &xmlElementRt);
	virtual void domReadElement(QDomNode node,QTreeWidgetItem *item);
private:
	QGroupBox *m_pGroupBox;
	QLabel *m_pDurationLabel;
	QDoubleSpinBox *m_pDuration;

	QLabel *m_pDurationPreinfo;
	QLabel *m_pDurationLastinfo;
};
#endif

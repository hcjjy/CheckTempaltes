#ifndef StereoSamePhase_H
#define StereoSamePhase_H
#include "MyWidget.h"
class QLabel;
class QDoubleSpinBox;
class QGroupBox;
class QTreeWidgetItem;
class StereoSamePhase :
	public MyWidget
{
	Q_OBJECT
public:
	StereoSamePhase(QWidget* parent = NULL);
	virtual ~StereoSamePhase(void);
public:
	void setPercentValue(double value);
	double getPercentValue() const;
protected:
	virtual void resizeEvent(QResizeEvent *event);
	virtual void domWriteElement(QDomDocument &doc,QDomElement xmlElement,
		QDomElement &xmlElementRt);
	virtual void domReadElement(QDomNode node,QTreeWidgetItem *item);
private:
	QGroupBox *m_pGroupBox;
	QLabel *m_pPercentLabel;
	QDoubleSpinBox *m_pPercent;

	QLabel *m_pPercentPreinfo;
	QLabel *m_pPercentLastinfo;
};
#endif


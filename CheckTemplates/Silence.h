#pragma once
#include "MyWidget.h"
class QSpinBox;
class QLabel;
class QGroupBox;
class QTreeWidgetItem;
class Silence :
	public MyWidget
{
	Q_OBJECT
public:
	Silence(QWidget *parent = NULL);
	~Silence(void);
public:
	void setLevelValue(int value);
	void setDurationValue(int value);
	int getLevelValue() const;
	int getDurationValue() const;
protected:
	virtual void resizeEvent(QResizeEvent *event);
	virtual void domWriteElement(QDomDocument &doc,QDomElement xmlElement,
								QDomElement &xmlElementRt);
	virtual void domReadElement(QDomNode node,QTreeWidgetItem *item);
private:
	QGroupBox *m_pGroupBox;
	QLabel *m_pLevelLabel;
	QSpinBox *m_pLevel;
	QLabel *m_pDurationLabel;
	QSpinBox *m_pDuration;

	QLabel *m_pLevelPreinfo;
	QLabel *m_pLevelLastinfo;
	QLabel *m_pDurationPreinfo;
	QLabel *m_pDurationLastinfo;
};


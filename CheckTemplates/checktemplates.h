#pragma once
#include <QtGui/QDialog>
#include <QDomElement>
#include "MyWidget.h"
#include <QtGui/QTreeWidgetItem>
class QPushButton;
class MyTreeWidget;
class QTreeWidgetItem;
class Video;
class BlackFrame;
class ColorFrame;
class Audio;
class Silence;
class PeakLevel;
class StereoCorrelation;
class StereoInvertPhase;
class StereoSamePhase;
class QXmlStreamWriter;
class QStackedWidget;
class CheckTemplates :
	public QDialog
{
	Q_OBJECT
public:
	CheckTemplates(QWidget * parent = NULL);
	virtual ~CheckTemplates(void);
public slots:
	void save();
	void saveAs();
	void cancel();
	void showItem();
	void showItem(QTreeWidgetItem* item, int column);
protected:
	virtual void resizeEvent(QResizeEvent *event);
private:
	bool domReadXml(const QString &fileName,QMap<QString ,QTreeWidgetItem* > &nameToPtr);
	void domReadElement(QDomElement element,QMap<QString ,QTreeWidgetItem* > &nameToPtr);
	bool domWriteXml(const QString &fileName);
	void domWriteElement(QDomDocument &doc,QDomElement xmlElement, 
						QTreeWidgetItem *item);
	QTreeWidgetItem* addTreeWidgetItem(QTreeWidgetItem *parent,QString itemName,
		MyWidget *widget,QString tagName,QMap<QString ,QTreeWidgetItem* > &nameToPtr);
		
private:
	MyTreeWidget *m_pTreeWidget;
	QPushButton *m_pSaveButton;
	QPushButton *m_pSaveAsButton;
	QPushButton *m_pCancelButton;
	QStackedWidget *m_pStackedWidget;
};


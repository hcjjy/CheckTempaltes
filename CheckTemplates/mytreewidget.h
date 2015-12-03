#pragma once
#include <QtGui/QTreeWidget>
class QTreeWidgetItem;
class MyTreeWidget:public QTreeWidget
{
	Q_OBJECT
public:
	MyTreeWidget(QWidget *parent = NULL);
	virtual ~MyTreeWidget(void);
public:
	//QTreeWidgetItem* addTreeWidgetItem(QTreeWidgetItem *parent,QString itemName);
	void setChildItemCheckState(QTreeWidgetItem *parent);
	void setParentItemCheckState(QTreeWidgetItem *child);
};


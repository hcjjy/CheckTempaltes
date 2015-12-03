#include "mytreewidget.h"
#include <QtGui>
int startVariant =0x10100;
MyTreeWidget::MyTreeWidget( QWidget *parent /*= NULL*/ )
	:QTreeWidget(parent)
{	
	this->setHeaderLabel("");

}
MyTreeWidget::~MyTreeWidget(void)
{
}

void MyTreeWidget::setChildItemCheckState( QTreeWidgetItem *parent )
{
	
	if (parent!=NULL)
	{
		if(parent->childCount()>0)
		{
			for(int i = 0;i<parent->childCount();i++)
			{
				parent->child(i)->setCheckState(0,parent->checkState(0));
				setChildItemCheckState(parent->child(i));
			}
		}
	}
}

void MyTreeWidget::setParentItemCheckState( QTreeWidgetItem *child )
{
	if (child!=NULL)
	{
		int j;
		QTreeWidgetItem * parentItem = child->parent();
		while(parentItem!=NULL)
		{
			for (j = 0;j < parentItem->childCount();j++)
			{
				if(parentItem->child(j)->checkState(0)==Qt::Unchecked)
					break;
			}
			if (j==parentItem->childCount())
			{
				parentItem->setCheckState(0,Qt::Checked);
			}
			else
			{
				parentItem->setCheckState(0,Qt::Unchecked);
			}
			parentItem = parentItem->parent();
		}
	}
	
}




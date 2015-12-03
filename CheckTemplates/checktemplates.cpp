#include "checktemplates.h"
#include "mytreewidget.h"
#include "MyWidget.h"
#include "Video.h"
#include "blackframe.h"
#include "ColorFrame.h"
#include "Audio.h"
#include "Silence.h"
#include "PeakLevel.h"
#include "StereoCorrelation.h"
#include "StereoInvertPhase.h"
#include "StereoSamePhase.h"
#include <iostream>
#include <QDomDocument>
#include <QTextStream>
#include <QtGui>
#include <QMap>
extern int startVariant;
CheckTemplates::CheckTemplates( QWidget * parent /*= NULL*/ )
{
	resize(QSize(700,700));
	m_pTreeWidget = new MyTreeWidget(this);
	m_pStackedWidget = new QStackedWidget(this);

	Video *m_pVideo = new Video();
	BlackFrame *blackFrame = new BlackFrame();
	ColorFrame *colorFrame = new ColorFrame();
	Audio *audio = new Audio();
	Silence *silence = new Silence();
	PeakLevel *peakLevel = new PeakLevel();
	StereoCorrelation *stereoCorrelation = new StereoCorrelation();
	StereoInvertPhase *stereoInvertPhase = new StereoInvertPhase();
	StereoSamePhase *stereoSamePhase  = new StereoSamePhase();
	m_pStackedWidget->addWidget(blackFrame);
	m_pStackedWidget->addWidget(colorFrame);
	m_pStackedWidget->addWidget(silence);
	m_pStackedWidget->addWidget(peakLevel);
	m_pStackedWidget->addWidget(stereoInvertPhase);
	m_pStackedWidget->addWidget(stereoSamePhase);

	QMap<QString ,QTreeWidgetItem* > nameToPtr;

	QTreeWidgetItem* FVideo = addTreeWidgetItem(m_pTreeWidget->invisibleRootItem(),
		"视频技审",m_pVideo,"Video",nameToPtr);
	addTreeWidgetItem(FVideo,"黑场检测",blackFrame,"BlackFrame",nameToPtr);
	addTreeWidgetItem(FVideo,"彩帧检测",colorFrame,"ColorFrame",nameToPtr);

	QTreeWidgetItem* FAudio = addTreeWidgetItem(m_pTreeWidget->invisibleRootItem(),
		"音频技审",audio,"Audio",nameToPtr);
	addTreeWidgetItem(FAudio,"静音检测",silence,"Slience",nameToPtr);
	addTreeWidgetItem(FAudio,"峰值检测",peakLevel,"PeakLevel",nameToPtr);
	QTreeWidgetItem* FAudioItem=addTreeWidgetItem(FAudio,"立体声相位检测",
		stereoCorrelation,"StereoCorrelation",nameToPtr);
	addTreeWidgetItem(FAudioItem,"立体声反向检测",stereoInvertPhase,
					"StereoInvertPhase",nameToPtr);
	addTreeWidgetItem(FAudioItem,"立体声同向检测",stereoSamePhase,
					"StereoSamePhase",nameToPtr);

	m_pSaveButton = new QPushButton(("保存"),this);
	m_pSaveAsButton = new QPushButton("另存为",this);
	m_pCancelButton= new QPushButton("取消",this);

	m_pSaveButton->setFixedSize(70,20);
	m_pSaveAsButton->setFixedSize(70,20);
	m_pCancelButton->setFixedSize(70,20);

	domReadXml("test.xml",nameToPtr);

	connect(m_pTreeWidget,SIGNAL(itemSelectionChanged()),
		this,SLOT(showItem()));
	
	connect(m_pTreeWidget,SIGNAL(itemChanged(QTreeWidgetItem*,int)),
		this,SLOT(showItem(QTreeWidgetItem*,int)));

	connect(m_pSaveButton,SIGNAL(clicked()),this,SLOT(save()));
	connect(m_pSaveAsButton,SIGNAL(clicked()),this,SLOT(saveAs()));
	connect(m_pCancelButton,SIGNAL(clicked()),this,SLOT(cancel()));
}
CheckTemplates::~CheckTemplates(void)
{
}

void CheckTemplates::save()
{
	domWriteXml("test.xml");
	close();
}

void CheckTemplates::saveAs()
{
	QString fileName = QFileDialog::getSaveFileName(this,"保存模版","","xml(*.xml)");
	if (!fileName.isEmpty())
	{
		domWriteXml("test.xml");
	}
}

void CheckTemplates::cancel()
{
	close();
}

void CheckTemplates::showItem()
{
	QTreeWidgetItem *item =m_pTreeWidget->currentItem();
 	QVariant variant = item->data(0,Qt::UserRole);
	MyWidget * curWigdet = (MyWidget *)variant.toInt();
	m_pStackedWidget->setCurrentWidget(curWigdet);
}
void CheckTemplates::showItem( QTreeWidgetItem* item, int column)
{
	QVariant variant = item->data(0,Qt::UserRole);
	MyWidget * curWigdet = (MyWidget *)variant.toInt();
	m_pStackedWidget->setCurrentWidget(curWigdet);

	disconnect(m_pTreeWidget,SIGNAL(itemChanged(QTreeWidgetItem*,int)),
		this,SLOT(showItem(QTreeWidgetItem*,int)));

	m_pTreeWidget->setChildItemCheckState(item);
	m_pTreeWidget->setParentItemCheckState(item);
	
	connect(m_pTreeWidget,SIGNAL(itemChanged(QTreeWidgetItem*,int)),
		this,SLOT(showItem(QTreeWidgetItem*,int)));
}
void CheckTemplates::resizeEvent( QResizeEvent *event )
{
	int thisWidth =width();
	int thisHeight = height();
	int saveWidth = m_pSaveButton->width();
	int saveHeight = m_pSaveButton->height();
	int saveAsWidth = m_pSaveAsButton->width();
	int saveAsHeight = m_pSaveAsButton->height();
	int cancleWidth = m_pCancelButton->width();
	int cancleHeight = m_pCancelButton->height();
	int treeWidgetWidth = m_pTreeWidget->width();
	int margin = 5;
	m_pSaveButton->setGeometry(thisWidth-saveWidth,thisHeight-saveHeight-margin,
		saveWidth,saveHeight);
	m_pCancelButton->setGeometry(thisWidth-saveWidth-cancleWidth-margin,
		thisHeight-cancleHeight-margin,cancleWidth,cancleHeight);
	m_pSaveAsButton->setGeometry(thisWidth-saveWidth-cancleWidth-saveAsWidth-2*margin,
		thisHeight-saveAsHeight-margin,saveAsWidth,saveAsHeight);

 	m_pTreeWidget->setGeometry(0,0,200,thisHeight-5*margin);
	
	m_pStackedWidget->setGeometry(200+margin,margin,
		thisWidth-200-2*margin,thisHeight-6*margin);
}

QTreeWidgetItem* CheckTemplates::addTreeWidgetItem( QTreeWidgetItem *parent,QString itemName ,
	MyWidget *widget,QString tagName,QMap<QString ,QTreeWidgetItem* > &nameToPtr)
{
	QTreeWidgetItem *item = new QTreeWidgetItem(parent);
	item->setText(0,itemName);
	item->setCheckState(0,Qt::Unchecked);
	item->setExpanded(true);
	item->setData(0,Qt::UserRole,int(widget));
	nameToPtr.insert(tagName,item);
	return item;
}

bool CheckTemplates::domWriteXml( const QString &fileName )
{
	QFile file(fileName);
	if (!file.open(QFile::WriteOnly|QFile::Text))
	{
		std::cerr<<"Error : Cannot write file"
			<<qPrintable(fileName)<<": "
			<<qPrintable(file.errorString())<<std::endl;
		return false;
	}
	const int indent = 4;
	QDomDocument doc;
	QTextStream out(&file);
	QDomNode proInstruction = doc.createProcessingInstruction("xml",
		"version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"");
	QDomElement xmlCheckTemplatesElement = doc.createElement("CheckTemplates");
	QDomElement xmlQualityCheckElement = doc.createElement("QualityCheck");

	doc.appendChild(xmlCheckTemplatesElement);
	doc.insertBefore(proInstruction,xmlCheckTemplatesElement);
	xmlCheckTemplatesElement.appendChild(xmlQualityCheckElement);

	for(int i = 0;i<m_pTreeWidget->topLevelItemCount();i++)
	{
		domWriteElement(doc,xmlQualityCheckElement,m_pTreeWidget->topLevelItem(i));
	}
	doc.save(out,indent);
	return true;
}

void CheckTemplates::domWriteElement(QDomDocument &doc,QDomElement xmlElement,
									 QTreeWidgetItem *item )
{
	QDomElement xmlElementRt;
	QVariant variant  = item->data(0,Qt::UserRole);
	MyWidget *curWigdet = (MyWidget *)variant.toInt();
	if (item->checkState(0)==Qt::Checked||item->childCount()>0)
	{
		curWigdet->domWriteElement(doc,xmlElement,xmlElementRt);
	}
	for (int i = 0;i < item->childCount();i++)
	{
		domWriteElement(doc,xmlElementRt,item->child(i));
	}
}

bool CheckTemplates::domReadXml(const QString &fileName ,QMap<QString ,QTreeWidgetItem* > &nameToPtr)
{
	QFile file(fileName);
	if(!file.open(QFile::ReadOnly|QFile::Text))
	{
		std::cerr<<"Error : Cannot read file"
			<<qPrintable(fileName)<<": "
			<<qPrintable(file.errorString())<<std::endl;
		return false;
	}
	QString errorStr;
	int errorLine;
	int errorColumn;

	QDomDocument doc;
	if(!doc.setContent(&file,false,&errorStr,&errorLine,&errorColumn))
	{
		std::cerr<<"Error : Parse error at line "<<errorLine<<", "
			<<"column"<<errorColumn<<": "
			<<qPrintable(errorStr)<<std::endl;
		return false;
	}
	QDomElement root = doc.documentElement();
	if(root.tagName()!="CheckTemplates")
	{
		std::cerr<<"Error: Not a CheckTemplates file"<<std::endl;
		return false;
	}
	QDomElement rootChild = root.firstChildElement("QualityCheck");
	if (rootChild.isNull())
	{
		std::cerr<<"Error: Not a QualityCheck Element"<<std::endl;
		return false;
	}
	else
	{
		domReadElement(rootChild,nameToPtr );
	}
	return true;
}

void CheckTemplates::domReadElement( QDomElement element,QMap<QString ,QTreeWidgetItem* > &nameToPtr )
{
	QDomNode childNode;
	for (childNode = element.firstChild();!childNode.isNull();
		childNode=childNode.nextSibling())
	{
		if (nameToPtr.count(childNode.nodeName()))
		{
			QTreeWidgetItem*  item = nameToPtr[childNode.nodeName()];
			QVariant variant  = item->data(0,Qt::UserRole);
			MyWidget *curWigdet = (MyWidget *)variant.toInt();
			curWigdet->domReadElement(childNode,item);
			m_pTreeWidget->setParentItemCheckState(item);
			if (childNode.hasChildNodes())
			{
				QDomNode node = childNode.firstChild();
				if (node.nodeType()==QDomNode::ElementNode)
				{
					if (node.hasChildNodes())
					{
						QDomNode textNode = node.firstChild();
						if (textNode.nodeType()==QDomNode::TextNode)
						{
							continue;
						}
					}
					domReadElement(childNode.toElement(),nameToPtr );
				}
			}
		}
	}
	
}

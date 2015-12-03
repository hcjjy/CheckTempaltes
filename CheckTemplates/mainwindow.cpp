#include "mainwindow.h"
#include "checktemplates.h"
#include <QtGui>
MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	//ui.setupUi(this);
	this->resize( QSize( 600, 400 ));
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
	
	//QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	setWindowTitle("技审模版生成");
	pushButton = new QPushButton("创建",this);
	pushButton->setFixedSize(70,20);
	
	connect(pushButton,SIGNAL(clicked()),this,SLOT(createCheckTemplate()));
}

MainWindow::~MainWindow(void)
{
	
}
void MainWindow::createCheckTemplate()
{
	checkTemplates = new CheckTemplates(this);
	if(checkTemplates->exec())
	{

	}
	delete checkTemplates;
	checkTemplates=NULL;
}
void MainWindow::resizeEvent( QResizeEvent *event )
{
	int w = width()/2;
	int h = height()/2;
	int w1 =pushButton->width();
	int h1 =pushButton->height();
	pushButton->setGeometry(w-w1/2,h-h1/2,w1,h1);
}

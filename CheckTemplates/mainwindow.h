#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainwindow.h"
#include <QtGui/QWidget>
class QPushButton;
class CheckTemplates;
class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MainWindow();
protected:
	virtual void resizeEvent(QResizeEvent *event);
public slots:
	void createCheckTemplate();
private:
	Ui::MainWindowClass ui;
	QPushButton *pushButton;
	CheckTemplates *checkTemplates;
};

#endif // MAINWINDOW_H

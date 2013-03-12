#ifndef TEST1_H
#define TEST1_H

#include <QtGui/QMainWindow>
#include "ui_test1.h"

class test1 : public QMainWindow
{
	Q_OBJECT

public:
	test1(QWidget *parent = 0, Qt::WFlags flags = 0);
	~test1();

private:
	Ui::test1Class ui;
};

#endif // TEST1_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GoalElement.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    parent->width();
    m_pParent = parent;
    ui->setupUi(this);

    GoalElement* ele = GoalFactory::get();
    m_pContainer.add(ele);
    frameNo = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
        m_pGoalRenderer.setEvent(event);
        m_pGoalRenderer.setWidget(m_pParent);

        std::vector<GoalElement*>::iterator begin = m_pContainer.begin();
        std::vector<GoalElement*>::iterator end = m_pContainer.end();
        std::vector<GoalElement*>::iterator cur = m_pContainer.begin();

        while (cur != end) {
                cur++;
                GoalElement* ele = *cur;
                m_pGoalRenderer.render(ele, frameNo);
        }
}

 void MainWindow::nextAnimationFrame()
 {
     ++frameNo;
     update();
 }

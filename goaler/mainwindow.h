#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "GoalContainer.h"
#include "GoalRenderer.h"
#include "GoalFactory.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
    void nextAnimationFrame();
    void paintEvent(QPaintEvent *event);

private:
    QWidget* m_pParent;
    Ui::MainWindow *ui;
    GoalContainer m_pContainer;
    GoalRenderer m_pGoalRenderer;
    int frameNo;
};

#endif // MAINWINDOW_H

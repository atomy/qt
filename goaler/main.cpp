 #include <QApplication>

 #include "GoalApp.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     GoalApp goalApp;
 #if defined(Q_OS_SYMBIAN)
     goalApp.showMaximized();
 #else
     goalApp.show();
 #endif
     return app.exec();
 }
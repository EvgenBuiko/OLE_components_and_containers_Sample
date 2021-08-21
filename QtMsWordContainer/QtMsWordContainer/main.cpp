#include "MainReport.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainReport report;
    report.InitializeData();
    report.show();
    return a.exec();
}

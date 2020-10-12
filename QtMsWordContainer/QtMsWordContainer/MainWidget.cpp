#include <QListView>
#include "MainWidget.h"
#include "ItemsModel.h"
#include <ActiveQt/qaxwidget.h>

MainWidget::MainWidget(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}
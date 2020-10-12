#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWidget.h"

class MainWidget : public QMainWindow
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = Q_NULLPTR);
    void setupWindow();
    QListView* GetDocsListView() { return ui.docsListView; }
    QVBoxLayout* GetDocEditorLayout() { return dynamic_cast<QVBoxLayout*>( ui.docsEditorLayout ); }
    
private:
    Ui::MainWidgetClass ui;
};

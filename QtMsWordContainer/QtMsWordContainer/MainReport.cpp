#include "MainReport.h"
#include "MainWidget.h"
#include "ItemsModel.h"

class MainReport::Private
{
public:
	void InitView()
	{
		MainWindow.GetDocsListView()->setModel( dynamic_cast<QAbstractItemModel*>( &Model ) );
	}
	MainWidget MainWindow;
	ItemsModel Model;
};

MainReport::MainReport()
	: d( *new Private )
{
	d.InitView();
}

void MainReport::show()
{
	d.MainWindow.show();
}

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
  ItemsDataManager dataMng;
};

MainReport::MainReport()
	: d( *new Private )
{
	d.InitView();
}

void MainReport::InitializeData()
{
  d.dataMng.LoadData();

  for( unsigned int i = 0; i < d.dataMng.DataCount(); i++ )
    d.Model.addToList( QString::fromStdString( d.dataMng.GetFilenameByIndex( i ) ) );
}

void MainReport::show()
{
	d.MainWindow.show();
}

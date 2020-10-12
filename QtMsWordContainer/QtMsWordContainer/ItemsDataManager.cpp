#include "ItemsDataManager.h"
#include "qdir.h"

ItemsDataManager::ItemsDataManager()
{
	m_bLoaded = false;
}

void ItemsDataManager::LoadData()
{
	QDir directory( QDir::currentPath() );
	QFileInfoList filesList = directory.entryInfoList( QDir::Files );

	for (const QFileInfo& file : filesList)
		Data.push_back( new QFileInfo( file ) );
	
	m_bLoaded = true;
}

QFileInfo ItemsDataManager::GetDataByIndex( long ind ) const
{
	return *( Data[ind] );
}

std::string ItemsDataManager::GetFilenameByIndex( long ind ) const
{
	return GetDataByIndex(ind).fileName().toStdString();
}

long ItemsDataManager::DataCount() const
{
	return Data.size();
}

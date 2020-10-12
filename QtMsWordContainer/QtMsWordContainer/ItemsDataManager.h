#pragma once
#include <vector>
#include <QFileInfo>

class ItemsDataManager
{
public:
	ItemsDataManager();
	void LoadData();

	QFileInfo GetDataByIndex( long ind ) const;
	std::string GetFilenameByIndex( long ind ) const;
	long DataCount() const;
private:
	bool m_bLoaded;
	std::vector<QFileInfo*> Data;
};
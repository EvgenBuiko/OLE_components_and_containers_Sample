#pragma once
#include <qabstractitemmodel.h>
#include "ItemsDataManager.h"

class ItemsModel : public QAbstractListModel
{
	Q_OBJECT

public:
	ItemsModel(QObject* parent = 0);

	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role) const;
	QVariant headerData(int section, Qt::Orientation orientation,
		int role = Qt::DisplayRole) const;

  void addToList( QString str );
private:
	QStringList stringList;
};

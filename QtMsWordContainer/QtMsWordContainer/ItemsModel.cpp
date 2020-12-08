#include "ItemsModel.h"
#include "ItemsDataManager.h"

ItemsModel::ItemsModel(QObject* parent /*= 0*/)
	: QAbstractListModel(parent)
{
}

int ItemsModel::rowCount(const QModelIndex& parent /*= QModelIndex()*/) const
{
	return stringList.count();
}

QVariant ItemsModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid() || index.row() >= stringList.size())
		return QVariant();

	if (role == Qt::DisplayRole)
		return stringList.at(index.row());

	return QVariant();
}

QVariant ItemsModel::headerData(int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole*/) const
{
	if (role != Qt::DisplayRole)
		return QVariant();

	if (orientation == Qt::Horizontal)
		return QString("Column %1").arg(section);
	else
		return QString("Row %1").arg(section);
}

void ItemsModel::addToList( QString str )
{
  stringList.append( str );
}


#include "Model.h"

int Model::rowCount(const QModelIndex & parent) const
{
	return this->repo.getUserWatchList().size();
}

int Model::columnCount(const QModelIndex & parent) const
{
	return 5;
}

QVariant Model::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	int column = index.column();
	std::vector<Movie> movies = this->repo.getUserWatchList();

	if (row == movies.size())
		return QVariant();

	Movie mov = movies[row];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (column)
		{
		case 0:
			return QString::fromStdString(mov.getTitle());
		case 1:
			return QString::fromStdString(mov.getGenre());
		case 2:
			return QString::fromStdString(std::to_string(mov.getYear()));
		case 3:
			return QString::fromStdString(std::to_string(mov.getNumberLikes()));
		case 4:
			return QString::fromStdString(mov.getTrailer());
		default:
			break;
		}
	}
	return QVariant();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Title" };
			case 1:
				return QString{ "Genre" };
			case 2:
				return QString{ "Year" };
			case 3:
				return QString{ "Number of likes" };
			case 4:
				return QString{ "Trailer link" };
			default:
				break;
			}
		}
	}

	return QVariant();
}

bool Model::setData(const QModelIndex & index, const QVariant & value, int role)
{
	/*if (!index.isValid() || role != Qt::EditRole)
		return false;

	// set the new data to the gene
	int movIndex = index.row();

	// get the genes
	std::vector<Movie> movies = this->repo.getUserWatchList();

	// Allow adding in the table
	//if the index is >= number of genes => a new gene is added
	if (movIndex == movies.size())
	{
		this->beginInsertRows(QModelIndex{}, movIndex, movIndex);

		switch (index.column())
		{
		case 0:
			this->repo.addGene(Gene{ value.toString().toStdString(), "", "" });
			break;
		case 1:
			this->repo.addGene(Gene{ "", value.toString().toStdString(), "" });
			break;
		case 2:
			this->repo.addGene(Gene{ "", "", value.toString().toStdString() });
			break;
		}

		this->endInsertRows();
		return true;
	}

	Gene& currentGene = genes[movIndex];
	switch (index.column())
	{
	case 0:
		currentGene.setName(value.toString().toStdString());
		break;
	case 1:
		currentGene.setOrganismName(value.toString().toStdString());
		break;
	case 2:
		currentGene.setFunction(value.toString().toStdString());
	}
	this->repo.updateGene(movIndex, currentGene);

	// emit the dataChanged signal
	emit dataChanged(index, index);*/
	return true;
}

Qt::ItemFlags Model::flags(const QModelIndex & index) const
{
	return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

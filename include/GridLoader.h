#include <deal.II/grid/tria.h>

#include <iostream>

class GridLoader
{
private:
	dealii::Triangulation<3>* triangulation_pointer;
public:
	GridLoader(dealii::Triangulation<3>* triangulation);
	void loadGridFromFile(std::string filename);
};
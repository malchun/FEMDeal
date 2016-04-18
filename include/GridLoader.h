#include <deal.II/grid/tria.h>
#include <deal.II/grid/grid_in.h>

#include <iostream>

class GridLoader
{
private:
	dealii::Triangulation<3>* triangulation_pointer;
	std::map <std::string, dealii::GridIn<3>::Format> format_map;
public:
	GridLoader(dealii::Triangulation<3>* triangulation);
	void loadGridFromFile(std::string filename, std::string format);
	void loadGeneratedExampleCubeGrid();
};
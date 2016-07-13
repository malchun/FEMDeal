#include <deal.II/grid/tria.h>
#include <deal.II/grid/grid_in.h>
#include <deal.II/dofs/dof_handler.h>

#include "Problem.h"

class ProblemGenerator
{
public:
	ProblemGenerator(dealii::Triangulation<3>* triangulation);
	void loadGridFromFile(std::string filename, std::string format);
	void loadGeneratedExampleCubeGrid(dealii::DoFHandler<3>& dof_handler);

private:
	dealii::Triangulation<3>* triangulation_pointer;
	std::map <std::string, dealii::GridIn<3>::Format> format_map;
	void initialize_format_map();
};
#include "../include/GridLoader.h"
#include "../include/DataOutput.h"

#include <deal.II/grid/tria.h>
#include <deal.II/dofs/dof_handler.h>
#include <deal.II/fe/fe_system.h>
#include <deal.II/fe/fe_q.h>

#include <iostream>

int main() 
{
	std::cout << "I'm composite solver, lol" << std::endl;

	dealii::Triangulation<3> triangulation;
	dealii::DoFHandler<3> dof_handler(triangulation);
	dealii::FESystem<3> fe(dealii::FE_Q<3>(1), 3);

	GridLoader gl(&triangulation);
	gl.loadGeneratedExampleCubeGrid(dof_handler);
	dof_handler.distribute_dofs (fe);
	DataOutput dataout(&triangulation);
	dataout.saveResultVtu("aaalolaaa", dof_handler);
	dof_handler.clear();
	return 0;
}
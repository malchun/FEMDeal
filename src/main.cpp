#include "../include/GridLoader.h"

#include <deal.II/grid/tria.h>

#include <iostream>

int main() 
{
	std::cout << "I'm composite solver, lol" << std::endl;
	dealii::Triangulation<3> triangulation;
	GridLoader gl(&triangulation);
	gl.loadGridFromFile("input/cube.msh", "msh");
	return 0;	
}
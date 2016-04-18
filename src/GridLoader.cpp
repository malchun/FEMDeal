#pragma once
#include "../include/GridLoader.h"

#include <deal.II/grid/grid_generator.h>
#include <deal.II/grid/grid_refinement.h>
#include <deal.II/grid/tria_accessor.h>
#include <deal.II/grid/tria_iterator.h>
#include <deal.II/grid/manifold_lib.h>
#include <deal.II/grid/grid_tools.h>

void initialise_format_map(std::map <std::string, dealii::GridIn<3>::Format>* format_map)
{
	(*format_map)["msh"] = dealii::GridIn<3>::Format::msh;
	(*format_map)["vtk"] = dealii::GridIn<3>::Format::vtk;
	(*format_map)[""] = dealii::GridIn<3>::Format::Default;
	return;
}

// Constructor.
// @param dealii::Triangulation<3> triangulation - pointer on <3,3> triangulation
GridLoader::GridLoader(dealii::Triangulation<3>* triangulation)
{
	std::cout << "GridLoader::GridLoader(Triangulation<3>)" << std::endl;
	this->triangulation_pointer = triangulation;
	initialise_format_map(&format_map);
}

// Function loads grid from file if possible.
// Warning! deal.II doesn't work with triangual grids in any way!
// @param string filename - name of file with grid
// @param string format - format of grid. Possible variants are "msh" and "vtk" (could be extended)
void GridLoader::loadGridFromFile(std::string filename, std::string format)
{
	std::cout << "GridLoader::loadGridFromFile(\"" << filename << "\")" << std::endl;
	dealii::GridIn<3> grid_in;
	grid_in.attach_triangulation (*triangulation_pointer);
	grid_in.read(filename, format_map[format]);
	return;
}


// Example function of grid genration. Creates cube 10x10x10 with two materials
// TODO make function that tooks some class with predefined function "create_grid"
void GridLoader::loadGeneratedExampleCubeGrid()
{
	std::cout << "GridLoader::loadGeneratedExampleCubeGrid()" << std::endl;
	const dealii::Point<3> p1(5, 5, 5),
                           p2(-5, -5, -5);
                 
    std::vector<unsigned int> repetitions(3);
    repetitions[0] = 30;
    repetitions[1] = 30;
    repetitions[2] = 30;

    dealii::GridGenerator::subdivided_hyper_rectangle ((*triangulation_pointer), repetitions,
                                                       p1, p2, true);
    (*triangulation_pointer).set_all_manifold_ids(0);
    for (typename dealii::Triangulation<3>::active_cell_iterator
         cell=(*triangulation_pointer).begin_active();
         cell!=(*triangulation_pointer).end(); ++cell)
    {
	    cell->set_material_id(0);
    	for (unsigned int f=0; f<dealii::GeometryInfo<3>::faces_per_cell; ++f)
    	{
        	if (cell->face(f)->at_boundary())
          	{
           		const dealii::Point<3> face_center = cell->face(f)->center();

	            if (face_center[2] == -5)
    		        cell->face(f)->set_boundary_id (0);
            	else if (face_center[2] == 5)
              		cell->face(f)->set_boundary_id (1);
            	else
              		cell->face(f)->set_boundary_id (3);
          	}
        }
    }
    dealii::GridTools::partition_triangulation (1, (*triangulation_pointer));
	return;
}


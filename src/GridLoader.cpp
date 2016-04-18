#pragma once
#include "../include/GridLoader.h"

#include <fstream>

void initialise_format_map(std::map <std::string, dealii::GridIn<3>::Format>* format_map)
{
	(*format_map)["msh"] = dealii::GridIn<3>::Format::msh;
	(*format_map)["vtk"] = dealii::GridIn<3>::Format::vtk;
	(*format_map)[""] = dealii::GridIn<3>::Format::Default;
	return;
}

GridLoader::GridLoader(dealii::Triangulation<3>* triangulation)
{
	std::cout << "GridLoader::GridLoader(Triangulation<3>)" << std::endl;
	this->triangulation_pointer = triangulation;
	initialise_format_map(&format_map);
}

void GridLoader::loadGridFromFile(std::string filename, std::string format)
{
	std::cout << "GridLoader::loadGridFromFile(\"" << filename << "\")" << std::endl;
	dealii::GridIn<3> grid_in;
	grid_in.attach_triangulation (*triangulation_pointer);
	grid_in.read(filename, format_map[format]);
	return;
}


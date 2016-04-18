#pragma once
#include "../include/GridLoader.h"

GridLoader::GridLoader(dealii::Triangulation<3>* triangulation)
{
	std::cout << "GridLoader::GridLoader(Triangulation<3>)" << std::endl;
	this->triangulation_pointer = triangulation;
}

void GridLoader::loadGridFromFile(std::string filename)
{
	std::cout << "GridLoader::loadGridFromFile(\"" << filename << "\")" << std::endl;
	return;
}
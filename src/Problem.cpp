#include "../include/Problem.h"

template <int dim>
Problem<dim>::Problem()
{}

template <int dim>
Problem<dim>::~Problem() 
{
	dof_handler.clear();
}

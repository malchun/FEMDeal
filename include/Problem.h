#include <deal.II/grid/tria.h>
#include <deal.II/grid/grid_in.h>
#include <deal.II/dofs/dof_handler.h>
#include <deal.II/fe/fe_system.h>

template <int dim>
class Problem
{
public:
	Problem();
	~Problem();

private:
	dealii::Triangulation<dim> triangulation;
	dealii::DoFHandler<dim> dof_handler;
	dealii::FESystem<dim> fe;
};
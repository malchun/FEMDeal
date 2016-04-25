#include <deal.II/grid/tria.h>
#include <deal.II/dofs/dof_handler.h>

class DataOutput
{
public:
	DataOutput(dealii::Triangulation<3>* triangulation);
	void saveResultVtu(std::string output_filename, dealii::DoFHandler<3>& dof_handler);
private:
	dealii::Triangulation<3>* triangulation_pointer;
	std::string res_dir_prefix;
};
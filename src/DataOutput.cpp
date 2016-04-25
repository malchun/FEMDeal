#include "../include/DataOutput.h"

#include <deal.II/numerics/data_out.h>
#include <deal.II/grid/tria_accessor.h>
#include <deal.II/grid/tria_iterator.h>

#include <fstream>
#include <iostream>

DataOutput::DataOutput(dealii::Triangulation<3>* triangulation)
{
	std::cout << "DataOut::DataOutput(Triangulation<3>)" << std::endl;
	this->triangulation_pointer = triangulation;
	res_dir_prefix = "res/";
}

void DataOutput::saveResultVtu(std::string output_filename, dealii::DoFHandler<3>& dof_handler)
{
	std::cout << "DataOut::saveResultVtu(\"" << output_filename <<  "\")" << std::endl;
	dealii::DataOut<3> data_out;
    data_out.attach_dof_handler (dof_handler);

    dealii::Vector<double> materials((*triangulation_pointer).n_active_cells());
    {
      // Loop over all the cells...
      typename dealii::Triangulation<3>::active_cell_iterator
      cell = (*triangulation_pointer).begin_active(),
      endc = (*triangulation_pointer).end();
      for (unsigned int index=0; cell!=endc; ++cell, ++index) {
        materials(index) = (double) cell->material_id();
      }
    }

    data_out.add_data_vector (materials, "material");
    data_out.build_patches ();


    std::string filename = res_dir_prefix + output_filename + ".vtu";

    std::ofstream output (filename.c_str());
    data_out.write_vtu (output);
}
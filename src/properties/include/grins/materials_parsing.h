//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
//
// GRINS - General Reacting Incompressible Navier-Stokes
//
// Copyright (C) 2014-2017 Paul T. Bauman, Roy H. Stogner
// Copyright (C) 2010-2013 The PECOS Development Team
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the Version 2.1 GNU Lesser General
// Public License as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc. 51 Franklin Street, Fifth Floor,
// Boston, MA  02110-1301  USA
//
//-----------------------------------------------------------------------el-

#ifndef GRINS_MATERIALS_PARSING_H
#define GRINS_MATERIALS_PARSING_H

// C++
#include <string>

// libMesh
#include "libmesh/getpot.h"

namespace GRINS
{
  // Forward declarations
  class ParameterUser;

  //! Helper functions for parsing material properties
  /*! There's no state needed for these functions so we put them in
    a namespace instead of an object. */
  class MaterialsParsing
  {
  public:
    MaterialsParsing(){};
    ~MaterialsParsing(){};

    //! Get the name of the material in the Physics/physics section
    /*! Will error is the material key is not found in GetPot input. */
    static std::string material_name( const GetPot & input, const std::string & physics );

    //! Parse the viscosity model for the given Physics
    static void viscosity_model( const GetPot & input, const std::string & physics,
                                 std::string & model );

    //! Parse the conductivity model for the given material
    static void thermal_conductivity_model( const GetPot & input, const std::string & physics,
                                            std::string & model );

    //! Parse the specific heat model for the given material
    static void specific_heat_model( const GetPot & input, const std::string & physics,
                                     std::string & model );

    //! Parse the turbulence viscosity model for the given material
    static void turb_viscosity_model( const GetPot & input,
                                      const std::string & physics,
                                      std::string & model );

    //! Parse the stress-strain model for the given material
    static void stress_strain_model( const GetPot & input,
                                     const std::string & physics,
                                     std::string & model,
                                     std::string & strain_energy );

    static void thermochemistry_lib( const GetPot& input,
                                       const std::string& physics,
                                       std::string& model );

    static void antioch_models( const GetPot& input,
                                const std::string& physics,
                                std::string& transport_model,
                                std::string& thermo_model,
                                std::string& viscosity_model,
                                std::string& conductivity_model,
                                std::string& diffusivity_model );

    //! Helper function for parsin
    /*! This  assumes that the property value should
      be positive and will error out if it's not.*/
    static void read_property( const GetPot & input,
                               const std::string & property,
                               const std::string & core_physics,
                               ParameterUser& param_user,
                               libMesh::Real& value );

    //! Helper function for parsing/maintaing backward compatibility
    static void dep_input_warning( const std::string & old_option,
                                   const std::string & property );

    //! Helper function for parsing/maintaing backward compatibility
    static void duplicate_input_test( const GetPot & input,
                                      const std::string & option1,
                                      const std::string & option2 );

    //! Helper function to check for option and error out if it's not found.
    static void check_for_input_option( const GetPot & input, const std::string & option );

    //! Helper function for parsing the chemical species
    /*! The user-provided vector will populated with the chemical
      species names in the input file. "Physics/Chemistry/species" is
      deprecated in favor of "Material/"+material+"/GasMixture/species" */
    static void parse_chemical_species( const GetPot & input,
                                        const std::string & material,
                                        std::vector<std::string>& species_names );

    //! Helper function for parsing the chemical species and setting variable name
    /*! The user-provided vector will populated with the chemical
      species variable names based on the species name the input file. The variable
      name will used for adding the variable to the libMesh System.
      "Physics/Chemistry/species" is deprecated in favor of
      "Material/"+material+"/GasMixture/species" */
    static void parse_species_varnames( const GetPot & input,
                                        const std::string & material,
                                        const std::string & prefix,
                                        std::vector<std::string>& species_names );

    static libMesh::Real parse_lewis_number( const GetPot & input,
                                             const std::string & material );

    static std::string parse_chemical_kinetics_datafile_name( const GetPot & input,
                                                              const std::string & material );

  };

  inline
  std::string MaterialsParsing::material_name( const GetPot & input, const std::string & physics )
  {
    std::string option("Physics/"+physics+"/material");
    MaterialsParsing::check_for_input_option(input,option);

    return input(option, "DIE!");
  }

  inline
  void MaterialsParsing::check_for_input_option( const GetPot & input, const std::string & option )
  {
    if( !input.have_variable(option) )
      libmesh_error_msg("ERROR: Could not find required input parameter "+option+"!");
  }

} // end namespace GRINS

#endif // GRINS_MATERIALS_PARSING_H

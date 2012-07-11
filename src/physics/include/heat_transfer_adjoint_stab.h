//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
// 
// GRINS - General Reacting Incompressible Navier-Stokes 
//
// Copyright (C) 2010-2012 The PECOS Development Team
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the Version 2 GNU General
// Public License as published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this library; if not, write to the Free Software
// Foundation, Inc. 51 Franklin Street, Fifth Floor, Boston, MA
// 02110-1301 USA
//
//-----------------------------------------------------------------------el-
//
// $Id$
//
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
#ifndef HEAT_TRANSFER_ADJOINT_STAB_H
#define HEAT_TRANSFER_ADJOINT_STAB_H

//libMesh
#include "time_solver.h"

//GRINS
#include "heat_transfer_stab_base.h"

//! GRINS namespace
namespace GRINS
{
  //! Adds VMS-based stabilization to LowMachNavierStokes physics class
  class HeatTransferAdjointStabilization : public HeatTransferStabilizationBase
  {

  public:

    HeatTransferAdjointStabilization( const GRINS::PhysicsName& physics_name, const GetPot& input );
    virtual ~HeatTransferAdjointStabilization();

    //! Read options from GetPot input file. By default, nothing is read.
    virtual void read_input_options( const GetPot& input );

    virtual bool element_time_derivative( bool request_jacobian,
					  libMesh::DiffContext& context,
					  libMesh::FEMSystem* system );

    virtual bool side_time_derivative( bool request_jacobian,
				       libMesh::DiffContext& context,
				       libMesh::FEMSystem* system );

    virtual bool element_constraint( bool request_jacobian,
				     libMesh::DiffContext& context,
				     libMesh::FEMSystem* system );

    virtual bool side_constraint( bool request_jacobian,
				  libMesh::DiffContext& context,
				  libMesh::FEMSystem* system );

    virtual bool mass_residual( bool request_jacobian,
				libMesh::DiffContext& context,
				libMesh::FEMSystem* system );

  protected:

    
  private:
    HeatTransferAdjointStabilization();

  }; // End HeatTransferAdjointStabilization class declarations

} // End namespace GRINS

#endif //HEAT_TRANSFER_ADJOINT_STAB_H
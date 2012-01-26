//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
// 
// GRINS - General Reacting Incompressible Navier-Stokes 
//
// Copyright (C) 2010,2011 The PECOS Development Team
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
#ifndef VAR_TYPEDEFS_H
#define VAR_TYPEDEFS_H

#include <string>
#include <map>
#include "boost/tr1/memory.hpp"

namespace GRINS
{
  //! Forward declare Physics class since Physics uses some of these typedefs
  class Physics;

  //! More descriptive name of the type used for variable indices
  typedef unsigned int VariableIndex;

  //! More descriptive name of the type used for boundary ids
  typedef unsigned int BoundaryID;

  //! Container for GRINS::Physics object pointers
  typedef std::map< std::string,std::tr1::shared_ptr<GRINS::Physics> > PhysicsList;

  //! Iterator for PhysicsList
  typedef std::map< std::string,std::tr1::shared_ptr<GRINS::Physics> >::const_iterator PhysicsListIter;

}
#endif //VAR_TYPEDEFS_H

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

#ifndef GRINS_IDEAL_GAS_MIXTURE_H
#define GRINS_IDEAL_GAS_MIXTURE_H

// libMesh
#include "getpot.h"

// GRINS
#include "cached_values.h"
#include "chemical_mixture.h"

namespace GRINS
{
  template<typename Thermo, typename Transport, typename Kinetics>
  class IdealGasMixture
  {
  public:

    IdealGasMixture( const GetPot& input );
    ~IdealGasMixture();

    // Chemistry quantities
    Real R( unsigned int species ) const;

    Real R( const std::vector<Real>& mass_fractions ) const;

    Real M( unsigned int species ) const;

    Real M( const std::vector<Real>& mass_fractions ) const;

    Real X( unsigned int species, Real M, Real mass_fraction ) const;

    void X( Real M, const std::vector<Real>& mass_fractions, 
	    std::vector<Real>& mole_fractions ) const;


    // Thermodynamic quantities
    Real cp( const CachedValues& cache, unsigned int qp ) const;

    Real cv( const CachedValues& cache, unsigned int qp ) const;
     
    Real h(const CachedValues& cache, unsigned int qp, unsigned int species) const;

    void h(const CachedValues& cache, unsigned int qp, std::vector<Real>& h) const;


    // Transport quantities
    Real mu( const CachedValues& cache, unsigned int qp ) const;

    Real k( const CachedValues& cache, unsigned int qp ) const;

    void D( const CachedValues& cache, unsigned int qp,
	    std::vector<Real>& D ) const;


    // Kinetics quantites
    void omega_dot( const CachedValues& cache, unsigned int qp,
		    std::vector<Real>& omega_dot ) const;

  protected:
    
    std::vector<std::string> read_species_list( const GetPot& input );

    //! Stash data for the requested chemical mixture
    /*!
     * A reference will be cached in Thermo, Transport, and Kinetics objects as
     * needed. The intent is for this object to maintain ownership.
     */
    ChemicalMixture _chem_mixture;
    
    Thermo _thermo;
    
    Transport _transport;

    Kinetics _kinetics;

  };

  // Chemistry quantities
  template<typename Thermo, typename Transport, typename Kinetics>
  inline
  Real IdealGasMixture<Thermo,Transport,Kinetics>::R( unsigned int species ) const
  { return this->_chem_mixture.R(species); }

  template<typename Thermo, typename Transport, typename Kinetics>
  inline
  Real IdealGasMixture<Thermo,Transport,Kinetics>::R( const std::vector<Real>& mass_fractions ) const
  { return this->_chem_mixture.R(mass_fractions); }

  template<typename Thermo, typename Transport, typename Kinetics>
  inline
  Real IdealGasMixture<Thermo,Transport,Kinetics>::M( unsigned int species ) const
  { return this->_chem_mixture.M(species); }

  template<typename Thermo, typename Transport, typename Kinetics>
  inline
  Real IdealGasMixture<Thermo,Transport,Kinetics>::M( const std::vector<Real>& mass_fractions ) const
  { return this->_chem_mixture.M(mass_fractions); }

  template<typename Thermo, typename Transport, typename Kinetics>
  inline
  Real IdealGasMixture<Thermo,Transport,Kinetics>::X( unsigned int species, Real M,
						      Real mass_fraction ) const
  { return this->_chem_mixture.X(species,M,mass_fraction); }

  template<typename Thermo, typename Transport, typename Kinetics>
  inline
  void IdealGasMixture<Thermo,Transport,Kinetics>::X( Real M, const std::vector<Real>& mass_fractions, 
						      std::vector<Real>& mole_fractions ) const
  { return this->_chem_mixture.X(M,mass_fractions,mole_fractions); }


  // Thermodynamic quantities
  template<typename Thermo, typename Transport, typename Kinetics>
  inline
  Real IdealGasMixture<Thermo,Transport,Kinetics>::cp( const CachedValues& cache, 
						       unsigned int qp ) const
  { return this->_thermo.cp(cache,qp); }

  template<typename Thermo, typename Transport, typename Kinetics>
  inline
  Real IdealGasMixture<Thermo,Transport,Kinetics>::cv( const CachedValues& cache, 
						       unsigned int qp ) const
  { return this->_thermo.cv(cache,qp); }
    
  template<typename Thermo, typename Transport, typename Kinetics>
  inline
  Real IdealGasMixture<Thermo,Transport,Kinetics>::h(const CachedValues& cache, 
						     unsigned int qp,
						     unsigned int species) const
  { return this->_thermo.h(cache,qp,species); }

  template<typename Thermo, typename Transport, typename Kinetics>
  inline
  void IdealGasMixture<Thermo,Transport,Kinetics>::h(const CachedValues& cache, 
						     unsigned int qp,
						     std::vector<Real>& h) const
  { return this->_thermo.h(cache,qp,h); }


  // Transport quantities
  template<typename Thermo, typename Transport, typename Kinetics>
  inline
  Real IdealGasMixture<Thermo,Transport,Kinetics>::mu( const CachedValues& cache, 
						       unsigned int qp ) const
  { return this->_transport.mu(cache,qp); }

  template<typename Thermo, typename Transport, typename Kinetics>
  inline
  Real IdealGasMixture<Thermo,Transport,Kinetics>::k( const CachedValues& cache,
						      unsigned int qp ) const
  { return this->_transport.k(cache,qp); }

  template<typename Thermo, typename Transport, typename Kinetics>
  inline
  void IdealGasMixture<Thermo,Transport,Kinetics>::D( const CachedValues& cache,
						      unsigned int qp, 
						      std::vector<Real>& D ) const
  { return this->_transport.D(cache,qp,D); }


  // Kinetics quantites
  template<typename Thermo, typename Transport, typename Kinetics>
  inline
  void IdealGasMixture<Thermo,Transport,Kinetics>::omega_dot( const CachedValues& cache,
							      unsigned int qp,
							      std::vector<Real>& omega_dot ) const
  { return this->_kinetics.omega_dot(cache,qp,omega_dot); }

  
}

#endif //GRINS_IDEAL_GAS_MIXTURE_H

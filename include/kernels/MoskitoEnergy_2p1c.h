/**************************************************************************/
/*  MOSKITO - Multiphysics cOupled Simulator toolKIT for wellbOres        */
/*                                                                        */
/*  Copyright (C) 2017 by Maziar Gholami Korzani                          */
/*  Karlsruhe Institute of Technology, Institute of Applied Geosciences   */
/*  Division of Geothermal Research                                       */
/*                                                                        */
/*  This file is part of MOSKITO App                                      */
/*                                                                        */
/*  This program is free software: you can redistribute it and/or modify  */
/*  it under the terms of the GNU General Public License as published by  */
/*  the Free Software Foundation, either version 3 of the License, or     */
/*  (at your option) any later version.                                   */
/*                                                                        */
/*  This program is distributed in the hope that it will be useful,       */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          */
/*  GNU General Public License for more details.                          */
/*                                                                        */
/*  You should have received a copy of the GNU General Public License     */
/*  along with this program.  If not, see <http://www.gnu.org/licenses/>  */
/**************************************************************************/

#pragma once

#include "Kernel.h"

class MoskitoEnergy_2p1c;

template <>
InputParameters validParams<MoskitoEnergy_2p1c>();

class MoskitoEnergy_2p1c : public Kernel
{
public:
  MoskitoEnergy_2p1c(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
  virtual Real computeQpOffDiagJacobian(unsigned jvar) override;

  // The coupled massrate
  const VariableValue & _m;
  const VariableGradient & _grad_m;
  unsigned _m_var_number;

  // The coupled pressure
  const VariableGradient & _grad_p;
  unsigned _p_var_number;

  // The area of pipe
  const MaterialProperty<Real> & _area;
  // The unit vector of well direction
  const MaterialProperty<RealVectorValue> & _well_dir;
  // The sign of well flow direction
  const MaterialProperty<Real> & _well_sign;
  // The thermal conductivity of casing and fluid
  const MaterialProperty<Real> & _lambda;
  // The specific heat at constant pressure
  const MaterialProperty<Real> & _cp;
  // The density
  const MaterialProperty<Real> & _rho;
  // The first derivative of density wrt pressure
  const MaterialProperty<Real> & _drho_dp;
  // The first derivative of density wrt enthalpy
  const MaterialProperty<Real> & _drho_dh;
  // The second derivative of density wrt pressure
  const MaterialProperty<Real> & _drho_dp2;
  // The second derivative of density wrt enthalpy
  const MaterialProperty<Real> & _drho_dh2;
  // The second derivative of density wrt enthalpy and pressure
  const MaterialProperty<Real> & _drho_dph;

  // The gravity acceleration as a vector
  const MaterialProperty<RealVectorValue> & _gravity;

  // // The kappa first derivatives
  // const MaterialProperty<Real> & _dkappa_dp;
  // // The kappa first derivatives
  // const MaterialProperty<Real> & _dkappa_dh;
  // // The kappa first derivatives
  // const MaterialProperty<Real> & _dkappa_dq;
  // // The kappa second derivatives
  // const MaterialProperty<Real> & _dkappa_dph;
  // // The kappa second derivatives
  // const MaterialProperty<Real> & _dkappa_dpq;
  // // The kappa second derivatives
  // const MaterialProperty<Real> & _dkappa_dhq;
  // // The kappa second derivatives
  // const MaterialProperty<Real> & _dkappa_dp2;
  // // The kappa second derivatives
  // const MaterialProperty<Real> & _dkappa_dh2;
  // // The kappa second derivatives
  // const MaterialProperty<Real> & _dkappa_dq2;
  //
  // // The omega first derivatives
  // const MaterialProperty<Real> & _domega_dp;
  // // The omega first derivatives
  // const MaterialProperty<Real> & _domega_dh;
  // // The omega first derivatives
  // const MaterialProperty<Real> & _domega_dq;
  // // The omega second derivatives
  // const MaterialProperty<Real> & _domega_dph;
  // // The omega second derivatives
  // const MaterialProperty<Real> & _domega_dpq;
  // // The omega second derivatives
  // const MaterialProperty<Real> & _domega_dhq;
  // // The omega second derivatives
  // const MaterialProperty<Real> & _domega_dp2;
  // // The omega second derivatives
  // const MaterialProperty<Real> & _domega_dh2;
  // // The omega second derivatives
  // const MaterialProperty<Real> & _domega_dq2;
};

//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: G4IrregularXTRdEdx.hh,v 1.1 2004/11/09 09:20:32 hpw Exp $
// GEANT4 tag $Name: geant4-07-01 $
//
// 
///////////////////////////////////////////////////////////////////////////
// 
// Very rough model describing a radiator of X-ray transition radiation.  
// Thicknesses of plates and gas gaps are exponentially distributed.
// We suppose that:
// formation zone << mean thickness << absorption length
// for each material and in the range 1-100 keV. This allows us to simplify
// essentially interference effects in radiator stack (GetStackFactor method).
// The price is decreasing of X-ray TR photon yield. 
// 
// History:
// 27.02.01 V. Grichine first version 
//


#ifndef G4IrregularXTRdEdx_h
#define G4IrregularXTRdEdx_h 1

#include "G4VXTRdEdx.hh"
#include "G4VFastSimulationModel.hh"

class G4IrregularXTRdEdx : public G4VXTRdEdx
{
public:

   G4IrregularXTRdEdx (G4LogicalVolume *anEnvelope,G4double,G4double);
  ~G4IrregularXTRdEdx();

  // Pure virtual function from base class

  //  void DoIt(const G4FastTrack&, G4FastStep&);
  G4double GetStackFactor( G4double energy, G4double gamma, G4double varAngle);
};

#endif
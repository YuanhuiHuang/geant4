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
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4VParticlePropertyReporter.hh,v 1.1 2003/09/21 19:38:50 kurasige Exp $
// GEANT4 tag $Name: geant4-06-00-patch-01 $
//
// 
// ---------------------------------------------------------------
#ifndef G4VParticlePropertyReporter_h
#define G4VParticlePropertyReporter_h 1

#include "globals.hh"
#include "G4ios.hh"
#include <vector>

#include "G4ParticlePropertyData.hh"
#include "G4ParticlePropertyTable.hh"

class G4VParticlePropertyReporter
{
 public:
  //constructors
  G4VParticlePropertyReporter();
  
  //destructor
  virtual ~G4VParticlePropertyReporter();
  
 public:
  // equality operators
  G4int operator==(const G4VParticlePropertyReporter &right) const 
  {   return (this == &right);    }
  
  G4int operator!=(const G4VParticlePropertyReporter &right) const 
  {   return (this != &right);    }
  
 public:
  typedef std::vector<G4ParticlePropertyData*> G4PPDContainer;

 public:
  virtual G4bool FillList(G4String name); 
  // fill out properties for specified particle type/name  
  // (return false if specified name/type does not exist) 

  virtual void Clear();
  // clear the list 

  virtual void Print(const G4String& option) = 0;
  // print out particle properties in the list

  const G4PPDContainer&     GetList() const {return pList;}
  
 protected:
  G4PPDContainer            pList;
  G4ParticlePropertyTable*  pPropertyTable;

};

#endif

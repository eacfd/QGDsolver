/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2016 OpenFOAM Foundation
    Copyright (C) 2019 OpenCFD Ltd.
    Copyright (C) 2016-2019 ISP RAS (www.ispras.ru) UniCFD Group (www.unicfd.ru)
-------------------------------------------------------------------------------
License
    This file is part of QGDsolver library, based on OpenFOAM+.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Group
    grpCheQGDModels

Description
    Creates chemistry model instances templated on the type of thermodynamics
    for QGD thermo

\*---------------------------------------------------------------------------*/

#include "makeChemistryReductionMethods.H"
#include "thermoPhysicsTypes.H"
#include "psiQGDReactionThermo.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    // Chemistry solvers based on sensibleEnthalpy
    makeChemistryReductionMethods(psiQGDReactionThermo, constGasHThermoPhysics);
    makeChemistryReductionMethods(psiQGDReactionThermo, gasHThermoPhysics);
    makeChemistryReductionMethods
    (
        psiQGDReactionThermo,
        constIncompressibleGasHThermoPhysics
    );
    makeChemistryReductionMethods
    (
        psiQGDReactionThermo,
        incompressibleGasHThermoPhysics
    );
    makeChemistryReductionMethods(psiQGDReactionThermo, icoPoly8HThermoPhysics);
    makeChemistryReductionMethods(psiQGDReactionThermo, constFluidHThermoPhysics);
    makeChemistryReductionMethods
    (
        psiQGDReactionThermo,
        constAdiabaticFluidHThermoPhysics
    );
    makeChemistryReductionMethods(psiQGDReactionThermo, constHThermoPhysics);


    // Chemistry solvers based on sensibleInternalEnergy
    makeChemistryReductionMethods(psiQGDReactionThermo, constGasEThermoPhysics);
    makeChemistryReductionMethods(psiQGDReactionThermo, gasEThermoPhysics);
    makeChemistryReductionMethods
    (
        psiQGDReactionThermo,
        constIncompressibleGasEThermoPhysics
    );
    makeChemistryReductionMethods
    (
        psiQGDReactionThermo,
        incompressibleGasEThermoPhysics
    );
    makeChemistryReductionMethods(psiQGDReactionThermo, icoPoly8EThermoPhysics);
    makeChemistryReductionMethods(psiQGDReactionThermo, constFluidEThermoPhysics);
    makeChemistryReductionMethods
    (
        psiQGDReactionThermo,
        constAdiabaticFluidEThermoPhysics
    );
    makeChemistryReductionMethods(psiQGDReactionThermo, constEThermoPhysics);

}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

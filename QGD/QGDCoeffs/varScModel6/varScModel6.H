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

Class
    Foam::qgd::varScModel6

Group
    grpQGDCoeffs

Description
    Class describing QGD model coefficients using dynamic values for
    Sc^{QGD}, Pr^{QGD} and specified \alpha field:

    Sc^{QGD} = min(\h^QGD abs(\nabla \rho)/\rho, 1)

    \tau^{QGD} = \alpha h / c + \mu / (p Sc)

    \mu^{QGD} = (\alpha h / c) p Sc^{QGD}

    \lambda^{QGD} = \mu^{QGD} Cp / Pr^{QGD}

SourceFiles
    varScModel6.C

\*---------------------------------------------------------------------------*/
#include "QGDCoeffs.H"

#ifndef varScModel6_H
#define varScModel6_H

namespace Foam
{

class cellSet;

namespace qgd
{

class varScModel6 : public QGDCoeffs
{

protected:

    scalar smoothCoeff_;
    scalar rC_;
    scalar minSc_;
    scalar maxSc_;
    scalar badQualitySc_;
    scalar qgdAspectRatioThreshold_;
    scalar constSc_;

    scalarField cqSc_;

    autoPtr<cellSet> constScCellSetPtr_;


public:

    //-
    TypeName ("varScModel6");

    //-
    varScModel6
    (
        const IOobject& io,
        const fvMesh& mesh,
        const dictionary& dict
    );

    //-
    ~varScModel6();

    //-
    void correct(const QGDThermo&);

};


}//namespace qgd

}//namespace Foam

#endif

//
//END-OF-FILe
//

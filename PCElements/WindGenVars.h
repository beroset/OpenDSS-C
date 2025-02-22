#ifndef WindGenVarsH
#define WindGenVarsH

#include "System.h"

#include "Ucomplex.h"

namespace WindGenVars
{



/*
  ----------------------------------------------------------
  Copyright (c) 2008-2022, Electric Power Research Institute, Inc.
  All rights reserved.
  ----------------------------------------------------------

  Definition of WindGen Public Data Record for passing to DLLs and other object
*/

   /*WindGen public data/state variable structure*/
#pragma pack (push, 1)

struct TWindGenVars;
typedef TWindGenVars* pTWindGenVars;

struct TWindGenVars
{
      /*Direct-Axis voltage magnitude & angle*/         /*present Shaft Power and relative Speed, rad/sec, difference from Synchronous speed, w0*/
                    /*actual speed = Speed + w0*/      /*Per unit mass constant*/      /*Mass constant actual values (Joule-sec/rad*/     /*Actual and per unit damping factors*/   /*machine Reactances, ohms*/   /*machine Reactances, per unit*/     /*Derivatives of Theta and Speed*/   /*history variables for integration*/  /*Target P and Q for power flow solution, watts, vars*/
	double Theta;
	double Pshaft;
	double Speed;
	double w0;
	double Hmass;
	double Mmass;
	double D;
	double Dpu;
	double kVArating;
	double kVWindGenBase;
	double XD;
	double Xdp;
	double Xdpp;
	double puXd;
	double puXdp;
	double puXdpp;
	double dTheta;
	double dSpeed;
	double ThetaHistory;
	double SpeedHistory;
	double Pnominalperphase;
	double Qnominalperphase;    /* All Doubles */

        /*32-bit integers*/       /*Number of phases*/   /*Total Number of conductors (wye-connected will have 4)*/
	int NumPhases;
	int NumConductors;
	int Conn;   // 0 = wye; 1 = Delta
	
        /* Revisons (additions) to structure ...
          Later additions are appended to end of the structure so that
          previously compiled DLLs do not break
          */
	double VthevMag;    /*Thevinen equivalent voltage for dynamic model*/
	double VThevHarm;    /*Thevinen equivalent voltage mag reference for Harmonic model*/
	double ThetaHarm;    /*Thevinen equivalent voltage angle reference for Harmonic model*/
	double VTarget;   // Target voltage for WindGen with voltage control
	Ucomplex::complex Zthev;
	double XRdp;  // Assumed X/R for Xd'
};
#pragma pack (pop)



}  // namespace WindGenVars

#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE)
using namespace WindGenVars;
#endif

#endif // WindGenVarsH





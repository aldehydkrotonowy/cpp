/* yrvlc.h                       freeware                 xhunga@tiscali.fr  */


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    : Rand Linear Combinaison of Two Vector in Rn  with integer coeff.   */
/*                                                                            */
/* see   :   vectag.zip   lnear2PI.c  lnear2VI.c                              */
/* -------------------------------------------------------------------------- */
void rnd_LC_2v_Rn_I(
PmF mA)
{
fraction s;
     int n;

double pbc  [MXR][MXC*C2];mF mc    ={MXR,MXC*C2,&pbc   [0][0]};
double pbsc1[MXR][MXC*C2];mF msc1  ={MXR,MXC*C2,&pbsc1 [0][0]};
double pbsc2[MXR][MXC*C2];mF msc2  ={MXR,MXC*C2,&pbsc2 [0][0]};
double pbc3 [MXR][MXC*C2];mF mc3   ={MXR,MXC*C2,&pbc3  [0][0]};

           n = mA->rows;

     mc.rows=n;      mc.cols= C2;
   msc1.rows=n;    msc1.cols= C2;
   msc2.rows=n;    msc2.cols= C2;
    mc3.rows=n;     mc3.cols= C2;
/*-------------------------------- PROGRAM ---------------------------------- */
   zero_mF(mA);

   rnd_mI(&mc,6);copy_cF(&mc,0,mA,0);s = rnd_FI(9);Fmul_mF(s,&mc,&msc1);
   rnd_mI(&mc,6);copy_cF(&mc,0,mA,1);s = rnd_FI(9);Fmul_mF(s,&mc,&msc2);

   add_mF(&msc1,&msc2,&mc3);
   copy_cF(&mc3, 0, mA,((mA->cols)/2)-1);
}


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    : Rand Linear Combinaison of Two Vector in Rn  with integer coeff.   */
/*                                                                            */
/* see   :   vectag.zip   lnear3PI.c  lnear3VI.c                              */
/* -------------------------------------------------------------------------- */
void rnd_LC_3v_Rn_I(
PmF mA)
{
fraction s;
     int n;

double pbc  [MXR][MXC*C2];mF mc    ={MXR,MXC*C2,&pbc   [0][0]};
double pbsc1[MXR][MXC*C2];mF msc1  ={MXR,MXC*C2,&pbsc1 [0][0]};
double pbsc2[MXR][MXC*C2];mF msc2  ={MXR,MXC*C2,&pbsc2 [0][0]};
double pbsc3[MXR][MXC*C2];mF msc3  ={MXR,MXC*C2,&pbsc3 [0][0]};
double pbc4 [MXR][MXC*C2];mF mc4   ={MXR,MXC*C2,&pbc4  [0][0]};

           n = mA->rows;

     mc.rows=n;      mc.cols= C2;
   msc1.rows=n;    msc1.cols= C2;
   msc2.rows=n;    msc2.cols= C2;
   msc3.rows=n;    msc3.cols= C2;
    mc4.rows=n;     mc4.cols= C2;
/*-------------------------------- PROGRAM ---------------------------------- */
   zero_mF(mA);

   rnd_mI(&mc,6);copy_cF(&mc,0,mA,0);s = rnd_FI(9);Fmul_mF(s,&mc,&msc1);
   rnd_mI(&mc,6);copy_cF(&mc,0,mA,1);s = rnd_FI(9);Fmul_mF(s,&mc,&msc2);
   rnd_mI(&mc,6);copy_cF(&mc,0,mA,2);s = rnd_FI(9);Fmul_mF(s,&mc,&msc3);

   add_mF(&msc1,&msc2,&mc);
   add_mF(&mc,  &msc3,&mc4);

   copy_cF(&mc4,0,mA,((mA->cols)/2)-1);
}



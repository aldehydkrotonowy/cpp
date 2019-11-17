/* yd_dot.h                     freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectab.zip vectak.zip vectal.zip vectan.zip                      */
/* -------------------------------------------------------------------------- */
fraction innerprod_F(
PmF mu,
PmF mv
)
{
fraction InnerProduct;

  if (mu->rows == 1                 &&
      mu->cols == mv->rows * C2 &&
      mv->cols == C2
     )
     {
      InnerProduct = innerprod_uDotv_uv(mu,mv);
     }
    else if
     (mu->rows == 1        &&
      mv->rows == 1        &&
      mu->cols == mv->cols
     )
     {
      InnerProduct = innerprod_uDotv_uvT(mu,mv);
     }
    else if
     (mu->rows == mv->rows &&
      mu->cols == mv->cols &&
      mu->cols == C2
     )
     {
      InnerProduct = innerprod_uDotv_vTu(mu,mv);
     }
    else if
     (mu->rows * C2 == mv->cols &&
      mu->cols          == C2   &&
      mv->rows          == 1
     )
     {
      InnerProduct = innerprod_uDotv_vu(mu,mv);
     }
     else
     {
      printf(" innerprod_F() error.\n\n");

      printf("\nPress Return to continue\n");
      getchar();
      exit(1);
     }


  return(InnerProduct);
}



/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectab.zip vectal.zip                                            */
/* -------------------------------------------------------------------------- */
fraction normP2_F(
PmF mu
)
{
fraction NormP2;

         NormP2 = innerprod_F(mu,mu);

  return(NormP2);
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectab.zip                                                       */
/* -------------------------------------------------------------------------- */
fraction distanceP2_F(
PmF mu,
PmF mv
)
{
fraction DistanceP2;

double pu_mns_v [MXR][MXC*C2];
mF mu_mns_v={MXR, MXC*C2,&pu_mns_v[0][0]};

       mu_mns_v.rows = mu->rows;
       mu_mns_v.cols = mu->cols;

      sub_mF(mu,mv,&mu_mns_v);

  DistanceP2 = normP2_F(&mu_mns_v);

  return(DistanceP2);
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectak.zip                                                       */
/* -------------------------------------------------------------------------- */
void projwn_mF(
PmF mu,
PmF mv,
PmF mvn
)
{
fraction InnerProduv;
fraction     NormvP2;
fraction   InvNormP2;
fraction InnerProduv_InvNormP2;
/*-------------------------------- PROGRAM ---------------------------------- */
             InnerProduv = innerprod_F(mu,mv);
                 NormvP2 =    normP2_F(   mv);
               InvNormP2 =      inv_F(NormvP2);

   InnerProduv_InvNormP2 =  mul_F(InnerProduv,InvNormP2);

        Fmul_mF(InnerProduv_InvNormP2,mv,mvn);
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectak.zip                                                       */
/* -------------------------------------------------------------------------- */
void p_mX(
PmF mX,
char c
)
{
fraction f;
int i;
int j;

double pbvT[MXR][MXC*C2];mF mvT ={MXR,MXC*C2,&pbvT[0][0]};
double pvnT[MXR][MXC*C2];mF mvnT={MXR,MXC*C2,&pvnT[0][0]};

   mvT.rows = 1;          mvT.cols = mX->cols;
  mvnT.rows = 1;         mvnT.cols = mX->cols;

for(i = 0; i < ((mX->cols/2) - 1) ; i++)
   {
   for(j = 1; j < (mX->cols/2) ; j++)
     {
      copy_rF(mX,i,&mvT, 0);
      copy_rF(mX,j,&mvnT,0);

      f = innerprod_F(&mvT,&mvnT);
      if(!(i==j || i>j))
        {
         printf("  %c%d.%c%d = %4.0f/%.0f;",
                   c,i+1,c,j+1,f.n,f.d);
        }
     }
   printf("\n");
   }
}



/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectal.zip                                                       */
/* -------------------------------------------------------------------------- */
void leastsqrs_mF(
PmF mA,
PmF mb,
PmF mx
)
{
int  n = mA->rows;

double pbAx    [MXR][MXC*C2];mF mAx     ={MXR,MXC*C2,&pbAx    [0][0]};
double pTrpsA  [MXR][MXC*C2];mF mTrpsA  ={MXR,MXC*C2,&pTrpsA  [0][0]};
double pTrpsA_A[MXR][MXC*C2];mF mTrpsA_A={MXR,MXC*C2,&pTrpsA_A[0][0]};
double pTrpsA_b[MXR][MXC*C2];mF mTrpsA_b={MXR,MXC*C2,&pTrpsA_b[0][0]};

double pAssNorSys[MXR][MXC*C2];
mF mAssNorSys ={MXR,MXC*C2,&pAssNorSys [0][0]};

                    mAx.rows= n;            mAx.cols=      C2;
                 mTrpsA.rows=(n-1);      mTrpsA.cols= n   *C2;
               mTrpsA_A.rows=(n-1);    mTrpsA_A.cols=(n-1)*C2;
               mTrpsA_b.rows=(n-1);    mTrpsA_b.cols=      C2;
             mAssNorSys.rows=(n-1);  mAssNorSys.cols= n   *C2;
/*-------------------------------- PROGRAM ---------------------------------- */
  transpose_mF( mA,&mTrpsA);
       mul_mF(&mTrpsA,mA,&mTrpsA_A);
       mul_mF(&mTrpsA,mb,&mTrpsA_b);
       copy_mF(&mTrpsA_A,&mAssNorSys);
     copy_cF(&mTrpsA_b,0,&mAssNorSys,n-1);
 gaussjordan_mF(&mAssNorSys);
     copy_cF(&mAssNorSys,n-1,mx,0);
}



/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectal.zip                                                       */
/* -------------------------------------------------------------------------- */
void orthprojwb_mF(
PmF mA,
PmF mb,
PmF mprojwb
)
{
int  n = mA->rows;

double pbx[MXR][MXC*C2];mF mx = {MXR,MXC*C2,&pbx[0][0]};

            mx.rows=(n-1);          mx.cols= C2;
/*-------------------------------- PROGRAM ---------------------------------- */
       leastsqrs_mF(mA, mb,&mx);
          mul_mF(mA,&mx, mprojwb);
}

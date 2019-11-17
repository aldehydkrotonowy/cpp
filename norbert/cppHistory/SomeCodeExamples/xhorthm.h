/* yrvlc.h                       freeware                  xhunga@tiscali.fr  */


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* see   :   vectal.zip   orthmAR.c orthmBR.c corthmCR.c corthmER.c           */
/* -------------------------------------------------------------------------- */
void rnd_orth_mF(
PmF mA,
int maxN,
int maxD
)
{
     int          n;
fraction       Norm;
fraction    InvNorm;
fraction Two ={2,1};


double pbID    [MXR][MXC*C2];mF mID     ={MXR,MXC*C2,&pbID    [0][0]};
double pbx     [MXR][MXC*C2];mF mx      ={MXR,MXC*C2,&pbx     [0][0]};
double pTrpsx  [MXR][MXC*C2];mF mTrpsx  ={MXR,MXC*C2,&pTrpsx  [0][0]};
double px_Trpsx[MXR][MXC*C2];mF mx_Trpsx={MXR,MXC*C2,&px_Trpsx[0][0]};

double pInvNorm_mx_Trpsx [MXR][MXC*C2];
mF mInvNorm_mx_Trpsx={MXR, MXC*C2,&pInvNorm_mx_Trpsx[0][0]};

                                   n = mA->rows;
                    mID.rows= n;                    mID.cols= n*C2;
                     mx.rows= n;                     mx.cols=   C2;
                 mTrpsx.rows= 1;                 mTrpsx.cols= n*C2;
               mx_Trpsx.rows= n;               mx_Trpsx.cols= n*C2;
      mInvNorm_mx_Trpsx.rows= n;      mInvNorm_mx_Trpsx.cols= n*C2;
/*-------------------------------- PROGRAM ---------------------------------- */
  rnd_mF(&mx,maxN,maxD);
    id_mF(&mID);

     Norm = normP2_F(&mx);
  InvNorm = mul_F(Two,inv_F(Norm));

  transpose_mF(&mx,&mTrpsx);
       mul_mF(&mx,&mTrpsx,&mx_Trpsx);

  Fmul_mF(InvNorm,&mx_Trpsx,&mInvNorm_mx_Trpsx);
    sub_mF(&mID,             &mInvNorm_mx_Trpsx, mA);
    swapcol_mF( mA,((mA->cols/2)-1),1);
    swaprow_mF( mA,( mA->rows   -1),0);
}


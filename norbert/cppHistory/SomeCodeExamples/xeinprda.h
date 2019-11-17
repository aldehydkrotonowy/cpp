/* yd_dot.h                     freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :  vectai.zip vectan.zip vectak.zip                                  */
/* -------------------------------------------------------------------------- */
fraction innerprod_A_F(
PmF mA,
PmF mU,
PmF mV
)
{
fraction InnerProduct;

double pTrposA [MXR][MXC*C2];mF mTrposA ={MXR,MXC*C2,&pTrposA [0][0]};
double pTrposAA[MXR][MXC*C2];mF mTrposAA={MXR,MXC*C2,&pTrposAA[0][0]};
double pTrposV [MXR][MXC*C2];mF mTrposV ={MXR,MXC*C2,&pTrposV [0][0]};

double pTrposV_TrposAA[MXR][MXC*C2];
mF mTrposV_TrposAA ={MXR,MXC*C2,&pTrposV_TrposAA[0][0]};

double pTrposV_TrposAA__U[MXR][MXC*C2];
mF mTrposV_TrposAA__U ={MXR,MXC*C2,&pTrposV_TrposAA__U[0][0]};

             mTrposA.rows =   mA->rows;               mTrposA.cols = mA->cols;
            mTrposAA.rows =   mA->rows;              mTrposAA.cols = mA->cols;
             mTrposV.rows =   mV->cols/2;             mTrposV.cols = mV->rows*C2;
     mTrposV_TrposAA.rows =   mV->cols/2;     mTrposV_TrposAA.cols = mA->cols;
  mTrposV_TrposAA__U.rows =   mV->cols/2;  mTrposV_TrposAA__U.cols = mU->cols;


            transpose_mF(mA,&mTrposA);
                 mul_mF(   &mTrposA,mA,&mTrposAA);

            transpose_mF(mV,&mTrposV);
                 mul_mF(   &mTrposV,&mTrposAA,&mTrposV_TrposAA);

                 mul_mF(&mTrposV_TrposAA,mU,&mTrposV_TrposAA__U);

       InnerProduct.n = *(mTrposV_TrposAA__U.pb+0 \
                             *mTrposV_TrposAA__U.cols+0*C2  );

       InnerProduct.d = *(mTrposV_TrposAA__U.pb+0 \
                             *mTrposV_TrposAA__U.cols+0*C2+1);

 return(InnerProduct);
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :  vectai.zip v                                                      */
/* -------------------------------------------------------------------------- */
fraction normP2_A_F(
PmF mA,
PmF mu
)
{
fraction NormP2;

         NormP2 = innerprod_A_F(mA,mu,mu);

  return(NormP2);
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :  vectai.zip v                                                      */
/* -------------------------------------------------------------------------- */
fraction distanceP2_A_F(
PmF mA,
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

  DistanceP2 = normP2_A_F(mA,&mu_mns_v);

  return(DistanceP2);
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :  vectak.zip v                                                      */
/* -------------------------------------------------------------------------- */
void projwn_A(
PmF mA,
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
             InnerProduv = innerprod_A_F(mA,mu,mv);
                 NormvP2 =    normP2_A_F(mA,mv);
               InvNormP2 =      inv_F(NormvP2);

   InnerProduv_InvNormP2 =  mul_F(InnerProduv,InvNormP2);

        Fmul_mF(InnerProduv_InvNormP2,mv,mvn);
}

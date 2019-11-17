/* yd_dot.h                     freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
fraction innerprod_W_F(
PmF mA,
PmF mU,
PmF mV
)
{
fraction InnerProduct;

double pTrposV [MXR][MXC*C2];mF mTrposV ={MXR,MXC*C2,&pTrposV [0][0]};

double pTrposV_A[MXR][MXC*C2];
mF mTrposV_A ={MXR,MXC*C2,&pTrposV_A[0][0]};

double pTrposV_A__U[MXR][MXC*C2];
mF mTrposV_A__U ={MXR,MXC*C2,&pTrposV_A__U[0][0]};

             mTrposV.rows =  mV->cols/2;        mTrposV.cols = mV->rows*C2;
           mTrposV_A.rows =  mV->cols/2;      mTrposV_A.cols = mA->cols;
        mTrposV_A__U.rows =  mV->cols/2;   mTrposV_A__U.cols = mU->cols;


            transpose_mF(mV,&mTrposV);
                 mul_mF(   &mTrposV,mA,&mTrposV_A);

                 mul_mF(&mTrposV_A,mU,&mTrposV_A__U);

       InnerProduct.n = *(mTrposV_A__U.pb+0 \
                             *mTrposV_A__U.cols+0*C2  );

       InnerProduct.d = *(mTrposV_A__U.pb+0 \
                             *mTrposV_A__U.cols+0*C2+1);

 return(InnerProduct);
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
fraction normP2_W_F(
PmF mA,
PmF mu
)
{
fraction NormP2;

         NormP2 = innerprod_W_F(mA,mu,mu);

  return(NormP2);
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
fraction distanceP2_W_F(
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

  DistanceP2 = normP2_W_F(mA,&mu_mns_v);

  return(DistanceP2);
}




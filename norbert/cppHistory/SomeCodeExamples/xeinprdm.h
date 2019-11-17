/* yd_dot.h                     freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectah.zip   vectak.zip     vectan.zip                           */
/* -------------------------------------------------------------------------- */
fraction innerprod_Mnm_F(
PmF mU,
PmF mV
)
{
fraction InnerProduct;

double pTrposU   [MXR][MXC*C2];mF mTrposU   ={MXR,MXC*C2,&pTrposU   [0][0]};
double pTrposU_V [MXR][MXC*C2];mF mTrposU_V ={MXR,MXC*C2,&pTrposU_V [0][0]};

             mTrposU.rows =   mU->cols/2;       mTrposU.cols = mU->rows*C2;
           mTrposU_V.rows = mTrposU.rows;     mTrposU_V.cols = mV->cols;

            transpose_mF(mU,&mTrposU);
                 mul_mF(   &mTrposU,mV,&mTrposU_V);
  InnerProduct= trace_mF(               &mTrposU_V);

 return(InnerProduct);
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectah.zip                                                       */
/* -------------------------------------------------------------------------- */
fraction normP2_Mnm_F(
PmF mu
)
{
fraction NormP2;

         NormP2 = innerprod_Mnm_F(mu,mu);

  return(NormP2);
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectah.zip                                                       */
/* -------------------------------------------------------------------------- */
fraction distanceP2_Mnm_F(
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

  DistanceP2 = normP2_Mnm_F(&mu_mns_v);

  return(DistanceP2);
}



/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectak.zip                                                       */
/* -------------------------------------------------------------------------- */
void projwn_Mnm(
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
             InnerProduv = innerprod_Mnm_F(mu,mv);

                 NormvP2 =    normP2_Mnm_F(   mv);
               InvNormP2 =      inv_F(NormvP2);
   InnerProduv_InvNormP2 =  mul_F(InnerProduv,InvNormP2);

        Fmul_mF(InnerProduv_InvNormP2,mv,mvn);
}

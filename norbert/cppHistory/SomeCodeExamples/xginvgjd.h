/* xginvgjd.h                    freeware                  xhunga@tiscali.fr  */

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void inv_gjd_mF(
PmF mA,
PmF minv)
{
double pAID [MXR][MXC*2*C2];mF mAID ={MXR,MXC*2*C2,&pAID [0][0]};

                  mAID.rows=mA->rows;         mAID.cols=2*mA->rows*C2;

     createAid_mF(mA,&mAID);
   gaussjordan_mF(   &mAID);
       copyinv_mF(   &mAID,minv);
}



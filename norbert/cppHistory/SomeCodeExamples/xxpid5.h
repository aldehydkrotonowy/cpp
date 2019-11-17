/* xxpid5.h                     freeware                   xhunga@tiscali.fr  */

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :  inv_xhunga_mF()                                                      */
/* -------------------------------------------------------------------------- */
void idF5(
PmF m)
{
     int row1;
     int row2;
     int i;
     int n;
fraction f;

double pbID [MXR][MXC*C2];mF mID  ={MXR,MXC*C2,&pbID [0][0]};
double pIDT1[MXR][MXC*C2];mF mIDT1={MXR,MXC*C2,&pIDT1[0][0]};
double pIDT2[MXR][MXC*C2];mF mIDT2={MXR,MXC*C2,&pIDT2[0][0]};
double pbT  [MXR][MXC*C2];mF mT   ={MXR,MXC*C2,&pbT  [0][0]};
double pbT2 [MXR][MXC*C2];mF mT2  ={MXR,MXC*C2,&pbT2 [0][0]};

 n = m->rows;
                   mID.rows=n;                 mID.cols=n*C2;
                 mIDT1.rows=n;               mIDT1.cols=n*C2;
                 mIDT2.rows=n;               mIDT2.cols=n*C2;
                    mT.rows=n;                  mT.cols=n*C2;
                   mT2.rows=n;                 mT2.cols=n*C2;
 copy_mF(m,&mT2);
    id_mF(&mID);
/*--------------------------------------------------------------------  gauss */
for (i = 0 ; i < m->rows ; i++)
{
 copy_mF(&mT2,m);
for (row1 = 0 ; row1 < m->rows - i; row1++)
{
 id_mF(&mIDT1);
 for (row2 = row1+1 ; row2 < m->rows ; row2++)
 {
 (*(mIDT1.pb+row2 *mIDT1.cols+row1*C2)) = \
   (-(*(m->pb+row2     *m->cols+row1*C2)))  ;

 (*(mIDT1.pb+row2 *mIDT1.cols+row1*C2+1)) =  \
     (*(m->pb+row2     *m->cols+row1*C2+1));
 }

 f.n =  *(m->pb+row1   *m->cols+row1 *C2    );
 f.d =  *(m->pb+row1   *m->cols+row1 *C2+1);

 pivotzeroF(f);

 if(f.n < 0 )
 {
 f.n = -1 * (f.n);
 f.d = -1 * (f.d);
 }

 for (row2 = row1  ; row2 < m->rows ; row2++)
 {
 *(mIDT1.pb+row2 *mIDT1.cols+row1*C2    ) *=   f.d;
 *(mIDT1.pb+row2 *mIDT1.cols+row1*C2+1) *=   f.n;
 }

 copy_mF(      m, &mT);
 mul_mF(&mIDT1,&mT,m );
}
 copy_mF(&mID,  &mIDT2);
 mul_mF(&mIDT2,&mIDT1, &mID);
}
 copy_mF(&mID,m);
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */

/* see   :  inv_xhunga_mF()                                                      */
/* -------------------------------------------------------------------------- */
void idF5a(
PmF m)
{
     int row1;
     int row2;
     int i;
     int n;

double pbID [MXR][MXC*C2];mF mID  ={MXR,MXC*C2,&pbID [0][0]};
double pIDT1[MXR][MXC*C2];mF mIDT1={MXR,MXC*C2,&pIDT1[0][0]};
double pIDT2[MXR][MXC*C2];mF mIDT2={MXR,MXC*C2,&pIDT2[0][0]};
double pbT  [MXR][MXC*C2];mF mT   ={MXR,MXC*C2,&pbT  [0][0]};
double pbT2 [MXR][MXC*C2];mF mT2  ={MXR,MXC*C2,&pbT2 [0][0]};

 n = m->rows;
                   mID.rows=n;                 mID.cols=n*C2;
                 mIDT1.rows=n;               mIDT1.cols=n*C2;
                 mIDT2.rows=n;               mIDT2.cols=n*C2;
                    mT.rows=n;                  mT.cols=n*C2;
                   mT2.rows=n;                 mT2.cols=n*C2;
 copy_mF(m,&mT2);
    id_mF(&mID);
/*-------------------------------------------------------------------- jordan */
for (i = 0 ; i < m->rows-1 ; i++)
{
  copy_mF(&mT2,m);
  for (row1 = m->rows-1 ; row1 - i>0 ; row1--)
   {
    id_mF(&mIDT1);
    for (row2 = 0 ; row2 < row1 ; row2++)
    {
     (*(mIDT1.pb+row2 *mIDT1.cols+row1*C2)) = \
      -(*(m->pb+row2     *m->cols+row1*C2));

      *(mIDT1.pb+row2 *mIDT1.cols+row1*C2+1) = \
        *(m->pb+row2     *m->cols+row1*C2+1);
     }
      copy_mF(       m,  &mT);
      mul_mF(&mIDT1, &mT, m );
   }
 copy_mF(&mID,  &mIDT2);
 mul_mF(&mIDT2,&mIDT1, &mID);
}
 copy_mF(&mID,m);
}


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* See   :  mtrxaa.zip, inv_xh .c                                             */
/* -------------------------------------------------------------------------- */
void inv_xhunga_mF(
PmF mA,
PmF minv)
{
int n;

double pAT1 [MXR][MXC*C2];mF mAT1 ={MXR,MXC*C2,&pAT1 [0][0]};
double pAT2 [MXR][MXC*C2];mF mAT2 ={MXR,MXC*C2,&pAT2 [0][0]};
double pAID [MXR][MXC*C2];mF mAID ={MXR,MXC*C2,&pAID [0][0]};
double pAIDT[MXR][MXC*C2];mF mAIDT={MXR,MXC*C2,&pAIDT[0][0]};

 n = mA->rows;
                  mAT1.rows=n;                mAT1.cols=n*C2;
                  mAT2.rows=n;                mAT2.cols=n*C2;
                  mAID.rows=n;                mAID.cols=n*C2*C2;
                 mAIDT.rows=n;               mAIDT.cols=n*C2*C2;
/*-------------------------------- PROGRAM ---------------------------------- */
 createAid_mF(mA,&mAID);
   copy_mF(mA,&mAT1);

 idF5  (&mAT1);
 mul_mF(&mAT1,&mAID,&mAIDT);
 mul_mF(&mAT1, mA,   &mAT2);

   idF5a(&mAT2);
  mul_mF(&mAT2,&mAIDT,&mAID);
 copyinv_mF(             &mAID,minv);
}




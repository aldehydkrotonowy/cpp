/* xxpid4.h                     freeware                   xhunga@tiscali.fr  */

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* See   :  mtrxid.zip, Bgauss0 .c, Cgauss0 .c, Cinv0 .c.                     */
/* -------------------------------------------------------------------------- */
void idF4(
PmF mID,
PmF m)
{
     int row1;
     int row2;
     int i;
     int n;
fraction f;

double pIDT1[MXR][MXC*C2];mF mIDT1={MXR,MXC*C2,&pIDT1[0][0]};
double pIDT2[MXR][MXC*C2];mF mIDT2={MXR,MXC*C2,&pIDT2[0][0]};
double pbT  [MXR][MXC*C2];mF mT   ={MXR,MXC*C2,&pbT  [0][0]};
double pbT2 [MXR][MXC*C2];mF mT2  ={MXR,MXC*C2,&pbT2 [0][0]};

 n = m->rows;
                 mIDT1.rows=n;               mIDT1.cols=n*C2;
                 mIDT2.rows=n;               mIDT2.cols=n*C2;
                    mT.rows=n;                  mT.cols=n*C2;
                   mT2.rows=n;                 mT2.cols=n*C2;
/*--------------------------------------------------------------------  gauss */
 copy_mF(m,&mT2);
    id_mF(mID);

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
     (*(m->pb+row2   *m->cols+row1*C2+1));
 }

 f.n =  *(m->pb+row1   *m->cols+row1*C2    );
 f.d =  *(m->pb+row1   *m->cols+row1*C2+1);

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
 copy_mF(mID,  &mIDT2);
 mul_mF(&mIDT2,&mIDT1, mID);
}

}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* See   :  mtrxid.zip, Bgauss0 .c, Cgauss0 .c, Cinv0 .c.                     */
/* -------------------------------------------------------------------------- */
void idF4a(
PmF mID,
PmF m)
{
     int row1;
     int row2;
     int i;
     int n;

double pIDT1[MXR][MXC*C2];mF mIDT1={MXR,MXC*C2,&pIDT1[0][0]};
double pIDT2[MXR][MXC*C2];mF mIDT2={MXR,MXC*C2,&pIDT2[0][0]};
double pbT  [MXR][MXC*C2];mF mT   ={MXR,MXC*C2,&pbT  [0][0]};
double pbT2 [MXR][MXC*C2];mF mT2  ={MXR,MXC*C2,&pbT2 [0][0]};

 n = m->rows;

                 mIDT1.rows=n;               mIDT1.cols=n*C2;
                 mIDT2.rows=n;               mIDT2.cols=n*C2;
                    mT.rows=n;                  mT.cols=n*C2;
                   mT2.rows=n;                 mT2.cols=n*C2;
/*-------------------------------------------------------------------- jordan */
 copy_mF(m,&mT2);
    id_mF(mID);

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
 copy_mF(mID,  &mIDT2);
 mul_mF(&mIDT2,&mIDT1, mID);
}
}



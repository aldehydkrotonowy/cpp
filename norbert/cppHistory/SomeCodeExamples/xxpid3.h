/* xxpid3.h                     freeware                   xhunga@tiscali.fr  */

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* See   :  mtrxid.zip, Bid.c, Cid.c.                                     */
/* -------------------------------------------------------------------------- */
void idF3(
PmF mID,
PmF m,
    int row1)
{
     int row2;
     int n;
fraction f;

double pbT  [MXR][MXC*C2];mF mT   ={MXR,MXC*C2,&pbT  [0][0]};

 n = m->rows;
                     mT.rows = n;        mT.cols = n*C2;
/*--------------------------------------------------------------------  gauss */
 id_mF(mID);

 for (row2 = row1+1 ; row2 < m->rows ; row2++)
 {
 (*(mID->pb+row2 *mID->cols+row1*C2)) = \
 (-(*(m->pb+row2   *m->cols+row1*C2)))  ;

 (*(mID->pb+row2 *mID->cols+row1*C2+1)) =  \
   (*(m->pb+row2   *m->cols+row1*C2+1));
 }

 f.n =  *(m->pb+row1   *m->cols+row1*C2    );
 f.d =  *(m->pb+row1   *m->cols+row1*C2+1);

 pivotzeroF(f);

if(f.n < 0 )
{
 f.n = -1*(f.n);
 f.d = -1*(f.d);
}

 for (row2 = row1  ; row2 < m->rows ; row2++)
 {
 *(mID->pb+row2 *mID->cols+row1*C2    ) *=   f.d;
 *(mID->pb+row2 *mID->cols+row1*C2+1) *=   f.n;
 }

 copy_mF(     m,  &mT);
 mul_mF(mID, &mT, m );
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* See   :  mtrxid06.zip, Bid.c, Cid.c.                                       */
/* -------------------------------------------------------------------------- */
void idF3a(
PmF mID,
PmF m,
     int row1)
{
     int row2;
     int n;

double pbT  [MXR][MXC*C2];mF mT   ={MXR,MXC*C2,&pbT  [0][0]};

 n = m->rows;
                     mT.rows = n;        mT.cols = n*C2;
/*-------------------------------------------------------------------- jordan */
 id_mF(mID);

 for (row2 = 0 ; row2 < row1 ; row2++)
 {
 (*(mID->pb+row2 *mID->cols+row1*C2)) = \
 -(*(m->pb+row2   *m->cols+row1*C2));

   *(mID->pb+row2 *mID->cols+row1*C2+1) = \
   *(m->pb+row2     *m->cols+row1*C2+1);
 }
 copy_mF(     m,  &mT);
 mul_mF(mID, &mT, m );
}


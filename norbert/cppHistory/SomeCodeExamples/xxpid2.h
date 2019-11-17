/* xxpid2.h                     freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */

/* See   :  mtrxid.zip,  Agaus0 .c                                          */
/* -------------------------------------------------------------------------- */
void gjidF2(
PmF m)
{
     int row1;
     int row2;
     int n;
fraction f;

double pbID [MXR][MXC*C2];mF mID  ={MXR,MXC*C2,&pbID [0][0]};
double pbT  [MXR][MXC*C2];mF mT   ={MXR,MXC*C2,&pbT  [0][0]};

 n = m->rows;
                    mID.rows = n;       mID.cols =  n   *C2;
                     mT.rows = n;        mT.cols = (n+1)*C2;
/*--------------------------------------------------------------------  gauss */
for (row1 = 0 ; row1 < m->rows-1 ; row1++)
{
 pivotntzeroF(m,row1, row1);
 gausspivotbestF(m,row1, row1);

 clrscrn();

 printf("The matrix mA\n");
 p_mF4(m);

 id_mF(&mID);
 for (row2 = row1+1 ; row2 < m->rows ; row2++)
 {
   (*(mID.pb+row2 *mID.cols+row1*C2)) = \
 (-(*(m->pb+row2  *m->cols+row1*C2)))  ;

 (*(mID.pb+row2 *mID.cols+row1*C2+1)) =  \
 (*(m->pb+row2   *m->cols+row1*C2+1));
 }

 printf("\n");
 printf(" a) You must copy all the values below the pivot  \n");
 printf("    in the identity mF. And take the opposite.\n");

 f.n =  *(m->pb+row1   *m->cols+row1*C2    );
 f.d =  *(m->pb+row1   *m->cols+row1*C2+1);

 if(f.n < 0 )
 {
 f.n = -1*(f.n);
 f.d = -1*(f.d);
 }

 for (row2 = row1  ; row2 < m->rows ; row2++)
 {
 *(mID.pb+row2 *mID.cols+row1*C2    ) *= f.d;
 *(mID.pb+row2 *mID.cols+row1*C2+1) *= f.n;
 }

 printf("\n");
 printf(" b) And you muliply all these values, plus the pivot,\n");
 printf("    by the inverse of the pivot value, of a matrix mA :\n");
 p_mF4(&mID);
 getchar();

 clrscrn();
 p_mF4(&mID);
 printf(" 1) Now if you muliply this matrix by mA\n");
 p_mF4(m);
 copy_mF(     m,  &mT);
 mul_mF(&mID, &mT, m );
 printf("\n");
 printf(" 2) The pivot equal 1\n");
 printf(" 3) All the values below the pivot will be equal to 0\n");
 p_mF4(m);
 getchar();
}

 clrscrn();
 printf(" The work above the pivot in one step.\n");


   row1 = m->rows-1;
  {
   f.n =  *(m->pb+row1   *m->cols+row1*C2    );
   f.d =  *(m->pb+row1   *m->cols+row1*C2+1);

   if(f.d < 0 )
     {
      f.n = -1*(f.n);
      f.d = -1*(f.d);
      }

   if(f.n < 0 )
     {
      f.n = -1*(f.n);
      f.d = -1*(f.d);
     }

    id_mF(&mID);

    *(mID.pb+row1 *mID.cols+row1*C2     ) = f.d;
    *(mID.pb+row1 *mID.cols+row1*C2+1 ) = f.n;

    copy_mF(     m,  &mT);
    mul_mF(&mID, &mT, m );
   }

/*-------------------------------------------------------------------- jordan */
for (row1 = m->rows-1 ; row1>0 ; row1--)
{
    id_mF(&mID);
    for (row2 = 0 ; row2 < row1 ; row2++)
    {
     (*(mID.pb+row2 *mID.cols+row1*C2)) = \
      -(*(m->pb+row2   *m->cols+row1*C2));

      *(mID.pb+row2 *mID.cols+row1*C2+1) = \
        *(m->pb+row2   *m->cols+row1*C2+1);
     }
           copy_mF(     m,  &mT);
           mul_mF(&mID, &mT, m );
}
  p_mF4(m);
  printf("\n");
}



/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* See   :  mtrxid.zip,  Ainv0 .c                                             */
/* -------------------------------------------------------------------------- */
void invidF2(
PmF mA,
PmF mAID
)
{
     int row1;
     int row2;
     int n;
fraction f;

double pID  [MXR][MXC*C2];mF mID  ={MXR,MXC*C2,&pID  [0][0]};
double pAIDT[MXR][MXC*C2];mF mAIDT={MXR,MXC*C2,&pAIDT[0][0]};

 n = mA->rows;
                   mID.rows=n;                 mID.cols=n  *C2;
                 mAIDT.rows=n;               mAIDT.cols=n*C2*C2;
/*--------------------------------------------------------------------  gauss */
createAid_mF (mA,mAID);

for (row1 = 0 ; row1 < mAID->rows-1 ; row1++)
{
 pivotntzeroF(mAID,row1, row1);

 clrscrn();

 printf("The matrix mA_mID\n");
 p_mF2(mAID);

 id_mF(&mID);
 for (row2 = row1+1 ; row2 < mAID->rows ; row2++)
 {
 (*(mID.pb+row2 *mID.cols+row1*C2)) = \
  -(*(mAID->pb+row2   *mAID->cols+row1* 2));

  *(mID.pb+row2 *mID.cols+row1*C2+1) = \
   *(mAID->pb+row2   *mAID->cols+row1*C2+1);
 }

 printf("\n");
 printf(" a) You must copy all the values below the pivot  \n");
 printf("    in the identity mF. And take the opposite.\n");

 f.n =  *(mAID->pb+row1   *mAID->cols+row1*C2    );
 f.d =  *(mAID->pb+row1   *mAID->cols+row1*C2+1);

 if(f.n < 0 )
 {
 f.n = -1*(f.n);
 f.d = -1*(f.d);
 }

 for (row2 = row1  ; row2 < mAID->rows ; row2++)
 {
 *(mID.pb+row2 *mID.cols+row1*C2) *= f.d;
 *(mID.pb+row2 *mID.cols+row1*C2+1) *= f.n;
 }

 printf("\n");
 printf(" b) Then you muliply all these values, plus the pivot,\n");
 printf("    by the inverse of the pivot value, of a matrix mA :\n");
 p_mF2(&mID);
 getchar();

 clrscrn();
 p_mF2(&mID);
 printf(" 1) Now if you muliply this matrix by mA_mID\n");
 p_mF2(mAID);
 copy_mF(     mAID,   &mAIDT);
 mul_mF(&mID, &mAIDT, mAID);
 printf("\n");
 printf(" 2) The pivot equal 1\n");
 printf(" 3) All the values below the pivot will be equal to 0\n");
 p_mF2(mAID);
 getchar();
}
   clrscrn();
   printf("\n The work above the pivot in one step.\n");


   row1 = mAID->rows-1;
  {
   f.n =  *(mAID->pb+row1   *mAID->cols+row1*C2    );
   f.d =  *(mAID->pb+row1   *mAID->cols+row1*C2+1);

   if(f.d < 0 )
     {
      f.n = -1*(f.n);
      f.d = -1*(f.d);
      }

   if(f.n < 0 )
     {
      f.n = -1*(f.n);
      f.d = -1*(f.d);
     }

    id_mF(&mID);

    *(mID.pb+row1 *mID.cols+row1*C2     ) = f.d;
    *(mID.pb+row1 *mID.cols+row1*C2+1 ) = f.n;

    copy_mF(   mAID,   &mAIDT);
    mul_mF(&mID, &mAIDT, mAID);
   }


/*-------------------------------------------------------------------- jordan */
for (row1 = mAID->rows-1 ; row1>0 ; row1--)
{
    id_mF(&mID);
    for (row2 = 0 ; row2 < row1 ; row2++)
    {
     (*(mID.pb+row2  *mID.cols+row1*C2)) = \
   -(*(mAID->pb+row2 *mAID->cols+row1*C2));

      *(mID.pb+row2  *mID.cols+row1*C2+1) = \
     *(mAID->pb+row2 *mAID->cols+row1*C2+1);
     }
           copy_mF(   mAID,   &mAIDT);
           mul_mF(&mID, &mAIDT, mAID);
}
 p_mF2(mAID);
 printf("\n");
}



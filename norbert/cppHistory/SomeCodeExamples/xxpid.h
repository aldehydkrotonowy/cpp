/* xxpid.h                      freeware                   xhunga@tiscali.fr  */

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :  gauss-jordan on a matrix with the identity mF.                */
/*                                                                            */


/* See   :  mtrxic.zip,  gjid0 .c                                             */
/* -------------------------------------------------------------------------- */
void gjidF(
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

 f.n =  *(m->pb+row1   *m->cols+row1*C2  );
 f.d =  *(m->pb+row1   *m->cols+row1*C2+1);

if(f.d < 0 )                              /* Only the numerator is signed */
{
 f.n = -1*(f.n);
 f.d = -1*(f.d);
}
 clrscrn();

 printf("The matrix m\n\n");
 p_mF4(m);
 printf("\n\n");
 printf(" The pivot value = %.0f/%.0f \n\n", f.n, f.d);

if(f.n < 0 )                                  /* The inverse of the pivot */
{
 f.n = -1*(f.n);
 f.d = -1*(f.d);
}

 printf(" The inverse of the pivot value = %.0f/%.0f \n\n",f.d, f.n);
 getchar();

 clrscrn();

 id_mF(&mID);

 *(mID.pb+row1 *mID.cols+row1*C2   ) = f.d;
 *(mID.pb+row1 *mID.cols+row1*C2+1 ) = f.n;

 printf("\n If you muliply this identity mF\n");
 printf(" (with the inverse of the pivot) :     \n");
 p_mF4(&mID);
 getchar();

 clrscrn();
 p_mF4(&mID);
 printf("\n By the matrix m :\n");
 p_mF4(m);
 copy_mF(     m,  &mT);
 mul_mF(&mID, &mT, m );
 printf("\n The pivot = 1 \n");
 p_mF4(m);
 getchar();

          id_mF(&mID);
          for (row2 = row1+1 ; row2 < m->rows ; row2++)
          {
              (*(mID.pb+row2 *mID.cols+row1*C2)) = \
             -(*(m->pb+row2  *m->cols+row1*C2));

               *(mID.pb+row2 *mID.cols+row1*C2+1) = \
               *(m->pb+row2  *m->cols+row1*C2+1);

          }
           clrscrn();
           printf("\n The matrix m \n");
           p_mF4(m);
           printf("\n Copy all the value below the pivot \n");
           printf(" in the identity mF. And take the opposite.\n");
           p_mF4(&mID);
           getchar();

           clrscrn();
           p_mF4(&mID);
           printf("\n Multiply this matrix by m :\n ");
           p_mF4(m);
           copy_mF(     m,  &mT);
           mul_mF(&mID, &mT, m );
           printf("\n All the coefficients under the pivot = 0\n ");
           p_mF4(m);
           getchar();
}



   row1 = m->rows-1;
  {
   f.n =  *(m->pb+row1   *m->cols+row1*C2  );
   f.d =  *(m->pb+row1   *m->cols+row1*C2+1);

   if(f.d < 0 )                           /* Only the numerator is signed */
     {
      f.n = -1*(f.n);
      f.d = -1*(f.d);
      }

   clrscrn();
   printf("The matrix m\n\n");
   p_mF4(m);
   printf("\n\n");
   printf(" The pivot value = %.0f/%.0f \n\n", f.n, f.d);

   if(f.n < 0 )                               /* The inverse of the pivot */
     {
      f.n = -1*(f.n);
      f.d = -1*(f.d);
     }

    printf(" The inverse of the pivot value = %.0f/%.0f \n\n",f.d, f.n);
    getchar();

    id_mF(&mID);

    *(mID.pb+row1 *mID.cols+row1*C2   ) = f.d;
    *(mID.pb+row1 *mID.cols+row1*C2+1 ) = f.n;

    clrscrn();

    printf("\n If you muliply this identity mF\n");
    printf(" (with the inverse of the pivot) :     \n");
    p_mF4(&mID);
    getchar();

    clrscrn();

    p_mF4(&mID);
    printf("\n By the matrix m :\n");
    p_mF4(m);
    copy_mF(     m,  &mT);
    mul_mF(&mID, &mT, m );
    printf("\n The pivot = 1\n");
    p_mF4(m);
    getchar();
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
      *(m->pb+row2  *m->cols+row1*C2+1);
     }
           clrscrn();
           p_mF4(m);
           printf("\n Copy all the value above the pivot \n");
           printf(" in the identity mF. And take the opposite.\n");
           p_mF4(&mID);
           getchar();

           clrscrn();
           p_mF4(&mID);
           printf("\n Multiply this matrix by m :\n");
           p_mF4(m);
           copy_mF(     m,  &mT);
           mul_mF(&mID, &mT, m );
           printf("\n All the coefficients above the pivot = 0\n");
           p_mF4(m);
           getchar();
}
  printf("\n Now, you have the solution \n");
}



/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :  Inverse a matrix with the identity mF.                        */
/*                                                                            */


/* See   :  mtrxic.zip,  invid0 .c                                            */
/* -------------------------------------------------------------------------- */
void invidF(
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
                   mID.rows=n;                 mID.cols=n*C2;
                 mAIDT.rows=n;               mAIDT.cols=n*C2*C2;
/*--------------------------------------------------------------------  gauss */
createAid_mF (mA,mAID);

for (row1 = 0 ; row1 < mAID->rows-1 ; row1++)
{
 pivotntzeroF(mAID,row1, row1);

 f.n =  *(mAID->pb+row1   *mAID->cols+row1*C2    );
 f.d =  *(mAID->pb+row1   *mAID->cols+row1*C2+1);

if(f.d < 0 )                              /* Only the numerator is signed */
{
 f.n = -1*(f.n);
 f.d = -1*(f.d);
}
 clrscrn();
 printf("The matrix mA mID\n\n");
 p_mF2(mAID);
 printf("\n\n");
 printf(" The pivot value = %.0f/%.0f \n\n", f.n, f.d);

if(f.n < 0 )                                  /* The inverse of the pivot */
{
 f.n = -1*(f.n);
 f.d = -1*(f.d);
}

 printf(" The inverse of the pivot value = %.0f/%.0f \n\n",f.d, f.n);
 getchar();

 id_mF(&mID);

 *(mID.pb+row1 *mID.cols+row1*C2  ) = f.d;
 *(mID.pb+row1 *mID.cols+row1*C2+1) = f.n;

 clrscrn();
 printf("\n If you muliply this identity matrix \n ");
 printf(" (with the inverse of the pivot) :    \n ");
 p_mF2(&mID);
 getchar();

 clrscrn();
 p_mF2(&mID);
 printf("\n By the matrix mA mID :\n ");
 p_mF2(mAID);
 copy_mF(     mAID,   &mAIDT);
 mul_mF(&mID,   &mAIDT, mAID);
 printf("\n The pivot = 1\n");
 p_mF2(mAID);
 getchar();

          id_mF(&mID);
          for (row2 = row1+1 ; row2 < mAID->rows ; row2++)
          {
              (*(mID.pb+row2     *mID.cols+row1* C2)) = \
             -(*(mAID->pb+row2   *mAID->cols+row1*C2));

               *(mID.pb+row2   *mID.cols+row1*C2+1) = \
               *(mAID->pb+row2 *mAID->cols+row1*C2+1);

          }
           clrscrn();
           p_mF2(mAID);
           printf("\n Copy all the value below the pivot \n ");
           printf(" in the identity mF. And take the opposite.\n ");
           p_mF2(&mID);
           getchar();

           clrscrn();
           p_mF2(&mID);
           printf("\n Multiply this matrix by mA mID :\n ");
           p_mF2(mAID);
           copy_mF( mAID,&mAIDT);
           mul_mF(&mID, &mAIDT, mAID);
           printf("\n All the coefficients under the pivot = 0 \n ");
           p_mF2(mAID);
           getchar();
}

   row1 = mAID->rows-1;
  {
   f.n =  *(mAID->pb+row1   *mAID->cols+row1*C2  );
   f.d =  *(mAID->pb+row1   *mAID->cols+row1*C2+1);

   if(f.d < 0 )                           /* Only the numerator is signed */
     {
      f.n = -1*(f.n);
      f.d = -1*(f.d);
      }

   clrscrn();
   printf("The matrix mA mID\n\n");
   p_mF2(mAID);
   printf("\n\n");
   printf(" The pivot value = %.0f/%.0f \n\n", f.n, f.d);

   if(f.n < 0 )                               /* The inverse of the pivot */
     {
      f.n = -1*(f.n);
      f.d = -1*(f.d);
     }

    printf(" The inverse of the pivot value = %.0f/%.0f \n\n",f.d, f.n);
    getchar();

    id_mF(&mID);

    *(mID.pb+row1 *mID.cols+row1*C2   ) = f.d;
    *(mID.pb+row1 *mID.cols+row1*C2+1 ) = f.n;

    clrscrn();
    printf("\n If you muliply this identity matrix \n ");
    printf(" (with the inverse of the pivot) :    \n ");
    p_mF2(&mID);
    getchar();

    clrscrn();
    p_mF2(&mID);
    printf("\n By the matrix mA mID :\n ");
    p_mF2(mAID);
    copy_mF(   mAID,   &mAIDT);
    mul_mF(&mID, &mAIDT, mAID);
    printf("\n The pivot = 1 \n");
    p_mF2(mAID);
    getchar();
   }


/*-------------------------------------------------------------------- jordan */
for (row1 = mAID->rows-1 ; row1>0 ; row1--)
{
    id_mF(&mID);
    for (row2 = 0 ; row2 < row1 ; row2++)
    {
     (*(mID.pb+row2   *mID.cols+row1*C2)) = \
    -(*(mAID->pb+row2 *mAID->cols+row1*C2));

      *(mID.pb+row2   *mID.cols+row1*C2+1) = \
      *(mAID->pb+row2 *mAID->cols+row1*C2+1);
     }
           clrscrn();
           p_mF2(mAID);
           printf("\n Copy all the value above the pivot \n ");
           printf(" in the identity mF. And take the opposite.\n ");
           p_mF2(&mID);
           getchar();

           clrscrn();
           p_mF2(&mID);
           printf("\n Multiply this matrix by mA mID :\n ");
           p_mF2(mAID);
           copy_mF(   mAID,   &mAIDT);
           mul_mF(&mID, &mAIDT, mAID);
           printf("\n All the coefficients above the pivot = 0\n ");
           p_mF2(mAID);
           getchar();
}
clrscrn();
p_mF2(mAID);
}



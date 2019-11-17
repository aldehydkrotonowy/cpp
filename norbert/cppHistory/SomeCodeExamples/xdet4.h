/* xdet4.h                      freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
fraction cofactor_F(
PmF mA,
int ci,
int cj)
{
     int i;
     int j;
     int tci = 0;
     int tcj = 0;
fraction f;

double pMinor [MXR][MXC*C2];mF mMinor ={MXR,MXC*C2,&pMinor [0][0]};

                mMinor.rows=(mA->rows-1);
                mMinor.cols=(mA->rows-1)*C2;

for (i=0, tci=0 ; i < mA->rows ; i++)
 if(i!=ci)
   {
    for ( j=0, tcj=0; j<mA->cols ; j+=C2)
      if(j!=cj*C2)
        {
         *(mMinor.pb+tci *mMinor.cols+tcj  ) = *(mA->pb+i *mA->cols+j  );
         *(mMinor.pb+tci *mMinor.cols+tcj+1) = *(mA->pb+i *mA->cols+j+1);
           tcj+=C2;
        }
    tci++;
   }

          f = det_F(&mMinor);
        f.n = pow(-1,(ci+1+cj+1))* f.n;

  return(f);
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void    cofactor_mF(
PmF mA,
PmF mCofactor)
{
     int i;
     int j;
fraction f;

  if (mA->rows != mCofactor->rows || mA-> cols != mCofactor->cols)
    {
     printf("\n mcofactor() error - matrices different sizes");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }

 for (   i=0 ; i<mA->rows ; i++)
   for ( j=0 ; j<mA->cols ; j+=C2)
    {
               f =  cofactor_F(mA,i, j/C2);

     *(mCofactor->pb+i *mCofactor->cols+j  ) = f.n;
     *(mCofactor->pb+i *mCofactor->cols+j+1) = f.d;
    }
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void    adjoint_mF(
PmF mCofactor,
PmF mAdjoint)
{
  if (mCofactor->rows != mAdjoint->rows || mCofactor-> cols != mAdjoint->cols)
    {
     printf("\n adjoint() error - matrices different sizes");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }

 transpose_mF(mCofactor,mAdjoint);
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void inverse_mF(
PmF  mA,
PmF  mInverse)
{
int      row;
fraction f;

double pCofact[MXR][MXC*C2];mF mCofact={MXR,MXC*C2,&pCofact[0][0]};

               mCofact.rows=mA->rows       ;
               mCofact.cols=mA->rows*C2;

     cofactor_mF(mA,&mCofact);
       adjoint_mF(   &mCofact,mInverse);

      f = det_F(mA);
      f = inv_F(f);
    for( row=0; row<mA->rows ; row++)
         mulrow_mF(mInverse,row,f);
}




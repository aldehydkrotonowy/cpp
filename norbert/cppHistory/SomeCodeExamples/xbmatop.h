/* xbmatop.h                    free ware                  xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    : mA + mB = mAplsB                                                   */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void add_mF(
PmF mA,
PmF mB,
PmF mAplsB)
{
     int i;
     int j;
fraction fA;
fraction fB;
fraction fAplsB;


  if (mA->rows != mB->rows || mA->cols != mB->cols)
    {
     printf("\n addm() error - matrices different sizes");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }
  if (mA->rows!=mAplsB->rows||mA->cols!=mAplsB->cols)
    {
     printf("\n addm() error - matrices different sizes");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }
  for (   i=0; i<mA->rows ; i++)
    for ( j=0; j<mA->cols ; j++,j++)
         {
          fA.n  = *(mA->pb+i *mA->cols+j  );
          fA.d  = *(mA->pb+i *mA->cols+j+1);

          fB.n  = *(mB->pb+i *mB->cols+j  );
          fB.d  = *(mB->pb+i *mB->cols+j+1);

         fAplsB = add_F(fA,fB);

                  *(mAplsB->pb+i *mAplsB->cols+j)     = fAplsB.n;
                  *(mAplsB->pb+i *mAplsB->cols+j+1)   = fAplsB.d;
         }
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    : mA - mB = mAmnsB                                                   */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void sub_mF(
PmF mA,
PmF mB,
PmF mAmnsB)
{

     int i;
     int j;
fraction fA;
fraction fB;
fraction fAmnsB;

  if (mA->rows != mB->rows || mA->cols != mB->cols)
    {
     printf("\n addm() error - matrices different sizes");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }
  if (mA->rows!=mAmnsB->rows||mA->cols!=mAmnsB->cols)
    {
     printf("\n addm() error - matrices different sizes");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }
  for (   i = 0; i < mA->rows ; i++  )
    for ( j = 0; j < mA->cols ; j+=C2)
         {
          fA.n  = *(mA->pb+i *mA->cols+j  );
          fA.d  = *(mA->pb+i *mA->cols+j+1);

          fB.n  = *(mB->pb+i *mB->cols+j  );
          fB.d  = *(mB->pb+i *mB->cols+j+1);

         fAmnsB = sub_F(fA,fB);

                  *(mAmnsB->pb+i *mAmnsB->cols+j)     = fAmnsB.n;
                  *(mAmnsB->pb+i *mAmnsB->cols+j+1)   = fAmnsB.d;

         }
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    : mA * mB = mAB                                                      */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void mul_mF(
PmF mA,
PmF mB,
PmF mAB)
{
     int i;
     int j;
     int k;
fraction fA;
fraction fB;
fraction fT;
fraction fAB;

              for(k= 0; k < mA->rows; k++)
               {
                  for(j=0; j<mB->cols; j+=C2)
                   { fAB.n = 0;
                     fAB.d = 1;
                    for(i=0; i<mA->cols; i+=C2)
                    {

                    fA.n = *(mA->pb+k   *(mA->cols)+i  );
                    fA.d = *(mA->pb+k   *(mA->cols)+i+1);

                    fB.n = *(mB->pb+i/C2 *(mB->cols)+j  );
                    fB.d = *(mB->pb+i/C2 *(mB->cols)+j+1);

                     fT = mul_F(fA,fB);
                    fAB = add_F(fAB,fT);
                    }
                     *(mAB->pb+k   *(mAB->cols)+j)   = fAB.n;
                     *(mAB->pb+k   *(mAB->cols)+j+1) = fAB.d;
                   }
               }
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :  s * mA = msA                                                      */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void Fmul_mF(
fraction f,
PmF mA,
PmF mfA)
{
     int i;
     int j;
fraction fT;

  for (   i=0; i<mA->rows; i++)
    for ( j=0; j<mA->cols; j+=C2)
         {
          fT.n = (*(mA->pb+i *mA->cols+j  )) * f.n;
          fT.d = (*(mA->pb+i *mA->cols+j+1)) * f.d;

                fT = mini_F(fT);

         (*(mfA->pb+i *mfA->cols+j  )) = fT.n;
         (*(mfA->pb+i *mfA->cols+j+1)) = fT.d;
         }
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void transpose_mF(
PmF mA,
PmF mTrpsA)
{
  int i;
  int j;

  if (mTrpsA->rows * C2 != mA->cols)
    {
     printf("\n transpose() error - dest matrixrows must = source matrix cols");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }
  if (mA->rows * C2 != mTrpsA->cols)
    {
     printf("\n transpose() error - source matrix rows must = dest matrix cols");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }
  for (  i=0 ; i<mA->rows; i++)
    for (j=0 ; j<mA->cols; j+=C2)
      {
       *(mTrpsA->pb+(j/C2) *mTrpsA->cols+i*C2)   = \
       *( mA->pb+i         *mA->cols+j);

       *(mTrpsA->pb+(j/C2) *mTrpsA->cols+i*C2+1) = \
       *( mA->pb+i         *mA->cols+j+1);
      }
}



/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
fraction trace_mF(
PmF m)
{
     int i;
fraction f;
fraction fT;

  if ((m->rows * C2) !=  m->cols)
    {
     printf("\n trF() error - Square matrix, please");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }

    f.n = 0;
    f.d = 1;

  for(   i = 0; i < m->rows ; i++)
     {
      fT.n = (*(m->pb+i *m->cols+i*C2   ));
      fT.d = (*(m->pb+i *m->cols+i*C2+1));

             f  =  add_F(f,fT);
     }

  return(f);
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    : mA**n = mAPn                                                       */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void pow_mF(
PmF mA,
int       Pn,
PmF mAPn
)
{
int    i;
double pbT[MXR][MXC*C2];mF mT ={MXR,MXC*C2,&pbT[0][0]};

                   mT.rows=mA->rows;
                   mT.cols=mA->rows*C2;
 copy_mF(mA,mAPn);

 if(!Pn) id_mF(mAPn);
 else    for(i = Pn-1 ; i ; i--)
            {
             mul_mF(mAPn, mA,&mT);
             copy_mF(&mT,mAPn);
            }
}



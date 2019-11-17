/* xdet3.h                      freeware                   xhunga@tiscali.fr  */




/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
fraction minor_F(
PmF mA,
int ci,
int cj)
{
   int i;
   int j;
   int n;
   int tci = 0;
   int tcj = 0;

fraction f;

double pMinor [MXR][MXC*C2];mF mMinor ={MXR,MXC*C2,&pMinor [0][0]};

 n = mA->rows;
                mMinor.rows=(n-1);
                mMinor.cols=(n-1)*C2;
  tci = 0;
  for (i = 0 ; i < mA->rows ; i++)
   {
    if(i != ci){

    tcj = 0;
    for ( j = 0; j < mA->cols ; j++,j++)
     {
      if(j != cj * C2)
      {
      *(mMinor.pb+tci *mMinor.cols+tcj  ) = *(mA->pb+i   *mA->cols+j  );
      *(mMinor.pb+tci *mMinor.cols+tcj+1) = *(mA->pb+i   *mA->cols+j+1);

       tcj++;
       tcj++;
      }
     }
    tci++; }
   }

    f = det_F(&mMinor);

  return(f);
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void minor_mF(
PmF mA,
PmF mMinor,
int ci,
int cj)
{
   int i;
   int j;
   int tci = 0;
   int tcj = 0;

  if (mA->rows != mMinor->rows+1 || mA-> cols != mMinor->cols+C2 )
    {
     printf("\n mMinor() error - matrices bad sizes");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }

  tci = 0;
  for (i = 0 ; i < mA->rows ; i++)
   {
    if(i != ci){

    tcj = 0;
    for ( j = 0; j < mA->cols ; j++,j++)
     {
      if(j != cj * C2)
      {
      *(mMinor->pb+tci *mMinor->cols+tcj  ) = *(mA->pb+i *mA->cols+j  );
      *(mMinor->pb+tci *mMinor->cols+tcj+1) = *(mA->pb+i *mA->cols+j+1);

       tcj++;
       tcj++;
      }
     }
    tci++; }
   }
}

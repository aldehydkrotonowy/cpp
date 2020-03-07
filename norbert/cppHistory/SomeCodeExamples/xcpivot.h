/* xcpivot.h                   freeware                   xhunga@tiscali.fr  */

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
int pivotntzeroF(
PmF mA,
int row1,
int row2)
{
   int sign = 1;
double pivot;
double t;

  pivot = *(mA->pb+row1 *mA->cols+row2*C2);
  if(!pivot)
  {
   row2 = row1+1;
   do
   {
    t = *(mA->pb+row2 *mA->cols+row1*C2);
    if(t)
    {
     swaprow_mF(mA,row1,row2);
     row2 = mA->rows;
     sign = -1;
    }
    row2++;
   }
   while(row2 < mA->rows);
  }
return(sign);
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void pivotminiF(
PmF mA)
{
   int row;
fraction f;

  for (row = 0 ; row < mA->rows ; row++)
   {
   f.n =  (*(mA->pb+row *mA->cols+row*C2  ));
   f.d =  (*(mA->pb+row *mA->cols+row*C2+1));

    if((f.n))
      {
         f = inv_F(f);
         mulrow_mF(mA,row,f);
       frowmini_F(mA,row);
      }
   }
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
int pivotworkF(
PmF     mA,
int     row1,
int     row2)
{
int      j;
fraction f;
fraction  pivot;
fraction upivot;
fraction fAr1;
fraction fAr2;
int      coefnulldoNothing = 1;


    pivot.n =  (*(mA->pb+row1 *mA->cols+row1*C2 ));
    pivot.d =   *(mA->pb+row1 *mA->cols+row1*C2+1);

   upivot.n = -(*(mA->pb+row2 *mA->cols+row1*C2 ));
   upivot.d =   *(mA->pb+row2 *mA->cols+row1*C2+1);

 if(pivot.n)
 {
 for ( j = 0 ; j < mA->cols ; j++,j++ )
    {
     fAr1.n = *(mA->pb+row1 *mA->cols+j  );
     fAr1.d = *(mA->pb+row1 *mA->cols+j+1);

     fAr2.n = *(mA->pb+row2 *mA->cols+j  );
     fAr2.d = *(mA->pb+row2 *mA->cols+j+1);


          f = add_F(mul_F(upivot,fAr1), mul_F( pivot,fAr2));

              *(mA->pb+row2 *mA->cols+j  ) = f.n;
              *(mA->pb+row2 *mA->cols+j+1) = f.d;
    }
  }
  else{coefnulldoNothing = 0;}

  return(coefnulldoNothing);
}



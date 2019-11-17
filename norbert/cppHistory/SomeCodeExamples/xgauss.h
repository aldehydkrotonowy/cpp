/* xgauss.h                    freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void growmini_F(
PmF m,
    int row)
{
     int j;
     int i;
  double ValueOfN;
     int nb1er;
     int ttrue;
     int row0;

/* ************************************************************************** */
/* In this function 0 = 0/0. In other part 0 = 0/1.                           */
/* Why :  rowmini_F(1, 2, 4, 6, 8) = 1, 2, 4, 6, 8                             */
/*        rowmini_F(0, 2, 4, 6, 8) = 0, 1, 2, 3, 4                             */
/*        0 is a muliple of any numbers                                      */
/*        1 is a muliple of 1                                                */
/* ************************************************************************** */
row0 = 0;

for (j = 0;  j < m->cols ; j++, j++)
{
 ValueOfN = *(m->pb+row *m->cols+j);
 if(!ValueOfN)
 {
 *(m->pb+row *m->cols+j+1) = 0;
   row0++;
 }
}
/* ************************************************************************** */

if((row0 * C2) != (m->cols))
{
for(i = 0; i < 2 ; i++)
{

      nb1er = FIRSTNB1ER;
while(nb1er < LASTNB1ER-1 )
{
j = i; ttrue = 1;

/* -------------------------------------------------------------------------- */
while((j < m->cols) && ttrue )
{
          ValueOfN = *(m->pb+row *m->cols+j);
  if(fmod(ValueOfN,tnb1er[nb1er]))
    {
     nb1er++;
     ttrue = 0;
     if( (tnb1er[nb1er]) > fabs(ValueOfN))
        {
          nb1er = LASTNB1ER-1;
        }
    }
j++;j++;
}
/* -------------------------------------------------------------------------- */


/* -------------------------------- true = y -------------------------------- */
if(ttrue)
  {
  for(j = i;  j < m->cols ; j++, j++)
     {
      *(m->pb+row *m->cols+j) = \
      *(m->pb+row *m->cols+j) / tnb1er[nb1er];
     }
  }
/* -------------------------------- true = y -------------------------------- */
}
}
}
/* ************************************************************************** */
/* In this function   0 = 0/0.                                                */
/* In other part      0 = 0/1.                                                */
/* Now you must write 0 = 0/1.                                                */
/* ************************************************************************** */
for (j = 0;  j < m->cols ; j++, j++)
{
 ValueOfN = *(m->pb+row *m->cols+j);
 if(!ValueOfN)
 {
 *(m->pb+row *m->cols+j+1 ) = 1;
 }
}
/* ************************************************************************** */
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void gausspivotbestF(
PmF m,
    int row,
    int col)
{
     int row2 = row+1;
fraction      pivot;
fraction belowpivot;


      frowmini_F(m,row);
       growmini_F(m,row);

       pivot.n = fabs(*(m->pb+row *m->cols+col*C2));

   while(row2 < m->rows)
   {
    growmini_F(m,row2);
    frowmini_F(m,row2);
    belowpivot.n = *(m->pb+row2 *m->cols+col*C2  );
    belowpivot.d = *(m->pb+row2 *m->cols+col*C2+1);

       if(fabs(belowpivot.n) < fabs(pivot.n))
         {
          if(belowpivot.n)
            {
             swaprow_mF(m,row,row2);
             pivot.n = belowpivot.n;
             pivot.d = belowpivot.d;
            }
         }

       if(fabs(belowpivot.n) == fabs(pivot.n))
         {
           if(fabs(belowpivot.d) < fabs(pivot.d))
            {
             swaprow_mF(m,row,row2);
             pivot.n = belowpivot.n;
             pivot.d = belowpivot.d;
            }
         }
    row2++;
   }
}



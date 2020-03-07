/* xcpivbst.h                   freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
int pivotbestFdenom(
PmF m,
    int row,
    int col)
{
fraction      pivot;
fraction belowpivot;
   int  sign =     1;
   int  row2 = row+1;

      frowmini_F(m,row);

  pivot.n = (*(m->pb+row *m->cols+col*C2   ));
  pivot.d = (*(m->pb+row *m->cols+col*C2+1));

   while(row2 < m->rows)
   {
    frowmini_F(m,row2);
    belowpivot.n = *(m->pb+row2 *m->cols+col*C2    );
    belowpivot.d = *(m->pb+row2 *m->cols+col*C2+1);

       if(fabs(belowpivot.d) < fabs(pivot.d))
         {
          if(belowpivot.n)
            {
             swaprow_mF(m,row,row2);
        pivot.n = belowpivot.n;
        pivot.d = belowpivot.d;
              sign *= -1;
            }
         }

       if(fabs(belowpivot.d) == fabs(pivot.d))
         {
          if(belowpivot.n)
           {
           if(fabs(belowpivot.n) < fabs(pivot.n))
            {
             swaprow_mF(m,row,row2);
        pivot.n = belowpivot.n;
        pivot.d = belowpivot.d;
             sign *= -1;
            }
          }
         }
    row2++;
   }

return(sign);
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
int pivotbestFnumermax(
PmF m,
    int row,
    int col)
{
fraction      pivot;
fraction belowpivot;
   int  sign =       1;
   int  row2 = row+1;

      frowmini_F(m,row);

  pivot.n = (*(m->pb+row *m->cols+col*C2  ));
  pivot.d = (*(m->pb+row *m->cols+col*C2+1));

   while(row2 < m->rows)
   {
    frowmini_F(m,row2);
    belowpivot.n = *(m->pb+row2 *m->cols+col*C2  );
    belowpivot.d = *(m->pb+row2 *m->cols+col*C2+1);

       if(fabs(belowpivot.n) > fabs(pivot.n))
         {
            {
             swaprow_mF(m,row,row2);
        pivot.n = belowpivot.n;
        pivot.d = belowpivot.d;
              sign *= -1;
            }
         }

       if(fabs(belowpivot.n) == fabs(pivot.n))
         {
           if(fabs(belowpivot.d) > fabs(pivot.d))
            {
             swaprow_mF(m,row,row2);
        pivot.n = belowpivot.n;
        pivot.d = belowpivot.d;
             sign *= -1;
            }
         }
    row2++;
   }

return(sign);
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
int pivotbestFnumer(
PmF m,
    int row,
    int col)
{
fraction      pivot;
fraction belowpivot;
   int  sign =       1;
   int  row2 = row+1;

      frowmini_F(m,row);

  pivot.n = (*(m->pb+row *m->cols+col*C2  ));
  pivot.d = (*(m->pb+row *m->cols+col*C2+1));

   while(row2 < m->rows)
   {
    frowmini_F(m,row2);
    belowpivot.n = *(m->pb+row2 *m->cols+col*C2   );
    belowpivot.d = *(m->pb+row2 *m->cols+col*C2+1);

       if(fabs(belowpivot.n) < fabs(pivot.n))
         {
          if(belowpivot.n)
            {
             swaprow_mF(m,row,row2);
        pivot.n = belowpivot.n;
        pivot.d = belowpivot.d;
              sign *= -1;
            }
         }

       if(fabs(belowpivot.n) == fabs(pivot.n))
         {
           if(fabs(belowpivot.d) < fabs(pivot.d))
            {
             swaprow_mF(m,row,row2);
        pivot.n = belowpivot.n;
        pivot.d = belowpivot.d;
             sign *= -1;
            }
         }
    row2++;
   }

return(sign);
}




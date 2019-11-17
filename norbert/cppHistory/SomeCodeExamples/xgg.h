/* xgj.h                    freeware                   xhunga@tiscali.fr  */


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    : On a fraction.                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
fraction gfpivotF(
PmF  m,
int      rowpivot,
int      colpivot,
int      colp,
int      rown_mns
)
{
fraction f;

fraction fn;
fraction fn_mns;

fraction fp;
fraction fpivot;

  fpivot.n =  (*(m->pb+rowpivot  *m->cols+colpivot*C2  ));
  fpivot.d =  (*(m->pb+rowpivot  *m->cols+colpivot*C2+1));

      fp.n =  (*(m->pb+rowpivot  *m->cols+colp*C2  ));
      fp.d =  (*(m->pb+rowpivot  *m->cols+colp*C2+1));

   fn_mns.n = -(*(m->pb+rown_mns *m->cols+colpivot*C2  ));
   fn_mns.d =  (*(m->pb+rown_mns *m->cols+colpivot*C2+1));

      fn.n =  (*(m->pb+rown_mns  *m->cols+colp*C2  ));
      fn.d =  (*(m->pb+rown_mns  *m->cols+colp*C2+1));

  if(fn_mns.n)
     {
      f = add_F( mul_F(fpivot,fn), mul_F(fp,fn_mns));
     }
  else
     {
      f.n =  (*(m->pb+rown_mns  *m->cols+colp*C2  ));
      f.d =  (*(m->pb+rown_mns  *m->cols+colp*C2+1));
     }

  mini_F(f);

/*
printf("\n\nfn_mns   %6.0f/%.0f fn       %.0f/%.0f\n",
        fn_mns.n, fn_mns.d,
        fn.n,     fn.d);
printf("fpivot   %6.0f/%.0f fp       %.0f/%.0f\n",
        fpivot.n, fpivot.d,
            fp.n,     fp.d);

printf("\n\n(fpivot*fn) + (fp*fn_mns) = f = %.0f/%.0f\n\n",
        f.n,      f.d);
printf("\n\n(%.0f/%.0f)*(%.0f/%.0f) + (%.0f/%.0f)*(%.0f/%.0f);  \n\n",
         fpivot.n, fpivot.d,
             fn.n,     fn.d,
             fp.n,     fp.d,
         fn_mns.n, fn_mns.d);


getchar();
        p_mF3(m);
*/
 return(f);
}




/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :  On a row.                                                         */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void grpivotF(
PmF  m,
int      rowpivot,
int      colpivot,
int      rown_mns
)
{
     int colp;
fraction f;

    if((*(m->pb+rowpivot  *m->cols+colpivot*C2)))
     {
      for(colp = (m->cols/2)-1 ; colp > -1 ; colp--)
        {
         f = gfpivotF(m, rowpivot, colpivot, colp, rown_mns);

         (*(m->pb+rown_mns  *m->cols+colp*C2  )) = f.n;
         (*(m->pb+rown_mns  *m->cols+colp*C2+1)) = f.d;
        }
      }

      frowmini_F(m,rown_mns);
      growmini_F(m,rown_mns);
}


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
int gcpivotnt0F(
PmF mA,
int rowpivot,
int colpivot)
{
int rowunderp;
int coeff0 = 1;

  if(!(*(mA->pb+rowpivot *mA->cols+colpivot*C2)))
  {
      coeff0 = 0;
   rowunderp = rowpivot + 1;
   do
   {
    if(*(mA->pb+rowunderp *mA->cols+colpivot*C2))
    {
     swaprow_mF(mA,rowpivot,rowunderp);
     rowunderp = mA->rows;
     coeff0 = 1;
    }
    rowunderp++;
   }
   while(rowunderp < mA->rows);
  }

return(coeff0);
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :  On a column.                                                      */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void gcpivotF(
PmF  m,
int      rowpivot,
int      colpivot
)
{
int      rown_mns;

     gcpivotnt0F(m,rowpivot,colpivot);


     for(rown_mns = rowpivot+1; rown_mns < (m->rows); rown_mns++)
        {
          while( !(*(m->pb+rowpivot  *m->cols+colpivot*C2)) &&
                  (colpivot < m->cols/2)
               )
               {
                colpivot++;
               };

         grpivotF(m, rowpivot, colpivot,rown_mns);
        }
}


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :  .                                                                 */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void gdpivotF(
PmF  m
)
{
int      rowpivot;

     for(rowpivot = 0; rowpivot < (m->rows)-1  ;rowpivot++)
     {

      gcpivotF(m, rowpivot,rowpivot);
     }
}





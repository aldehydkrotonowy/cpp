/* xcpivot.h                   freeware                   xhunga@tiscali.fr  */


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    : On a fraction.                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
fraction jfpivotF(
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


if(colpivot != colp)
{
      f = add_F( mul_F(fpivot,fn), mul_F(fp,fn_mns));
}

if(colpivot == colp)
{
 (*(m->pb+rown_mns *m->cols+colpivot*C2  )) = 0;
 (*(m->pb+rown_mns *m->cols+colpivot*C2+1)) = 1;

 f = add_F( mul_F(fpivot,fn), mul_F(fp,fn_mns));
}

  mini_F(f);
/*
if(colp<colpivot)
{
printf("fn_mns[%d,%d]   %6.0f/%.0f fn[%d,%d]       %.0f/%.0f\n",
            rown_mns, colpivot,
        fn_mns.n, fn_mns.d,
            rown_mns,    colp,
            fn.n,     fn.d);
printf("fpivot[%d,%d]   %6.0f/%.0f fp[%d,%d]       %.0f/%.0f\n",
            rowpivot, colpivot,
        fpivot.n, fpivot.d,
            rowpivot,   colp,
            fp.n,     fp.d);

printf("\n\n(fpivot*fn) + (fp*fn_mns) = f = %.0f/%.0f\n\n",
        f.n,      f.d);
printf("\n\n(%.0f/%.0f)*(%.0f/%.0f) + (%.0f/%.0f)*(%.0f/%.0f);  \n\n",
         fpivot.n, fpivot.d,
             fn.n,     fn.d,
             fp.n,     fp.d,
         fn_mns.n, fn_mns.d);

     p_mF(m);
getchar();
}
*/

 return(f);
}


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :  On a row.                                                         */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void jrpivotF(
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
         f = jfpivotF(m, rowpivot, colpivot, colp, rown_mns);

         (*(m->pb+rown_mns  *m->cols+colp*C2  )) = f.n;
         (*(m->pb+rown_mns  *m->cols+colp*C2+1)) = f.d;

        }
     }

      frowmini_F(m,rown_mns);
      growmini_F(m,rown_mns);
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :  On a row.                                                         */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void jcpivotF(
PmF  m,
int      rowpivot,
int      colpivot
)
{
int      rown_mns;

      for(rown_mns = rowpivot-1; rown_mns > -1 ; rown_mns--)
        {
          while( !(*(m->pb+rowpivot  *m->cols+colpivot*C2)) &&
                  (colpivot < (m->cols/2)-1)
               )
               {
                colpivot++;
               };

         jrpivotF(m, rowpivot, colpivot,rown_mns);
        }
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void jdpivotF(
PmF  m
)
{
int      rowpivot;

     for(rowpivot = (m->rows)-1; rowpivot  ; rowpivot--)
         jcpivotF(m, rowpivot,0);
}



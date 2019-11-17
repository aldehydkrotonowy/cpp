/* xglu.h                   freeware                   xhunga@tiscali.fr  */

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void LU_mF(
PmF m,
PmF mL,
PmF mU
)
{
fraction pivot;
fraction underpivot;
     int rowpivot;
     int rowunder;
     int col;

    zero_mF(  mL);
   copy_mF(m,mU);

         col = 0;
for(rowpivot = 0; rowpivot<(mU->rows); rowpivot++)
{
  pivot.n = *(mU->pb+rowpivot *mU->cols+col+1);
  pivot.d = *(mU->pb+rowpivot *mU->cols+col  );
  if(pivot.d<0){pivot.n*= -1;pivot.d *= -1;}
  if(!pivot.n)
    {
     printf("\n Pivot error - A pivot is Zero");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }

  *(mL->pb+rowpivot *mL->cols+col  )=*(mU->pb+rowpivot *mU->cols+col  );
  *(mL->pb+rowpivot *mL->cols+col+1)=*(mU->pb+rowpivot *mU->cols+col+1);

    mulrow_mF(mU,rowpivot,pivot);
  frowmini_F(mU,rowpivot);

  for(rowunder = rowpivot+1; rowunder<mU->rows; rowunder++)
     {

*(mL->pb+rowunder *mL->cols+col  )= (*(mU->pb+rowunder *mU->cols+col ));
*(mL->pb+rowunder *mL->cols+col+1)=  *(mU->pb+rowunder *mU->cols+col+1);

                     underpivot.n =-(*(mU->pb+rowunder *mU->cols+col ));
                     underpivot.d =  *(mU->pb+rowunder *mU->cols+col+1);

        addrow_mF(mU,underpivot,rowpivot,rowunder);
      frowmini_F(mU,                    rowunder);
     }
  col++;
  col++;
}
}


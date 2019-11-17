/* xpminf.h                     freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_mInF(
PmF mA)
{
 int i;
 int j;

 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   for ( j = 0 ; j < ((mA->rows)*C2) ; j++,j++)
    {
     printf(" %5.0f",*(mA->pb+i *mA->cols+j));
    }

   for ( j = ((mA->rows)*C2) ; j < mA->cols ; j++,j++)
    {
     printf(" %5.0f/%-5.0f",*(mA->pb+i *mA->cols+j  ),
                              *(mA->pb+i *mA->cols+j+1));
    }

  }
  printf("\n");
}



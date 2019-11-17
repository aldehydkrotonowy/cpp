/* xpmaple.h                    freeware                   xhunga@tiscali.fr  */


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_mpl(
PmF mA)
{
 int i;
 int j;

 printf(" := matrix(%d,%d,[", mA->rows, mA->cols/C2);

 for (   i = 0 ; i < mA->rows ;     i++)
  {
   printf("\n");
   for ( j = 0 ; j < mA->cols ; j++,j++)
    {
     printf("%6.0f/%-.0f,",*(mA->pb+i *mA->cols+j  ),
                             *(mA->pb+i *mA->cols+j+1));
    }
  }
  printf("\b \n");
  printf("]):");
  printf("\n");
}



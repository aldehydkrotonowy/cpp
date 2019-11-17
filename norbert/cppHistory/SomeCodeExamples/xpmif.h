/* xpmif.h                      freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_mIF(
PmF mA)
{
 int i;
 int j;

 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   for ( j = 0 ; j < mA->cols - 2 ; j++,j++)
    {
     printf(" %6.0f",*(mA->pb+i *mA->cols+j));
    }
     printf(" %6.0f/%-6.0f",*(mA->pb+i *mA->cols+j  ),
                              *(mA->pb+i *mA->cols+j+1));
  }
  printf("\n");
}



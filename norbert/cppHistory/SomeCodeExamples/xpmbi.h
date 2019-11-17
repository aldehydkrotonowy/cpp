/* xpmbi.h                      freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_mA_IDbI(
PmF mA)
{
 int i;
 int j;
 int n;

 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   n=0;
   for ( j = 0 ; j < mA->rows * C2; j++,j++)
    {
     printf(" %2.0f",*(mA->pb+i *mA->cols+j  ));
    }

   printf(" [");
   for ( j = mA->rows * C2 ; j < mA->cols; j++,j++)
    {
     n++;
     if(*(mA->pb+i *mA->cols+j))
     {
      if(*(mA->pb+i *mA->cols+j  )==1 &&
         *(mA->pb+i *mA->cols+j+1)==1)
        {
         printf("+b%d",n);
        }
      else if(*(mA->pb+i *mA->cols+j  )==-1 &&
              *(mA->pb+i *mA->cols+j+1)==1)
        {
         printf(" - b%d",n);
        }
      else if(*(mA->pb+i *mA->cols+j+1)==1)
        {
         printf("%+.0f b%d",*(mA->pb+i *mA->cols+j),n);
        }
      else
        {
         printf("%+.0f/%-.0f b%d",*(mA->pb+i *mA->cols+j  ),
                                    *(mA->pb+i *mA->cols+j+1),n);
        }
     }
    }
    printf("]");

  }

  printf("\n");
}


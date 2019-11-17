/* xpmbf.h                      freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_mA_IDbF(
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
     printf(" %2.0f/%-.0f",*(mA->pb+i *mA->cols+j  ),
                             *(mA->pb+i *mA->cols+j+1));
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

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_xbF(
PmF mA)
{
 int i;
 int j;
 int n;
 int m;

 m = 0;
 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   n=0;
   m++;
   printf(" x%d = ",m);
   for ( j = 0 ; j < mA->cols; j++,j++)
    {
     n++;
     if(*(mA->pb+i *mA->cols+j))
     {
      if(*(mA->pb+i *mA->cols+j  )==1 &&
         *(mA->pb+i *mA->cols+j+1)==1)
        {
         printf("+b%d ",n);
        }
      else if(*(mA->pb+i *mA->cols+j  )==-1 &&
              *(mA->pb+i *mA->cols+j+1)==1)
        {
         printf(" - b%d",n);
        }
      else if(*(mA->pb+i *mA->cols+j+1)==1)
        {
         printf("%+.0f b%d",*(mA->pb+i *mA->cols+j    ),n);
        }
      else
        {
         printf(" %+.0f/%-.0f b%d ",*(mA->pb+i *mA->cols+j  ),
                                      *(mA->pb+i *mA->cols+j+1),n);
        }
     }
    }
  }
  printf("\n");
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_minvAbF(
PmF mA)
{
 int i;
 int j;
 int n;

 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   n=0;
   for ( j = 0 ; j < mA->cols; j++,j++)
    {
     n++;

     {
      if(*(mA->pb+i *mA->cols+j    )==1 &&
         *(mA->pb+i *mA->cols+j+1)==1)
        {
         printf("       +b%d ",n);
        }
      else if(*(mA->pb+i *mA->cols+j  )==-1 &&
              *(mA->pb+i *mA->cols+j+1)==1)
        {
         printf("        - b%d",n);
        }
      else if(*(mA->pb+i *mA->cols+j+1)==1)
        {
         printf("    %+5.0f b%d",*(mA->pb+i *mA->cols+j),n);
        }
      else
        {
         printf(" %+5.0f/%-.0f b%d ",*(mA->pb+i *mA->cols+j  ),
                                       *(mA->pb+i *mA->cols+j+1),n);
        }
     }
    }
  }
  printf("\n");
}


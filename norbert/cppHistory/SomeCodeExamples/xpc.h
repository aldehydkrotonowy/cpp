/* xpc.h                        freeware                   xhunga@tiscali.fr  */

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void p_lgC(
PmF mA)
{
 int i;
 int j;

 printf("double pb[%d][%d*C2]=\n", mA->rows, mA->cols/C2);
 printf("{");

 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   for ( j = 0 ; j < mA->cols ; j++,j++)
    {
     printf(" %6.0f,%-.0f, ",*(mA->pb+i *mA->cols+j  ),
                               *(mA->pb+i *mA->cols+j+1));
    }
  }

 printf("\n};\n");
 printf(" mF m={%d,%d*C2,&pb[0][0]};\n",mA->rows,mA->cols/C2);

 printf("\n");
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_lgC4(
PmF mA)
{
 int i;
 int j;

 printf("double pb[%d][%d*C2]=\n", mA->rows, mA->cols/C2);
 printf("{");

 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   for ( j = 0 ; j < mA->cols ; j++,j++)
    {
     printf(" %4.0f,%-.0f, ",*(mA->pb+i *mA->cols+j  ),
                               *(mA->pb+i *mA->cols+j+1));
    }
  }

 printf("\n};\n");
 printf(" mF m={%d,%d*C2,&pb[0][0]};\n",mA->rows,mA->cols/C2);

 printf("\n");
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_lgC3(
PmF mA)
{
 int i;
 int j;

 printf("double pb[%d][%d*C2]=\n", mA->rows, mA->cols/C2);
 printf("{");

 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   for ( j = 0 ; j < mA->cols ; j++,j++)
    {
     printf(" %3.0f,%-.0f, ",*(mA->pb+i *mA->cols+j  ),
                               *(mA->pb+i *mA->cols+j+1));
    }
  }

 printf("\n};\n");
 printf(" mF m={%d,%d*C2,&pb[0][0]};\n",mA->rows,mA->cols/C2);

 printf("\n");
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_lgC2(
PmF mA)
{
 int i;
 int j;

 printf("double pb[%d][%d*C2]=\n", mA->rows, mA->cols/C2);
 printf("{");

 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   for ( j = 0 ; j < mA->cols ; j++,j++)
    {
     printf(" %2.0f,%-.0f,",*(mA->pb+i *mA->cols+j  ),
                             *(mA->pb+i *mA->cols+j+1) );
    }
  }

 printf("\n};\n");
 printf(" mF m={%d,%d*C2,&pb[0][0]};\n",mA->rows,mA->cols/C2);

 printf("\n");
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_lgC0(
PmF mA)
{
 int i;
 int j;

 printf("double pb[%d][%d*C2]=\n", mA->rows, mA->cols/C2);
 printf("{");

 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   for ( j = 0 ; j < mA->cols ; j++,j++)
    {
     printf(" %.0f,%-.0f, ",*(mA->pb+i *mA->cols+j  ),
                             *(mA->pb+i *mA->cols+j+1) );
    }
  }

 printf("\n};\n");
 printf(" mF m={%d,%d*C2,&pb[0][0]};\n",mA->rows,mA->cols/C2);

 printf("\n");
}


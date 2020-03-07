/* xpm.h                        freeware                   xhunga@tiscali.fr  */



/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_mF(
PmF mA)
{
 int i;
 int j;

 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   for ( j = 0 ; j < mA->cols ; j++,j++)
    {
     printf(" %6.0f/%-6.0f",*(mA->pb+i *mA->cols+j  ),
                              *(mA->pb+i *mA->cols+j+1));
    }
  }
  printf("\n");
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_mF0(
PmF mA)
{
 int i;
 int j;

 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   for ( j = 0 ; j < mA->cols ; j++,j++)
    {
     printf(" %.0f/%-.0f ",*(mA->pb+i *mA->cols+j  ),
                             *(mA->pb+i *mA->cols+j+1));
    }
  }
  printf("\n");
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_mF2(
PmF mA)
{
 int i;
 int j;

 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   for ( j = 0 ; j < mA->cols ; j++,j++)
    {
     printf(" %2.0f/%-2.0f",*(mA->pb+i *mA->cols+j  ),
                              *(mA->pb+i *mA->cols+j+1));
    }
  }
  printf("\n");
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_mF3(
PmF mA)
{
 int i;
 int j;

 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   for ( j = 0 ; j < mA->cols ; j++,j++)
    {
     printf(" %3.0f/%-3.0f",*(mA->pb+i *mA->cols+j  ),
                              *(mA->pb+i *mA->cols+j+1));
    }
  }
  printf("\n");
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_mF4(
PmF mA)
{
 int i;
 int j;

 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   for ( j = 0 ; j < mA->cols ; j++,j++)
    {
     printf(" %4.0f/%-4.0f",*(mA->pb+i *mA->cols+j  ),
                              *(mA->pb+i *mA->cols+j+1));
    }
  }
  printf("\n");
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_mF5(
PmF mA)
{
 int i;
 int j;

 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   for ( j = 0 ; j < mA->cols ; j++,j++)
    {
     printf(" %5.0f/%-5.0f",*(mA->pb+i *mA->cols+j  ),
                             *(mA->pb+i *mA->cols+j+1));
    }
  }
  printf("\n");
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_mF8(
PmF mA)
{
 int i;
 int j;

 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   for ( j = 0 ; j < mA->cols ; j++,j++)
    {
     printf(" %8.0f/%-8.0f",*(mA->pb+i *mA->cols+j  ),
                              *(mA->pb+i *mA->cols+j+1));
    }
  }
  printf("\n");
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_mF10(
PmF mA)
{
 int i;
 int j;

 for (i = 0 ; i < mA->rows ; i++)
  {
   printf("\n");
   for ( j = 0 ; j < mA->cols ; j++,j++)
    {
     printf(" %10.0f/%-10.0f",*(mA->pb+i *mA->cols+j  ),
                                *(mA->pb+i *mA->cols+j+1));
    }
  }
  printf("\n");
}




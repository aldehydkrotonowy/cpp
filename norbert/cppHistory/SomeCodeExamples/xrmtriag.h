/* xkmtriag.h                   freeware                   xhunga@tiscali.fr  */

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void mlowertriangF(
PmF m,
int n,
int d)
{
int i;
int j;
int row;

  if (m->rows * C2 != m->cols)
    {
     printf("\n id_mF() error - matrix must be square");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }
  for (   i = 0 ; i < m->rows ; i++)
    {
    for ( j = 0 ; j < m->cols ; j++,j++)
       {
       *(m->pb+i *m->cols+j ) = 0;
       *(m->pb+i *m->cols+j+1) = 1;

       if( (i*C2) >= j)
         {
          *(m->pb+i *m->cols+j  ) = rnd_I (n);
          *(m->pb+i *m->cols+j+1) = rndp_I(d);
         }
       }
    }

    for ( row = 0; row < m->rows ; row++)
     {
      frowmini_F(m,row);                                 /* a) fraction mini   */
     }
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void mlowertriangI(
PmF m,
int n)
{
int i;
int j;

  if (m->rows * C2 != m->cols)
    {
     printf("\n id_mF() error - matrix must be square");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }
  for (   i = 0 ; i < m->rows ; i++)
    {
    for ( j = 0 ; j < m->cols ; j++,j++)
       {
       *(m->pb+i *m->cols+j  ) = 0;
       *(m->pb+i *m->cols+j+1) = 1;

       if( (i*C2) >= j)
         {
          *(m->pb+i *m->cols+j) = rnd_I(n);
         }
       }
    }
}



/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void muppertriangF(
PmF m,
int n,
int d)
{
int i;
int j;
int row;

  if (m->rows * C2 != m->cols)
    {
     printf("\n id_mF() error - matrix must be square");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }
  for (   i = 0 ; i < m->rows ; i++)
    {
    for ( j = 0 ; j < m->cols ; j++,j++)
       {
       *(m->pb+i *m->cols+j  ) = 0;
       *(m->pb+i *m->cols+j+1) = 1;

       if( (i*C2) <= j)
         {
          *(m->pb+i *m->cols+j  ) = rnd_I (n);
          *(m->pb+i *m->cols+j+1) = rndp_I(d);
         }
       }
    }

    for ( row = 0; row < m->rows ; row++)
     {
      frowmini_F(m,row);                                 /* a) fraction mini   */
     }
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void muppertriangI(
PmF m,
int n)
{
int i;
int j;

  if (m->rows * C2 != m->cols)
    {
     printf("\n id_mF() error - matrix must be square");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }
  for (   i = 0 ; i < m->rows ; i++)
    {
    for ( j = 0 ; j < m->cols ; j++,j++)
       {
       *(m->pb+i *m->cols+j  ) = 0;
       *(m->pb+i *m->cols+j+1) = 1;

       if( (i*C2) <= j)
         {
          *(m->pb+i *m->cols+j) = rnd_I(n);
         }
       }
    }
}


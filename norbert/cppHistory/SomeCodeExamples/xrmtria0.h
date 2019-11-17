/* xkmtria0.h                   freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void mlowertriang0F(
PmF m,
int n,
int d)
{
int i;
int j;
int row0;
int row;

     row0 = rndp0_I(m->rows);

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
          *(m->pb+i *m->cols+j  ) = rnd_I (n);
          *(m->pb+i *m->cols+j+1) = rndp_I(d);

          if( i == row0 && j == (i*C2))
            {
            *(m->pb+i *m->cols+j)   = 0;
            *(m->pb+i *m->cols+j+1) = 1;
            }
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
void mlowertriang0I(
PmF m,
int n)
{
int i;
int j;
int row0;

     row0 = rndp0_I(m->rows);

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

          if( i == row0 && j == (i*C2))
            {
            *(m->pb+i *m->cols+j)     = 0;
            }
         }
       }
    }
}



/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void muppertriang0F(
PmF m,
int n,
int d)
{
int i;
int j;
int row0;
int row;

     row0 = rndp0_I(m->rows);

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
          *(m->pb+i *m->cols+j    ) = rnd_I (n);
          *(m->pb+i *m->cols+j+1) = rndp_I(d);

          if( i == row0 && j == (i*C2))
            {
            *(m->pb+i *m->cols+j)   = 0;
            *(m->pb+i *m->cols+j+1) = 1;
            }
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
void muppertriang0I(
PmF m,
int n)
{
int i;
int j;
int row0;

     row0 = rndp0_I(m->rows);

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

          if( i == row0 && j == (i*C2))
            {
            *(m->pb+i *m->cols+j)     = 0;
            }
         }
       }
    }
}


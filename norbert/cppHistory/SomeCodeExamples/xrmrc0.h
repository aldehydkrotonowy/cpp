/* xrmrc0.h                   freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void mrow0F(
PmF m,
int n,
int d)
{
int i;
int j;
int row0;
int row;

  row0 = rndp0_I(m->rows);

  for (   i = 0 ; i < m->rows ; i++)
    {
    for ( j = 0 ; j < m->cols ; j++,j++)
       {
        *(m->pb+i *m->cols+j  ) = rnd_I (n);
        *(m->pb+i *m->cols+j+1) = rndp_I(d);

        if(i==row0)
          {
          *(m->pb+i *m->cols+j)   = 0;
          *(m->pb+i *m->cols+j+1) = 1;
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
void mcol0F(
PmF m,
int n,
int d
)
{
int i;
int j;
int col0;
int row;

  col0 = rndp0_I(m->rows) * 2;

  for (   i = 0 ; i < m->rows ; i++)
    {
    for ( j = 0 ; j < m->cols ; j++,j++)
       {
        *(m->pb+i *m->cols+j  ) = rnd_I (n);
        *(m->pb+i *m->cols+j+1) = rndp_I(d);

        if(j==col0)
          {
          *(m->pb+i *m->cols+j)   = 0;
          *(m->pb+i *m->cols+j+1) = 1;
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
void mrow0I(
PmF m,
int n)
{
int i;
int j;
int row0;

  row0 = rndp0_I(m->rows);

  for (   i = 0 ; i < m->rows ; i++)
    {
    for ( j = 0 ; j < m->cols ; j++,j++)
       {
        *(m->pb+i *m->cols+j)   = rnd_I (n);
        *(m->pb+i *m->cols+j+1) = 1;

        if(i==row0)
          {
          *(m->pb+i *m->cols+j  ) = 0;
          *(m->pb+i *m->cols+j+1) = 1;
          }
       }
    }
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void mcol0I(
PmF m,
int n
)
{
int i;
int j;
int col0;

  col0 = rndp0_I(m->rows) * 2;

  for (   i = 0 ; i < m->rows ; i++)
    {
    for ( j = 0 ; j < m->cols ; j++,j++)
       {
        *(m->pb+i *m->cols+j  ) = rnd_I(n);
        *(m->pb+i *m->cols+j+1) = 1;

        if(j==col0)
          {
          *(m->pb+i *m->cols+j  ) = 0;
          *(m->pb+i *m->cols+j+1) = 1;
          }
       }
    }
}


/* xrndm.h                    freeware                    xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void rnd_mF(
PmF mA,
int n,
int d)
{
int      i;
int      j;
fraction f;

  for (   i = 0 ; i < mA->rows ; i++)
    for ( j = 0 ; j < mA->cols ; j++,j++)
       {
        f = rnd_F(n,d);

        *(mA->pb+i *mA->cols+j  ) = f.n;
        *(mA->pb+i *mA->cols+j+1) = f.d;
       }
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void rnd0_mF(
PmF mA,
int n,
int d)
{
int      i;
int      j;
fraction f;

  for (   i = 0 ; i < mA->rows ; i++)
    for ( j = 0 ; j < mA->cols ; j++,j++)
       {
        f = rnd0_F(n,d);

        *(mA->pb+i *mA->cols+j  ) = rnd0_I(n);
        *(mA->pb+i *mA->cols+j+1) = rndp_I(d);
       }
}



/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void rnd_mI(
PmF mA,
int n)
{
int i;
int j;

  for (   i = 0 ; i < mA->rows ; i++)
    for ( j = 0 ; j < mA->cols ; j++,j++)
       {
        *(mA->pb+i *mA->cols+j)   = rnd_I(n);
        *(mA->pb+i *mA->cols+j+1) = 1;
       }
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void rnd0_mI(
PmF mA,
int n)
{
int i;
int j;

  for (   i = 0 ; i < mA->rows ; i++)
    for ( j = 0 ; j < mA->cols ; j++,j++)
       {
        *(mA->pb+i *mA->cols+j)   = rnd0_I(n);
        *(mA->pb+i *mA->cols+j+1) = 1;
       }
}


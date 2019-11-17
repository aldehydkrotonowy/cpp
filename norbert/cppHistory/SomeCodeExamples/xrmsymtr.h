/* .h                    freeware                  xhunga@tiscali.fr  */

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void msymetricF(
PmF m,
int n,
int d)
{
int i;
int j;
int row;
double Tnumer;
double Tdenom;


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
        Tnumer = rnd_I (n);
        Tdenom = rndp_I(d);

       *(m->pb+i     *m->cols+j)         = Tnumer;
       *(m->pb+i     *m->cols+j+1)        = Tdenom;
       *(m->pb+(j/2) *m->cols+i*C2)   = Tnumer;
       *(m->pb+(j/2) *m->cols+i*C2+1) = Tdenom;

       }
    }

    for ( row = 0; row < m->rows ; row++)
     {
      frowmini_F(m,row);                                 /* a) fraction mini   */
     }
}

/* ------------------------------ FUNCTION ---------------------------- id_mF() */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void msymetricI(
PmF m,
int n)
{
int i;
int j;
double Tnumer;


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
        Tnumer = rnd_I (n);

       *(m->pb+i     *m->cols+j)          = Tnumer;
       *(m->pb+i     *m->cols+j+1)        = 1;
       *(m->pb+(j/2) *m->cols+i*C2)   = Tnumer;
       *(m->pb+(j/2) *m->cols+i*C2+1) = 1;

       }
    }
}


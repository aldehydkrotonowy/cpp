/* xcelrop.h               freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    : swap two rows in a matrix                                          */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void swaprow_mF(
PmF m,
int     row1,
int     row2)
{
  int    j;
  double t;

    for ( j=0 ; j<m->cols ; j++)
    {
                            t   = *(m->pb+row1 *m->cols+j);
      *(m->pb+row1 *m->cols+j ) = *(m->pb+row2 *m->cols+j);
      *(m->pb+row2 *m->cols+j ) =       t;
    }
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    : returns a copy of the matrix m in which row is muliply by scalar  */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void mulrow_mF(
PmF m,
int rown,
fraction f
)
{
 int j;
fraction fA;

 for( j=0 ; j<m->cols ; j++,j++)
 {
  fA.n =  *(m->pb+rown *m->cols+j  );
  fA.d =  *(m->pb+rown *m->cols+j+1);

  fA   = mul_F(fA,f);

          *(m->pb+rown *m->cols+j  ) = fA.n;
          *(m->pb+rown *m->cols+j+1) = fA.d;
 }
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    : returns a copy of the matrix m in which row r2 is                  */
/*         replaced  by (s*r1+r2)                                             */
/* -------------------------------------------------------------------------- */
void addrow_mF(
PmF  m,
fraction f,
int      row1,
int      row2

)
{
     int   j;
fraction fr1;
fraction fr2;


 for ( j = 0 ; j < m->cols ; j++,j++ )
    {
     fr1.n = *(m->pb+row1 *m->cols+j  );
     fr1.d = *(m->pb+row1 *m->cols+j+1);

     fr2.n = *(m->pb+row2 *m->cols+j  );
     fr2.d = *(m->pb+row2 *m->cols+j+1);

       fr2 =  add_F(fr2,mul_F(f,fr1));

             *(m->pb+row2 *m->cols+j  ) = fr2.n;
             *(m->pb+row2 *m->cols+j+1) = fr2.d;
    }
}




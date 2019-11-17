/* xcelrop.h               freeware                   xhunga@tiscali.fr  */

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :  swap two cols in a matrix                                         */
/*                                                                            */
/* -------------------------------------------------------------------------- */

void swapcol_mF(
PmF m,
int     col1,
int     col2)
{
  int    i;
  double tnumer;
  double tdenom;

for ( i = 0 ; i < m->rows ; i++)
 {
                                   tnumer = *(m->pb+i *m->cols+(col1*C2)  );
                                   tdenom = *(m->pb+i *m->cols+(col1*C2)+1);

  *(m->pb+i *m->cols+(col1*C2)  ) = *(m->pb+i *m->cols+(col2*C2)  );
  *(m->pb+i *m->cols+(col1*C2)+1) = *(m->pb+i *m->cols+(col2*C2)+1);

  *(m->pb+i *m->cols+(col2*C2)  ) = tnumer;
  *(m->pb+i *m->cols+(col2*C2)+1) = tdenom;
 }
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    : returns a copy of the matrix m in which column is muliply         */
/*         by scalar                                                          */
/* -------------------------------------------------------------------------- */
void mulcol_mF(
PmF m,
int coln,
fraction f
)
{
 int i;

 for( i = 0 ; i < m->rows ; i++)
 {
                 (*(m->pb+i *m->cols+coln*C2)) = \
       f.n * (*(m->pb+i *m->cols+coln*C2)) ;

                 (*(m->pb+i *m->cols+coln*C2+1)) = \
       f.d * (*(m->pb+i *m->cols+coln*C2+1)) ;
 }
}


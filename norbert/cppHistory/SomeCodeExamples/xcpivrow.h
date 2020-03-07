/* xcpivrow.h                   freeware                   xhunga@tiscali.fr  */

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    : All pivot = 1.                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void pivot1F(
PmF  m
)
{
     int i;
     int j;
fraction f;

 for (i = 0 ; i < m->rows ; i++)
  {
   for ( j = 0 ; j < m->cols; j++,j++)
    {
     if( (*(m->pb+i *m->cols+j)) )
       {
        f.n = *(m->pb+i *m->cols+j);
        f.d = *(m->pb+i *m->cols+j+1);

         f = inv_F(f);

          mulrow_mF(m,i,f);
        frowmini_F(m,i  );

        j = m->cols;
       }
    }
  }
}


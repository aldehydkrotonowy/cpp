/* xprowi.h                     freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void p_rI(
PmF m,
int rown)
{
  int j;

    printf("\n");
    for ( j = 0 ; j < m->cols ; j++ ,j++)
      {
         printf(" %6.0f",*(m->pb+rown *m->cols+j));
      }
    printf("\n");
}



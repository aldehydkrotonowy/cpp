/* xprow.h                    freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_rF(
PmF m,
int rown)
{
  int j;

    printf("\n");
    for ( j = 0 ; j < m->cols ; j++ ,j++)
      {
         printf(" %6.0f/%-6.0f",*(m->pb+rown *m->cols+j  ),
                                  *(m->pb+rown *m->cols+j+1));
      }
    printf("\n");
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_rF0(
PmF m,
int rown)
{
  int j;

    printf("\n");
    for ( j = 0 ; j < m->cols ; j++ ,j++)
      {
         printf(" %.0f/%-.0f ",*(m->pb+rown *m->cols+j  ),
                                 *(m->pb+rown *m->cols+j+1));
      }
    printf("\n");
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_rF3(
PmF m,
int rown)
{
  int j;

    printf("\n");
    for ( j = 0 ; j < m->cols ; j++ ,j++)
      {
         printf(" %3.0f/%-3.0f",*(m->pb+rown *m->cols+j  ),
                                  *(m->pb+rown *m->cols+j+1));
      }
    printf("\n");
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_rF4(
PmF m,
int rown)
{
  int j;

    printf("\n");
    for ( j = 0 ; j < m->cols ; j++ ,j++)
      {
         printf(" %4.0f/%-4.0f",*(m->pb+rown *m->cols+j  ),
                                  *(m->pb+rown *m->cols+j+1));
      }
    printf("\n");
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_rF10(
PmF m,
int rown)
{
  int j;

    printf("\n");
    for ( j = 0 ; j < m->cols ; j++ ,j++)
      {
         printf(" %10.0f/%-10.0f",*(m->pb+rown *m->cols+j  ),
                                    *(m->pb+rown *m->cols+j+1));
      }
    printf("\n");
}


/* xpcol.h                      freeware                   xhunga@tiscali.fr  */

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_cF(
PmF m,
int col)
{
  int i;

  for (i = 0 ; i < m->rows ; i++)
    {
     printf("\n");
     printf("%6.0f/%-6.0f",*(m->pb+i *m->cols+col*C2  ),
                           *(m->pb+i *m->cols+col*C2+1));
    }
  printf("\n");
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_cI(
PmF m,
int col)
{
  int i;

  for (i = 0 ; i < m->rows ; i++)
    {
     printf("\n");
     printf("%6.0f",*(m->pb+i *m->cols+col*C2));
    }
  printf("\n");
}



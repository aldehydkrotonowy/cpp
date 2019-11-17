/* xg_hfile.h                    freeware                  xhunga@tiscali.fr  */


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void gauss_mF(
PmF  m
)
{
          gdpivotF(m);
           pivot1F(m);
}


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void gaussjordan_mF(
PmF  m
)
{
          gdpivotF(m);
          jdpivotF(m);
           pivot1F(m);
}


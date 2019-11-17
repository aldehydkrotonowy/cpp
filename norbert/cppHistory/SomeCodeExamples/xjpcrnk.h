/* yspcrnk.h                   freeware                   xhunga@tiscali.fr  */

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* see   :   matrxf.zip                                                       */
/*           vectao.zip   simil5.c                                            */
/* -------------------------------------------------------------------------- */
int rank_mF(
PmF mA)
{
int rank = 0;
int    i;
int    j;

 for (i = 0 ; i < mA->rows ; i++)
  {
   for ( j = 0 ; j < mA->cols ; j++,j++)
    {
     if((*(mA->pb+i *mA->cols+j)))
       {
        rank++;
        j = mA->cols;
       }
    }
  }
  return(rank);
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* see   :   matrxf.zip                                                       */
/* -------------------------------------------------------------------------- */
int rowdim_mF(
PmF mA)
{
  return(mA->rows);
}


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* see   :   matrxf.zip                                                       */
/* -------------------------------------------------------------------------- */
int coldim_mF(
PmF mA)
{
  return(((mA->cols)/2));
}


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* see   :   matrxf.zip                                                       */
/*           vectao.zip   simil6.c                                            */
/* -------------------------------------------------------------------------- */
int nullity_mF(
PmF mA)
{
  return(coldim_mF(mA)-rank_mF(mA));
}

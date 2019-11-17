/* yd_dot.h                     freeware                   xhunga@tiscali.fr  */

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectab.zip   pythgF.c                                            */
/* -------------------------------------------------------------------------- */
void rndv_uDv0F(
PmF mu,
PmF mv,
    int n,
    int d)
{
     int i;
     int j;
fraction InnerProduct;

   rnd_mF(mu,n,d);
   rnd_mF(mv,n,d);

       i = mu->rows - 1;
       j = mu->cols - 2;

     *(mu->pb+i *mu->cols+j    ) = 0;
     *(mu->pb+i *mu->cols+j+1) = 1;

     *(mv->pb+i *mv->cols+j    ) = 1;
     *(mv->pb+i *mv->cols+j+1) = 1;

   InnerProduct = innerprod_F(mu,mv);

     *(mu->pb+i *mu->cols+j  ) = -InnerProduct.n;
     *(mu->pb+i *mu->cols+j+1) =  InnerProduct.d;
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectab.zip   pythgI.c                                            */
/* -------------------------------------------------------------------------- */
void rndv_uDv0I(
PmF mu,
PmF mv,
    int n)
{
     int i;
     int j;
fraction InnerProduct;

   rnd_mI(mu,n);
   rnd_mI(mv,n);

       i = mu->rows - 1;
       j = mu->cols - 2;

     *(mu->pb+i *mu->cols+j    ) = 0;
     *(mv->pb+i *mv->cols+j    ) = 1;

   InnerProduct = innerprod_F(mu,mv);

     *(mu->pb+i *mu->cols+j    ) = -InnerProduct.n;
}


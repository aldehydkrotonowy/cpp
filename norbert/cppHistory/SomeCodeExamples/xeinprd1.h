/* yd_dot.h                     freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   matrxh.zip                                                       */
/* -------------------------------------------------------------------------- */
fraction innerprod_uDotv_uv(
PmF mu,
PmF mv
)
{
fraction InnerProduct;

double pbuv [MXR][MXC*C2];mF muv ={MXR,MXC*C2,&pbuv [0][0]};

                 muv.rows =1;    muv.cols =1*C2;

  if (mu->rows != 1 ||
      mu->cols != mv->rows * C2 ||
      mv->cols != C2
     )
    {
     printf(" uDotv_uv() error.\n\n");

     printf(" u.rows = 1\n");
     printf(" u.cols = v.rows\n");
     printf(" v.cols = 1\n");

     printf("\nPress Return to continue\n");
     getchar();
     exit(1);
    }

  mul_mF(mu,mv,&muv);

  InnerProduct.n = *(muv.pb+0 *muv.cols+0  );
  InnerProduct.d = *(muv.pb+0 *muv.cols+1  );

  return(InnerProduct);
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   matrxh.zip                                                       */
/* -------------------------------------------------------------------------- */
fraction innerprod_uDotv_uvT(
PmF mu,
PmF mv
)
{
fraction InnerProduct             ;
int      n           =  mu->cols / C2;

double pbvT   [MXR][MXC*C2];mF mvT   ={MXR,MXC*C2,&pbvT   [0][0]};
double pbuvT  [MXR][MXC*C2];mF muvT  ={MXR,MXC*C2,&pbuvT  [0][0]};

                 mvT.rows =n;       mvT.cols =  C2;
                muvT.rows =1;      muvT.cols =  C2;

  if (mu->rows != mv->rows ||
      mu->cols != mv->cols ||
      mu->rows != 1
     )
    {
     printf(" uDotv_uvT() error.\n\n");

     printf(" u.rows = v.rows\n");
     printf(" u.cols = v.cols\n");
     printf(" u.rows = 1\n");

     printf("\nPress Return to continue\n");
     getchar();
     exit(1);
    }

  transpose_mF(mv,&mvT);

  mul_mF(mu,&mvT,&muvT);

  InnerProduct.n = *(muvT.pb+0 *muvT.cols+0  );
  InnerProduct.d = *(muvT.pb+0 *muvT.cols+1  );

  return(InnerProduct);
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   matrxh.zip                                                       */
/* -------------------------------------------------------------------------- */
fraction innerprod_uDotv_vTu(
PmF mu,
PmF mv
)
{
fraction InnerProduct             ;
int      n           =  mu->rows;

double pbvT   [MXR][MXC*C2];mF mvT   ={MXR,MXC*C2,&pbvT   [0][0]};
double pbvT_u [MXR][MXC*C2];mF mvT_u ={MXR,MXC*C2,&pbvT_u [0][0]};

                  mvT.rows =1;      mvT.cols =n*C2;
                mvT_u.rows =1;    mvT_u.cols =1*C2;

  if (mu->rows != mv->rows ||
      mu->cols != mv->cols ||
      mu->cols != C2
     )
    {
     printf(" uDotv_vTu() error.\n\n");

     printf(" u.rows = v.rows\n");
     printf(" u.cols = v.cols\n");
     printf(" u.cols = 1\n");

     printf("\nPress Return to continue\n");
     getchar();
     exit(1);
    }

  transpose_mF(mv,&mvT);

  mul_mF(&mvT,mu,&mvT_u);

  InnerProduct.n = *(mvT_u.pb+0 *mvT_u.cols+0  );
  InnerProduct.d = *(mvT_u.pb+0 *mvT_u.cols+1  );

  return(InnerProduct);
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   matrxh.zip                                                       */
/* -------------------------------------------------------------------------- */
fraction innerprod_uDotv_vu(
PmF mu,
PmF mv
)
{
fraction InnerProduct             ;

double pbvu [MXR][MXC*C2];mF mvu ={MXR,MXC*C2,&pbvu [0][0]};

                mvu.rows =1;    mvu.cols =1*C2;

  if (mu->rows * C2 != mv->cols ||
      mu->cols          != C2   ||
      mv->rows          != 1
     )
    {
     printf(" uDotv_vu() error.\n\n");

     printf(" u.rows = v.cols\n");
     printf(" u.cols = 1\n");
     printf(" v.rows = 1\n");

     printf("\nPress Return to continue\n");
     getchar();
     exit(1);
    }

  mul_mF(mv,mu,&mvu);

  InnerProduct.n = *(mvu.pb+0 *mvu.cols+0  );
  InnerProduct.d = *(mvu.pb+0 *mvu.cols+1  );

  return(InnerProduct);
}


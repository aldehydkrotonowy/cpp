/* xpgplt_.h                    freeware                   xhunga@tiscali.fr  */


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void gplt_vectcol3d(
   char filename[FILENAME],
PmF mA
)
{
FILE *fp;
  int j;

   fp = fopen(filename,"w");

   for (j = 0; j < mA->cols;j++,j++)
    {
     fprintf(fp,"  %.3f  %.3f  %.3f \n",
                 *(mA->pb+0 *mA->cols+j  )/
                 *(mA->pb+0 *mA->cols+j+1),
                 *(mA->pb+1 *mA->cols+j  )/
                 *(mA->pb+1 *mA->cols+j+1),
                 *(mA->pb+2 *mA->cols+j  )/
                 *(mA->pb+2 *mA->cols+j+1));
    }

  fclose(fp);
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void gplt_axyz3d(
   char filename[FILENAME]
)
{
FILE *fp;

   fp = fopen(filename,"w");

   fprintf(fp,"\n");
   fprintf(fp,"    9.000   0.000   0.000\n");
   fprintf(fp,"   -9.000   0.000   0.000\n");
   fprintf(fp,"    0.000   0.000   0.000\n");
   fprintf(fp,"    0.000   9.000   0.000\n");
   fprintf(fp,"    0.000  -9.000   0.000\n");
   fprintf(fp,"    0.000   0.000   0.000\n");
   fprintf(fp,"    0.000   0.000   9.000\n");
   fprintf(fp,"    0.000   0.000  -9.000 \n");
   fprintf(fp,"\n");

   fclose(fp);
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void gplt_xypln3d(
   char filename[FILENAME]
)
{
FILE *fp;

   fp = fopen(filename,"w");

   fprintf(fp,"\n");
   fprintf(fp,"        9.000   9.000   0.000\n");
   fprintf(fp,"        9.000  -9.000   0.000\n");
   fprintf(fp,"       -9.000  -9.000   0.000\n");
   fprintf(fp,"       -9.000   9.000   0.000\n");
   fprintf(fp,"        9.000   9.000   0.000\n");
   fprintf(fp,"\n");

   fclose(fp);
}


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void gplt_xzpln3d(
   char filename[FILENAME]
)
{
FILE *fp;

   fp = fopen(filename,"w");

   fprintf(fp,"\n");
   fprintf(fp,"        9.000   0.000   9.000\n");
   fprintf(fp,"        9.000   0.000  -9.000\n");
   fprintf(fp,"       -9.000   0.000  -9.000\n");
   fprintf(fp,"       -9.000   0.000   9.000\n");
   fprintf(fp,"        9.000   0.000   9.000\n");
   fprintf(fp,"\n");

   fclose(fp);
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void gplt_yzpln3d(
   char filename[FILENAME]
)
{
FILE *fp;

   fp = fopen(filename,"w");

   fprintf(fp,"\n");
   fprintf(fp,"        0.000   9.000   9.000\n");
   fprintf(fp,"        0.000   9.000  -9.000\n");
   fprintf(fp,"        0.000  -9.000  -9.000\n");
   fprintf(fp,"        0.000  -9.000   9.000\n");
   fprintf(fp,"        0.000   9.000   9.000\n");
   fprintf(fp,"\n");

   fclose(fp);
}

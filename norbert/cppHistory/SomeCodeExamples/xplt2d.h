/* xpgplt_.h                    freeware                   xhunga@tiscali.fr  */


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void gplt_vectrow2d(
   char filename[FILENAME],
PmF mA
)
{
FILE *fp;
  int j;
  int i;

   fp = fopen(filename,"w");

for (i=0; i < mA->rows; i++)
  {
   for (j = 0; j < mA->cols;j++,j++)
    {
     fprintf(fp,"  %.3f ",
                 *(mA->pb+i  *mA->cols+j  )/
                 *(mA->pb+i  *mA->cols+j+1));
    }
     fprintf(fp,"\n");
  }
  fclose(fp);
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void gplt_vectcol2d(
   char filename[FILENAME],
PmF mA
)
{
FILE *fp;
  int j;

   fp = fopen(filename,"w");

   for (j = 0; j < mA->cols;j++,j++)
    {
     fprintf(fp,"  %.3f  %.3f \n",
                 *(mA->pb+0 *mA->cols+j  )/
                 *(mA->pb+0 *mA->cols+j+1),
                 *(mA->pb+1 *mA->cols+j  )/
                 *(mA->pb+1 *mA->cols+j+1));
    }

  fclose(fp);
}


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void gplt_conicresultis(
   char filename[FILENAME],
PmF mOut)
{
FILE *fp;
 int i;

   fp = fopen(filename,"w");

    fprintf(fp,"\n");
    fprintf(fp," f(x,y) = ");
    i = 0;
    if((*(mOut->pb+i *mOut->cols+mOut->cols-2)))
    fprintf(fp,"%+.0f./%.0f. * x**2 ",
            *(mOut->pb+i *mOut->cols+mOut->cols-2),
            *(mOut->pb+i *mOut->cols+mOut->cols-1));
    i++;
    if((*(mOut->pb+i *mOut->cols+mOut->cols-2)))
    {
    fprintf(fp,"%+.0f./%.0f. * y**2 ",
            *(mOut->pb+i *mOut->cols+mOut->cols-2),
            *(mOut->pb+i *mOut->cols+mOut->cols-1));
    }

    i++;
    if((*(mOut->pb+i *mOut->cols+mOut->cols-2)))
    {
    fprintf(fp,"%+.0f./%.0f. * x ",
            *(mOut->pb+i *mOut->cols+mOut->cols-2),
            *(mOut->pb+i *mOut->cols+mOut->cols-1));
    }

    i++;
    if((*(mOut->pb+i *mOut->cols+mOut->cols-2)))
    {
    fprintf(fp,"%+.0f./%.0f. * y ",
            *(mOut->pb+i *mOut->cols+mOut->cols-2),
            *(mOut->pb+i *mOut->cols+mOut->cols-1));
    }

    i++;
    if((*(mOut->pb+i *mOut->cols+mOut->cols-2)))
    {
    fprintf(fp,"%+.0f./%.0f.\n",
            *(mOut->pb+i *mOut->cols+mOut->cols-2),
            *(mOut->pb+i *mOut->cols+mOut->cols-1));
    }

    fprintf(fp,"\n\n");
   fprintf(fp," set contour base\n");
   fprintf(fp," set cntrparam levels discrete 0.0\n");
   fprintf(fp," set nosurface\n");
   fprintf(fp," set term table\n");
   fprintf(fp," set out 'curve.dat'\n");
   fprintf(fp," splot f(x,y)\n");
   fprintf(fp," set term windows\n\n");
   fprintf(fp," plot \"curve.dat\" with lines, \"points\" with points\n");
   fprintf(fp," reset\n");

    fclose(fp);
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void gplt_polyresultis(
   char filename[FILENAME],
PmF mOut)
{
FILE *fp;
 int i;
 int p = mOut->rows;

  fp = fopen(filename,"w");

  fprintf(fp,"\n");
  fprintf(fp,"  f(x) = ");
  for (   i = 0 ; i < mOut->rows    ; i++)
   {
    fprintf(fp,"%+.0f./%.0f.*x**%d ",
            *(mOut->pb+i *mOut->cols+mOut->cols-2),
            *(mOut->pb+i *mOut->cols+mOut->cols-1),
            --p);
   }
   fprintf(fp,"  \n\n");
   fprintf(fp,"  plot f(x) with lines, \"points\" with points\n");
   fprintf(fp,"  reset\n");

   fclose(fp);
}


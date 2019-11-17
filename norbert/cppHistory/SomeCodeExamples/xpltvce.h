/* xpltve.h                     freeware                    xhunga@tiscali.fr */

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void gplt_axis(
   char filename[FILENAME]
)
{
FILE *fp;

   fp = fopen(filename,"w");

fprintf(fp,"#\n");
fprintf(fp,"# Worksheet for gp371w32.exe by xhunga bernard 06000 Nice France\n");
fprintf(fp,"#\n");
fprintf(fp,"set zeroaxis\n");
fprintf(fp,"set data style lines\n");
fprintf(fp,"#\n");
fprintf(fp,"#\n");
fprintf(fp,"#\n");
fprintf(fp,"set xrange [-9:9]\n");
fprintf(fp,"set yrange [-9.5:9.5]\n");
fprintf(fp,"#\n");
fprintf(fp,"#\n");
fprintf(fp,"#\n");
fprintf(fp,"  plot \"u\", \"v\"\n");
 
 fclose(fp);
}


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void gplt_a11xy(
   char filename[FILENAME]
)
{
FILE *fp;

   fp = fopen(filename,"w");

fprintf(fp,"#\n");
fprintf(fp,"# Worksheet for gp373w32.exe by xhunga bernard 06000 Nice France\n");
fprintf(fp,"#\n");
fprintf(fp,"set data style line\n");
fprintf(fp,"set xlabel   \"<x>\" \n");
fprintf(fp,"set ylabel   \"<y>\"\n");
fprintf(fp,"set zlabel   \"<z>\"\n");
fprintf(fp,"#\n");
fprintf(fp,"# view is 60 rot_x, 40 rot_z, 1 scale, 1 scale_z\n\n");

fprintf(fp,"   set view  60, 30, 1, 1\n\n");

fprintf(fp," splot \"u\" lt 3, \"v\" lt 1,");
fprintf(fp," \"u_v\" lt 0, \"v_u\" lt 0, \"axyz\" lt -1, \"plnxy\" lt -1\n");
fprintf(fp,"pause 1\n\n");

fprintf(fp,"   set view  70, 30, 1, 1\n");
fprintf(fp,"replot\n");
fprintf(fp,"pause 1\n\n");

fprintf(fp,"   set view  80, 30, 1, 1\n");
fprintf(fp,"replot\n");
fprintf(fp,"pause 1\n\n");

fprintf(fp,"   set view  90, 30, 1, 1\n");
fprintf(fp,"replot\n");
fprintf(fp,"pause 1\n\n");

fprintf(fp,"   set view 100, 30, 1, 1\n");
fprintf(fp,"replot\n");
fprintf(fp,"pause 1\n\n");

fprintf(fp,"   set view 110, 30, 1, 1\n");
fprintf(fp,"replot\n\n");

 fclose(fp);
}


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void gplt_b22xz(
   char filename[FILENAME]
)
{
FILE *fp;

   fp = fopen(filename,"w");

fprintf(fp,"#\n");
fprintf(fp,"# Worksheet for gp373w32.exe by xhunga bernard 06000 Nice France\n");
fprintf(fp,"#\n");
fprintf(fp,"set data style line\n");
fprintf(fp,"set xlabel   \"<x>\"\n");
fprintf(fp,"set ylabel   \"<y>\"\n");
fprintf(fp,"set zlabel   \"<z>\"\n");
fprintf(fp,"#\n");
fprintf(fp,"# view is 00 rot_x, 00 rot_z, 1 scale, 1 scale_z\n\n");

fprintf(fp,"   set view  00, 00, 1, 1\n\n");

fprintf(fp," splot \"u\" lt 3, \"v\" lt 1, \"u_v\" lt 0,");
fprintf(fp," \"v_u\" lt 0, \"axyz\" lt -1, \"plnxz\" lt -1\n");
fprintf(fp,"pause 1\n\n");

fprintf(fp,"   set view  10, 10, 1, 1\n");
fprintf(fp,"replot\n");
fprintf(fp,"pause 1\n\n");

fprintf(fp,"   set view  20, 20, 1, 1\n");
fprintf(fp,"replot\n");
fprintf(fp,"pause 1\n");

fprintf(fp,"   set view  30, 30, 1, 1\n");
fprintf(fp,"replot\n");
fprintf(fp,"pause 1\n\n");

fprintf(fp,"   set view  30, 40, 1, 1\n");
fprintf(fp,"replot\n");
fprintf(fp,"pause 1\n\n");

 fclose(fp);
}


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void gplt_c33yz(
   char filename[FILENAME]
)
{
FILE *fp;

   fp = fopen(filename,"w");

fprintf(fp,"#\n");
fprintf(fp,"# Worksheet for gp373w32.exe by xhunga bernard 06000 Nice France \n");
fprintf(fp,"#\n");
fprintf(fp,"set data style line\n");
fprintf(fp,"set xlabel   \"<x>\"\n");
fprintf(fp,"set ylabel   \"<y>\"\n");
fprintf(fp,"set zlabel   \"<z>\"\n");
fprintf(fp,"#\n");
fprintf(fp,"# view is 00 rot_x, 90 rot_z, 1 scale, 1 scale_z\n\n");

fprintf(fp,"   set view  00, 90, 1, 1\n\n");

fprintf(fp," splot \"u\" lt 3, \"v\" lt  1, \"u_v\" lt 0,");
fprintf(fp," \"v_u\" lt 0, \"axyz\" lt -1, \"plnyz\" lt -1 \n");
fprintf(fp,"pause 1\n\n");

fprintf(fp,"   set view  10, 80, 1, 1\n");
fprintf(fp,"replot\n");
fprintf(fp,"pause 1\n\n");

fprintf(fp,"   set view  20, 70, 1, 1\n");
fprintf(fp,"replot\n");
fprintf(fp,"pause 1\n\n");

fprintf(fp,"   set view  30, 60, 1, 1\n");
fprintf(fp,"replot\n");
fprintf(fp,"pause 1\n\n");

 fclose(fp);
}

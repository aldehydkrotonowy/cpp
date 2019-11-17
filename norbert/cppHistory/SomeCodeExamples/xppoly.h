/* xppoly.h                     freeware                   xhunga@tiscali.fr  */

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_polyI(
PmF mpoly)
{
   int i;
double coeff;
   int p0 = 1;
   int p = mpoly->rows;

printf("   ");

for (   i = 0 ; i < mpoly->rows    ; i++)
{
 coeff = *(mpoly->pb+i *mpoly->cols);

 --p;

 if(coeff)
 {
  p0 = 0;
  if(p)
  {
     if(     coeff == 1)
       {
        printf("+ x**%d  ",p);
       }
     else if(coeff == -1)
       {
        printf("- x**%d  ",p);
       }
     else
       {
        printf("%+.0fx**%d  ",coeff,p);
       }
  }
  else
  {
     printf("%+.0f  ",coeff);
  }
 }

}

   if(p0){printf("   0");}

   printf("\n");
}



/* yplnrI.h                     freeware                   xhunga@tiscali.fr  */


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectag.zip                                                       */
/* -------------------------------------------------------------------------- */
void printavn_w(
PmF mvn_w)
{
int i;
char constnt;

  printf("   ");
  for(i=0,constnt='a' ; i<((mvn_w->cols)/2); i++,constnt++)
     {
      if(i<((mvn_w->cols)/2)-1)
        {
         printf("%c v%d",constnt,i+1);
         if(i<((mvn_w->cols)/2)-2){printf(" + ");};
        }
      else
        {
         printf(" = w\n\n");
        }
     }
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectag.zip                                                       */
/* -------------------------------------------------------------------------- */
void printavn_wI(
PmF mvn_w)
{
int i;
char constnt;

    printf("   ");
    for(i = 0,  constnt = 'a'; i < (mvn_w->cols/2); i++, constnt++)
     {
      if(i < ((mvn_w->cols/2)-1))
        {
         printf("%c[",constnt);
         p_crowvI(mvn_w,i);
         printf("]");
         if(i <((mvn_w->cols/2)-2)){printf(" + ");}
        }
      else
        {
         printf(" = [");
         p_crowvI(mvn_w,i);
         printf("]\n\n");
        }
     }
}



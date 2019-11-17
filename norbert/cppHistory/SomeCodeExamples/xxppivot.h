/* xxppivot.h                   freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void pivotzeroF(fraction f)
{
  if(f.n == 0)
  {
     printf("\n The value of pivot is 0. ");
     printf("\n You must use another method.");
     printf("\n\n Press return to continue \n");
     getchar();
     exit(1);
  }
}


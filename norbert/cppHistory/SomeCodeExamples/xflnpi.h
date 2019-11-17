/* yplinea.h                    freeware                   xhunga@tiscali.fr  */


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectag.zip                                                       */
/* -------------------------------------------------------------------------- */
void printapn_q(
PmF mA)
{
int i;
char constnt;

  printf("   ");
  for(i=0,constnt='a' ; i<((mA->cols)/2); i++,constnt++)
     {
      if(i<((mA->cols)/2)-1)
        {
         printf("%c p%d",constnt,i+1);
         if(i<((mA->cols)/2)-2){printf("+");};
        }
      else
        {
         printf(" = q\n\n");
        }
     }
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectag.zip                                                       */
/* -------------------------------------------------------------------------- */
void p_pn_qI(
PmF mA)
{
int i;

    for(i = 0 ; i < (mA->cols/2); i++)
     {
      if(i < ((mA->cols/2)-1))
        {
         printf("   p%d = ",i+1);
         p_crowpI(mA,i);
         printf(" \n");
        }
    else{
         printf("\n    q = ");
         p_crowpI(mA,i);
         printf("\n\n");
        }
     }
}



/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectag.zip                                                       */
/* -------------------------------------------------------------------------- */
void printapn_qI(
PmF mA)
{
int i;
char constnt;

    for(i = 0,  constnt = 'a'; i < (mA->cols/2); i++, constnt++)
     {
      if(i < ((mA->cols/2)-1))
        {
         printf("   %c ( ",constnt);
         p_crowpI(mA,i);
         printf(")");
         if(i <((mA->cols/2)-2)){printf(" +\n");}
        }
    else{
         printf(" = \n\n       ");
         p_crowpI(mA,i);
         printf("\n\n");
        }
     }
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectag.zip                                                       */
/* -------------------------------------------------------------------------- */
void p_xpn_qI(
PmF mA,
PmF mAT)
{
int i;

    for(i = 0; i < (mA->cols/2); i++)
     {
      if(i<(mA->cols/2)-1)
        {
         if( (*(mAT->pb+i *mAT->cols +(mAT->cols - 2) )))
            {
             printf("   %+6.0f/%.0f*( ",
                     *(mAT->pb+i *mAT->cols+(mAT->cols-2) ),
                     *(mAT->pb+i *mAT->cols+(mAT->cols-1)));
             p_crowpI(mA,i);
             printf(")\n");
            }
         }
    else{
         printf(";\n    =          ");
         p_crowpI(mA,i);
         printf("\n\n");
        }
     }
}


/* ypmp.h                    freeware                   xhunga@tiscali.fr  */


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_crowpI(
PmF m,
int col)
{
  int i;

  for (i = 0 ; i < m->rows ; i++)
    {
     if(!i)
       {
        printf("%+.0f ",*(m->pb+i *m->cols+col*C2 ));
       }
     else if(i==1)
       {
        printf("%+.0f*x ",*(m->pb+i *m->cols+col*C2 ));
       }
     else
       {
     printf("%+.0f*x**%d ",*(m->pb+i *m->cols+col*C2 ),i);
       }
    }
}


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_crowpF(
PmF m,
int col)
{
  int i;

  for (i = 0 ; i < m->rows ; i++)
    {
     if(!i)
       {
        printf("%+.0f/%.0f ",*(m->pb+i *m->cols+ col*C2   ),
                               *(m->pb+i *m->cols+(col*C2)+1));
       }
     else if(i==1)
       {
        printf("%+.0f/%.0f * x ",*(m->pb+i *m->cols+ col*C2   ),
                                  *(m->pb+i *m->cols+(col*C2)+1));
       }
     else
       {
     printf("%+.0f/%.0f * x**%d ",*(m->pb+i *m->cols+ col*C2   ),
                                   *(m->pb+i *m->cols+(col*C2)+1),i);
       }
    }
}


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectag.zip                                                       */
/* -------------------------------------------------------------------------- */
void p_mpI(
PmF mA,
char strings[99])
{
int i;

    for(i=0 ;i<(mA->cols/2) ;i++)
     {
      if((mA->cols/2)==1)
        {
         printf("   %s = [",strings);
         p_crowpI(mA,i);
         printf("] \n");
        }
    else{
         printf("   %s%d = [",strings,i+1);
         p_crowpI(mA,i);
         printf("] \n");
        }
     }
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectag.zip                                                       */
/* -------------------------------------------------------------------------- */
void p_mpF(
PmF mA,
char strings[99])
{
int i;

    for(i=0 ;i<(mA->cols/2) ;i++)
     {
      if((mA->cols/2)==1)
        {
         printf("   %s = [",strings);
         p_crowpF(mA,i);
         printf("] \n");
        }
    else{
         printf("   %s%d = [",strings,i+1);
         p_crowpF(mA,i);
         printf("] \n");
        }
     }
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectag.zip                                                       */
/* -------------------------------------------------------------------------- */
void printq_s_pnI(
PmF mw_s,
PmF mvn)
{
int i;

for(i=0; i< ((mvn->cols)/2); i++)
 {
     printf("   %+6.0f/%.0f * [",*(mw_s->pb+i *mw_s->cols+0),
                                   *(mw_s->pb+i *mw_s->cols+1));
     p_crowpI(mvn,i);
     printf("]\n");
 }
  printf(";");
}





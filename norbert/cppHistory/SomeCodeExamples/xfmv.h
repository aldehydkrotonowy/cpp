/* yplnrI.h                     freeware                   xhunga@tiscali.fr  */

/* see   :   vectao.zip                                                       */
/*           vectao.zip   simil5.c                                            */

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_crowvI(
PmF m,
int col)
{
  int i;

  for (i = 0 ; i < m->rows ; i++)
    {
     printf("%.0f",*(m->pb+i *m->cols+(col*C2) ));
     if(i<(m->rows-1)){printf(",");}
    }
}


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void p_crowvF(
PmF m,
int col)
{
  int i;

  for (i = 0 ; i < m->rows ; i++)
    {
     printf("%.0f/%.0f",*(m->pb+i *m->cols+ col*C2   ),
                          *(m->pb+i *m->cols+(col*C2)+1));
     if(i<(m->rows-1)){printf(",");}
    }
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectag.zip  ws_VI.c    dpindpVI.c  lnear2VI.c  lnearVI.c         */
/* -------------------------------------------------------------------------- */
void p_mvI(
PmF mA,
char strings[99])
{
int i;

    for(i=0 ;i<(mA->cols/2) ;i++)
     {
      if((mA->cols/2)==1)
        {
         printf("   %s = [",strings);
         p_crowvI(mA,i);
         printf("] \n");
        }
    else{
         printf("   %s%d = [",strings,i+1);
         p_crowvI(mA,i);
         printf("] \n");
        }
     }
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectag.zip                                                       */
/* -------------------------------------------------------------------------- */
void p_mvF(
PmF mA,
char strings[99])
{
int i;

    for(i=0 ;i<(mA->cols/2) ;i++)
     {
      if((mA->cols/2)==1)
        {
         printf("   %s = [",strings);
         p_crowvF(mA,i);
         printf("] \n");
        }
    else{
         printf("   %s%d = [",strings,i+1);
         p_crowvF(mA,i);
         printf("] \n");
        }
     }
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectag.zip                                                       */
/* -------------------------------------------------------------------------- */
void printw_s_vnI(
PmF mw_s,
PmF mvn)
{
int i;

printf("   ");
for(i=0; i< ((mvn->cols)/2); i++)
 {
     printf(" %+.0f/%.0f*[",*(mw_s->pb+i *mw_s->cols+0),
                               *(mw_s->pb+i *mw_s->cols+1));
     p_crowvI(mvn,i);
     printf("]");
 }
  printf(";");
}





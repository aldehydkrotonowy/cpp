/* xxnpoly.h                    freeware                   xhunga@tiscali.fr  */

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void mofpoly(

PmF mpxy,
PmF mOut)
{
   int i;
   int j;
   int p;

  for (   i = 0 ; i < mpxy->rows    ; i++)
   {
    p = mpxy->rows;
    for ( j = 0 ; j < mOut->cols-2; j++,j++)
     {
          *(mOut->pb+i *mOut->cols+j  )        = \
      pow(*(mpxy->pb+i *mpxy->cols    ),--p);
          *(mOut->pb+i *mOut->cols+j+1)        = \
      pow(*(mpxy->pb+i *mpxy->cols  +1),  p);
     }
     *(mOut->pb+i *mOut->cols+j  )  = \
     *(mpxy->pb+i *mpxy->cols  +2);
     *(mOut->pb+i *mOut->cols+j+1)  = \
     *(mpxy->pb+i *mpxy->cols  +3);
    }
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void polyresultis(
PmF mOut)
{
int i;
int p = mOut->rows;

  printf("  y = ");
  for (   i = 0 ; i < mOut->rows    ; i++)
   {
    printf("(%.0f/%.0f)x**%d",
            *(mOut->pb+i *mOut->cols+mOut->cols-2),
            *(mOut->pb+i *mOut->cols+mOut->cols-1),
            --p);
    if(p){printf("+");}
   }
   printf("\n");
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void calculate_y(
PmF mOut,
fraction fpoint)
{
int i;
int p = mOut->rows;
fraction fT;
fraction fT2;

fT2.n = 0;
fT2.d = 1;

  for (   i = 0 ; i < mOut->rows    ; i++)
   {
    fT.n = *(mOut->pb+i *mOut->cols+mOut->cols-2) * \
                     pow(fpoint.n,--p);
    fT.d = *(mOut->pb+i *mOut->cols+mOut->cols-1) * \
                     pow(fpoint.d,  p);

    fT2 = add_F(fT2,fT);
   }

   printf(" With x =  %3.0f/%.0f,       y = %3.0f/%.0f \n",
           fpoint.n,fpoint.d,
              fT2.n,   fT2.d);
}


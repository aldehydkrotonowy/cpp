/* xxconic.h                    freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void mofconicA(

PmF mpxy,
PmF mOut)
{
   int i;
   int j;

    i = 0 ;
    j = 0 ;
  *(mOut->pb+i *mOut->cols+j    )        = 1;
  *(mOut->pb+i *mOut->cols+j+1)        = 1;

  for (   j = 2 ; j < mOut->cols -2    ; j++, j++)
  {
   *(mOut->pb+i *mOut->cols+j    )        = 0;
   *(mOut->pb+i *mOut->cols+j+1)        = 1;
  }

  *(mOut->pb+i *mOut->cols+j    )        =  1;
  *(mOut->pb+i *mOut->cols+j+1)        =  1;

  for (   i = 1 ; i < mOut->rows    ; i++)
   {      j = 0 ;

                                                                      /* x**2 */
          *(mOut->pb+i *mOut->cols+j    )        = \
      pow(*(mpxy->pb+(i-1)  *mpxy->cols        ),2);
          *(mOut->pb+i *mOut->cols+j+1)        = \
      pow(*(mpxy->pb+(i-1)  *mpxy->cols    +1),2);

            j++; j++;                                                 /* y**2 */
          *(mOut->pb+i *mOut->cols+j    )        = \
      pow(*(mpxy->pb+(i-1)  *mpxy->cols +2      ),2);
          *(mOut->pb+i *mOut->cols+j+1)        = \
      pow(*(mpxy->pb+(i-1)  *mpxy->cols+2  +1),2);

            j++; j++;                                                 /* x    */
          *(mOut->pb+i *mOut->cols+j    )        = \
          *(mpxy->pb+(i-1)  *mpxy->cols        );
          *(mOut->pb+i *mOut->cols+j+1)        = \
          *(mpxy->pb+(i-1)  *mpxy->cols    +1);

            j++; j++;                                                 /* y    */
          *(mOut->pb+i *mOut->cols+j    )        = \
          *(mpxy->pb+(i-1)  *mpxy->cols +2      );
          *(mOut->pb+i *mOut->cols+j+1)        = \
          *(mpxy->pb+(i-1)  *mpxy->cols+2  +1);

            j++; j++;
          *(mOut->pb+i *mOut->cols+j    )        =  1;
          *(mOut->pb+i *mOut->cols+j+1)        =  1;

            j++; j++;
          *(mOut->pb+i *mOut->cols+j    )        =  0;
          *(mOut->pb+i *mOut->cols+j+1)        =  1;
    }
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void mofconicE(

PmF mpxy,
PmF mOut)
{
   int i;
   int j;

  for (   i = 0 ; i < mOut->rows -1  ; i++)
   {      j = 0 ;
                                                                      /* x**2 */
          *(mOut->pb+i *mOut->cols+j    )        = \
      pow(*(mpxy->pb+(i)  *mpxy->cols        ),2);
          *(mOut->pb+i *mOut->cols+j+1)        = \
      pow(*(mpxy->pb+(i)  *mpxy->cols    +1),2);

            j++; j++;                                                 /* y**2 */
          *(mOut->pb+i *mOut->cols+j    )        = \
      pow(*(mpxy->pb+(i)  *mpxy->cols +2      ),2);
          *(mOut->pb+i *mOut->cols+j+1)        = \
      pow(*(mpxy->pb+(i)  *mpxy->cols+2  +1),2);
                             
            j++; j++;                                                 /* x    */
          *(mOut->pb+i *mOut->cols+j    )        = \
          *(mpxy->pb+(i)  *mpxy->cols        );
          *(mOut->pb+i *mOut->cols+j+1)        = \
          *(mpxy->pb+(i)  *mpxy->cols    +1);

            j++; j++;                                                 /* y    */
          *(mOut->pb+i *mOut->cols+j    )        = \
          *(mpxy->pb+(i)  *mpxy->cols +2      );
          *(mOut->pb+i *mOut->cols+j+1)        = \
          *(mpxy->pb+(i)  *mpxy->cols+2  +1);

            j++; j++;
          *(mOut->pb+i *mOut->cols+j    )        =  1;
          *(mOut->pb+i *mOut->cols+j+1)        =  1;

            j++; j++;
          *(mOut->pb+i *mOut->cols+j    )        =  0;
          *(mOut->pb+i *mOut->cols+j+1)        =  1;
    }


    i = mOut->rows -1;

  for (   j = 0 ; j < mOut->cols - 4    ; j++, j++)
  {
   *(mOut->pb+i *mOut->cols+j    )        = 0;
   *(mOut->pb+i *mOut->cols+j+1)        = 1;
  }

  *(mOut->pb+i *mOut->cols+j    )        =  1;
  *(mOut->pb+i *mOut->cols+j+1)        =  1;

    j++, j++;
  *(mOut->pb+i *mOut->cols+j    )        =  1;
  *(mOut->pb+i *mOut->cols+j+1)        =  1;

}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void mofcircle(

PmF mpxy,
PmF mOut)
{
   int i;
   int j;

    i = 0 ;
    j = 0 ;
  *(mOut->pb+i *mOut->cols+j    )        = 1;
  *(mOut->pb+i *mOut->cols+j+1)        = 1;

  for (   j = 2 ; j < mOut->cols -2    ; j++, j++)
  {
   *(mOut->pb+i *mOut->cols+j    )        = 0;
   *(mOut->pb+i *mOut->cols+j+1)        = 1;
  }

  *(mOut->pb+i *mOut->cols+j    )        =  1;
  *(mOut->pb+i *mOut->cols+j+1)        =  1;

    i = 1 ;
    j = 0 ;
  *(mOut->pb+i *mOut->cols+j    )        = 0;                 /*a y**2*/
  *(mOut->pb+i *mOut->cols+j+1)        = 1;

    j++, j++;
  *(mOut->pb+i *mOut->cols+j    )        = 1;
  *(mOut->pb+i *mOut->cols+j+1)        = 1;

  for (   j = 4 ; j < mOut->cols -2    ; j++, j++)
  {
   *(mOut->pb+i *mOut->cols+j    )        = 0;
   *(mOut->pb+i *mOut->cols+j+1)        = 1;
  }

  *(mOut->pb+i *mOut->cols+j    )        =  1;
  *(mOut->pb+i *mOut->cols+j+1)        =  1;

  for (   i = 2 ; i < mOut->rows    ; i++)
   {      j = 0 ;

          *(mOut->pb+i *mOut->cols+j    )        = \
      pow(*(mpxy->pb+(i-2)  *mpxy->cols        ),2);
          *(mOut->pb+i *mOut->cols+j+1)        = \
      pow(*(mpxy->pb+(i-2)  *mpxy->cols    +1),2);

            j++; j++;                                                 /* y**2 */
          *(mOut->pb+i *mOut->cols+j    )        = \
      pow(*(mpxy->pb+(i-2)  *mpxy->cols +2      ),2);
          *(mOut->pb+i *mOut->cols+j+1)        = \
      pow(*(mpxy->pb+(i-2)  *mpxy->cols+2  +1),2);

            j++; j++;                                                 /* x    */
          *(mOut->pb+i *mOut->cols+j    )        = \
          *(mpxy->pb+(i-2)  *mpxy->cols        );
          *(mOut->pb+i *mOut->cols+j+1)        = \
          *(mpxy->pb+(i-2)  *mpxy->cols    +1);

            j++; j++;                                                 /* y    */
          *(mOut->pb+i *mOut->cols+j    )      = \
          *(mpxy->pb+(i-2)  *mpxy->cols +2      );
          *(mOut->pb+i *mOut->cols+j+1)        = \
          *(mpxy->pb+(i-2)  *mpxy->cols+2  +1);

            j++; j++;
          *(mOut->pb+i *mOut->cols+j    )      =  1;
          *(mOut->pb+i *mOut->cols+j+1)        =  1;

            j++; j++;
          *(mOut->pb+i *mOut->cols+j    )      =  0;
          *(mOut->pb+i *mOut->cols+j+1)        =  1;
    }
}



/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void conicresultis(
PmF mOut)
{
int i;

    i = 0;
    if((*(mOut->pb+i *mOut->cols+mOut->cols-2)))
    printf("   %+.0f/%.0f x**2 ",
            *(mOut->pb+i *mOut->cols+mOut->cols-2),
            *(mOut->pb+i *mOut->cols+mOut->cols-1));
    i++;
    if((*(mOut->pb+i *mOut->cols+mOut->cols-2)))
    {
    printf("%+.0f/%.0f y**2 ",
            *(mOut->pb+i *mOut->cols+mOut->cols-2),
            *(mOut->pb+i *mOut->cols+mOut->cols-1));
    }

    i++;
    if((*(mOut->pb+i *mOut->cols+mOut->cols-2)))
    {
    printf("%+.0f/%.0f x ",
            *(mOut->pb+i *mOut->cols+mOut->cols-2),
            *(mOut->pb+i *mOut->cols+mOut->cols-1));
    }

    i++;
    if((*(mOut->pb+i *mOut->cols+mOut->cols-2)))
    {
    printf("%+.0f/%.0f y ",
            *(mOut->pb+i *mOut->cols+mOut->cols-2),
            *(mOut->pb+i *mOut->cols+mOut->cols-1));
    }

    i++;
    if((*(mOut->pb+i *mOut->cols+mOut->cols-2)))
    {
    printf("%+.0f/%.0f ",
            *(mOut->pb+i *mOut->cols+mOut->cols-2),
            *(mOut->pb+i *mOut->cols+mOut->cols-1));
    }

    printf(" = 0 ");

   printf("\n");
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void calculate_conic(
PmF mOut,
fraction fx,
fraction fy)
{
int i;
fraction fT;
fraction fT2;

fT2.n = 0;
fT2.d = 1;

    i = 0;

    fT.n = *(mOut->pb+i *mOut->cols+mOut->cols-2) * \
                     pow(fx.n,2);
    fT.d = *(mOut->pb+i *mOut->cols+mOut->cols-1) * \
                     pow(fx.d,2);

    fT2 = add_F(fT2,fT);

    i++;

    fT.n = *(mOut->pb+i *mOut->cols+mOut->cols-2) * \
                     pow(fy.n,2);
    fT.d = *(mOut->pb+i *mOut->cols+mOut->cols-1) * \
                     pow(fy.d,2);

    fT2 = add_F(fT2,fT);

    i++;
    fT.n = *(mOut->pb+i *mOut->cols+mOut->cols-2) * fx.n;
    fT.d = *(mOut->pb+i *mOut->cols+mOut->cols-1) * fx.d;

    fT2 = add_F(fT2,fT);

    i++;
    fT.n = *(mOut->pb+i *mOut->cols+mOut->cols-2) * fy.n;
    fT.d = *(mOut->pb+i *mOut->cols+mOut->cols-1) * fy.d;

    fT2 = add_F(fT2,fT);

    i++;
    fT.n = *(mOut->pb+i *mOut->cols+mOut->cols-2);
    fT.d = *(mOut->pb+i *mOut->cols+mOut->cols-1);

    fT2 = add_F(fT2,fT);

   printf(" With x = %2.0f/%.0f and  y = %2.0f/%.0f ",
           fx.n,fx.d,
           fy.n,fy.d);

   printf("  a x**2+b y**2+c x+d y+e = %3.0f/%.0f \n",
           fT2.n,fT2.d);

}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
void calculate_circle(
PmF mOut,
fraction fx,
fraction fy)
{
int i;
fraction fT;
fraction fT2;

fT2.n = 0;
fT2.d = 1;

    i = 0;

    fT.n = *(mOut->pb+i *mOut->cols+mOut->cols-2) * \
                     pow(fx.n,2);
    fT.d = *(mOut->pb+i *mOut->cols+mOut->cols-1) * \
                     pow(fx.d,2);

    fT2 = add_F(fT2,fT);

    i++;

    fT.n = *(mOut->pb+i *mOut->cols+mOut->cols-2) * \
                     pow(fy.n,2);
    fT.d = *(mOut->pb+i *mOut->cols+mOut->cols-1) * \
                     pow(fy.d,2);

    fT2 = add_F(fT2,fT);

    i++;
    fT.n = *(mOut->pb+i *mOut->cols+mOut->cols-2) * fx.n;
    fT.d = *(mOut->pb+i *mOut->cols+mOut->cols-1) * fx.d;

    fT2 = add_F(fT2,fT);

    i++;
    fT.n = *(mOut->pb+i *mOut->cols+mOut->cols-2) * fy.n;
    fT.d = *(mOut->pb+i *mOut->cols+mOut->cols-1) * fy.d;

    fT2 = add_F(fT2,fT);

    i++;
    fT.n = *(mOut->pb+i *mOut->cols+mOut->cols-2);
    fT.d = *(mOut->pb+i *mOut->cols+mOut->cols-1);

    fT2 = add_F(fT2,fT);

   printf(" With x = %2.0f/%.0f and  y = %2.0f/%.0f ",
           fx.n,fx.d,
           fy.n,fy.d);

   printf("  a x**2 + a y**2 + bx + cy + d = %3.0f/%.0f \n",
           fT2.n,fT2.d);

}



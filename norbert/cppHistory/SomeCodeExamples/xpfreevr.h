/* xp_freev.h                    freeware                  xhunga@tiscali.fr  */

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void p_freevariable(
PmF mA)
{
 int i;
 int j;
 int    m = 0;
 int zero;
char c;


for (i = 0 ; i < mA->rows ; i++)
{
    c = 't' - ((mA->rows-1)*C2);
 zero = -1;
 m++;
 printf("\n");
 printf(" x%d = ",m);

 for ( j = 0; j < mA->cols; j++,j++)
 {
  ++c;
  if(*(mA->pb + i *mA->cols + j))
    {
     zero++;
     if(j > mA->rows*C2)
       {
        if(*(mA->pb+i *mA->cols+j)== 1 && *(mA->pb+i *mA->cols+j+1)==1)
          {printf(" +%c ",c);}
   else if(*(mA->pb+i *mA->cols+j)==-1 && *(mA->pb+i *mA->cols+j+1)==1)
          {printf(" -%c ",c);}
   else if(*(mA->pb+i *mA->cols+j+1)==1)
          {printf(" %+.0f %c ",*(mA->pb+i *mA->cols+j),c);}
   else   {printf(" %+.0f/%-.0f %c ",*(mA->pb+i *mA->cols+j),
                                       *(mA->pb+i *mA->cols+j+1),c);}
       }

        if(j == mA->rows*C2)
        {
         if(*(mA->pb+i *mA->cols+j+1)==1)
           {printf(" %+.0f",*(mA->pb+i *mA->cols+j));}
   else    {printf(" %+.0f/%-.0f",*(mA->pb+i *mA->cols+j    ),
                                    *(mA->pb+i *mA->cols+j+1));}
        }
    }
 }
 if(!zero){printf(" 0");};
}
printf("\n");
}


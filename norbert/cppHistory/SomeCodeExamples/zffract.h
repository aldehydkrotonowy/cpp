/* xbfract.h                    free ware                  xhunga@tiscali.fr  */


/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
double modf_F(
fraction f
)
{
 double x;

 modf((f.n/f.d),&x);

 return(x);
}

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */
/* -------------------------------------------------------------------------- */
fraction mini_F(
fraction f
)
{
   double t;
 fraction ft;

/*
  if( ((f.n) > 1000000000000000) && ( ((f.n)-(f.d)) < 2 ))
       {f.n = 1;
        f.d = 1;}
*/
  if(!f.n){f.d = 1;}

  if(f.n == f.d)
    {f.n = 1;
     f.d = 1;}

 ft.n = fabs(f.n);
 ft.d = fabs(f.d);

 while (ft.n>0)
 {
  if(ft.n<ft.d)
  {
     t=ft.n;
   ft.n=ft.d;
   ft.d=t;
   }
 ft.n= ft.n-ft.d*modf_F(ft);
 }

 f.n/=ft.d;
 f.d/=ft.d;

 if(f.d < 0 )
{
 f.n = -1 * (f.n);
 f.d = -1 * (f.d);
}

if(!f.n){f.d = 1;}

 return(f);
}

/* ------------------------------ FUNCTION --------------------------- addf() */
/* -------------------------------------------------------------------------- */
fraction add_F(
fraction f1,
fraction f2)
{
         f1 = mini_F(f1);
         f2 = mini_F(f2);

   f1.n = (f1.n)*(f2.d) + (f2.n)*(f1.d);
   f1.d = (f1.d)*(f2.d);

  return(mini_F(f1));
}

/* ------------------------------ FUNCTION --------------------------- sub_F() */
/* -------------------------------------------------------------------------- */
fraction sub_F(
fraction f1,
fraction f2)
{
         f1 = mini_F(f1);
         f2 = mini_F(f2);

   f1.n = (f1.n)*(f2.d) - (f2.n)*(f1.d);
   f1.d = (f1.d)*(f2.d);

  return(mini_F(f1));
}

/* ------------------------------ FUNCTION --------------------------- mul_F() */
/* -------------------------------------------------------------------------- */
fraction mul_F(
fraction f1,
fraction f2)
{
         f1 = mini_F(f1);
         f2 = mini_F(f2);

   f1.n = (f1.n)*(f2.n);
   f1.d = (f1.d)*(f2.d);

  return(mini_F(f1));
}

/* ------------------------------ FUNCTION --------------------------- div_F() */
/* -------------------------------------------------------------------------- */
fraction div_F(
fraction f1,
fraction f2)
{

  if (!f2.n)
    {
     printf("\n div_F() error - 0 no inverse");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }
         f1 = mini_F(f1);
         f2 = mini_F(f2);

   f1.n = (f1.n)*(f2.d);
   f1.d = (f1.d)*(f2.n);

  return(mini_F(f1));
}


/* ------------------------------ FUNCTION --------------------------- inv_F() */
/* -------------------------------------------------------------------------- */
fraction inv_F(
fraction f)
{
 double T;

  f = mini_F(f);

  if (!f.n)
    {
     printf("\n inv_F() error - 0 no inverse");
     printf("\n Press return to continue");
     getchar();
     exit(1);
    }

      T = f.n;
    f.n = f.d;
    f.d = T;

  return(f);
}





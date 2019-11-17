/* xkrndf.h                   freeware                    xhunga@tiscali.fr  */

/* ------------------------------ FUNCTION --------------------------- rnd_F() */
/*Call :   time_t t;                                                          */
/*       fraction f;                                                          */
/*                                                                            */
/*        srand(time(&t));                                                    */
/*           f = rnd_F(9,9);                                                   */
/* -------------------------------------------------------------------------- */
fraction rnd_F(
int maxNumer,
int maxDenom)
{
fraction f;

    f.n  = rnd_I (maxNumer);
    f.d  = rndp_I(maxDenom);

 return(mini_F(f));
}

/* ------------------------------ FUNCTION --------------------------- rnd_F() */
/*Call :   time_t t;                                                          */
/*       fraction f;                                                          */
/*                                                                            */
/*        srand(time(&t));                                                    */
/*           f = rnd_F(9,9);                                                   */
/* -------------------------------------------------------------------------- */
fraction rnd0_F(
int maxNumer,
int maxDenom)
{
fraction f;

    f.n  = rnd0_I(maxNumer);
    f.d  = rndp_I(maxDenom);

 return(mini_F(f));
}


/* ------------------------------ FUNCTION --------------------------- rnd_F() */
/*Call :   time_t t;                                                          */
/*       fraction f;                                                          */
/*                                                                            */
/*        srand(time(&t));                                                    */
/*           f = rnd_F(9,9);                                                   */
/* -------------------------------------------------------------------------- */
fraction rnd_FI(
int maxNumer
)
{
fraction f;

    f.n  = rnd_I (maxNumer);
    f.d  = 1;

 return(f);
}



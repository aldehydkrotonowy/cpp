/* xdet2.h                      freeware                   xhunga@tiscali.fr  */


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
fraction det_F(
PmF mA)
{
fraction deter;
fraction deterT;

  deter  = detFbasic    (mA);

  deterT = detFbasicT(mA);
  if(fabs(deter.n) > fabs(deterT.n)){deter.n = deterT.n;
                                             deter.d = deterT.d;}

  deterT = detFnumerMini(mA);
  if(fabs(deter.n) > fabs(deterT.n)){deter.n = deterT.n;
                                             deter.d = deterT.d;}

  deterT = detFnumerMiniT(mA);
  if(fabs(deter.n) > fabs(deterT.n)){deter.n = deterT.n;
                                             deter.d = deterT.d;}

  deterT = detFdenomMini(mA);
  if(fabs(deter.n) > fabs(deterT.n)){deter.n = deterT.n;
                                             deter.d = deterT.d;}

  deterT = detFdenomMiniT(mA);
  if(fabs(deter.n) > fabs(deterT.n)){deter.n = deterT.n;
                                             deter.d = deterT.d;}

 return(deter);
}




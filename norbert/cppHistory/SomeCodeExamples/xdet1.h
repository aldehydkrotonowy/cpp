/* xdet1.h                      freeware                   xhunga@tiscali.fr  */



/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
fraction detFbasic(
PmF mA)
{
      int row1;
      int row2;
      int n;
   double coefnulldoNothing = 1;
 fraction deter;

double pbAT [MXR][MXC*C2];mF mAT ={MXR,MXC*C2,&pbAT [0][0]};

 n = mA->rows;
                mAT.rows=n       ;
                mAT.cols=n*C2;

 deter.n = 1;
 deter.d = 1;

 copy_mF(mA,&mAT);

/*--------------------------------------------------------------------  gauss */
for (row1 = 0 ; row1 < mAT.rows - 1 ; row1++)
{
   deter.n *= pivotntzeroF(&mAT,row1,row1);           /*    Pivot row     */
   deter        =     rowmini_F(&mAT,row1,deter);
                     frowmini_F(&mAT,row1      );          /* a) fraction mini */

  for (row2 = row1+1 ; row2 < mAT.rows ; row2++)
    {                                                   /*    Before the work */
               deter = rowmini_F(&mAT,row2,deter);
                      frowmini_F(&mAT,row2);             /* a) fraction mini   */

     coefnulldoNothing = *(mAT.pb+row2 *mAT.cols+row1*C2);

        if(!(coefnulldoNothing==0))
        {
                pivotworkF(&mAT,row1,row2);             /*     After the work */
          deter = rowmini_F(&mAT,row2,deter);
                 frowmini_F(&mAT,row2);                  /*  a) fraction mini  */

          deter.n *=  *(mAT.pb+row1 *mAT.cols+row1*C2+1);
          deter.d *=  *(mAT.pb+row1 *mAT.cols+row1*C2  );

                 deter = mini_F(deter);
      }
     }
}
/*------------------------------------------------------------------ Diagonal */
    for (row1 = 0 ; row1 < mAT.rows ; row1++)
     {
       deter.n *= *(mAT.pb+row1 *mAT.cols+row1*C2     );
       deter.d *= *(mAT.pb+row1 *mAT.cols+row1*C2 +1);

              deter = mini_F(deter);
      }

 return(deter);
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
fraction detFbasicT(
PmF mA)
{
      int row1;
      int row2;
      int n;
   double coefnulldoNothing = 1;
 fraction deter;

double pbAT [MXR][MXC*C2];mF mAT ={MXR,MXC*C2,&pbAT [0][0]};

 n = mA->rows;
                mAT.rows=n       ;
                mAT.cols=n*C2;

 deter.n = 1;
 deter.d = 1;

 transpose_mF(mA,&mAT);

/* copy_mF(mA,&mAT); */

/*--------------------------------------------------------------------  gauss */
for (row1 = 0 ; row1 < mAT.rows - 1 ; row1++)
{
   deter.n *= pivotntzeroF(&mAT,row1,row1);           /*    Pivot row     */
   deter        =     rowmini_F(&mAT,row1,deter);
                     frowmini_F(&mAT,row1      );          /* a) fraction mini */

  for (row2 = row1+1 ; row2 < mAT.rows ; row2++)
    {                                                   /*    Before the work */
               deter = rowmini_F(&mAT,row2,deter);
                      frowmini_F(&mAT,row2);             /* a) fraction mini   */

     coefnulldoNothing = *(mAT.pb+row2 *mAT.cols+row1*C2);

        if(!(coefnulldoNothing==0))
        {
                pivotworkF(&mAT,row1,row2);             /*     After the work */
          deter = rowmini_F(&mAT,row2,deter);
                 frowmini_F(&mAT,row2);                  /*  a) fraction mini  */

          deter.n *=  *(mAT.pb+row1 *mAT.cols+row1*C2+1);
          deter.d *=  *(mAT.pb+row1 *mAT.cols+row1*C2  );

                 deter = mini_F(deter);
      }
     }
}
/*------------------------------------------------------------------ Diagonal */
    for (row1 = 0 ; row1 < mAT.rows ; row1++)
     {
       deter.n *= *(mAT.pb+row1 *mAT.cols+row1*C2  );
       deter.d *= *(mAT.pb+row1 *mAT.cols+row1*C2+1);

              deter = mini_F(deter);
      }

 return(deter);
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
fraction detFnumerMini(
PmF mA)
{
      int row1;
      int row2;
      int n;
   double coefnulldoNothing = 1;
 fraction deter;

double pbAT [MXR][MXC*C2];mF mAT ={MXR,MXC*C2,&pbAT [0][0]};

 n = mA->rows;
                mAT.rows=n       ;
                mAT.cols=n*C2;

 deter.n = 1;
 deter.d = 1;

 copy_mF(mA,&mAT);

/*--------------------------------------------------------------------  gauss */
for (row1 = 0 ; row1 < mAT.rows - 1 ; row1++)
{
   deter.n *=  pivotntzeroF(&mAT,row1,row1);          /*    Pivot row     */
   deter        =      rowmini_F(&mAT,row1,deter);
                      frowmini_F(&mAT,row1     );          /* a) fraction mini */
   deter.n *=  pivotbestFnumer(&mAT,row1,row1);
               deter = rowmini_F(&mAT,row1,deter);
                      frowmini_F(&mAT,row1      );         /* a) fraction mini */

  for (row2 = row1+1 ; row2 < mAT.rows ; row2++)
    {                                                   /*    Before the work */
                    deter = rowmini_F(&mAT,row2,deter);
                           frowmini_F(&mAT,row2);        /* a) fraction mini   */

     coefnulldoNothing = *(mAT.pb+row2 *mAT.cols+row1*C2);

        if(!(coefnulldoNothing==0))
        {

                pivotworkF(&mAT,row1,row2);             /*     After the work */
          deter = rowmini_F(&mAT,row2,deter);
                 frowmini_F(&mAT,row1);                  /*  a) fraction mini  */

          deter.n *=  *(mAT.pb+row1 *mAT.cols+row1*C2+1);
          deter.d *=  *(mAT.pb+row1 *mAT.cols+row1*C2  );

                 deter = mini_F(deter);
      }
     }
}
/*------------------------------------------------------------------ Diagonal */
    for (row1 = 0 ; row1 < mAT.rows ; row1++)
     {
       deter.n *= *(mAT.pb+row1 *mAT.cols+row1*C2  );
       deter.d *= *(mAT.pb+row1 *mAT.cols+row1*C2+1);

              deter = mini_F(deter);
      }

 return(deter);
}

/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
fraction detFnumerMiniT(
PmF mA)
{
      int row1;
      int row2;
      int n;
   double coefnulldoNothing = 1;
 fraction deter;

double pbAT [MXR][MXC*C2];mF mAT ={MXR,MXC*C2,&pbAT [0][0]};

 n = mA->rows;
                mAT.rows=n       ;
                mAT.cols=n*C2;

 deter.n = 1;
 deter.d = 1;

 transpose_mF(mA,&mAT);

/*--------------------------------------------------------------------  gauss */
for (row1 = 0 ; row1 < mAT.rows - 1 ; row1++)
{
   deter.n *=  pivotntzeroF(&mAT,row1,row1);          /*    Pivot row     */
   deter        =      rowmini_F(&mAT,row1,deter);
                      frowmini_F(&mAT,row1     );          /* a) fraction mini */
   deter.n *=  pivotbestFnumer(&mAT,row1,row1);
               deter = rowmini_F(&mAT,row1,deter);
                      frowmini_F(&mAT,row1      );         /* a) fraction mini */

  for (row2 = row1+1 ; row2 < mAT.rows ; row2++)
    {                                                   /*    Before the work */
                    deter = rowmini_F(&mAT,row2,deter);
                           frowmini_F(&mAT,row2);        /* a) fraction mini   */

     coefnulldoNothing = *(mAT.pb+row2 *mAT.cols+row1*C2);

        if(!(coefnulldoNothing==0))
        {

                pivotworkF(&mAT,row1,row2);             /*     After the work */
          deter = rowmini_F(&mAT,row2,deter);
                 frowmini_F(&mAT,row1);                  /*  a) fraction mini  */

          deter.n *=  *(mAT.pb+row1 *mAT.cols+row1*C2+1);
          deter.d *=  *(mAT.pb+row1 *mAT.cols+row1*C2  );

                 deter = mini_F(deter);
      }
     }
}
/*------------------------------------------------------------------ Diagonal */
    for (row1 = 0 ; row1 < mAT.rows ; row1++)
     {
       deter.n *= *(mAT.pb+row1 *mAT.cols+row1*C2  );
       deter.d *= *(mAT.pb+row1 *mAT.cols+row1*C2+1);

              deter = mini_F(deter);
      }

 return(deter);
}


/* --------------------------------- FUNCTION ------------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* -------------------------------------------------------------------------- */
fraction detFdenomMini(
PmF mA)
{
      int row1;
      int row2;
      int n;
   double coefnulldoNothing = 1;
 fraction deter;

double pbAT [MXR][MXC*C2];mF mAT ={MXR,MXC*C2,&pbAT [0][0]};

 n = mA->rows;
                mAT.rows=n       ;
                mAT.cols=n*C2;

 deter.n = 1;
 deter.d = 1;

 copy_mF(mA,&mAT);

/*--------------------------------------------------------------------  gauss */
for (row1 = 0 ; row1 < mAT.rows - 1 ; row1++)
{
   deter.n *=  pivotntzeroF(&mAT,row1,row1);          /*    Pivot row     */
   deter        =      rowmini_F(&mAT,row1,deter);
                      frowmini_F(&mAT,row1     );          /* a) fraction mini */
   deter.n *=  pivotbestFdenom(&mAT,row1,row1);
               deter = rowmini_F(&mAT,row1,deter);
                      frowmini_F(&mAT,row1     );          /* a) fraction mini */

  for (row2 = row1+1 ; row2 < mAT.rows ; row2++)
    {                                                   /*    Before the work */
                    deter = rowmini_F(&mAT,row1,deter);
                           frowmini_F(&mAT,row2);        /* a) fraction mini   */

     coefnulldoNothing = *(mAT.pb+row2 *mAT.cols+row1*C2);

        if(!(coefnulldoNothing==0))
        {

                pivotworkF(&mAT,row1,row2);             /*     After the work */
          deter = rowmini_F(&mAT,row2,deter);
                 frowmini_F(&mAT,row1);                  /*  a) fraction mini  */

          deter.n *=  *(mAT.pb+row1 *mAT.cols+row1*C2+1);
          deter.d *=  *(mAT.pb+row1 *mAT.cols+row1*C2  );

                 deter = mini_F(deter);
      }
     }
}
/*------------------------------------------------------------------ Diagonal */
    for (row1 = 0 ; row1 < mAT.rows ; row1++)
     {
       deter.n *= *(mAT.pb+row1 *mAT.cols+row1*C2  );
       deter.d *= *(mAT.pb+row1 *mAT.cols+row1*C2+1);

              deter = mini_F(deter);
      }

 return(deter);
}


/* ------------------------------ FUNCTION ---------------------------- det() */
/*                                                                            */
/* -------------------------------------------------------------------------- */
fraction detFdenomMiniT(
PmF mA)
{
      int row1;
      int row2;
      int n;
   double coefnulldoNothing = 1;
 fraction deter;

double pbAT [MXR][MXC*C2];mF mAT ={MXR,MXC*C2,&pbAT [0][0]};

 n = mA->rows;
                mAT.rows=n       ;
                mAT.cols=n*C2;

 deter.n = 1;
 deter.d = 1;

 transpose_mF(mA,&mAT);

/*--------------------------------------------------------------------  gauss */
for (row1 = 0 ; row1 < mAT.rows - 1 ; row1++)
{
   deter.n *=  pivotntzeroF(&mAT,row1,row1);          /*    Pivot row     */
   deter        =      rowmini_F(&mAT,row1,deter);
                      frowmini_F(&mAT,row1     );          /* a) fraction mini */
   deter.n *=  pivotbestFdenom(&mAT,row1,row1);
               deter = rowmini_F(&mAT,row1,deter);
                      frowmini_F(&mAT,row1     );          /* a) fraction mini */

  for (row2 = row1+1 ; row2 < mAT.rows ; row2++)
    {                                                   /*    Before the work */
                    deter = rowmini_F(&mAT,row1,deter);
                           frowmini_F(&mAT,row2);        /* a) fraction mini   */

     coefnulldoNothing = *(mAT.pb+row2 *mAT.cols+row1*C2);

        if(!(coefnulldoNothing==0))
        {

                pivotworkF(&mAT,row1,row2);             /*     After the work */
          deter = rowmini_F(&mAT,row2,deter);
                 frowmini_F(&mAT,row1);                  /*  a) fraction mini  */

          deter.n *=  *(mAT.pb+row1 *mAT.cols+row1*C2+1);
          deter.d *=  *(mAT.pb+row1 *mAT.cols+row1*C2  );

                 deter = mini_F(deter);
      }
     }
}
/*------------------------------------------------------------------ Diagonal */
    for (row1 = 0 ; row1 < mAT.rows ; row1++)
     {
       deter.n *= *(mAT.pb+row1 *mAT.cols+row1*C2  );
       deter.d *= *(mAT.pb+row1 *mAT.cols+row1*C2+1);

              deter = mini_F(deter);
      }

 return(deter);
}




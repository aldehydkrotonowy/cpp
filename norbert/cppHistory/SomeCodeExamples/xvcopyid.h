/* xvcopyid.h                     freeware                xhunga@tiscali.fr  */


/*------------------------------- FUNCTION ---------------------------------- */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void createAid_mF(
PmF mA,
PmF mAID
)
{
int i;
int j;
int k = mA->rows * C2;
int n = mA->rows;

double pbID[MXR][MXC*C2];mF mID={MXR,MXC*C2,&pbID[0][0]};

               mID.rows = n   ;
               mID.cols = n*C2;
/* ------------------------------------------------------------------ copy mA */
  for (i = 0 ; i < mA->rows ; i++)
    for ( j = 0; j < mA->cols ; j++)
          *(mAID->pb+i *mAID->cols+j) = *(mA->pb+i *mA->cols+j);
/* ----------------------------------------------------------------- copy mID */
  id_mF(&mID);

  for (i = 0 ; i < mA->rows ; i++)
    for ( j = 0; j < mA->cols ; j++)
          *(mAID->pb+i *mAID->cols+j+k) = *(mID.pb+i *mID.cols+j);
}

/*------------------------------- FUNCTION ---------------------------------- */
/*                                                                            */
/* -------------------------------------------------------------------------- */
void copyinv_mF(
PmF mAID,
PmF minvA)
{
int i;
int j;
int k = mAID->rows * C2;

  for (i = 0 ; i < minvA->rows ; i++)
    for ( j = 0; j < minvA->cols ; j++)
         *(minvA->pb+i *minvA->cols+j) = *(mAID->pb+i *mAID->cols+k+j);
}


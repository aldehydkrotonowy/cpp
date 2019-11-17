/* yadd.h                   freeware                   xhunga@tiscali.fr  */

/* ------------------------------------- FUNCTION --------------------------  */
/* Do    :                                                                    */
/*                                                                            */


/* see   :   vectag.zip                                                       */
/* -------------------------------------------------------------------------- */
void addw_svnF(
PmF mvn,
PmF mw_s,
PmF mw_svn
)
{
int i;
int j;
fraction s;

double pbvnT [MXR][MXC*C2];mF mvnT  ={MXR,MXC*C2,&pbvnT [0][0]};
double pbT1  [MXR][MXC*C2];mF mT1   ={MXR,MXC*C2,&pbT1  [0][0]};
double pbT2  [MXR][MXC*C2];mF mT2   ={MXR,MXC*C2,&pbT2  [0][0]};

                    mvnT.rows =  mvn->rows;     mvnT.cols =  mvn->cols;
                     mT1.rows = mw_s->rows;      mT1.cols = mw_s->cols;
                     mT2.rows = mw_s->rows;      mT2.cols = mw_s->cols;
/*-------------------------------- PROGRAM ---------------------------------- */
copy_mF(mvn,&mvnT);

for(i=0; i<(mvnT.cols/2); i++)
 {
  s = copycoeffinto_F(mw_s,i,0);
             mulcol_mF(&mvnT,i,s);
 }

  zero_mF(&mT1);
for(j=0; j<(mvnT.cols/2); j++)
 {
  copy_cF(&mvnT,j,&mT2,0);
     add_mF(&mT1,&mT2,mw_svn);
    copy_mF(mw_svn,&mT1);
 }
}

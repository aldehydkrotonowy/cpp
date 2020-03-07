/* xastruct.h                   free ware                   xhunga@tiscali.fr */


/*---------------------------------------------------------- Matrix structure */
typedef struct
{
     int  rows;
     int  cols;
  double *pb;
}mF, *PmF;

/*-------------------------------------------------------- Fraction structure */
typedef struct
{
    double  n;
    double  d;
}fraction, *pfraction;


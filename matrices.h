#ifndef _MATRICES
#define _MATRICES
typedef struct
{
    int n;
    double *vect;
} vecteur_t;

typedef struct
{
    int nl, nc;
    double **mat; // allouer nl pointeurs puis  allouer nc pointeur
} matrice_t;

typedef struct
{
    int indice;
    int nmbrZero;
} ligne;

void creerMatrice(matrice_t *);
void scanMatrice(matrice_t *);
void scanVect(vecteur_t *);
void printfMatrice(const matrice_t *); // pour eviter une copie (lourde)
void printfVect(const vecteur_t *);

matrice_t multiplication(const matrice_t *, const matrice_t *);
vecteur_t MatDotVect(const matrice_t *, const vecteur_t *);
vecteur_t getDiag(const matrice_t *);
vecteur_t get2emeDiag(const matrice_t *);
vecteur_t Mat2Vect(const matrice_t *);
matrice_t Vect2Mat(vecteur_t *,int );
double getTrace(const matrice_t *);
matrice_t extractSubMatrice(const matrice_t *, int, int);
void getBestligneCol(const matrice_t *);
double getDet(matrice_t);
matrice_t getTranspose(const matrice_t *);
matrice_t getInverse(const matrice_t *);


matrice_t coMatrice(const matrice_t *);
matrice_t produitScalaire(const matrice_t, double );
vecteur_t solveSys();


#endif

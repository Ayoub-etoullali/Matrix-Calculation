#include "Matrices.h"
#include <stdio.h>	// printf, scanf, gets, getchar
#include <stdlib.h> // pour malloc, calloc, realloc
#include <assert.h> // pour assert
#include <math.h>

void creerMatrice(matrice_t *ptrMat)
{
	double **p;
	ptrMat->mat = (double **)malloc(ptrMat->nl * sizeof(double *));
	for (p = ptrMat->mat; p < ptrMat->mat + ptrMat->nl; p++)
		*p = (double *)malloc(ptrMat->nc * sizeof(double));
}

//--------------------------------------------------

void creerVect(vecteur_t *ptrV)
{
	ptrV->vect = (double *)malloc(ptrV->n * sizeof(double));
}

//--------------------------------------------------

void scanMatrice(matrice_t *ptrMat)
{
	double **p, *q;
	printf("Nombre de lignes ? ");
	scanf("%d", &ptrMat->nl);
	printf("Nombre de colonnes ? ");
	scanf("%d", &ptrMat->nc);
	creerMatrice(ptrMat);
	// la saisie des données de la matrice
	printf("les donnees de la matrice \n");
	for (p = ptrMat->mat; p < ptrMat->mat + ptrMat->nl; p++)
		for (q = *p; q < *p + ptrMat->nc; q++)
		{
			printf("[%d][%d] = ", (int)(p - ptrMat->mat), (int)(q - *p));
			scanf("%lf", q);
		}
}

//--------------------------------------------------

void scanVect(vecteur_t *ptrV)
{
	int i;
	printf("Nombre de colonnes ? ");
	scanf("%d", &ptrV->n);
	creerVect(ptrV);
	// la saisie des données de vect
	printf("les donnees de vecteurs :  \n");
	for (i = 0; i < ptrV->n; i++)
	{
		printf("[%d] = ", i);
		scanf("%lf", &ptrV->vect[i]);
	}
}

//--------------------------------------------------

void printfMatrice(const matrice_t *ptrMat)
{
	double **p, *q;
	puts("Matrice : ");
	printf("\tnbre de lignes = %d\n", ptrMat->nl);
	printf("\tnbre de colonnes = %d\n", ptrMat->nc);
	// la saisie des données de la matrice
	puts("\tValeurs :");
	for (p = ptrMat->mat; p < ptrMat->mat + ptrMat->nl; p++)
	{
		for (q = *p; q < *p + ptrMat->nc; q++)
			printf("%12.0f", *q);
		puts("");
	}
}

//--------------------------------------------------

void printfVect(const vecteur_t *v)
{
	puts(" ");
	puts("vecteur  : ");
	int i;
	printf("\tnbre de colonnes = %d\n", v->n);
	// la saisie des données de la matrice
	puts("\tValeurs :");
	for (i = 0; i < v->n; i++)
	{
		printf("%12.0f", v->vect[i]);
	}
	puts(" ");
}

//--------------------------------------------------(1)

matrice_t multiplication(const matrice_t *ptr1, const matrice_t *ptr2)
{
	matrice_t result;
	assert(ptr1->nc == ptr2->nl);
	result.nl = ptr1->nl;
	result.nc = ptr1->nc;
	creerMatrice(&result);
	int i, j, k;
	for (i = 0; i < ptr1->nl; i++)
	{
		for (j = 0; j < ptr1->nc; j++)
		{
			for (k = 0; k < ptr1->nl; k++)
			{
				result.mat[i][j] += ptr1->mat[i][k] * ptr2->mat[k][j];
			}
		}
	}

	return result;
}

//--------------------------------------------------(2)

vecteur_t MatDotVect(const matrice_t *m, const vecteur_t *v)
{
	vecteur_t res;
	res.n = v->n;
	creerVect(&res);
	int i, j;
	for (i = 0; i < m->nl; i++)
		for (j = 0; j < m->nc; j++)
			res.vect[i] += m->mat[i][j] * v->vect[j];
	return res;
}

//--------------------------------------------------(3)

vecteur_t getDiag(const matrice_t *m)
{
	vecteur_t res;
	int i;
	res.n = m->nl;
	creerVect(&res);
	for (i = 0; i < m->nl; i++)
		res.vect[i] = m->mat[i][i];
	return res;
}

//--------------------------------------------------(4)

vecteur_t get2emeDiag(const matrice_t *m)
{
	vecteur_t res;
	int i;
	res.n = m->nc;
	assert(m->nl == m->nc);
	creerVect(&res);
	int end = m->nc - 1;
	for (i = 0; i < m->nc; i++)
		res.vect[i] = m->mat[i][end - i];
	return res;
}

//--------------------------------------------------(5)

vecteur_t Mat2Vect(const matrice_t *m)
{
	vecteur_t v;
	v.n = m->nc;
	creerVect(&v);
	int i, j;
	for (i = 0; i < m->nl - 1; i++)
	{
		for (j = 0; j < m->nc; j++)
		{
			v.vect[i] = m->mat[i][j];
		}
		puts("");
		printfVect(&v);
	}
	puts("");
	for (j = 0; j < m->nc; j++)
	{
		v.vect[i] = m->mat[i][j];
	}
	return v;
}

//--------------------------------------------------(6)

matrice_t Vect2Mat(vecteur_t *v, int x)
{
	matrice_t m;
	m.nc = v->n;
	m.nl = x;
	creerMatrice(&m);
	assert(m.nc % m.nl == 0);
	int i, j;
	for (i = 0; i < m.nl; i++)
	{
		for (j = 0; j < m.nc; j++)
		{
			m.mat[i][j] = v->vect[i];
		}
	}
	return m;
}

//--------------------------------------------------(7)

double getTrace(const matrice_t *ptr)
{
	int i;
	double T = 0;
	assert(ptr->nc == ptr->nl);
	for (i = 0; i < ptr->nl; i++)
	{
		T += ptr->mat[i][i];
	}
	return T;
}

//--------------------------------------------------(8)

matrice_t extractSubMatrice(const matrice_t *m, int l, int c)
{
	int i, j, k = 0, f = 0;
	matrice_t U;
	if (l != 0)
		U.nl = m->nl - 1;
	else
		U.nl = m->nl;
	if (c != 0)
		U.nc = m->nc - 1;
	else
		U.nc = m->nc;
	creerMatrice(&U);
	assert(m->nc >= c - 1 && m->nl >= l - 1);
	for (i = 0; i < m->nl; i++)
	{
		f = 0;
		if (i != l - 1)
		{
			for (j = 0; j < m->nc; j++)
			{
				if (j != c - 1)
				{
					U.mat[k][f] = m->mat[i][j];
					f++;
				}
			}
			k++;
		}
	}

	return U;
}

//--------------------------------------------------(9)

ligne bestlgn(const matrice_t *m)
{
	int in = 0, i, j;
	ligne best;

	best.indice = 0;
	best.nmbrZero = 0;
	for (i = 0; i < m->nl; i++)
	{
		for (j = 0; j < m->nc; j++)
		{
			if (m->mat[i][j] == 0)
				in++;
		}
		if (best.nmbrZero < in)
		{
			best.indice = i;
			best.nmbrZero = in;
		}
		in = 0;
	}
	return best;
}

ligne bestcln(const matrice_t *m)
{
	int in = 0, i, j;
	ligne best;
	best.indice = 0;
	best.nmbrZero = 0;
	for (i = 0; i < m->nc; i++)
	{
		for (j = 0; j < m->nl; j++)
		{
			if (m->mat[j][i] == 0)
				in++;
		}
		if (best.nmbrZero < in)
		{
			best.indice = i;
			best.nmbrZero = in;
		}
		in = 0;
	}
	return best;
}

void getBestligneCol(const matrice_t *m)
{

	ligne l = bestlgn(m);
	ligne c = bestcln(m);

	if (l.nmbrZero >= c.nmbrZero)
	{
		printf("\n \t\t best ligne est : %d nmbr des zeros  : %d \n", l.indice + 1, l.nmbrZero);
	}
	else
	{

		printf("\n \t\t best colonne est : %d nmbr des zeros  : %d \n", c.indice + 1, c.nmbrZero);
	}
}

//--------------------------------------------------(10)

double getDet(matrice_t m)
{
	//assert(m.nc == m.nl);
	int j;
	double det = 0;
	if (m.nc > 2)
	{
		for (j = 2; j < m.nc; j++)
			det += pow(-1, j) * m.mat[0][j] * getDet(extractSubMatrice(&m, 0, j));
		return det;
	}
	else
	{
		return det = (m.mat[0][0] * m.mat[1][1]) - (m.mat[0][1] * m.mat[1][0]);
	}
}

//--------------------------------------------------(11)

matrice_t getTranspose(const matrice_t *A)
{
	matrice_t T;
	int i, j;
	T.nl = A->nc;
	T.nc = A->nl;
	creerMatrice(&T);
	for (i = 0; i < A->nl; i++)
		for (j = 0; j < A->nc; j++)
			T.mat[j][i] = A->mat[i][j];
	return T;
}

//--------------------------------------------------(12)

matrice_t getInverse(const matrice_t *m)
{
	double det;
	int i, j;

	assert(getDet(*m) != 0);
	det = 1 / getDet(*m);
	matrice_t m2, m3;

	m2.nl = m->nl;
	m2.nc = m->nc;
	m3.nl = m->nl;
	m3.nc = m->nc;
	creerMatrice(&m2);
	creerMatrice(&m3);
	m3 = coMatrice(m);
	m3 = getTranspose(&m3);
	m2 = produitScalaire(m3, det);

	return m2;
}

//--------------------------------------------------

matrice_t coMatrice(const matrice_t *m)
{
	matrice_t coMAt;
	coMAt.nl = m->nl;
	coMAt.nc = m->nc;
	creerMatrice(&coMAt);
	int i, j;
	for (i = 0; i < coMAt.nl; i++)
	{
		for (j = 0; j < coMAt.nc; j++)
		{

			coMAt.mat[i][j] = pow(-1, i + j) * getDet(extractSubMatrice(m, i, j));
		}
	}
	return coMAt;
}

//--------------------------------------------------

matrice_t produitScalaire(const matrice_t A, double scalaire)
{
	int i, j;
	matrice_t res;
	res.nc = A.nc;
	res.nl = A.nl;
	creerMatrice(&res);
	for (i = 0; i < A.nl; i++)
		for (j = 0; j < A.nc; j++)
			res.mat[i][j] = A.mat[i][j] * scalaire;
	return res;
}
vecteur_t get2diagonal(const matrice_t *ptr)
{
	vecteur_t vect;
	int i;
	vect.n = ptr->nl;
	creerVect(&vect);
	for (i = ptr->nl; i < -1; i--)
		vect.vect[i] = ptr->mat[i][i];
	return vect;
}

// Méthode de Gauss
vecteur_t solveSys()
{
	vecteur_t vect;
	matrice_t mat;
	int i, j, k, n;
	double c, sum = 0.0;
	double **p, *q;

	printf("Ordre de la matrice? ");
	scanf("%d", &n);
	mat.nc = n + 1;
	mat.nl = n;
	creerMatrice(&mat);
	vect.n = n;
	creerVect(&vect);

	// entrer les données
	for (p = mat.mat; p < mat.mat + mat.nl; p++)
		for (q = *p; q < *p + mat.nc; q++)
		{
			printf("[%d][%d] = ", (int)(p - mat.mat), (int)(q - *p));
			scanf("%lf", q);
		}

	// trangularisation
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
		{
			if (i > j)
			{
				c = mat.mat[i][j] / mat.mat[j][j];
				for (k = 0; k < n + 1; k++)
				{
					mat.mat[i][k] = mat.mat[i][k] - c * mat.mat[j][k];
				}
			}
		}
	}
	vect.vect[n - 1] = mat.mat[n - 1][n] / mat.mat[n - 1][n - 1];

	// la substitution inverse
	for (i = n - 1; i >= 1; i--)
	{
		sum = 0;
		for (j = i + 1; j < n; j++)
		{
			sum = sum + mat.mat[i][j] * vect.vect[j];
		}
		vect.vect[i - 1] = (mat.mat[i - 1][n] - sum) / mat.mat[i - 1][i - 1];
	}
	return vect;
}

// triangulaire : méthode de guass

//----------------------------------------------------------(13)

/*vecteur_t solveSys(matrice_t *m1)
{
	vecteur_t vect;
	int i, j, k, n;
	double c, sum = 0.0;
	double **p, *q;

	printf("Ordre de la matrice? ");
	scanf("%d", &n);
	m1->nc = n + 1;
	m1->nl = n;
	creerMatrice(&m1);
	vect.n = n;
	creerVect(&vect);

	// trangularisation
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
		{
			if (i > j)
			{
				c = m1->mat[i][j] / m1->mat[j][j];
				for (k = 0; k < n + 1; k++)
				{
					m1->mat[i][k] = m1->mat[i][k] - c * m1->mat[j][k];
				}
			}
		}
	}
	vect.vect[n - 1] = m1->mat[n - 1][n] / m1->mat[n - 1][n - 1];

	// la substitution inverse
	for (i = n - 1; i >= 1; i--)
	{
		sum = 0;
		for (j = i + 1; j < n; j++)
		{
			sum = sum + m1->mat[i][j] * vect.vect[j];
		}
		vect.vect[i - 1] = (m1->mat[i - 1][n] - sum) / m1->mat[i - 1][i - 1];
	}
	return vect;
}
*/
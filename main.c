#include "Matrices.c"

int main()
{
    int n, nc, nl;
    double x;
    matrice_t m1, m2, m3;
    vecteur_t v1, v2;

   printf("\n\nPrepare par : \n Aya AIT OULAHYANE \n Ayoub ETOULLALI \n Fatima Ezzahra HOUD ");

    printf("\n\n ----------------------------------------MENU---------------------------------------  \n");
    printf("(1) Multiplication de deux matrice  \n");
    printf("(2) Multiplication d’une matrice et d’un vecteur \n");
    printf("(3) Extraction de la 1ère diagonale d’une matrice carree : \n");
    printf("(4) Extraire la 2eme diagonale d’une matrice carree \n");
    printf("(5) Transformer une matrice en un vecteur en justaposant les lignes ou les colonnes ) \n");
    printf("(6) Transformer un vecteur en une matrice \n");
    printf("(7) Calculer la somme des elements de la diagonale d’une matrice carree \n");
    printf("(8) Extraire la sous matrice d’une matrice en eliminant la ligne I et la colonne j \n");
    printf("(9) Trouver la ligne ou la colonne d’une matrice qui contient le maximum de zeros \n");
    printf("(10) Calculer le determinant d’une matrice carree \n");
    printf("(11) Calculer la matrice transpose d’une matrice \n");
    printf("(12) Calculer la matrice inverse d’une matrice carree si le determinant est non null \n");
    printf("(13) Resoudre un système lineaire A nxn X nx1 =Y nx1 \n");
    printf("(14) Exit \n");
    printf(" ----------------------------------------------------------------------------------- \n\n");

    printf("Veuillez saisair une operation : ");
    scanf("%d", &n);

    switch (n)
    {

    case 1:
    {
        scanMatrice(&m1);
        scanMatrice(&m2);

        printf("\n\nMultiplication de deux matrice : \n");
        m3 = multiplication(&m1, &m2);

        printfMatrice(&m1);
        printfMatrice(&m2);
        printfMatrice(&m3);
        break;
    }
    case 2:
    {
        scanMatrice(&m1);
        scanVect(&v1);

        printf("\n\nMultiplication d’une matrice et d’un vecteur : \n");
        v2 = MatDotVect(&m1, &v1);

        printfMatrice(&m1);
        printfVect(&v1);
        printfVect(&v2);
        break;
    }
    case 3:
    {
        scanMatrice(&m1);

        printf("\n\nExtraction de la 1ere diagonale d’une matrice carree : \n");
        v1 = getDiag(&m1);

        printfMatrice(&m1);
        printfVect(&v1);
        break;
    }
    case 4:
    {
        scanMatrice(&m1);

        printf("\n\nExtraire la 2eme diagonale d’une matrice carree : \n");
        v1 = get2emeDiag(&m1);

        printfMatrice(&m1);
        printfVect(&v1);
        break;
    }
    case 5:
    {
        scanMatrice(&m1);
        printfMatrice(&m1);

        printf("\n\nTransformer une matrice en un vecteur : \n");
        v1 = Mat2Vect(&m1);
        printfVect(&v1);
        break;
    }
    case 6:
    {
        scanVect(&v1);

        printf("\n\nEntrer le nombre de ligne de la matrice : \n");
        scanf("%d", &nl);

        printf("\n\nTransformer un vecteur en une matrice : \n");
        m2 = Vect2Mat(&v1, nl);
        printfMatrice(&m2);

        break;
    }
    case 7:
    {
        scanMatrice(&m1);

        printf("\n\nca8lculer la somme des elements de la diagonale d une matrice carree : \n");
        x = getTrace(&m1);

        printfMatrice(&m1);
        printf("\nla Trace est : %.2lf ", x);
        break;
    }
    case 8:
    {
        scanMatrice(&m1);

        printf("nbr Ligne : ");
        scanf("%d", &nl);
        printf("nbr Colone : ");
        scanf("%d", &nc);

        printf("\n\nextraire la sous matrice d’une matrice en eliminant la ligne I et la colonne j : \n");
        m2 = extractSubMatrice(&m1, nl, nc);

        printfMatrice(&m1);
        printfMatrice(&m2);
        break;
    }
    case 9:
    {
        scanMatrice(&m1);

        printf("\n\ntrouver la ligne ou la colonne d une matrice qui contient le maximum de zeros : \n");
        getBestligneCol(&m1);

        printfMatrice(&m1);
        break;
    }
    case 10:
    {
        scanMatrice(&m1);

        printf("\n\ncalculer le determinant d une matrice carre : \n");

        printf("Determinant est : %.2lf", getDet(m1));
        break;
    }
    case 11:
    {
        scanMatrice(&m1);

        printf("\n\ncalculer la matrice transpose d une matrice : \n");
        m2 = getTranspose(&m1);

        printfMatrice(&m1);
        printfMatrice(&m2);
        break;
    }
    case 12:
    {
        scanMatrice(&m1);

        printf("\n\nCalculer la matrice inverse d une matrice carree si le determinant est non null : \n");
        m2 = getInverse(&m1);

        printfMatrice(&m1);
        printfMatrice(&m2);
        break;
    }
    case 13:
    {
        matrice_t m1;
        vecteur_t vect3;
        vect3 = solveSys(&m1);
        printfVect(&vect3);
        break;

        /*scanMatrice(&m1);

        printf("\n\nresoudre un systeme lineaire : \n");

        v1 = solveSys(&m1);
        printfVect(&v1);
        break;*/
    }
    case 14:
    {
        printf("\n\n Exit \n");
        break;
    }
    default:
    {
        printf(" veuillez entrer le nombre entre [|1,14|]");
    }
    }

}



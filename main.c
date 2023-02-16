#include <stdio.h>
#include <stdlib.h>

// Prototypes des fonctions
void dessinGrille(char tabl[][3], int taille);
void saisieJoueur(char tabl[][3], int taille, char joueur, int* abscisse, int *ordonnee);
int saisieValide(char tabl[][3], int taille, int* abscisse, int* ordonnee);


int main()
{
    printf("TP9: Les fonctions\n");

    char grille[3][3]=
    {
       {'.','.','.'},
       {'.','.','.'},
       {'.','.','.'}
    };

    int fin_partie=0;
    char joueur = 'X';
    int coord_x, coord_y;
    dessinGrille(grille, 3);
    do
    {
    saisieJoueur(grille, 3, joueur, &coord_x, &coord_y);
    saisieValide(grille, 3,&coord_x, &coord_y);
    }while (saisieValide ==0);
    dessinGrille(grille,3);

    return 0;
}

void dessinGrille(char tabl[][3], int nb_ligne)
{
    for( int x=0; x<nb_ligne; x++)
    {
        printf("|%c|%c|%c|\n", tabl[x][0], tabl[x][1], tabl[x][2]);
    }
}

void saisieJoueur(char tabl[][3], int taille, char joueur, int* abscisse, int *ordonnee)
{
    printf("Joueur %c ou voullez-vous jouer (x y\n", joueur);
    fflush(stdin);
    scanf("%d""%d",abscisse, ordonnee);
    tabl[*abscisse][*ordonnee]=joueur;


}

int saisieValide(char tabl[][3], int taille, int* abscisse, int* ordonnee)
{
    if (*abscisse>2 || *abscisse<0 || *ordonnee<0 || *ordonnee>2)
    {
        printf("Saisie invalide!\n");
        return 0;
    }
    if((tabl[*abscisse][*ordonnee])!='.')
    {
        printf("case occupee \n");
        return 0;
    }
    return 1;
}


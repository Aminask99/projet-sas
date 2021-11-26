
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct Compte                                                    //structure
{
    float Montant;
    char CIN[80];
    char Nom[60];
    char Prenom[50];
};
typedef struct Compte CMP;

void IntroduireCompte(CMP comptes[], int n);
char *RecherchCIN(CMP comptes[], int n, char *cin);
void *Retrait(CMP comptes[], int n, float retrait, char *cin);                               //les fonction
void *Depot(CMP comptes[], int n, float Depot, char *cin);
void MenuPrincipale();                                                                       //prototype
void AffichageNormal(CMP comptes[], int n);
void quitter();
void AffichageTrieAscendant(CMP comptes[], int n);
void AffichageTrieDescendant(CMP comptes[], int n);
void AffiDesParChiffre(CMP comptes[], int n, float chifre);
void Fidelisation(CMP comptes[], int n);

CMP cptes[100];
int n;
int main()
{
    int choix;
MN:
    do
    {
        system("cls");
        MenuPrincipale();
        printf(" Votre Choix est \n");
        scanf("%d", &choix);
        switch (choix)
        {

        case 1:
        {
            printf(" Introduire un Compte Bancaire \n\n");                  //crier un compte
            int l;
            n = 1;
            IntroduireCompte(cptes, n);

            system("cls");
            printf("le compte est bien crier \n");
            AffichageNormal(cptes, n);
            printf("pour le menu principale taper 0 \n");
            scanf("%d", &l);
            if (l == 0)
            {
                system("cls");
                goto MN;
            }
            break;
        }

        case 2:
        {
            int rtrn;
            printf("Introduire plusieurs Comptes Bancaires\n\n");            //crier plusieurs compte
            printf("donner le nombre de comptes : \n");
            scanf("%d", &n);
            IntroduireCompte(cptes, n);
            system("cls");
            printf("les comptes % d est bien crier \n", n);
            AffichageNormal(cptes, n);
            printf("le menu principale taper 0 \n");
            scanf("%d", &rtrn);
            if (rtrn == 0)
            {
                system("cls");
                goto MN;
            }
            break;
        }
        case 3:

        {
            int choix2;                                                    //operations
        operation:
            system("cls");
            printf("================================================= Operations ============================================\n\n");
            printf("\t\t\t\t1  --->   Retrait \n\n\t\t\t\t2  --->   Depot \n \n\t\t\t\t3  --->   Menu Principale  \n \n\t\t\t\tEntrer Votre Choix \n");
            scanf("%d", &choix2);
            switch (choix2)
            {

            case 1:
            {
                system("cls");
                printf("============================================== Retrait ================================================= \n\n");
                char cin[50];
                float retrait;
                int v;
                printf("saisie CIN  \n ");
                scanf("%s", cin);                                              //retrait
                printf("saisie le mantant de retrait \n");
                scanf("%f", &retrait);
                Retrait(cptes, 100, retrait, cin);
                printf("taper 0 pour le menu principale\n");
                scanf("%d", &v);
                if (v == 0)
                {
                    system("cls");
                    goto MN;
                }

                break;
            }

            case 2:
            {
                system("cls");
                printf("===============================================  Depo ==============================================\n\n");
                char cin[50];
                float depot;
                int v;                                             //depot
                printf("Entrer CIN  \n ");
                scanf("%s", cin);
                printf("entrer le mantant de depot \n");
                scanf("%f", &depot);
                Depot(cptes, 100, depot, cin);
                printf("taper 0 pour le menu principale\n");
                scanf("%d", &v);
                if (v == 0)
                {
                    system("cls");
                    goto MN;
                }

                break;
            }
            case 3:
            {
                system("cls");
                goto MN;
                break;
            }
            default:
            {
                printf("Entrer un nombre entre 1 et 3 \n");
                goto operation;
                break;
            }
            }
            break;
        }

        case 4:
        {
            int choix3;                                                            //affichage
        affiche:
            system("cls");
            printf("======  Affichage   ====== \n\t1== Ordre Ascendant  \n\t2== Order Descendant   \n\t3== Order Descendant par un chifre  \n\t4== Order Descendant par un chifre  \n\t5== Recherche Par CIN   \n\t6== Menu Principale  \n \n");
            printf("Entrer votre Choix : \t");
            scanf("%d", &choix3);
            switch (choix3)
            {

            case 1:
            {
                system("cls");
                printf("=================================== Les Comptes trie   Ordre Ascendant  =================================== \n\n");
                AffichageTrieAscendant(cptes, n);                                      //tri ascendant
                int v;
                printf("taper 0 pour le menu principale\n");
                scanf("%d", &v);
                if (v == 0)
                {
                    system("cls");
                    goto MN;
                }

                break;
            }

            case 2:
            {
                system("cls");                                                               //tri descendant
                printf("=======================================  Les Comptes trie  Order Descendant ============================== \n\n");
                AffichageTrieDescendant(cptes, n);
                int v;
                printf("taper 0 pour le menu principale\n");
                scanf("%d", &v);
                if (v == 0)
                {
                    system("cls");
                    goto MN;
                }
                break;
            }

            case 3:
            {
                printf("============================  Les Comptes trie  Order Ascendant  superieur  un chifre  ===================== \n\n");
                float chifre;
                printf("entrer le chifre \n");                          // TRI  Ascendant PAR UN CHIFRE DONNEE
                scanf("%f", &chifre);
                int i, taille = 0;
                CMP temp[100];
                for (i = 0; i < n; i++)
                {
                    if (cptes[i].Montant > chifre)
                    {
                        temp[taille] = cptes[i];
                        taille++;
                    }
                }
                AffichageTrieAscendant(temp, taille); //K ==> TAILLE

                int v;
                printf("taper 0 pour le menu principale\n");
                scanf("%d", &v);
                if (v == 0)
                {
                    system("cls");
                    goto MN;
                }
                break;
            }
                                                                        //tri Descendant par chifre (done)
            case 4:
            {
                printf("=========================  Les Comptes trie  Order Descendant  superieur  un chifre ===================== \n\n");

                float chifre;
                printf("saisie le chifre \n");
                scanf("%f", &chifre);
                int i, taille = 0;
                CMP temp[100];
                for (i = 0; i < n; i++)
                {
                    if (cptes[i].Montant > chifre)
                    {
                        temp[taille] = cptes[i];
                        taille++;
                    }
                }
                AffichageTrieDescendant(temp, taille);

                int v;
                printf("taper 0 pour le menu principale\n");
                scanf("%d", &v);
                if (v == 0)
                {
                    system("cls");
                    goto MN;
                }
                break;
            }

            case 5:
            {
                char c[50];
                int r;
                char *nom;
                printf("============================================ Recherche Par CIN =============================================== \n\n");
                printf(" saisie  le CIN \n");
                scanf("%s", c);
                nom = RecherchCIN(cptes, 100, c);                                   //Recherche  (Done)
                if (nom == NULL)                                                          // linier
                {
                    printf(" n'est pas existe \n  ");
                }
                else
                {
                    printf(" ce compte est existe :\n - nom : %s  \n- num : %s   \n", nom, c);
                }
                printf("pour le menu principale taper 0 \n");
                scanf("%d", &r);
                if (r == 0)
                {
                    system("cls");
                    goto MN;
                }
                break;
            }
            case 6:
            {
                system("cls");
                goto MN;
                break;
            }
            default:
            {
                printf("saisie un nombre entre 1 et 6 \n");
                goto affiche;
                break;
            }
            }
            break;
        }

        case 5:
        {
            printf("==================================================== Fidelisation =========================================== \n\n");
                                                           //Fidelisation

            Fidelisation(cptes, n);
            int v;
            printf("taper 0 pour le menu principale\n");
            scanf("%d", &v);
            if (v == 0)
            {
                system("cls");
                goto MN;
            }

            break;
        }
        case 6:
        {
            system("cls");                                                     //quitter
            quitter();
            break;
        }
        }

    } while (choix < 1 || choix > 6);
    return 0;
}
void MenuPrincipale()
{
    printf("\t===========================   MENU PRINCIPALE  \n");
    printf("                  1 :Introduire un Compte Bancaire\n");
    printf("                  2 :Introduire plusieurs Comptes Bancaires \n");              // menu
    printf("                           3 :Operation\n");
    printf("                           4 :Affichage\n");
    printf("                           5 :Fidelisation \n");
    printf("                      6 :Quiter l'application \n \n");
    printf("\t=============================================================================================================\n");
}
void IntroduireCompte(CMP comptes[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("_____________ Compte num :%d __________\n ", i + 1);
        printf("Entrer CIN : \t ");
        scanf("%s", comptes[i].CIN);                                                      //COMPTE
        printf("Entrer le Nom  : \t ");
        scanf("%s", comptes[i].Nom);
        printf("Entrer le Prenom : \t ");
        scanf("%s", comptes[i].Prenom);
        printf("Entrer Montant : \t ");
        scanf("%f", &comptes[i].Montant);
        printf("_______________________________________ Compte num %d Cree avec succes  \n", i + 1);
    }
}
void AffichageNormal(CMP comptes[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("_________________________________________________________________________________________________________________________ \n ");
        printf("CIN : %s \n ", comptes[i].CIN);

        printf("le Nom %s  : \n ", comptes[i].Nom);
                                                                            //AffichageNormal
        printf("le Prenom : %s \n ", comptes[i].Prenom);

        printf("Montant %f: \n ", comptes[i].Montant);
        printf("__________________________________________________________________________________________________________________________ \n ");
    }
}
char *RecherchCIN(CMP comptes[], int n, char *cin)
{
    int i = 0;
    while (i <= n - 1)
    {
        if (strcmp(comptes[i].CIN, cin) == 0)
        {                                                                              //RecherchCIN
            return comptes[i].Nom;
        }
        i++;
    }
    return NULL;
}
void *Depot(CMP comptes[], int n, float Depot, char *cin)
{
    int i;
    int trouve = 0;
                                                                                                         //Depot
    for (i = 0; i < n; i++)
    {
        if (strcmp(cin, comptes[i].CIN) == 0)
        {
            int trouve = 1;
            float m = comptes[i].Montant;
            comptes[i].Montant += Depot;
            system("cls");
            printf("  Compte de : %s - %s\n ", comptes[i].Prenom, comptes[i].Nom);
            printf("______________________________________________\n");
            printf(" votre sold avant  le Depot est : %.2f DH \n\n", m);
            printf(" mantant de Depot est :%.2f DH \n\n", Depot);
            printf(" votre sold apres le Depot est : %.2f DH\n\n", comptes[i].Montant);
            break;
        }
    }
    if (trouve == 0)
    {
        printf("Compte n'est pas existe   \n");
    }
}
void *Retrait(CMP comptes[], int n, float retrait, char *cin)
{
    int i;
    int trouve = 0;
    for (i = 0; i < n; i++)                                                             //RETRAIS
    {
        if (strcmp(cin, comptes[i].CIN) == 0)
        {
            trouve = 1;
            if (retrait > comptes[i].Montant)
            {
                printf("\n  c'est impossible votre sold inferieur a %.2f\n", retrait);
                break;
            }
            else if (retrait < 0)
            {
                printf("imposiple");
            }
            else
            {
                float m = comptes[i].Montant;
                comptes[i].Montant -= retrait;
                system("cls");
                printf(" compte de : %s - %s\n ", comptes[i].Prenom, comptes[i].Nom);
                printf("______________________________________________\n");
                printf("votre sold avant  le retrait est : %.2f DH \n\n", m);
                printf(" mantant de retrait est :%.2f  DH\n\n", retrait);
                printf(" votre sold apres le retrait est : %.2f  DH\n\n ", comptes[i].Montant);
            }
        }
    }
    if (trouve == 0)
    {
        printf("Compte n'existe pas  !!! \n");
    }
}
void AffichageTrieAscendant(CMP comptes[], int n)
{
    CMP temp;
    int i, j;
    for (j = 0; j < n - 1; j++)
    {
        for (i = 0; i < n - 1; i++)
        {
            if (comptes[i].Montant > comptes[i + 1].Montant)
            {
                temp = comptes[i];
                comptes[i] = comptes[i + 1];
                comptes[i + 1] = temp;                                                     //permitation
            }
        }
    }

    AffichageNormal(comptes, n);
}
void AffichageTrieDescendant(CMP comptes[], int n)
{                                                                            //AffichageTrieDescendant
    CMP temp;
    int i, j;
    for (j = 0; j < n - 1; j++)
    {
        for (i = 0; i < n - 1; i++)
        {
            if (comptes[i].Montant < comptes[i + 1].Montant)
            {
                temp = comptes[i];
                comptes[i] = comptes[i + 1];
                comptes[i + 1] = temp;
            }
        }
    }

    AffichageNormal(comptes, n);
}
void Fidelisation(CMP comptes[], int n)
{
    int i;
    AffichageTrieDescendant(comptes, n);                                             // Fidelisation
    for (i = 0; i < 3; i++)
    {
        comptes[i].Montant = comptes[i].Montant * 1.013;                      //1.3\100=0,013
                                                                               //m=m+0,13
    }                                                                             //m=1+0,13
    system("cls");
    AffichageNormal(comptes, 3);
}
void quitter()
{

    printf("mercii");
}

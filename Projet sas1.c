#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Compte
{
    char CIN[50];
    char Nom[50];
    char Prenom[50];
    float Montant;
};
  typedef struct Compte CMP;
 void IntroduireCompte(CMP comptes[], int n);

  //  void operation(CMP comptes[], int n) 

 CMP cptes[100];
    int n ;
   
int main ()

        {   
            int choix;
              printf("                 .Gestion Bancaire........................ \n");
              printf("  Menu principal \n");
              printf("1aIntroduire un compte bancaire (CIN, Nom et Prénom, Montant) \n");
              printf("2:Introduire plusieurs comptes bancaires (CIN, Nom et Prénom, Montant)\n");
              printf("3:Operations : \n 3/1 : Retrait \n 3/2 : Depot\n");
              printf("4: Affichage\n");
              printf("5:Recherche par CIN \n");
              printf("6:Fidelisation\n");
              printf("7:Quitter l application\n ");
              printf("Votre choix : ");
		      scanf("%d", &choix);
		
		switch (choix)
		{
			case 1 :{
             printf("Introduire  comptes bancaires");
             n=1;
             IntroduireCompte(cptes,n);
                 break;
            }
            case 2 :{
              printf("plusieurs comptes bancaires ");
             
       
             
             
            break;
           }
				
           case 3 : printf("Operations\n 1 Retrait \n 2 Depot \n"); 
            
                printf("entrer votre choix \n");
                scanf("%d",&choix);
                 if (choix==1){
            printf("Retrait est\n");
              }
                 else if (choix==2){
            printf("Depot est\n");
            
             }
                break;
               case 4 : printf("affichage");
                break;
            case 5 :  printf("nom a rechercher : ");
			         
				 break;
                 case 6 :  printf("Fidelisation : ");
                  break;
                   case 7 :  printf("Quitter  lapplication : ");
                   printf("\n Paaaaaaaaaaaaay");
                  
                   
                  break;
                  default : break;
                  
		}
	}

    void IntroduireCompte(CMP comptes[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\n \n \n Compte num :%d \n ", i + 1);
        printf("CIN est : \t ");
        scanf("%s", comptes[i].CIN);
        printf("le Nom est  : \t ");
        scanf("%s", comptes[i].Nom);
        printf("le Prenom est: \t ");
        scanf("%s", comptes[i].Prenom);
        printf("le Montant est : \t ");
        scanf("%f", &comptes[i].Montant);
        printf("....................................................> VALIDER  \n");
    }
    
    
    
    

     
}
     
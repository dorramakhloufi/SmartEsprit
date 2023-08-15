#include <gtk/gtk.h>

typedef struct date
{
int jour;
int mois;
int annee;
}Datee;


typedef struct Etu
{


char nom[30];
char prenom[30];
char identifiant[30];
char sexe[30];
char cin[30];
char chambre[30];
char etage[30];
Datee date;
}Etu;

void affichage(GtkWidget* treeview);
void ajout(Etu s);

void suppression(char id[30], Etu s);
void recherche(GtkWidget* AStreeview);
void modification(char id[30], Etu s);
int verifid(char id[30]);
int veriff(char x[]);

void affichage_etud(char niveau[30],GtkWidget* treeview1);

typedef struct etudiant
{
char nomm[20];    
char prenomm[20];  
char cinn[20];
char sexee[20];
char niv[30];
}etudiant;
int nombrer(char niveau[30]); 

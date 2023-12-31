#include "utilisateurs.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>


enum{CHAMBRE,IDENTIFIANT,NOM,PRENOM,DATE,CIN,SEXE,ETAGE,COLUMNS};

void affichage(GtkWidget* Treeviewstock)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
Etu s;
char Identifiant[30];
char Nom[30];
char Prenom[30];
char Sexe[30];
char Cin[30];
char Chambre[30];
char Etage[30];
char Date[100]; 
store=NULL;
FILE *f=NULL;
store=gtk_tree_view_get_model(Treeviewstock);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Chambre", renderer, "text",CHAMBRE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (Treeviewstock), column);}

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text",IDENTIFIANT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (Treeviewstock), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",NOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (Treeviewstock), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text",PRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (Treeviewstock), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("DATE", renderer, "text",DATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (Treeviewstock), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text",CIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (Treeviewstock), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Sexe", renderer, "text",SEXE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (Treeviewstock), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Niveau", renderer, "text",ETAGE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (Treeviewstock), column);







store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

  f = fopen("etudiant.txt","r");

    if (f==NULL)
    {
      return;
    }
    else{
      
      while ((fscanf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",&Chambre,&Identifiant,&Nom,&Prenom,&Date,&Cin,&Sexe,&Etage)!=EOF)){

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,CHAMBRE,Chambre,IDENTIFIANT,Identifiant,NOM,Nom,PRENOM,Prenom,DATE,Date,CIN,Cin,SEXE,Sexe,ETAGE,Etage,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(Treeviewstock),GTK_TREE_MODEL (store));
g_object_unref(store);}}

void ajout (Etu s){

FILE*f=NULL; 
f=fopen("etudiant.txt","a+");
if(f!=NULL)
{

fprintf(f,"%s *** %s *** %s *** %s *** %d/%d/%d *** %s *** %s *** %s\n",s.chambre,s.identifiant,s.nom,s.prenom,s.date.jour,s.date.mois,s.date.annee,s.cin,s.sexe,s.etage);
fclose(f);

}
else printf("\n not found");
 
}
int verifid(char id[30])
{
char Identifiant[30];
char Nom[30];
char Prenom[30];
char Sexe[30];
char Cin[30];
char Chambre[30];
char Etage[30];
char Date[100]; 
   Etu s;
   int res = 1;
   FILE *f;
   f = fopen("etudiant.txt", "a+");
   if (f != NULL)
   {
       while ((fscanf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",&Chambre,&Identifiant,&Nom,&Prenom,&Date,&Cin,&Sexe,&Etage)!=EOF))
      {
         if (strcmp(id,Identifiant) == 0)
         {
            res = 0;
         }
         else
         {
            res = 1;
         }
      }
   }
   fclose(f);
   return res;
}
int veriff(char x[])
{
   int i=0;
   if (strcmp(x, "")==0)
   {
      i=0;
   }
   else
   {
      i=1;
   }
   return i;
}

void suppression(char id[30],Etu s){
char Identifiant[30];
char Nom[30];
char Prenom[30];
char Sexe[30];
char Cin[30];
char Chambre[30];
char Etage[30];
char Date[100]; 
FILE*f=NULL;
FILE*g=NULL;
f=fopen("etudiant.txt","r+");
g=fopen("neww.txt","w+");
if(g!=NULL){
while ((fscanf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",&Chambre,&Identifiant,&Nom,&Prenom,&Date,&Cin,&Sexe,&Etage)!=EOF))
{
if (strcmp(Identifiant,id)!=0){
fprintf(g,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",Chambre,Identifiant,Nom,Prenom,Date,Cin,Sexe,Etage);


}
}
}fclose(f);
fclose(g);
remove("etudiant.txt");
rename("neww.txt","etudiant.txt");
}

void modification(char id[30],Etu s)
{

	suppression(id,s);
	ajout(s);

}

void recherche(GtkWidget* Treeviewstock)
{
GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;


 FILE *f2=NULL;
Etu s;
char Nom[30];
char Prenom[30];
char Sexe[30];
char Cin[30];
char Chambre[30];
char Etage[30];
char Date[100];
char Identifiant[30];  
store=NULL; 
store=gtk_tree_view_get_model(Treeviewstock);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Chambre", renderer, "text",CHAMBRE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (Treeviewstock), column);}

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text",IDENTIFIANT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (Treeviewstock), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",NOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (Treeviewstock), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text",PRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (Treeviewstock), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("DATE", renderer, "text",DATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (Treeviewstock), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text",CIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (Treeviewstock), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Sexe", renderer, "text",SEXE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (Treeviewstock), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Niveau", renderer, "text",ETAGE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (Treeviewstock), column);
   


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f2=fopen("recherche.txt", "r");
if(f2==NULL)
{
 return;
}
else 
{ f2=fopen("recherche.txt", "a+");
    while ((fscanf(f2,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",&Chambre,&Identifiant,&Nom,&Prenom,&Date,&Cin,&Sexe,&Etage)!=EOF))
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,CHAMBRE,Chambre,IDENTIFIANT,Identifiant,NOM,Nom,PRENOM,Prenom,DATE,Date,CIN,Cin,SEXE,Sexe,ETAGE,Etage,-1);
}
fclose(f2);
gtk_tree_view_set_model (GTK_TREE_VIEW (Treeviewstock), GTK_TREE_MODEL (store));
g_object_unref (store);
}}


enum
{
	NOMM,
	PRENOMM,
	CINN,
	SEXEE,
	NIV,
	COLUMNSSS
};


void affichage_etud (char niveau[30],GtkWidget *liste)
{
  	GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;


 FILE *f=NULL;
Etu s;
char Nom[30];
char Prenom[30];
char Sexe[30];
char Cin[30];
char Chambre[30];
char Etage[30];
char Date[100];
char Identifiant[30];  
store=NULL; 
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Chambre", renderer, "text",CHAMBRE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);}

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text",IDENTIFIANT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",NOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text",PRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("DATE", renderer, "text",DATE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text",CIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Sexe", renderer, "text",SEXE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Niveau", renderer, "text",ETAGE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
   


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
 

  f = fopen("etudiant.txt","r");

    if (f==NULL)
    {
      return;
    }
    else{
      
      while ((fscanf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",&Chambre,&Identifiant,&Nom,&Prenom,&Date,&Cin,&Sexe,&Etage)!=EOF)){
if(strcmp(Etage,niveau)==0){
       gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,CHAMBRE,Chambre,IDENTIFIANT,Identifiant,NOM,Nom,PRENOM,Prenom,DATE,Date,CIN,Cin,SEXE,Sexe,ETAGE,Etage,-1);
}

      }
      fclose(f);
	


      gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		  g_object_unref(store);



    
}


}

int nombrer(char niveau[30])
{
int h=0;

 FILE *f=NULL;

char Nom[30];
char Prenom[30];
char Sexe[30];
char Cin[30];
char Chambre[30];
char Etage[30];
char Date[100];
char Identifiant[30]; 

f = fopen("etudiant.txt", "r");
while ((fscanf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",&Chambre,&Identifiant,&Nom,&Prenom,&Date,&Cin,&Sexe,&Etage)!=EOF)){
if(strcmp(Etage,niveau)==0)
h=h+1;


}fclose(f);

return h;
}

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "utilisateurs.h"

char id[30],idrech[30];
GtkWidget *Windowutil;
GtkWidget *WindowAjout;
GtkWidget *windowmodif;
GtkWidget *Accueil;
GtkWidget *windowetudd;
GtkWidget *windowealarm;
int l=0,j=1;


void
on_checkbutton_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
l=1;}
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
j=1;}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
j=2;}
}


void
on_Treeviewstock_row_activated         (GtkTreeView     *Treeviewstock,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* identifiant;
	GtkTreeModel *Model = gtk_tree_view_get_model(Treeviewstock);

		if (gtk_tree_model_get_iter(Model, &iter, path)){
				gtk_tree_model_get(GTK_LIST_STORE(Model),&iter,1,&identifiant, -1);
				strcpy(id,identifiant);}

}


void
on_buttonactualiser_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
Windowutil=lookup_widget(button,"Windowutil");
treeview=lookup_widget(Windowutil,"Treeviewstock");
affichage(treeview);

}


void
on_buttonModif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *entrymodi;
GtkWidget *Windwskippoo;
		entrymodi=lookup_widget(button,"entrymodi");
                
                Windwskippoo=create_windowmodifierr();
                gtk_widget_show (Windwskippoo);	
		gtk_entry_set_text(GTK_ENTRY(entrymodi),id);
}


void
on_buttonAjout_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowskipo;

windowskipo=create_WindowAjout();
gtk_widget_show (windowskipo);

}


void
on_buttonchercher_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

Etu s;
GtkWidget *windowskipoi;
GtkWidget *entrychercher;
GtkWidget *Treeviewstock;
GtkWidget *alert2;
FILE*f=NULL;
FILE*f2=NULL;
char Identifiant[30];
char Nom[30];
char Prenom[30];
char Sexe[30];
char Cin[30];
char Chambre[30];
char Etage[30];
char Date[100];
alert2=lookup_widget(button, "labelalertrech");
windowskipoi=lookup_widget(button,"Windowutil");
entrychercher=lookup_widget(button,"entrychercher");
strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(entrychercher)));
if (veriff(idrech)==0){gtk_label_set_text(GTK_LABEL(alert2),"Champs obligatoire!");}
else if (veriff(idrech)==1){
f=fopen("etudiant.txt","r");

 if(f!=NULL)
 {
  while ((fscanf(f,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",&Chambre,&Identifiant,&Nom,&Prenom,&Date,&Cin,&Sexe,&Etage)!=EOF))
     {
       f2=fopen("recherche.txt","a+");
       if  (f2!=NULL)
   {  
     
     if (((strcmp(Cin,idrech)==0))||((strcmp(Nom,idrech)==0)) ||((strcmp(Prenom,idrech)==0)) )
     { 
     
fprintf(f2,"%s *** %s *** %s *** %s *** %s *** %s *** %s *** %s\n",Chambre,Identifiant,Nom,Prenom,Date,Cin,Sexe,Etage);
     }
   
     Treeviewstock=lookup_widget(windowskipoi,"Treeviewstock");
     recherche(Treeviewstock);
    
        fclose(f2);
    }

 }
 fclose(f);
}
remove("recherche.txt");}


}


void
on_buttonSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
Etu s;
	    GtkWidget *treeview;
            Windowutil=lookup_widget(button,"Windowutil");
	    treeview=lookup_widget(Windowutil,"Treeviewstock");
	    suppression(id,s);
            affichage(treeview);

}


void
on_buttonAjouter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
char Chambre[30];
char Etage[30];char Date[30];char Nomm[30];char Prenomm[30];char Cinn[30];
char x[30];char Sexe[30];char lid[20];

Etu s;
GtkWidget *entryajoutid;
GtkWidget *entryNom;
GtkWidget *entryprenom;
GtkWidget *entrycin;
GtkWidget *comboboxentryrole;
GtkWidget *comboboxentrysex;
GtkWidget *comboboxentrysex1;
GtkWidget *spinbuttonday;
GtkWidget *spinbuttonmonth;
GtkWidget *spinbuttonyear;
GtkWidget *sortiea;
GtkWidget *alert1;
GtkWidget *bien_ajout;
GtkWidget *windowskipppp;
GtkWidget *comboboxentry1;

entryajoutid=lookup_widget(button,"entryajoutid");
spinbuttonday=lookup_widget(button, "spinbuttonday");
spinbuttonmonth=lookup_widget(button, "spinbuttonmonth");
spinbuttonyear=lookup_widget(button, "spinbuttonyear");
comboboxentrysex=lookup_widget(button, "radiobutton1");
comboboxentrysex1=lookup_widget(button, "radiobutton2");
comboboxentryrole=lookup_widget(button, "comboboxentryrole");
entrycin=lookup_widget(button, "entrycin");
entryNom=lookup_widget(button, "entryNom");
entryprenom=lookup_widget(button, "entryprenom");
sortiea=lookup_widget(button, "ASlabelmsgsucc");
alert1=lookup_widget(button, "ASlabelajoutalertid");
comboboxentry1=lookup_widget(button, "comboboxentry1");
strcpy(Nomm,gtk_entry_get_text(GTK_ENTRY(entryNom)));
strcpy(Prenomm,gtk_entry_get_text(GTK_ENTRY(entryprenom)));
strcpy(Cinn,gtk_entry_get_text(GTK_ENTRY(entrycin)));
strcpy(Etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentryrole)));
strcpy(Chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1)));
strcpy(x,gtk_entry_get_text(GTK_ENTRY(entryajoutid)));
if ((veriff(x)==0)||(veriff(Etage)==0)||(veriff(Chambre)==0)||(veriff(Cinn)==0)||(veriff(Nomm)==0)||(veriff(Prenomm)==0)){gtk_label_set_text(GTK_LABEL(alert1),"il faut remplir tous toutes les cases!");}
else if (veriff(x)==1){
	if(verifid(x)==0){gtk_label_set_text(GTK_LABEL(alert1),"THIS ID IS NOT AVAILABLE !");}

	else if((verifid(x)==1)&&(l==1)){

	
strcpy(s.identifiant,gtk_entry_get_text(GTK_ENTRY(entryajoutid)));
strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(entryNom)));
strcpy(s.prenom,gtk_entry_get_text(GTK_ENTRY(entryprenom)));
strcpy(s.cin,gtk_entry_get_text(GTK_ENTRY(entrycin)));
s.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonday));
s.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmonth));
s.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonyear));

if(j==1)strcpy(Sexe,"Homme");
else if (j==2) strcpy(Sexe,"Femme");
strcpy(s.sexe,Sexe);

strcpy(Etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentryrole)));
strcpy(s.etage,Etage);
strcpy(Chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1)));
strcpy(s.chambre,Chambre);

ajout(s);
gtk_label_set_text(GTK_LABEL(sortiea),"Ajout effectué avec succès!");}}

j=1;}




void
on_Buttonmodier_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

char Chambre[30];
char Etage[30];

char Nomm[30];char Prenomm[30];char Cinn[30];
char x[30];char Sexee[30];
Etu s;
GtkWidget *modifid;
GtkWidget *modifNom;
GtkWidget *modifprenom;
GtkWidget *modifcin;
GtkWidget *comboboxmodifrole;
GtkWidget *comboboxmodifsex;
GtkWidget *spinbuttondaymodif;
GtkWidget *spinbuttonmonthmodif;
GtkWidget *spinbuttonyearmodif;
GtkWidget *sortieamodif;
GtkWidget *alert1modif;
GtkWidget *comboboxentry2;


spinbuttondaymodif=lookup_widget(button, "spinbuttonjour");
spinbuttonmonthmodif=lookup_widget(button, "spinbuttonmois");
spinbuttonyearmodif=lookup_widget(button, "spinbuttonannee");
comboboxmodifsex=lookup_widget(button, "comboboxentryse");
comboboxmodifrole=lookup_widget(button, "comboboxentryrol");
modifcin=lookup_widget(button, "entryci");
modifNom=lookup_widget(button, "entrynomm");
modifprenom=lookup_widget(button, "entryprenomm");
sortieamodif=lookup_widget(button, "ASlabelmsgsucc");
alert1modif=lookup_widget(button, "ASlabelajoutalertid");
comboboxentry2=lookup_widget(button, "comboboxentry2");


strcpy(s.identifiant,id);
strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(modifNom)));
strcpy(s.prenom,gtk_entry_get_text(GTK_ENTRY(modifprenom)));
strcpy(s.cin,gtk_entry_get_text(GTK_ENTRY(modifcin)));


s.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttondaymodif));
s.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmonthmodif));
s.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonyearmodif));

strcpy(Sexee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodifsex)));
strcpy(s.sexe,Sexee);

strcpy(Etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)));
strcpy(s.etage,Etage);
strcpy(Chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodifrole)));
strcpy(s.chambre,Chambre);
strcpy(Nomm,gtk_entry_get_text(GTK_ENTRY(modifNom)));
strcpy(Prenomm,gtk_entry_get_text(GTK_ENTRY(modifprenom)));
strcpy(Cinn,gtk_entry_get_text(GTK_ENTRY(modifcin)));
strcpy(Etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodifrole)));
strcpy(Chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)));

if ((veriff(Etage)==0)||(veriff(Chambre)==0)||(veriff(Cinn)==0) ||(veriff(Sexee)==0)||(veriff(Nomm)==0)||(veriff(Prenomm)==0))
{gtk_label_set_text(GTK_LABEL(sortieamodif),"il faut remplir tous toutes les cases!");}
else if ((veriff(Etage)==1)||(veriff(Chambre)==1)||(veriff(Cinn)==1)||(veriff(Nomm)==1)||(veriff(Prenomm)==1)){
modification(id,s);gtk_label_set_text(GTK_LABEL(sortieamodif),"MODIFICATION DONE!");}


}




void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
char chr[30];
int k;
GtkWidget *labelrest;
etudiant e;
char nomm[20];    
char prenomm[20];  
char cinn[20];
char sexee[20];
char niveau[30];
GtkWidget *windowskipoii;
GtkWidget *entrychercherr;
GtkWidget *Treevieww;
GtkWidget *comboboxentry3;
FILE*f;
FILE*f2;
labelrest=lookup_widget(button,"labelrest");
windowetudd=lookup_widget(button,"windowetudd");
treeview1=lookup_widget(windowetudd,"treeview1");
comboboxentry3=lookup_widget(button, "comboboxentry3");
strcpy(niveau,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry3)));

k=nombrer(niveau);
sprintf(chr,"le nombre d etud est :%d",k);

gtk_label_set_text(labelrest,chr);

     Treevieww=lookup_widget(windowetudd,"treeview1");
     affichage_etud(niveau,treeview1);



}


void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

windowealarm=create_windowetudd();
gtk_widget_show (windowealarm);
}





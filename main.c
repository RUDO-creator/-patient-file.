#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct patient{
    int id;
     char last_name[30];
      char first_name[30];
       int age;
         char gender;
            char illness[30];
};
//-----------------------------------------------------------------------------------------
void ajoutpatinet(){
    FILE *F = fopen("patients.txt","a");

    if(F == NULL){
        printf("erreur d'ouverture du fichier\n");
        return;
    }
   struct patient P;
   printf("entre the firste name of patient ");
   scanf("%s",P.first_name);
   printf("entre the laste name of patient ");
   scanf("%s",P.last_name);
   printf("entre  the idof patient ");
   scanf("%d",&P.id);
   printf("entre  the age of patient ");
   scanf("%d",&P.age);
   printf("entre the gender of the patinet('f':female|'M':male) ");
   scanf(" %c",&P.gender);
   printf("entre the illnes of patient ");
   scanf("%s",P.illness);


    fprintf(F,"%d %s %s %d %c %s\n",P.id,P.first_name,P.last_name,P.age,P.gender,P.illness);
    fclose(F);
}
//------------------------------------------------------------------------------------------------------
int  count_F_patients() {

    FILE *F = fopen("patients.txt", "r");

    if (F == NULL) {
        printf("ereeure \n");
        return ;
    }

struct patient P;
    int count = 0;

    while (fscanf(F,"%d %s %s %d %c %s",&P.id,P.first_name,P.last_name,&P.age,&P.gender,P.illness)!=EOF){
        if (P.gender == 'F' || P.gender == 'f') {
            count++;
        }
    }

    fclose(F);
    return count;
}
//-----------------------------------------------------------------------------------------------------------
void Search_patient(){

    FILE *F = fopen("patients.txt","r");
    if(F==NULL)
        return;

    struct patient P;
    char namechercher[30];
    int trouve=0;
    printf("Entrer last name: ");
    scanf("%s",namechercher);

    while (fscanf(F,"%d %s %s %d %c %s",&P.id,P.first_name,P.last_name,&P.age,&P.gender,P.illness)!=EOF){
        if(strcmp(P.last_name,namechercher)==0)
            printf("%d %s %s %d %c %s\n",P.id,P.first_name,P.last_name,P.age,P.gender,P.illness);
            trouve=1;
    }
    if(trouve==0){
        printf("Aucun patient trouve\n");
    }

    fclose(F);
}
//--------------------------------------------------------------------------------------------------------------
void serche_by_age(){
int age_cherche;
printf("entre l'age pour la rechercher ");
scanf("%d",&age_cherche);

 FILE *F = fopen("patients.txt","r");
    if(F==NULL){
        return;
        }
  struct patient P;
  int trouve=0;

while (fscanf(F,"%d %s %s %d %c %s",&P.id,P.first_name,P.last_name,&P.age,&P.gender,P.illness)!=EOF){

        if(P.age > age_cherche){

        printf("ID:%d \nFIRST NAME:%s \nLAST NAME:%s \nAGE:%d\n GENDER:%c\nILLNESS:%s\n",P.id,P.first_name,P.last_name,P.age,P.gender,P.illness);
        trouve=1;
    }
}
if(trouve==0){
        printf("Aucun patient trouve\n");
    }
fclose(F);
}
//--------------------------------------------------------------------------------------------------------------
void search_by_letter(){

    FILE *F = fopen("patients.txt","r");
    if(F==NULL){
        printf("Erreur ouverture fichier\n");
        return;
    }

    struct patient P;
    char lettre;
    int trouve = 0;

    printf("Entrer la lettre : ");
    scanf(" %c",&lettre);

    lettre = toupper(lettre);

    while (fscanf(F,"%d %s %s %d %c %s",&P.id,P.first_name,P.last_name,&P.age,&P.gender,P.illness)!=EOF)


    {
        if(toupper(P.first_name[0]) == lettre){
            printf("ID:%d \nFIRST NAME:%s \nLAST NAME:%s \nAGE:%d\n GENDER:%c\nILLNESS:%s\n",P.id,P.first_name,P.last_name,P.age,P.gender,P.illness);

            trouve = 1;
        }
    }

    if(trouve==0){
        printf("Aucun patient trouve\n");
    }
    fclose(F);
}
//--------------------------------------------------------------------------------------------------------------
void rm_patient(){
FILE *F = fopen("patients.txt","r");
    if(F==NULL){
        printf("Erreur ouverture fichier\n");
        return;
    }
FILE *T = fopen("temp.txt","w");
    if(T==NULL){
        printf("Erreur ouverture fichier\n");
        return;
    }
    struct patient P;
    int trouve=0;
char rm_patient[30];
printf("entre the laste name of the patient to remove them:");
scanf("%s",rm_patient);


 while (fscanf(F,"%d %s %s %d %c %s",&P.id,P.first_name,P.last_name,&P.age,&P.gender,P.illness)!=EOF){
        if(strcmp(P.last_name,rm_patient)!=0){
        fprintf(T,"%d %s %s %d %c %s\n",P.id,P.first_name,P.last_name,P.age,P.gender,P.illness);

 }else{
            trouve = 1;
        }
}

 fclose(F);
    fclose(T);

remove("patients.txt");
    rename("temp.txt","patients.txt");
if(trouve){
        printf("Patient supprime avec succes\n");
}
    else{
        printf("Patient non trouve\n");
    }
}
//--------------------------------------------------------------------------------------------------------------
int main() {

    int choix;

    do {
        printf("1. Ajouter patient\n");
        printf("2. Count the number of female patients.\n");
        printf("3. Search for a patient by last name\n");
        printf("4. Search for a patient by age \n");
        printf("5. Search for a patient by letre \n");
        printf("6. remouve a patient  \n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d",&choix);

        switch(choix){

            case 1:
                ajoutpatinet();
                break;

            case 2:
                printf("Nombre de femmes : %d\n", count_F_patients());
                break;

            case 3:
                Search_patient();
                break;
            case 4:
                serche_by_age();
                break;
            case 5:
                search_by_letter();
                break;
            case 6:
                rm_patient();
                break;
            case 0:
                printf("Au revoir...\n");
                break;

            default:
                printf("Choix invalide\n");
        }

    } while(choix != 0);

    return 0;
}

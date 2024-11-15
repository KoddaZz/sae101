#include "fonctionsGlobales.h"
#include "etudiant.h"
#include "responsable.h"
#include "jury.h"
#include <stdio.h>

//
//Menu permettant le choix d'utilisateur
//
int globalProgramme(){
    int valeurEntree, caractere;
    int tNumeroEtudiant[TMAX_ETUDIANT], tReferenceStageEtudiant[TMAX_ETUDIANT], tNbrCandidatureEtudiant[TMAX_ETUDIANT], tLogEtudiant = 0;
    int tReferenceOffreStage[TMAX_OFFRESTAGE], tDept[TMAX_OFFRESTAGE], tPourvu[TMAX_OFFRESTAGE], tNbrCandidatures[TMAX_OFFRESTAGE], tPremierCandidat[TMAX_OFFRESTAGE], tSecondCandidat[TMAX_OFFRESTAGE], tTroisiemeCandidat[TMAX_OFFRESTAGE], tCandidatPourvu[TMAX_OFFRESTAGE], tLogOffreStage = 0;
    float tNoteFinale[TMAX_ETUDIANT];

    //Chargement fichier
    printf("%d %d", tLogEtudiant, tLogOffreStage);
    tLogEtudiant = fChargementEtudiant(tNumeroEtudiant, tReferenceStageEtudiant, tNoteFinale, tNbrCandidatureEtudiant, TMAX_ETUDIANT);
    tLogOffreStage = fChargementStage(tReferenceOffreStage, tDept, tPourvu, tNbrCandidatures, tPremierCandidat, tSecondCandidat, tTroisiemeCandidat, TMAX_OFFRESTAGE, tNumeroEtudiant, tLogEtudiant, tNbrCandidatureEtudiant, tCandidatPourvu);
    printf("%d %d", tLogEtudiant, tLogOffreStage);
    while(valeurEntree != -111){
        printf("\nMenu Principal\n");
        printf("\t1.\tConnexion Etudiant\n");
        printf("\t2.\tConnexion Responsable de stage\n");
        printf("\t3.\tConnexion Jury\n");
        printf("\t .\t(Pour fermer le programme tapez [-111])\n");

        caractere = scanf(" %d", &valeurEntree);
        if (caractere != 1){
            printf("\nLa valeur saisie est incorrecte,vous avez saisie un caractère veuillez saisir un entier [1 ou 2 ou 3].\n(Pour revenir en arrière tapez [-111]) :\n\n");
            while(getchar() != '\n');
        }
        else if (valeurEntree == 1){
            //etudiant
            globaleEtudiant(tNumeroEtudiant, tLogEtudiant, tNbrCandidatureEtudiant, tReferenceOffreStage, tDept, tPourvu, tNbrCandidatures, tPremierCandidat, tSecondCandidat, tTroisiemeCandidat, tLogOffreStage, tReferenceStageEtudiant, tCandidatPourvu);
        }
        else if (valeurEntree == 2){
            //responsable
            tLogOffreStage = globaleResponsable(tLogEtudiant, tReferenceStageEtudiant, tNumeroEtudiant, tPourvu, tReferenceOffreStage, tLogOffreStage, tNbrCandidatures, tPremierCandidat, tSecondCandidat, tTroisiemeCandidat, tDept);
        }
        else if (valeurEntree == 3){
            //jury
            //globalJury();
        }
        else if (valeurEntree != -111){
            //Pourquoi faire ...(Omar Sy)
            printf("\nLa valeur saisie est incorrect, veuillez un entier [1 ou 2 ou 3].\n(Pour revenir en arrière tapez [-111]) :\n\n");
        }

        //Sauvegarde fichier
        fSauvegardeEtudiant(tNumeroEtudiant, tReferenceStageEtudiant, tNoteFinale, tLogEtudiant);
        fSauvegardeStage(tReferenceOffreStage, tDept, tPourvu, tNbrCandidatures, tPremierCandidat, tSecondCandidat, tTroisiemeCandidat, tLogOffreStage, tCandidatPourvu);

    }

    return -1;

}
//
//Fin menu
//

//
//Début chargement des fichiers
//
int fChargementEtudiant(int tNumeroEtudiant[], int tReferenceStageEtudiant[], float tNoteFinale[], int tNbrCandidatureEtudiant[], int tMaxEtudiant){
    int tLogEtudiant = 0, numeroEtudiant, referenceStageEtudiant;
    float noteFinale;
    FILE *f;

    //En cas d'erreur d'ouverture
    if((f=fopen("fichiers/fEtudiant.txt","r"))==NULL){
        perror("Le fichier n'a pas pu s'ouvrir correctement.\n");
        return -1;

    }
    
    //Chargement des données
    while((fscanf(f," %d %d %f", &numeroEtudiant, &referenceStageEtudiant, &noteFinale))==3){

        //En cas de taille physique du tableau dépassé
        if(tLogEtudiant == tMaxEtudiant){
            perror("Le tableau à atteint sa taille maximale et ne peut plus être rempli.");
            return 999;
        }

        tNumeroEtudiant[tLogEtudiant] = numeroEtudiant;
        tReferenceStageEtudiant[tLogEtudiant] = referenceStageEtudiant;
        tNoteFinale[tLogEtudiant] = noteFinale;
        tNbrCandidatureEtudiant[tLogEtudiant] = 3;

        ++tLogEtudiant;

    }
    fclose(f);
    return tLogEtudiant;

}

int fChargementStage( int tReferenceOffreStage[], int tDept[], int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[], int tMaxOffreStage, int tNumeroEtudiant[], int tLogEtudiant, int tNbrCandidatureEtudiant[], int tCandidatPourvu[]){
    int tLogStage = 0, referenceStage, departement, pourvu, nbrCandidatures, premierCandidat, secondCandidat, troisiemeCandidat, i, trouve = 0, candidatPourvu;
    FILE *f;

    //En cas d'erreur d'ouverture
    if((f=fopen("fichiers/fOffreStage.txt","r"))==NULL){
        perror("Le fichier n'a pas pu s'ouvrir correctement.\n");
        return -1;
    }
  
    //Chargement des données
    while((fscanf(f," %d %d", &referenceStage, &departement))!=EOF){

        //En cas de taille physique du tableau dépassé
        if(tLogStage == tMaxOffreStage){
            perror("Le tableau à atteint sa taille maximale et ne peut plus être rempli.");
            return 999;
        }

        fscanf(f," %d", &pourvu);
        fscanf(f," %d", &nbrCandidatures);
        if(pourvu == 1){
            fscanf(f,"%d", &candidatPourvu);
        }
        else if(nbrCandidatures > 0){
            fscanf(f," %d", &premierCandidat);
            i = rechercheEtudiant(tNumeroEtudiant, tLogEtudiant, premierCandidat, &trouve);
            tNbrCandidatureEtudiant[i]--;

            if(nbrCandidatures > 1){
                fscanf(f," %d", &secondCandidat);
                i = rechercheEtudiant(tNumeroEtudiant, tLogEtudiant, secondCandidat, &trouve);
                tNbrCandidatureEtudiant[i]--;

                if(nbrCandidatures > 2){
                    fscanf(f," %d", &troisiemeCandidat);
                    i = rechercheEtudiant(tNumeroEtudiant, tLogEtudiant, troisiemeCandidat, &trouve);
                    tNbrCandidatureEtudiant[i]--;

                }
            }
        }

        tReferenceOffreStage[tLogStage] = referenceStage;
        tDept[tLogStage] = departement;
        tPourvu[tLogStage] = pourvu;
        tNbrCandidatures[tLogStage] = nbrCandidatures;
        tCandidatPourvu[tLogStage] = candidatPourvu;
        if(nbrCandidatures > 0) tPremierCandidat[tLogStage] = premierCandidat;
        if(nbrCandidatures > 1) tSecondCandidat[tLogStage] = secondCandidat;
        if(nbrCandidatures > 2) tTroisiemeCandidat[tLogStage] = troisiemeCandidat;

        ++tLogStage;
    }
  
  fclose(f);
  return tLogStage;
}
//
//Fin chargement des fichiers
//

//
//Debut sauvegarde des fichiers
//
int fSauvegardeEtudiant(int tNumeroEtudiant[], int tReferenceStageEtudiant[], float tNoteFinale[],int tLogEtudiant){
    FILE *f;

    //En cas d'erreur d'ouverture
    if((f=fopen("fichiers/fEtudiant.txt","w"))==NULL){
        perror("Le fichier n'a pas pu s'ouvrir correctement.\n");
        return -1;
    }

    //Ecriture dans le fichier
    for(int i = 0; i < tLogEtudiant; ++i){
        fprintf(f,"%d %d %.2f\n", tNumeroEtudiant[i], tReferenceStageEtudiant[i], tNoteFinale[i]);
    }

    fclose(f);
    return 0;

}

int fSauvegardeStage(int tReferenceOffreStage[], int tDept[], int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[], int tLogOffreStage, int tCandidatPourvu[]){
    FILE *f;
    int i = 0;

    //En cas d'erreur d'ouverture
    if((f=fopen("fichiers/fOffreStage.txt","w+"))==NULL){
        perror("Le fichier n'a pas pu s'ouvrir correctement.\n");
        return -1;
    }

    //Ecriture dans le fichier
    for(; i < tLogOffreStage; ++i){
        fprintf(f,"%d %d\n%d\n%d\n", tReferenceOffreStage[i], tDept[i], tPourvu[i], tNbrCandidatures[i]);
        if(tPourvu[i] == 1){
            fprintf(f,"%d\n", tCandidatPourvu[i]);
        }
        else if(tNbrCandidatures[i] > 0){
  	        fprintf(f,"%d\n", tPremierCandidat[i]);

  	        if(tNbrCandidatures[i] > 1){
      	        fprintf(f,"%d\n", tSecondCandidat[i]);

    	        if(tNbrCandidatures[i] > 2){
        	        fprintf(f,"%d\n", tTroisiemeCandidat[i]);

    	        }
  	        }
        }
    }

    fclose(f);
    return 0;

}
//
//Fin sauvegarde de fichier
//

/*
ne pas oublier de faire les fonction globale responsable et jury*/
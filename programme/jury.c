/*
#include <stdio.h>
#include "jury.h"
#include "etudiant.h"

float note_finale(float note_entreprise, float note_rapport, float note_soutenance) {
   
    int coef_entreprise = 2, coef_rapport = 1, coef_soutenance = 1;
    
    return (note_entreprise * coef_entreprise + note_rapport * coef_rapport + note_soutenance * coef_soutenance) / (coef_entreprise + coef_rapport + coef_soutenance);
}


i



int globalJury() {

    float note_entreprise = -1, note_rapport = -1, note_soutenance = -1;

int numEtudiant;
    printf("Entrez l'ID de l'étudiant : ");
    while (scanf("%d", &numEtudiant) != 1) {
        printf("ID invalide. Entrez un numéro d'étudiant valide : ");
        while(getchar() != '\n'); 
    }
    
    return 0;


        while (note_entreprise < 0 || note_entreprise > 20) {
            printf("Entrez la note de l'entreprise (coeff 2) : "); 
            scanf(" %f", &note_entreprise);
            if (note_entreprise < 0) printf ("La note est inférieure à 0. Veuillez entrer une note entre 0 et 20. ");
            else if (note_entreprise > 20) printf ("La note est supérieure à 20. Veuillez entrer une note entre 0 et 20. ");
        }

        while (note_rapport < 0 || note_rapport > 20) {
            printf("Entrez la note du rapport (coeff 1) : "); 
            scanf(" %f", &note_rapport);
            if (note_rapport < 0) printf ("La note est inférieure à 0. Veuillez entrer une note entre 0 et 20. ");
            else if (note_rapport > 20) printf ("La note est supérieure à 20. Veuillez entrer une note entre 0 et 20. ");
        }

         while (note_soutenance < 0 || note_soutenance > 20){
            printf("Entrez la note de soutenance (coeff 1) : "); 
            scanf(" %f", &note_soutenance);
            if (note_soutenance < 0) printf ("La note est inférieure à 0. Veuillez entrer une note entre 0 et 20. ");
            else if (note_soutenance > 20) printf ("La note est supérieure à 20. Veuillez entrer une note entre 0 et 20. ");
        }
        printf("La note finale est : %.2f\n", note_finale(note_entreprise, note_rapport, note_soutenance));
    
    return 0;
}
    
nt verifierStage(int tNumeroEtudiant[], int tLogEtudiant, int tReferenceOffreStage[], int tLogOffreStage, int tPourvu[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[], int indiceEtudiant) {
    for (int i = 0; i < tLogOffreStage; i++) {
        if (tPremierCandidat[i] == tNumeroEtudiant[indiceEtudiant] || tSecondCandidat[i] == tNumeroEtudiant[indiceEtudiant] || tTroisiemeCandidat[i] == tNumeroEtudiant[indiceEtudiant]) {
            if (tPourvu[i] == 1) { 
                return 1; 
            }
        }
    }
    return 0; 
}

void attribuer_note(int tNumeroEtudiant[], int tLogEtudiant, int tReferenceOffreStage[], int tLogOffreStage, int tPourvu[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[], int numEtudiant) {
    int trouve, indiceEtudiant;
    
    
    if (trouve) {
        
        if (verifierStage(tNumeroEtudiant, tLogEtudiant, tReferenceOffreStage, tLogOffreStage, tPourvu, tPremierCandidat, tSecondCandidat, tTroisiemeCandidat, indiceEtudiant)) {
            float note_entreprise, note_rapport, note_soutenance;
            
            printf("Entrez la note de l'entreprise (coeff 2) : ");
            while (scanf("%f", &note_entreprise) != 1 || note_entreprise < 0 || note_entreprise > 20) {
                printf("La note doit être entre 0 et 20. Veuillez entrer une note correcte : ");
                while(getchar() != '\n'); 
            }
            
            printf("Entrez la note du rapport (coeff 1) : ");
            while (scanf("%f", &note_rapport) != 1 || note_rapport < 0 || note_rapport > 20) {
                printf("La note doit être entre 0 et 20. Veuillez entrer une note correcte : ");
                while(getchar() != '\n'); 
            }
            
            printf("Entrez la note de soutenance (coeff 1) : ");
            while (scanf("%f", &note_soutenance) != 1 || note_soutenance < 0 || note_soutenance > 20) {
                printf("La note doit être entre 0 et 20. Veuillez entrer une note correcte : ");
                while(getchar() != '\n'); 
            }
            
           
            printf("La note finale de l'étudiant %d est : %.2f\n", numEtudiant, note_finale(note_entreprise, note_rapport, note_soutenance));
        } else {
            printf("L'étudiant %d n'a pas de stage ou n'a pas été accepté.\n", numEtudiant);
        }
    } else {
        printf("L'étudiant avec le numéro %d n'existe pas.\n", numEtudiant);
    }
}
*/
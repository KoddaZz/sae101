#include "responsable.h"
#include "etudiant.h"
#include <stdio.h>

void stagePourvuAffectation(int tLogEtudiant, int tReferenceStageEtudiant[], int tNumeroEtudiant[]){
  int i = 0;

  for(i = 0; i < tLogEtudiant; ++i){
    if(tReferenceStageEtudiant[i] != -1){
  	  printf("\nRéférence du Stage : %d\tCandidat : %d\n", tReferenceStageEtudiant[i], tNumeroEtudiant[i]);
    }

  }

  printf("\n");

}

void stageNonPourvu(int tLogOffreStage, int tPourvu[], int tReferenceOffreStage[]){
  int i = 0;
  for(i = 0; i < tLogOffreStage; ++i){
    if(tPourvu[i] == 0){
  	  printf("\nRéférence du Stage : %d\n", tReferenceOffreStage[i]);
    }

  }

  printf("\n");

}

void etudiantSansStage(int tLogEtudiant, int tReferenceStageEtudiant[], int tNumeroEtudiant[]){
  int i = 0;

  for(i = 0; i < tLogEtudiant; ++i){
    if(tReferenceStageEtudiant[i] == -1){
  	  printf("\nCandidat : %d\n", tNumeroEtudiant[i]);
    }

  }

  printf("\n");
 
}

int infoStageDonnee(int tReferenceOffreStage[], int tLogOffreStage, int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[], int tDept[]){
  int i = 0, stageSaisie, deptSaisie, trouveStage = 0, trouveDept = 0, carac, caractere, indiceRefOffreStage = -1;
  
  printf("\nSaisissez une référence de stage puis son département\n(Pour revenir en arrière tapez [-111]) :\n");
  while(trouveStage != 1){
    carac = 0;
    caractere = scanf(" %d %d", &stageSaisie, &deptSaisie);
    if (caractere != 2){
      printf("\nLa référence saisie ou le département est incorrect,vous avez saisie un caractère veuillez saisir des entiers.\n(Pour revenir en arrière tapez [-111]) :\n");
      while(getchar() != '\n');
      carac = 1;

    }
    else if(stageSaisie == -111 || deptSaisie == -111) return -1;
    trouveStage = rechercheOffreStage(tReferenceOffreStage, tLogOffreStage, stageSaisie);
    trouveDept = rechercheDept(tDept, tLogOffreStage, deptSaisie);

    if(trouveStage != 1 && carac == 0){
      trouveDept = 0;
      printf("\nLa réference  saisie est incorrect, veuillez saisir à nouveau.\n(Pour revenir en arrière tapez [-111]) :\n");
    }
    else if(trouveDept != 1 && carac == 0){
      trouveStage = 0;
      printf("\nLe département  saisie est incorrect, veuillez saisir à nouveau.\n(Pour revenir en arrière tapez [-111]) :\n");
    }
    else{
      for(i = 0; i < tLogOffreStage; ++i){
        if(tReferenceOffreStage[i] == stageSaisie && tDept[i] == deptSaisie){
          indiceRefOffreStage = i;
          trouveDept = 1;
          trouveStage = 1;
        }
        else if(indiceRefOffreStage == -1){
          trouveDept = 0;
          trouveStage = 0;
        }
      }
      if(indiceRefOffreStage == -1)printf("\nLa référence saisie n'est pas associé au bon département.\n(Pour revenir en arrière tapez [-111]) :\n"); 
    }
  }

  for(i = 0; i < tLogOffreStage; ++i){
    if(stageSaisie == tReferenceOffreStage[i]){
  	  printf("\nRéférence du Stage : %d\tDépartement : %d\nPourvu : %d\nNombre de Candidatures : %d\n\n", tReferenceOffreStage[i], tDept[i], tPourvu[i], tNbrCandidatures[i]);
  	  if(tNbrCandidatures[i] > 0){
    	  printf("Candidat 1 : %d\n", tPremierCandidat[i]);
    	  if(tNbrCandidatures[i] > 1){
      		  printf("Candidat 2 : %d\n", tSecondCandidat[i]);
      		  if(tNbrCandidatures[i] > 2) printf("Candidat 3 : %d\n", tTroisiemeCandidat[i]);

  		  }

  	  }

    }

  }

  return 0;
  printf("\n");

}

int stageFonctionReference(int tReferenceOffreStage[], int tLogOffreStage, int tDept[], int tPourvu[], int tNbrCandidatures[],int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[]){
  int i = 0, refSaisie, trouve = 0, carac, caractere;
  
  printf("\nSaisissez une référence\n(Pour revenir en arrière tapez [-111]) :\n");
  while(trouve != 1){
    carac = 0;
    caractere = scanf("%d", &refSaisie);
    if (caractere != 1){
      printf("\nLa référence saisie est incorrecte,vous avez saisie un caractère veuillez saisir des entiers.\n(Pour revenir en arrière tapez [-111]) :\n");
      while(getchar() != '\n');
      carac = 1;

    }
    else if(refSaisie == -111) return -1;
    trouve = rechercheOffreStage(tReferenceOffreStage, tLogOffreStage, refSaisie);

    if(trouve != 1 && carac == 0) printf("\nLa référence saisie est incorrecte, veuillez saisir une nouvelle référence.\n(Pour revenir en arrière tapez [-111]) :\n");
  }

  for(i = 0; i < tLogOffreStage; ++i){
    if(refSaisie == tReferenceOffreStage[i]){
  	  printf("\nRéférence du Stage : %d\tDépartement : %d\nPourvu : %d\nNombre de Candidatures : %d\n\n", tReferenceOffreStage[i], tDept[i], tPourvu[i], tNbrCandidatures[i]);
  	  if(tNbrCandidatures[i] > 0){
    	  printf("Candidat 1 : %d\n", tPremierCandidat[i]);
    	  if(tNbrCandidatures[i] > 1){
      		  printf("Candidat 2 : %d\n", tSecondCandidat[i]);
      		  if(tNbrCandidatures[i] > 2) printf("Candidat 3 : %d\n", tTroisiemeCandidat[i]);

  		  }

  	  }

    }

  }

  return 0;
  printf("\n");

}

int stageFonctionDept(int tDept[], int tLogOffreStage, int tReferenceOffreStage[], int tPourvu[], int tNbrCandidatures[],int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[]){
    int i = 0, deptSaisie, trouve = 0, carac, caractere;
  
  printf("\nSaisissez un département\n(Pour revenir en arrière tapez [-111]) :\n");
  while(trouve != 1){
    carac = 0;
    caractere = scanf("%d", &deptSaisie);
    if (caractere != 1){
      printf("\nLe département saisie est incorrect,vous avez saisie un caractère veuillez saisir des entiers.\n(Pour revenir en arrière tapez [-111]) :\n");
      while(getchar() != '\n');
      carac = 1;

    }
    else if(deptSaisie == -111) return -1;
    trouve = rechercheDept(tDept, tLogOffreStage, deptSaisie);

    if(trouve != 1 && carac == 0) printf("\nLe département saisie est incorrect, veuillez saisir un nouveau département.\n(Pour revenir en arrière tapez [-111]) :\n");
  }

  for(i = 0; i < tLogOffreStage; ++i){
    if(deptSaisie == tDept[i]){
  	  printf("\nRéférence du Stage : %d\tDépartement : %d\nPourvu : %d\nNombre de Candidatures : %d\n\n", tReferenceOffreStage[i], tDept[i], tPourvu[i], tNbrCandidatures[i]);
  	  if(tNbrCandidatures[i] > 0){
    	  printf("Candidat 1 : %d\n", tPremierCandidat[i]);
    	  if(tNbrCandidatures[i] > 1){
      		  printf("Candidat 2 : %d\n", tSecondCandidat[i]);
      		  if(tNbrCandidatures[i] > 2) printf("Candidat 3 : %d\n", tTroisiemeCandidat[i]);

  		  }

  	  }

    }

  }

  return 0;
  printf("\n");

}

int ajoutStage(int tLogOffreStage, int tReferenceOffreStage[], int tDept[], int tPourvu[], int tNbrCandidatures[]){
  int i = 0, stageSaisie, deptSaisie, caractere, carac, prochainTLog = tLogOffreStage+1, existe = 0;
  
  printf("\nSaisissez une référence de stage puis son département afin de l'ajouter\n(Pour revenir en arrière tapez [-111]) :\n");
  printf("%d", tLogOffreStage);
  while(tLogOffreStage != prochainTLog){
    carac =0;
    caractere = scanf(" %d %d", &stageSaisie, &deptSaisie);
    if (caractere != 2){
      printf("\nLa référence saisie ou le département est incorrect,vous avez saisie un caractère veuillez saisir des entiers.\n(Pour revenir en arrière tapez [-111]) :\n");
      while(getchar() != '\n');
      carac = 1;

    }
    else if(stageSaisie == -111 || deptSaisie == -111) return tLogOffreStage;
    rechercheOffreStage(tReferenceOffreStage, tLogOffreStage, stageSaisie);
    rechercheDept(tDept, tLogOffreStage, deptSaisie);

    if((stageSaisie < 0 || stageSaisie > 9999) && carac == 0){
      printf("\nLa réference saisie est incorrect, veuillez saisir à nouveau, elle doit être comprise entre 0 et 9999.\n(Pour revenir en arrière tapez [-111]) :\n");
    }
    else if((deptSaisie < 0 || deptSaisie > 99) && carac == 0){
      printf("\nLe département saisie est incorrect, veuillez saisir à nouveau, il doit être compris entre 0 et 99.\n(Pour revenir en arrière tapez [-111]) :\n");
    }
    else if(carac == 0){
      printf("%d %d %d", tLogOffreStage, stageSaisie, deptSaisie);
      tLogOffreStage++;
      for(i = 0; i < tLogOffreStage; ++i){
        if(tReferenceOffreStage[i] == stageSaisie && tDept[i] == deptSaisie){
          printf("er");
          tLogOffreStage--;
          existe = 1;
          printf("\nCette Offre de Stage existe déjà.\n");
          printf("%d", tLogOffreStage);
          return tLogOffreStage;
          
        }
        else if(i == tLogOffreStage-1 && existe != 1){
          printf("fdhhc");
          tReferenceOffreStage[tLogOffreStage-1] = stageSaisie;
          tDept[tLogOffreStage-1] = deptSaisie;
          tPourvu[tLogOffreStage-1] = 0;
          tNbrCandidatures[tLogOffreStage-1] = 0;

          printf("\nL'offre de stage %d dans le %d a bien été ajoutée\n", stageSaisie, deptSaisie);
        }
      }
    }
  }
  printf("%d", tLogOffreStage);
  return tLogOffreStage;
}


int ajoutEtudiant(int tLogEtudiant, int tNumeroEtudiant[], int tReferenceStageEtudiant[]) {
    int etudiantSaisie;
    printf("\nSaisissez le numéro de l'étudiant à ajouter (ou -111 pour annuler) :\n");
    scanf("%d", &etudiantSaisie);
    
    if (etudiantSaisie == -111) return tLogEtudiant;
    
   
    for (int i = 0; i < tLogEtudiant; i++) {
        if (tNumeroEtudiant[i] == etudiantSaisie) {
            printf("\nCet étudiant est déjà enregistré.\n");
            return tLogEtudiant;
        }
    }
    
    
    tNumeroEtudiant[tLogEtudiant] = etudiantSaisie;
    tReferenceStageEtudiant[tLogEtudiant] = -1; // 
    tLogEtudiant++;
    printf("\nL'étudiant %d a été ajouté avec succès.\n", etudiantSaisie);
    
    return tLogEtudiant;
}

void affectationStage(int tLogEtudiant, int tReferenceStageEtudiant[], int tNumeroEtudiant[], int tLogOffreStage, int tReferenceOffreStage[], int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[]) {
    int etudiantSaisie, stageSaisie;
    printf("\nEntrez le numéro de l'étudiant et la référence de stage pour l'affectation (ou tapez -111 pour annuler) :\n");
    if (scanf(" %d %d", &etudiantSaisie, &stageSaisie) != 2 || etudiantSaisie == -111 || stageSaisie == -111) {
        printf("Annulation de l'affectation.\n");
        return;
    }
    
    
    int etudiantTrouve = -1;
    for (int i = 0; i < tLogEtudiant; i++) {
        if (tNumeroEtudiant[i] == etudiantSaisie) {
            etudiantTrouve = i;
            break;
        }
    }
    
    // Vérifier si le stage existe
    int stageTrouve = -1;
    for (int i = 0; i < tLogOffreStage; i++) {
        if (tReferenceOffreStage[i] == stageSaisie) {
            stageTrouve = i;
            break;
        }
    }
    
    // Si l'étudiant et le stage sont trouvés
    if (etudiantTrouve != -1 && stageTrouve != -1) {
        if (tNbrCandidatures[stageTrouve] < 3) {
            if (tNbrCandidatures[stageTrouve] == 0)
                tPremierCandidat[stageTrouve] = etudiantSaisie;
            else if (tNbrCandidatures[stageTrouve] == 1)
                tSecondCandidat[stageTrouve] = etudiantSaisie;
            else
                tTroisiemeCandidat[stageTrouve] = etudiantSaisie;
            tNbrCandidatures[stageTrouve]++;
            tPourvu[stageTrouve] = 1;
            tReferenceStageEtudiant[etudiantTrouve] = stageSaisie;
            printf("L'étudiant %d a été affecté au stage %d avec succès.\n", etudiantSaisie, stageSaisie);
        } else {
            printf("Ce stage a déjà le nombre maximum de candidats.\n");
        }
    } else {
        printf("Étudiant ou stage non trouvé. Veuillez vérifier les entrées.\n");
    }
}

int suppressionStage(int *tLogOffreStage, int tReferenceOffreStage[], int tDept[], int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[]) {
  int refSaisie, deptSaisie, i, j;

  printf("\nEntrez la référence de stage et le département du stage à supprimer (ou tapez -111 pour annuler) :\n");
  if (scanf(" %d %d", &refSaisie, &deptSaisie) != 2 || refSaisie == -111 || deptSaisie == -111) {
    printf("Annulation de la suppression.\n");
    return *tLogOffreStage;
  }

  for (i = 0; i < *tLogOffreStage; ++i) {
    if (tReferenceOffreStage[i] == refSaisie && tDept[i] == deptSaisie) {
      
      for (j = i; j < *tLogOffreStage - 1; j++) {
        tReferenceOffreStage[j] = tReferenceOffreStage[j + 1];
        tDept[j] = tDept[j + 1];
        tPourvu[j] = tPourvu[j + 1];
        tNbrCandidatures[j] = tNbrCandidatures[j + 1];
        tPremierCandidat[j] = tPremierCandidat[j + 1];
        tSecondCandidat[j] = tSecondCandidat[j + 1];
        tTroisiemeCandidat[j] = tTroisiemeCandidat[j + 1];
      }
      (*tLogOffreStage)--; 
      printf("Stage supprimé avec succès.\n");
      return *tLogOffreStage; 
    }
  }

  
  printf("Stage non trouvé. Veuillez vérifier la référence et le département.\n");

  return *tLogOffreStage;
}
//Fonction globale du responsable de stage
int globaleResponsable(int tLogEtudiant, int tReferenceStageEtudiant[], int tNumeroEtudiant[], int tPourvu[], int tReferenceOffreStage[], int tLogOffreStage, int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[], int tDept[]){
  int valeurEntree, caractere;

  while(valeurEntree != -111){
    printf("\nMenu Responsable\n");
    printf("\t1.\tVoir les références de stage pourvues et les étudiants affectés.\n");
    printf("\t2.\tVoir les références de stage non pourvues.\n");
    printf("\t3.\tVoir la liste des étudiants n'ayant pas de stages.\n");
    printf("\t4.\tRegarder les informations pour un stage donné.\n");
    printf("\t5.\tVoir les stages en fonction de leur référence\n");
    printf("\t6.\tVoir les stages en fonction de leur département\n");
    printf("\t7.\tAjouter un stage à la liste.\n");
    printf("\t8.\tSupprimer un stage de la liste.\n");
    printf("\t9.\tAffecter un étudiant à un stage.\n");
    printf("\t10.\tAjouter un étudiant.\n");
    printf("\t .\t(Pour revenir en arrière tapez [-111])\n");

    caractere = scanf(" %d", &valeurEntree);
    if (caractere != 1){
      printf("\nLa valeur saisie est incorrecte,vous avez saisie un caractère veuillez saisir un entier [1 ou 2 ou 3 ou 4].\n(Pour revenir en arrière tapez [-111]) :\n\n");
      while(getchar() != '\n');
    }
    else if (valeurEntree == 1){
      stagePourvuAffectation(tLogEtudiant, tReferenceStageEtudiant, tNumeroEtudiant);
    }
    else if (valeurEntree == 2){
      stageNonPourvu(tLogOffreStage, tPourvu, tReferenceOffreStage);
    }
    else if (valeurEntree == 3){
      etudiantSansStage(tLogEtudiant, tReferenceStageEtudiant, tNumeroEtudiant);
    }      
    else if (valeurEntree == 4){
      infoStageDonnee(tReferenceOffreStage, tLogOffreStage, tPourvu, tNbrCandidatures, tPremierCandidat, tSecondCandidat, tTroisiemeCandidat, tDept);
    }
    else if (valeurEntree == 5){
      stageFonctionReference(tReferenceOffreStage, tLogOffreStage, tDept, tPourvu, tNbrCandidatures,tPremierCandidat, tSecondCandidat, tTroisiemeCandidat);
    }
    else if (valeurEntree == 6){
      stageFonctionDept(tDept, tLogOffreStage, tReferenceOffreStage, tPourvu, tNbrCandidatures,tPremierCandidat, tSecondCandidat, tTroisiemeCandidat);
    }
    else if (valeurEntree == 7){
      tLogOffreStage = ajoutStage(tLogOffreStage, tReferenceOffreStage, tDept, tPourvu, tNbrCandidatures);
    }
    else if (valeurEntree == 8){
      int suppressionStage(int *tLogOffreStage, int tReferenceOffreStage[], int tDept[], int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[]);
    }
    else if (valeurEntree == 9){
      void affectationStage(int tLogEtudiant, int tReferenceStageEtudiant[], int tNumeroEtudiant[], int tLogOffreStage, int tReferenceOffreStage[], int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[]);
    }   
    else if (valeurEntree == 10){
      int ajoutEtudiant(int tLogEtudiant, int tNumeroEtudiant[], int tReferenceStageEtudiant[]);
    }   
    else if (valeurEntree != -111) printf("\nLa valeur saisie est incorrect, veuillez un entier [1 ou 2 ou 3 ou 4 ou ...].\n(Pour revenir en arrière tapez [-111]) :\n\n");
    
  }
       
  return tLogOffreStage;

}

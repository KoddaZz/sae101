#include "etudiant.h"
#include <stdio.h>

int rechercheEtudiant(int tNumeroEtudiant[], int tLogEtudiant, int numARechercher, int *trouve){
  int i = 0;

  for(; i < tLogEtudiant && numARechercher > tNumeroEtudiant[i]; ++i);

  if(numARechercher == tNumeroEtudiant[i]) *trouve = 1;

  return i;

}

int rechercheOffreStage(int tReferenceOffreStage[], int tLogOffreStage, int refARechercher){
  int i = 0, trouve = 0;

  for(; i < tLogOffreStage ; ++i){
    if(refARechercher == tReferenceOffreStage[i]){
      trouve = 1;
      return trouve;

    }
    
  }

  return trouve;

}

int rechercheDept(int tDept[], int tLogOffreStage, int deptSaisie){
  int i = 0, trouve = 0;

  for(; i < tLogOffreStage ; ++i){
    if(deptSaisie == tDept[i]){
      trouve = 1;
      return trouve;

    }
    
  }

  return trouve;

}

int identificationEtudiant(int tNumeroEtudiant[], int tLogEtudiant){
  int trouve = 0, numARechercher, caractere, carac, indiceEtudiant;
  printf("Entrez votre numéro Étudiant : \n(Pour revenir en arrière tapez [-111]) :\n");

  while(trouve != 1){
    carac = 0;
    caractere = scanf("%d", &numARechercher);
    if (caractere != 1){
      printf("\nLe numéro saisie est incorrect,vous avez saisie un caractère veuillez saisir des entiers.\n(Pour revenir en arrière tapez [-111]) :\n");
      while(getchar() != '\n');
      carac = 1;

    }
    else if(numARechercher == -111) return -1;
    indiceEtudiant = rechercheEtudiant(tNumeroEtudiant, tLogEtudiant, numARechercher, &trouve);

    if(trouve != 1 && carac == 0) printf("\nLe numéro saisie est incorrect, veuillez saisir un nouveau numéro.\n(Pour revenir en arrière tapez [-111]) :\n");
  }
  printf("\n\tEtudiant %d connecté\n\n", numARechercher);
  return indiceEtudiant;

}

void consultationOffreStage(int tReferenceOffreStage[], int tDept[], int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[], int tLogOffreStage){
  int i = 0;

  for(; i < tLogOffreStage; ++i){
    if (tPourvu[i] != 1){
  	  printf("\nRéférence du Stage : %d\tDépartement : %d\nPourvu : %d\nNombre de Candidatures : %d\n", tReferenceOffreStage[i], tDept[i], tPourvu[i], tNbrCandidatures[i]);
  	  if(tNbrCandidatures[i] > 0){
    	  printf("Candidat 1 : %d\n", tPremierCandidat[i]);
    	  if(tNbrCandidatures[i] > 1){
      		  printf("Candidat 2 : %d\n", tSecondCandidat[i]);
      		  if(tNbrCandidatures[i] > 2) printf("Candidat 3 : %d\n", tTroisiemeCandidat[i]);

  		  }

  	  }

    }

  }

  printf("\n");

}

void consultationOffreStageEtudiant(int tLogOffreStage, int tPremierCandidat[], int tNumeroEtudiant[], int indiceEtudiant, int tSecondCandidat[], int tTroisiemeCandidat[], int tReferenceOffreStage[], int tDept[], int tPourvu[], int tNbrCandidatures[]){
  int i = 0;

  for(i = 0; i < tLogOffreStage; ++i){
    if(tPremierCandidat[i] == tNumeroEtudiant[indiceEtudiant] || tSecondCandidat[indiceEtudiant] == tNumeroEtudiant[i] || tTroisiemeCandidat[i] == tNumeroEtudiant[indiceEtudiant]){
  	  printf("\nRéférence du Stage : %d\tDépartement : %d\nPourvu : %d\nNombre de Candidatures : %d\n", tReferenceOffreStage[i], tDept[i], tPourvu[i], tNbrCandidatures[i]);
  	  if(tNbrCandidatures[i] > 0){
    	  printf("Candidat 1 : %d\n", tPremierCandidat[i]);
    	  if(tNbrCandidatures[i] > 1){
      		  printf("Candidat 2 : %d\n", tSecondCandidat[i]);
      		  if(tNbrCandidatures[i] > 2) printf("Candidat 3 : %d\n", tTroisiemeCandidat[i]);

  		  }

  	  }

    }

  }

  printf("\n");

}

int consultationOffreStageDept(int tDept[], int tLogOffreStage, int tReferenceOffreStage[], int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[]){
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

void consultationOffreStageAffectee(int tDept[], int tLogOffreStage, int tCandidatPourvu[], int tPourvu[], int tNumeroEtudiant[], int indiceEtudiant, int tReferenceOffreStage[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[]){
  int i = 0;

  for(i = 0; i < tLogOffreStage; ++i){
    if(tPourvu[i] == 1 && tCandidatPourvu[i] == tNumeroEtudiant[indiceEtudiant]){
  	  printf("\nRéférence du Stage : %d\tDépartement : %d\nPourvu : %d\nNombre de Candidatures : %d\nCandidat : %d\n", tReferenceOffreStage[i], tDept[i], tPourvu[i], tNbrCandidatures[i], tCandidatPourvu[i]);
  	  if(tNbrCandidatures[i] > 0){
    	  printf("Candidat 1 : %d\n", tPremierCandidat[i]);
    	  if(tNbrCandidatures[i] > 1){
      		  printf("Candidat 2 : %d\n", tSecondCandidat[i]);
      		  if(tNbrCandidatures[i] > 2) printf("Candidat 3 : %d\n", tTroisiemeCandidat[i]);

  		  }

  	  }

    }

  }

  printf("\n");

}

int candidatureEtudiant(int tNbrCandidatureEtudiant[], int indiceEtudiant, int tLogOffreStage, int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[], int tNumeroEtudiant[], int tReferenceOffreStage[], int tNbrCandidatures[], int tPourvu[],int tDept[]){
  int trouveStage = 0, trouveDept = 0, refARechercher, deptARechercher, caractere, indiceRefOffreStage = -1, carac, i;

  printf("\nIl vous reste %d candidature(s).\n", tNbrCandidatureEtudiant[indiceEtudiant]);
  printf("\tVeuiller entrez la référence de l'offre de stage à laquelle vous voulez postuler puis son département\n");

  while(trouveStage != 1){
    carac = 0;
    caractere = scanf(" %d %d", &refARechercher, &deptARechercher);
    if (caractere != 2){
      printf("\nLa référence saisie ou le département est incorrect,vous avez saisie un caractère veuillez saisir des entiers.\n(Pour revenir en arrière tapez [-111]) :\n");
      while(getchar() != '\n');
      carac = 1;

    }
    else if(refARechercher == -111 || deptARechercher == -111) return -1;
    trouveStage = rechercheOffreStage(tReferenceOffreStage, tLogOffreStage, refARechercher);
    trouveDept = rechercheDept(tDept, tLogOffreStage, deptARechercher);

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
        if(tReferenceOffreStage[i] == refARechercher && tDept[i] == deptARechercher){
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

  tNbrCandidatureEtudiant[indiceEtudiant]--;
  tNbrCandidatures[indiceRefOffreStage]++;
  
  if (tNbrCandidatures[indiceRefOffreStage] > 3){
    tNbrCandidatureEtudiant[indiceEtudiant]++;
    tNbrCandidatures[indiceRefOffreStage]--;
    printf("\nL'offre a déjà atteint le nombre de candidatures maximal.\n");
    return -1;
  }
  else if(tPremierCandidat[indiceRefOffreStage] == tNumeroEtudiant[indiceEtudiant] || tSecondCandidat[indiceRefOffreStage] == tNumeroEtudiant[indiceEtudiant] || tTroisiemeCandidat[indiceRefOffreStage] == tNumeroEtudiant[indiceEtudiant]){
    tNbrCandidatureEtudiant[indiceEtudiant]++;
    tNbrCandidatures[indiceRefOffreStage]--;
    printf("\nVous avez déjà candidaté à cette offre.\n\n");
    return -1;
  }
  else if(tPourvu[indiceRefOffreStage] == 1){
    tNbrCandidatureEtudiant[indiceEtudiant]++;
    tNbrCandidatures[indiceRefOffreStage]--;
    printf("\nCette offre de stage est déjà pourvu (pourquoi la tapez vous ?)\n\n");
    return 0;
  }
  else if(tNbrCandidatures[indiceRefOffreStage] == 1) tPremierCandidat[indiceRefOffreStage] = tNumeroEtudiant[indiceEtudiant];
  else if(tNbrCandidatures[indiceRefOffreStage] == 2) tSecondCandidat[indiceRefOffreStage] = tNumeroEtudiant[indiceEtudiant];
  else if(tNbrCandidatures[indiceRefOffreStage] == 3) tTroisiemeCandidat[indiceRefOffreStage] = tNumeroEtudiant[indiceEtudiant];

  printf("\tL'étudiant %d a bien postulé à l'offre de stage %d.\n\n", tNumeroEtudiant[indiceEtudiant], tReferenceOffreStage[indiceRefOffreStage]);

  return 0;

}

int globaleEtudiant(int tNumeroEtudiant[], int tLogEtudiant, int tNbrCandidatureEtudiant[], int tReferenceOffreStage[], int tDept[], int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[], int tLogOffreStage, int tReferenceStageEtudiant[], int tCandidatPourvu[]){
  int indiceEtudiant, valeurEntree, caractere;

  if ((indiceEtudiant = identificationEtudiant(tNumeroEtudiant, tLogEtudiant)) == -1){
    printf("\nRetour en arrière\n\n");
    return -1;
  }
  else {
    while(valeurEntree != -111){
      if(tReferenceStageEtudiant[indiceEtudiant] != -1){
        printf("\t1.\tVoir l'offre où vous avez été reçu.\n");
      }
      else {
        printf("\t1.\tVoir les références de stage non pourvu.\n");
        printf("\t2.\tVoir les offres où vous êtes candidat.\n");
        printf("\t3.\tVoir les offres en fonction du département.\n");
        if(tNbrCandidatureEtudiant[indiceEtudiant] != 0){
        printf("\t4.\tPostuler à une offre de stage.\n");
      }
      }

      printf("\t .\t(Pour revenir en arrière tapez [-111])\n");

      caractere = scanf(" %d", &valeurEntree);
      if (caractere != 1){
        if(tReferenceStageEtudiant[indiceEtudiant] != -1)printf("\nLa valeur saisie est incorrecte,vous avez saisie un caractère veuillez saisir [1].\n(Pour revenir en arrière tapez [-111]) :\n\n");
        else printf("\nLa valeur saisie est incorrecte,vous avez saisie un caractère veuillez saisir un entier [1 ou 2 ou 3 ou 4].\n(Pour revenir en arrière tapez [-111]) :\n\n");
        while(getchar() != '\n');
      }
      else if(tReferenceStageEtudiant[indiceEtudiant] != -1){
        if (valeurEntree == 1){
          consultationOffreStageAffectee(tDept, tLogOffreStage, tCandidatPourvu, tPourvu, tNumeroEtudiant, indiceEtudiant, tReferenceOffreStage, tNbrCandidatures, tPremierCandidat, tSecondCandidat, tTroisiemeCandidat);
        }
        else if (valeurEntree != -111) printf("\nLa valeur saisie est incorrect, veuillez saisir [1].\n(Pour revenir en arrière tapez [-111]) :\n\n");
      }
      else if (valeurEntree == 1){
        consultationOffreStage(tReferenceOffreStage, tDept, tPourvu, tNbrCandidatures, tPremierCandidat, tSecondCandidat, tTroisiemeCandidat, tLogOffreStage);
      }
      else if (valeurEntree == 2 && tNbrCandidatureEtudiant[indiceEtudiant] != 0){
        consultationOffreStageEtudiant(tLogOffreStage, tPremierCandidat, tNumeroEtudiant, indiceEtudiant, tSecondCandidat, tTroisiemeCandidat, tReferenceOffreStage, tDept, tPourvu, tNbrCandidatures);
      }
      else if (valeurEntree == 3 && tNbrCandidatureEtudiant[indiceEtudiant] != 0){
        consultationOffreStageDept(tDept, tLogOffreStage, tReferenceOffreStage, tPourvu, tNbrCandidatures, tPremierCandidat, tSecondCandidat, tTroisiemeCandidat);
      }      
      else if (valeurEntree == 4 && tNbrCandidatureEtudiant[indiceEtudiant] != 0){
        candidatureEtudiant(tNbrCandidatureEtudiant, indiceEtudiant, tLogOffreStage, tPremierCandidat, tSecondCandidat, tTroisiemeCandidat, tNumeroEtudiant, tReferenceOffreStage, tNbrCandidatures, tPourvu, tDept);
      }      
      else if (valeurEntree != -111) printf("\nLa valeur saisie est incorrect, veuillez un entier [1 ou 2 ou 3 ou 4].\n(Pour revenir en arrière tapez [-111]) :\n\n");
    
    }
       
    return -1;

  }

  return 0;

}

/*r(i=0;i < tLogOffreStage;++i){
  printf("%d %d\n %d\n %d\n %d\n %d\n %d\n", tReferenceOffreStage[i], tDept[i], tPourvu[i], tNbrCandidatures[i], tPremierCandidat[i], tSecondCandidat[i], tTroisiemeCandidat[i]);
}
*/
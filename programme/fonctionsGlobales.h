/**
 * \file etudiant.h
 * \author Grégoire FORTUNÉ
 * \date 14/11/24
 * \brief fonctions de gestion des étudiants
 */

#define TMAX_ETUDIANT 1000
#define TMAX_OFFRESTAGE 10000

#ifndef FONCTIONGLOBALES_H
#define FONCTIONGLOBALES_H

int globalProgramme();
int fChargementEtudiant(int tNumeroEtudiant[], int tReferenceStageEtudiant[], float tNoteFinale[], int tNbrCandidatureEtudiant[], int tMaxEtudiant);
int fChargementStage( int tReferenceOffreStage[], int tDept[], int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[], int tMaxOffreStage, int tNumeroEtudiant[], int tLogEtudiant, int tNbrCandidatureEtudiant[], int tCandidatPourvu[]);
int fSauvegardeEtudiant(int tNumeroEtudiant[], int tReferenceStageEtudiant[], float tNoteFinale[],int tLogEtudiant);
int fSauvegardeStage(int tReferenceOffreStage[], int tDept[], int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[], int tLogOffreStage, int tCandidatPourvu[]);



#endif //FONCTIONGLOBALES_H
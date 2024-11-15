/**
 * \file etudiant.h
 * \author Grégoire FORTUNÉ Farès MAZOUZ
 * \date 15/11/24
 * \brief fonctions de gestion des responsables
 */

#ifndef RESPONSABLE_H
#define RESPONSABLE_H

/**
 * 
 */
void stagePourvuAfectation(int tLogEtudiant, int tReferenceStageEtudiant[], int tNumeroEtudiant[]);

/**
 * 
 */
void stageNonPourvu(int tLogOffreStage, int tPourvu[], int tReferenceOffreStage[]);

/**
 * 
 */
void etudiantSansStage(int tLogEtudiant, int tReferenceStageEtudiant[], int tNumeroEtudiant[]);

/**
 * 
 */
int infoStageDonnee(int tReferenceOffreStage[], int tLogOffreStage, int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[], int tDept[]);

/**
 * 
 */
int stageFonctionReference(int tReferenceOffreStage[], int tLogOffreStage, int tDept[], int tPourvu[], int tNbrCandidatures[],int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[]);

/**
 * 
 */
int stageFonctionDept(int tDept[], int tLogOffreStage, int tReferenceOffreStage[], int tPourvu[], int tNbrCandidatures[],int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[]);

/**
 * 
 */
int ajoutStage(int tLogOffreStage, int tReferenceOffreStage[], int tDept[], int tPourvu[], int tNbrCandidatures[]);

/**
 * 
 */
int globaleResponsable(int tLogEtudiant, int tReferenceStageEtudiant[], int tNumeroEtudiant[], int tPourvu[], int tReferenceOffreStage[], int tLogOffreStage, int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[], int tDept[]);

/**
 * @author fares
 * @brief Ajoute un étudiant
 */
int ajoutEtudiant(int tLogEtudiant, int tNumeroEtudiant[], int tReferenceStageEtudiant[]);

/**
 * @author fares
 * @brief Affecte un stage à un étudiant 
 */
void affectationStage(int tLogEtudiant, int tReferenceStageEtudiant[], int tNumeroEtudiant[], int tLogOffreStage, int tReferenceOffreStage[], int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[]);

/**
 * @author fares
 * @brief supprime un stage
 */
int suppressionStage(int *tLogOffreStage, int tReferenceOffreStage[], int tDept[], int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[]);
#endif //RESPONSABLE_H
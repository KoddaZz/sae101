/**
 * \file etudiant.h
 * \author Farès MAZOUZ
 * \date 15/11/24
 * \brief fonctions de gestion de notes
 */

#ifndef JURY_H
#define JURY_H

/**
 * @brief fonction pour calculer la note finale
 * @param note_entreprise cest la note en entreprise
 * @param note_rapport cest la note du rapport 
 * @param note_soutenance cest la note de la soutenance
 */
float note_finale(float note_entreprise, float note_rapport, float note_soutenance);

/**
 * @brief fonction pour calculer la note finale
 * @param note_entreprise cest la note en entreprise
 * @param note_rapport cest la note du rapport 
 * @param note_soutenance cest la note de la soutenance
 */
float note_finale(float note_entreprise, float note_rapport, float note_soutenance);

/**
 * @brief fonction pour calculer la note finale
 * @param note_entreprise cest la note en entreprise
 * @param note_rapport cest la note du rapport 
 * @param note_soutenance cest la note de la soutenance
 */
int verifierStage(int tNumeroEtudiant[], int tLogEtudiant, int tReferenceOffreStage[], int tLogOffreStage, int tPourvu[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[], int indiceEtudiant);

/**
 * @brief fonction
 */
int globalJury();

#endif //JURY_H

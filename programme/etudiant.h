/**
 * \file etudiant.h
 * \author Grégoire FORTUNÉ
 * \date 15/11/24
 * \brief fonctions de gestion des étudiants
 */

#ifndef ETUDIANT_H
#define ETUDIANT_H

/**
 * \brief fonction de recherche d'un étudiant pour voir si il existe
 * \param tNumeroEtudiant tableau d'entier : contenant les numéro d'étudiant
 * \param tLogEtudiant variable int : taille logique du tableau d'entier tNumeroEtudiant
 * \param numARechercher variable int : valeur saisie qui est censé être un numéro d'étudiant
 * \param trouve pointeur sur un entier : si le numARechercher est trouvé dans le tableau il prend la valeur de 1
 * \return indiceEtudiant variable int : c'est l'indice dans le tableau tNumeroEtudiant où se trouve le numARechercher
 */
int rechercheEtudiant(int tNumeroEtudiant[], int tLogEtudiant, int numARechercher, int *trouve);

/**
 * \brief fonction de recherche d'une offre de stage
 * \param tReferenceOffreStage tableau d'entier : contenant les référence des offres de stages
 * \param tlogOffreStage variable int : taille logique du tableau d'entier tReferenceOfrreStage
 * \param refARechercher variable int : valeur saisie qui est censé êtree une référence de stage
 * \return trouve variable int : permet de savoir si la référence de l'offre de stage est trouvée
*/
int rechercheOffreStage(int tReferenceOffreStage[], int tLogOffreStage, int refARechercher);

/**
 * \brief fonction de recherche d'un département
 * \param tDept tableau d'entier : contenant les départements des offres de stage
 * \param tlogOffreStage variable int : taille logique du tableau d'entier tDept
 * \param deptSaisie variable int : valeur saisie qui est censé êtree un département
 * \return trouve variable int : permet de savoir si le département est trouvée
*/
int rechercheDept(int tDept[], int tLogOffreStage, int deptSaisie);

/**
 * \brief fonction permettant à un étudiant de s'identifier
 * \param tNumeroEtudiant tableau d'entier : contenant les numéro d'étudiant
 * \param tLogEtudiant variable int : taille logique du tableau d'entier tNumeroEtudiant
 * \return indiceEtudiant variable int : c'est l'indice dans le tableau tNumeroEtudiant où se trouve le numARechercher
 */
int identificationEtudiant(int tNumeroEtudiant[], int tLogEtudiant);

/**
 * \brief fonction affichant en détail toutes les offres de stage non pourvu
 * \param tReferenceOffreStage tableau d'entier : contenant les référence des offres de stages
 * \param tDept tableau d'entier : contenant les départements des offres de stage
 * \param tPourvu tableau d'entier : contenant la valeur si le stage est pourvu
 * \param tNbrCandidatures tableau d'entier : contenant le nombre de candidature
 * \param tPremierCandidat tableau d'entier : contenant le numéro du premier candidat inscrit
 * \param tSecondCandidat tableau d'entier : contenant le numéro du second candidat inscrit
 * \param tTroisiemeCandidat tableau d'entier : contenant le numéro du troisieme candidat inscrit
 * \param tLogOffreStage variable int : taille logique des tableaux précédent
 */
void consultationOffreStage(int tReferenceOffreStage[], int tDept[], int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int  [], int tTroisiemeCandidat[], int tLogOffreStage);

/**
 * \brief fonction d'affichage des offres de stage ou le candidat connecté à postulé
 * \param tLogOffreStage variable int : taille logique des tableaux chargeé avec le fichier offreStage
 * \param tPremierCandidat tableau d'entier : contenant le numéro du premier candidat inscrit
 */
void consultationOffreStageEtudiant(int tLogOffreStage, int tPremierCandidat[], int tNumeroEtudiant[], int indiceEtudiant, int tSecondCandidat[], int tTroisiemeCandidat[], int tReferenceOffreStage[], int tDept[], int tPourvu[], int tNbrCandidatures[]);

/**
 * 
 */
int consultationOffreStageDept(int tDept[], int tLogOffreStage, int tReferenceOffreStage[], int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[]);

/**
 * 
 */
void consultationOffreStageAffectee(int tDept[], int tLogOffreStage, int tCandidatPourvu[], int tPourvu[], int tNumeroEtudiant[], int indiceEtudiant, int tReferenceOffreStage[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[]);

/**
 * \brief
 */
int candidatureEtudiant(int tNbrCandidatureEtudiant[], int indiceEtudiant, int tLogOffreStage, int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[], int tNumeroEtudiant[], int tReferenceOffreStage[], int tNbrCandidatures[], int tPourvu[],int tDept[]);

/**
 * 
 */
int globaleEtudiant(int tNumeroEtudiant[], int tLogEtudiant, int tNbrCandidatureEtudiant[], int tReferenceOffreStage[], int tDept[], int tPourvu[], int tNbrCandidatures[], int tPremierCandidat[], int tSecondCandidat[], int tTroisiemeCandidat[], int tLogOffreStage, int tReferenceStageEtudiant[], int tCandidatPourvu[]);

#endif //ETUDIANT_H

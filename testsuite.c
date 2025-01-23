/*************** Tests unitaires du module math ****************/
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "math.h"
#include <stdio.h>

#include "nombre.h"
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

/** Montage de la fixation - appelé avant chaque cas de test. **/
int init_suite(void) { return 0; }

/* Démontage de la fixation - appelé après chaque cas de test. */
int clean_suite(void) { return 0; }

/****** Cas de test - nominal *****/
void echo_valide(void) {
  CU_ASSERT_EQUAL(traiter_commande_wrapper(5,[./a.out,172.0.0.1,2000,message,4],
}

void envoie_message_bien(void){
	CU_ASSERT_EQUAL(envoyer_message("bonjour"),

/******************* Lancement des tests ***********************/
int main ( void )
{
   CU_pSuite pSuite = NULL;
   unsigned int status = 0;

   /* initialisation des test CUnit */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* ajout de la suite de test */
   pSuite = CU_add_suite( "Test module math", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* ajout des cas de test dans la suite de test */
   if ( (NULL == CU_add_test(pSuite, "Cas de test - maximum avec arguments du même signe", test_maximum_meme_signe)) ||
        (NULL == CU_add_test(pSuite, "Cas de test - maximum avec arguments de signes opposés", test_maximum_signes_opposes)) ||
        (NULL == CU_add_test(pSuite, "Cas de test - maximum avec arguments égaux", test_maximum_egalite))
      )
   {;
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* lancement de tous les tests avac l'interface de base */
   CU_basic_set_mode(CU_BRM_NORMAL);
   if ( CUE_SUCCESS != CU_basic_run_tests() )
      return CU_get_error();
   
   status = CU_get_number_of_tests_failed();
   CU_basic_show_failures(CU_get_failure_list());
  
   /* cloture des tests */
   CU_cleanup_registry();
   return status;
}

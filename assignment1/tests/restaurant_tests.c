#include "../a1.h"
#include "a1_starter_tests.h"

TestResults* test_restaurant(){
	TestResults* test_results_single = (TestResults*)malloc(sizeof(TestResults));
	TestResults* test_results_all = (TestResults*)malloc(sizeof(TestResults));	
	
	test_results_all->mistakes = 0;
	test_results_all->correct = 0;
	
	char* restaurant_name = "McBonalbs";
	Restaurant* restaurant = initialize_restaurant(restaurant_name);
	
	fprintf(stdout, "=============================================================\n");
	fprintf(stdout, "|| Checking restaurant initialization... \n");
	
	test_results_single->mistakes = 0;
	test_results_single->correct = 0;
	
	if(strcmp(restaurant->name, restaurant_name) != 0){
		fprintf(stdout, "|| ERROR! Expected restaurant name to be %s, got %s.\n", 
							restaurant_name, restaurant->name);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(restaurant->num_pending_orders != 0){
		fprintf(stdout, "|| ERROR! Expected restaurant->num_pending_orders name to be %d, got %d.\n", 
							0, restaurant->num_pending_orders );
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(restaurant->num_completed_orders != 0){
		fprintf(stdout, "|| ERROR! Expected restaurant->num_completed_orders name to be %d, got %d.\n", 
							0, restaurant->num_completed_orders );
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(restaurant->pending_orders->head != NULL){
		fprintf(stdout, "|| ERROR! Expected restaurant->pending_orders->head to be NULL, got %p.\n", 
							restaurant->pending_orders->head);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(restaurant->pending_orders->tail != NULL){
		fprintf(stdout, "|| ERROR! Expected restaurant->pending_orders->tail to be NULL, got %p.\n", 
							restaurant->pending_orders->tail);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}	

	fprintf(stdout, "|| [%d/%d] restaurant initialization check.      \n",
		test_results_single->correct, 
		test_results_single->correct + test_results_single->mistakes);
	fprintf(stdout, "=============================================================\n");
	
	test_results_all->mistakes = test_results_all->mistakes + test_results_single->mistakes;	
	test_results_all->correct = test_results_all->correct + test_results_single->correct;	
	
	free(test_results_single);	
	
	close_restaurant(&restaurant);
	return test_results_all;
}

int main(){
	run_tests("RESTAURANT TESTER", &test_restaurant);
}

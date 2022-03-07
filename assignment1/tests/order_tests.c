#include "../a1.h"
#include "a1_starter_tests.h"

TestResults* test_order_init(){
	TestResults* test_results_single = (TestResults*)malloc(sizeof(TestResults));
	TestResults* test_results_all = (TestResults*)malloc(sizeof(TestResults));	
	
	test_results_all->mistakes = 0;
	test_results_all->correct = 0;
	
	Order* order = build_order("L1L2", "5,10");
	
	fprintf(stdout, "=============================================================\n");
	fprintf(stdout, "|| Checking order initialization... \n");
	
	test_results_single->mistakes = 0;
	test_results_single->correct = 0;
	
	if(order->num_items != 2){
		fprintf(stdout, "|| ERROR! Expected order->num_items to be %d, got %d.\n", 
							2, order->num_items);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(strcmp(order->item_codes[0], "L1") != 0 ){
		fprintf(stdout, "|| ERROR! Expected order->item_codes[0] to be %s, got %s.\n", 
							"L1", order->item_codes[0]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(strcmp(order->item_codes[1], "L2") != 0 ){
		fprintf(stdout, "|| ERROR! Expected order->item_codes[1] to be %s, got %s.\n", 
							"L2", order->item_codes[1]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(order->item_quantities[0] != 5){
		fprintf(stdout, "|| ERROR! Expected order->item_quantities[0] to be %d, got %d.\n", 
							5, order->item_quantities[0]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(order->item_quantities[1] != 10){
		fprintf(stdout, "|| ERROR! Expected order->item_quantities[1] to be %d, got %d.\n", 
							10, order->item_quantities[10]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	fprintf(stdout, "|| [%d/%d] order initialization check.      \n",
		test_results_single->correct, 
		test_results_single->correct + test_results_single->mistakes);
	fprintf(stdout, "=============================================================\n");
	
	test_results_all->mistakes = test_results_all->mistakes + test_results_single->mistakes;	
	test_results_all->correct = test_results_all->correct + test_results_single->correct;	
	
	clear_order(&order);
	free(test_results_single);
	return test_results_all;
}

int main(){
	run_tests("ORDER INITIALIZATION TESTER", &test_order_init);
}



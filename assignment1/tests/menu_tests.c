#include "../a1.h"
#include "a1_starter_tests.h"

TestResults* test_menu(){
	TestResults* test_results_single = malloc(sizeof(TestResults));
	TestResults* test_results_all = malloc(sizeof(TestResults));	
	
	test_results_all->mistakes = 0;
	test_results_all->correct = 0;
	
	char* menu_fname = "menu.txt";
	fprintf(stdout, "Loading menu from %s.\n",
			menu_fname);
	Menu* menu = load_menu(menu_fname);
	

	/**
		CHECKING ITEM NAMES
	*/
	test_results_single->mistakes = 0;
	test_results_single->correct = 0;
	
	/**
		CHECKING ITEM COUNTS
	*/
	if(menu->num_items != 6){
		fprintf(stdout, "=============================================================\n");
		fprintf(stdout, "|| ERROR! Expected menu's num_items to be %d, got %d.\n", 
						6, menu->num_items);
		fprintf(stdout, "=============================================================\n");
		test_results_all->mistakes++;
	} else {
		test_results_all->correct++;
	}	
	
	fprintf(stdout, "=============================================================\n");
	fprintf(stdout, "|| Checking item names are stored correctly in the menu... \n");
	if(strcmp(menu->item_names[0], "Chicken Sandwich") != 0){
		fprintf(stdout, "|| ERROR! Expected item name at index 0 to be %s, got %s.\n", 
						"Chicken Sandwich", menu->item_names[0]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(strcmp(menu->item_names[1], "Egg Salad Sandwich") != 0){
		fprintf(stdout, "|| ERROR! Expected item name at index 1 to be %s, got %s.\n", 
						"Egg Salad Sandwich", menu->item_names[1]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(strcmp(menu->item_names[2], "Fresh Greens") != 0){
		fprintf(stdout, "  ERROR! Expected item name at index 2 to be %s, got %s.\n", 
						"Fresh Greens", menu->item_names[2]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(strcmp(menu->item_names[3], "Steak and Potatoes") != 0){
		fprintf(stdout, "|| ERROR! Expected item name at index 3 to be %s, got %s.\n", 
						"Steak and Potatoes", menu->item_names[3]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(strcmp(menu->item_names[4], "Coffee") != 0){
		fprintf(stdout, "|| ERROR! Expected item name at index 4 to be %s, got %s.\n", 
						"Coffee", menu->item_names[4]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(strcmp(menu->item_names[5], "Hot Chocolate") != 0){
		fprintf(stdout, "|| ERROR! Expected item name at index 4 to be %s, got %s.\n", 
						"Hot Chocolate", menu->item_names[5]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	fprintf(stdout, "|| [%d/%d] item names are stored correctly in the menu.      \n",
			test_results_single->correct, 
			test_results_single->correct + test_results_single->mistakes);
	fprintf(stdout, "=============================================================\n");
			
	test_results_all->mistakes = test_results_all->mistakes + test_results_single->mistakes;	
	test_results_all->correct = test_results_all->correct + test_results_single->correct;	
	
	/**
		CHECKING ITEM CODES
	*/	
	test_results_single->mistakes = 0;
	test_results_single->correct = 0;
	
	fprintf(stdout, "=============================================================\n");
	fprintf(stdout, "|| Checking item codes are stored correctly in the menu... \n");
			
	if(strcmp(menu->item_codes[0], "L1") != 0){
		fprintf(stdout, "|| ERROR! Expected item code at index 0 to be %s, got %s.\n", 
						"L1", menu->item_codes[0]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(strcmp(menu->item_codes[1], "L2") != 0){
		fprintf(stdout, "|| ERROR! Expected item code at index 1 to be %s, got %s.\n", 
						"L2", menu->item_codes[1]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(strcmp(menu->item_codes[2], "L3") != 0){
		fprintf(stdout, "|| ERROR! Expected item code at index 2 to be %s, got %s.\n", 
						"L3", menu->item_codes[2]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(strcmp(menu->item_codes[3], "D1") != 0){
		fprintf(stdout, "|| ERROR! Expected item code at index 3 to be %s, got %s.\n", 
						"D1", menu->item_codes[3]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(strcmp(menu->item_codes[4], "B1") != 0){
		fprintf(stdout, "|| ERROR! Expected item code at index 4 to be %s, got %s.\n", 
						"B1", menu->item_codes[4]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(strcmp(menu->item_codes[5], "B2") != 0){
		fprintf(stdout, "|| ERROR! Expected item code at index 5 to be %s, got %s.\n", 
						"B2", menu->item_codes[5]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	
	fprintf(stdout, "|| [%d/%d] item codes are stored correctly in the menu.      \n",
			test_results_single->correct, 
			test_results_single->correct + test_results_single->mistakes);
		fprintf(stdout, "=============================================================\n");
			
	test_results_all->mistakes = test_results_all->mistakes + test_results_single->mistakes;	
	test_results_all->correct = test_results_all->correct + test_results_single->correct;	
	
	/**
		CHECKING ITEM COSTS
	*/	
	test_results_single->mistakes = 0;
	test_results_single->correct = 0;
	
	fprintf(stdout, "=============================================================\n");
	fprintf(stdout, "|| Checking item costs are stored correctly in the menu... \n");
	if(menu->item_cost_per_unit[0] != 5.99){
		fprintf(stdout, "|| ERROR! Expected item cost at index 0 to be %.2f, got %.2f.\n", 
						5.99, menu->item_cost_per_unit[0]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(menu->item_cost_per_unit[1] != 4.50){
		fprintf(stdout, "|| ERROR! Expected item cost at index 1 to be %.2f, got %.2f.\n", 
						4.50, menu->item_cost_per_unit[1]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(menu->item_cost_per_unit[2] != 8.50){
		fprintf(stdout, "|| ERROR! Expected item cost at index 2 to be %.2f, got %.2f.\n", 
						8.50, menu->item_cost_per_unit[2]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}	
	if(menu->item_cost_per_unit[3] != 12.99){
		fprintf(stdout, "|| ERROR! Expected item cost at index 3 to be %.2f, got %.2f.\n", 
						12.99, menu->item_cost_per_unit[3]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}
	if(menu->item_cost_per_unit[4] != 2.99){
		fprintf(stdout, "|| ERROR! Expected item cost at index 4 to be %.2f, got %.2f.\n", 
						2.99, menu->item_cost_per_unit[4]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}	
	if(menu->item_cost_per_unit[5] != 3.50){
		fprintf(stdout, "|| ERROR! Expected item cost at index 5 to be %.2f, got %.2f.\n", 
						3.50, menu->item_cost_per_unit[5]);
		test_results_single->mistakes++;
	} else {
		test_results_single->correct++;
	}	
	
	fprintf(stdout, "|| [%d/%d] item costs are stored correctly in the menu.      \n",
		test_results_single->correct, 
		test_results_single->correct + test_results_single->mistakes);
	fprintf(stdout, "=============================================================\n");
	
	test_results_all->mistakes = test_results_all->mistakes + test_results_single->mistakes;	
	test_results_all->correct = test_results_all->correct + test_results_single->correct;	
	
	// Cleaning up 
	free(test_results_single);
	clear_menu(&menu);

	return test_results_all;
}

int main(){
	run_tests("MENU TESTER", &test_menu);
}
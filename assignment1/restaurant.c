#include "a1.h"
#define CLOSING_OPTION 3

int main(){
	char* restaurant_name = "Tim Bortons";
	int choice = -1;
	
	int num_pending_orders;
	int num_completed_orders;
	
	// just ... dont enter too many items....
	char str_input1[100];
	char str_input2[100];
	memset(str_input1, '\0', sizeof(char) * 100);
	memset(str_input2, '\0', sizeof(char) * 100);
	
	fprintf(stdout, "Welcome to %s!\n", restaurant_name);
	
	char* options_str = "Options:\n"
	"\t (%d) Take an order\n"
	"\t (%d) Process an order\n"
	"\t (%d) Close the restaurant\n"
	">>> ";
	
	Restaurant* restaurant = initialize_restaurant(restaurant_name);
	
	while (choice != CLOSING_OPTION){
		fprintf(stdout, options_str, 1, 2, 3);
		fscanf(stdin, "%d", &choice);
		
		switch (choice){
			case 1:
				fprintf(stdout, 
					"----------------------------------------------\n"
					"|           STARTING TAKE AN ORDER           |\n"
					"----------------------------------------------\n"
				);
				num_pending_orders = get_num_pending_orders(restaurant);
				num_completed_orders = get_num_completed_orders(restaurant);
				fprintf(stdout, "Number of completed orders: %d\nNumber of pending orders: %d\n",
					num_completed_orders, num_pending_orders);
				
				print_menu(restaurant->menu);
				
				fprintf(stdout, "Enter a sequence of %d-digit item codes: ", ITEM_CODE_LENGTH - 1);
				fscanf(stdin, "%s", str_input1); // it's not a string literal here, haha
		
				fprintf(stdout, "Enter  '%s'-delimited integer quantities of each item: ", MENU_DELIM);
				fscanf(stdin, "%s", str_input2);	
				
				Order *new_order = build_order(str_input1, str_input2);
				enqueue_order(new_order, restaurant);
				
				fprintf(stdout, "Order taken: \n");
				print_order(new_order);
				
				num_pending_orders = get_num_pending_orders(restaurant);
				num_completed_orders = get_num_completed_orders(restaurant);
				fprintf(stdout, "Number of completed orders: %d\nNumber of pending orders: %d\n",
					num_completed_orders, num_pending_orders);
				fprintf(stdout, 
					"----------------------------------------------\n"
					"|          COMPLETED TAKE AN ORDER           |\n"
					"----------------------------------------------\n"
				);
				break;
			case 2:
				fprintf(stdout, 
					"----------------------------------------------\n"
					"|          STARTING PROCESS AN ORDER         |\n"
					"----------------------------------------------\n"
				);
				fprintf(stdout, "----------- STARTING PROCESS AN ORDER -----------");
				num_pending_orders = get_num_pending_orders(restaurant);
				num_completed_orders = get_num_completed_orders(restaurant);
				fprintf(stdout, "Number of completed orders: %d\nNumber of pending orders: %d\n",
					num_completed_orders, num_pending_orders);
				
				if (num_pending_orders != 0){
					Order* dequeued_order = dequeue_order(restaurant);
					fprintf(stdout, "Now processing order...\n");
					print_receipt(dequeued_order, restaurant->menu);
					clear_order(&dequeued_order);
				
					num_pending_orders = get_num_pending_orders(restaurant);
					num_completed_orders = get_num_completed_orders(restaurant);
					fprintf(stdout, "Number of completed orders: %d\nNumber of pending orders: %d\n",
					num_completed_orders, num_pending_orders);
					
				} else {
					fprintf(stdout, "No pending orders available for processing...\n");
				}

					
				fprintf(stdout, 
					"----------------------------------------------\n"
					"|         COMPLETED PROCESS AN ORDER         |\n"
					"----------------------------------------------\n"
				);
				break;
			case 3:
				fprintf(stdout, 
					"----------------------------------------------\n"
					"|          STARTING CLOSE RESTAURANT         |\n"
					"----------------------------------------------\n"
				);
				close_restaurant(&restaurant);
				fprintf(stdout, "Thank you for coming to %s. Goodbye...\n", restaurant_name);
				fprintf(stdout, 
					"----------------------------------------------\n"
					"|         COMPLETED CLOSE RESTAURANT         |\n"
					"----------------------------------------------\n"
				);
				break;
			default:
				fprintf(stdout, 
					"----------------------------------------------\n"
					"|              ?!!!! ERROR !!!!?             |\n"
					"----------------------------------------------\n"
				);
				fprintf(stdout, "Your entry (%d) is not a valid option...\nEnter a valid numeric option\n", choice);
		}
		
	}


	return 0;
}
#define  _GNU_SOURCE
#include "a1.h"

/**
	Add your functions to this file.
	Make sure to review a1.h.
	Do NOT include a main() function in this file
	when you submit.
*/

Queue * initialize_queue(){
	Queue * q = malloc(sizeof(Queue));
	q->head = NULL;
	q->tail = NULL;
	return q;
};

Restaurant* initialize_restaurant(char* name) {
	Restaurant * resto = malloc(sizeof(Restaurant));

	resto->name = malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(resto->name, name);

	resto->num_completed_orders = 0;
	resto->num_pending_orders = 0;

	resto->pending_orders = initialize_queue();
	resto->menu = load_menu(MENU_FNAME);

	return resto;
};


int in(char character, char elements[], int n) {
	for (int i = 0; i < n; i++){
		if(character==elements[i]) return 1;
	}
	return 0;
}

int empty_line(char * line,char elements[], int n) {
	for(int i = 0; i < strlen(line); i++) {
		if(!in(line[i], elements, n)) return 0;
	}
	return 1;
}

Menu* load_menu(char* fname){
	FILE *fp = fopen(fname, "r");
	char* line = NULL;
	size_t line_len = 0;

	char whitespace[]= {'\n', '\r', '\t', ' '};
	int n = 4;
	Menu *menu = malloc(sizeof(Menu)); //initialize menu struct
	int count = 0; //count the # of lines in the strini
	int empty = 0;
	while(getline(&line, &line_len, fp) != -1){
		if(empty_line(line, whitespace, n)) empty ++;
		count++;
	}

	count = count - empty;

	free(line);

	//allocate memory for contents of struct
	menu->num_items = count;
  //printf("%i\n", count);
	menu->item_codes = malloc(sizeof(char*)*count + 1);
	menu->item_names = malloc(sizeof(char*)*count + 1);
	menu->item_cost_per_unit = malloc(sizeof(double*)*count + 1);
  fclose(fp);

	//go through the menu.txt file again, split up each line by commas and add the individual sections to the struct
  	FILE *fp1 = fopen(fname, "r");
	char* line1 = NULL;
	size_t line_len1 = 0;
	count = 0;

	for (int i = 0; i < empty; i ++){
		getline(&line1, &line_len1, fp1);
	}
  

	while(getline(&line1, &line_len1, fp1) != -1){ //implicitly allocates memory to line1 -> need to be freed
		int index = 0;
		
		// while (in(line1[index], whitespace, n)) index ++;
		// char * temp = malloc(sizeof(char) * strlen(&(line1[index])));
		// strcpy(temp, &(line1[index]));
  //   free(line1);
		// line1 = temp;
    // printf("%s\n", line1);
    // return menu;
		char *token;

		token = strtok(line1, MENU_DELIM);
		menu->item_codes[count] = malloc(sizeof(char)*ITEM_CODE_LENGTH); 
    
    //allocate space for item_code 
		strcpy(menu->item_codes[count], token); //copy item_code into struct


		token = strtok(NULL, MENU_DELIM);

		(menu->item_names)[count] = malloc(sizeof(char) * (MAX_ITEM_NAME_LENGTH + 1));
		strcpy((menu->item_names)[count], token);

		token = strtok(NULL, MENU_DELIM);

		menu->item_cost_per_unit[count] = atof(&(token[1]));


		count++;
	}
	free(line1);

	fclose(fp1); // close file

	return menu;

}

// Menu* load_menu(char* fname) {
// 	FILE* file_ptr, *fp;

// 	fp = fopen(fname, "r");

// 	char ch;
// 	int lines = 0;

// 	while(!feof(fp))
// 	{
// 		ch = fgetc(fp);
// 		if(ch == '\n') lines++;
// 	}
// 	lines ++;
// 	fclose(fp);
	

// 	Menu * menu = malloc(sizeof(Menu));
// 	menu->item_codes = malloc(sizeof(char *) * lines);
// 	menu->item_names = malloc(sizeof(char *) * lines);
// 	menu->item_cost_per_unit = malloc(sizeof(double) * lines);
// 	menu->num_items = lines;

// 	char * code, * item, * price;

// 	char* line = NULL;
// 	size_t line_len = 0;

// 	file_ptr = fopen(fname, "r+");
// 	for (int index = 0; index < lines ; index ++){
// 		getline(&line, &line_len, file_ptr);
// 		code = strtok(line, MENU_DELIM);
// 		item = strtok(NULL, MENU_DELIM);
// 		price = strtok(NULL, "\n");
    
// 		menu->item_codes[index] = malloc(sizeof(char) * ITEM_CODE_LENGTH);
// 		strcpy(menu->item_codes[index], code);

// 		menu->item_names[index] = malloc(sizeof(char) * strlen(item));
// 		strcpy(menu->item_names[index], item);

// 		menu->item_cost_per_unit[index] = atof(&(price[1]));
// 	}

//   	free(line);

//     fclose(file_ptr);
	

//     return menu;
// }

Order* build_order(char* items, char* quantities) {
	Order * order = malloc(sizeof(Order));
	order->num_items = strlen(items)/2;
	order->item_codes = malloc(sizeof(char *) * (order->num_items));
	order->item_quantities = malloc(sizeof(int) * (order->num_items));

	const char s[] = ",";

	char *token= strtok(quantities, s);
	int i = 0;
	while( token != NULL ) {
		order->item_codes[i] = malloc(sizeof(char) * ITEM_CODE_LENGTH);
		strncpy(order->item_codes[i], items + i * (ITEM_CODE_LENGTH - 1),  (ITEM_CODE_LENGTH - 1));
    order->item_codes[i][2] = '\0';
		order->item_quantities[i] = atoi(token);
		i ++;
		token= strtok(NULL, s);
	}

	return order;
}; 


void enqueue_order(Order* order, Restaurant* restaurant) {
	QueueNode * new_tail = malloc(sizeof(QueueNode));
	new_tail->order = order;
	new_tail->next = NULL;
	if(restaurant->pending_orders->tail) restaurant->pending_orders->tail->next = new_tail;
	else restaurant->pending_orders->head = new_tail;
	restaurant->pending_orders->tail = new_tail;
	restaurant->num_pending_orders ++;
};

Order* dequeue_order(Restaurant* restaurant) {
	if(!restaurant->pending_orders->head){
    	return NULL;
  	}
	
	QueueNode * to_remove = restaurant->pending_orders->head;
	restaurant->pending_orders->head = restaurant->pending_orders->head->next;
	to_remove->next = NULL;

	// Get order
	Order * resultant_order = to_remove->order;

	free(to_remove);

	restaurant->num_pending_orders --;
	restaurant->num_completed_orders ++;
	if(restaurant->num_pending_orders == 0) restaurant->pending_orders->tail = NULL;

	return resultant_order;
};

/*
	Getting information about our orders and order status
*/
double get_item_cost(char* item_code, Menu* menu){
  int i;
	for(i = 0; i < menu->num_items; i ++) {
		if(strcmp(menu->item_codes[i], item_code) == 0) break;
	}
	return (double) menu->item_cost_per_unit[i];
};

double get_order_subtotal(Order* order, Menu* menu){
	double sub_total = 0;
	for(int i = 0; i < order->num_items; i ++) {
		sub_total += get_item_cost(order->item_codes[i], menu) * ((double) order->item_quantities[i]);
	}

	return sub_total;
};

double get_order_total(Order* order, Menu* menu){
	double sub_total = get_order_subtotal(order, menu);
	return sub_total *(double) (1 + (double)TAX_RATE/100);
}

int get_num_completed_orders(Restaurant* restaurant){
	return restaurant->num_completed_orders;
}
int get_num_pending_orders(Restaurant* restaurant){
	return restaurant->num_pending_orders;
}

/*
	Closing down and deallocating memory
*/
void clear_order(Order** order) {
	for (int i = 0; i < (*order)->num_items; i ++) {
		free((*order)->item_codes[i]);
	} 
	free((*order)->item_codes);
	free((*order)->item_quantities);
	free(*order);
	*order = NULL;
}

void clear_menu(Menu** menu) {
	for(int i = 0; i < (*menu)->num_items; i ++) {
		free((*menu)->item_codes[i]);
		free((*menu)->item_names[i]);
	}
	free((*menu)->item_codes);
	free((*menu)->item_names);
	free((*menu)->item_cost_per_unit);
	free(*menu);
	*menu = NULL;
}

void close_restaurant(Restaurant** restaurant) {
	// Free pending orders
	Order * order = dequeue_order(*restaurant);
	while (order != NULL) {
		clear_order(&order);
		order = dequeue_order(*restaurant);
	}

	free((*restaurant)->pending_orders);
	free((*restaurant)->name);
  
	clear_menu(&((*restaurant)->menu));
  free(*restaurant);
  *restaurant = NULL;
}

void print_menu(Menu* menu) {
	fprintf(stdout, "--- Menu ---\n");
	for (int i = 0; i < menu->num_items; i++){
		fprintf(stdout, "(%s) %s: %.2f\n", 
			menu->item_codes[i], 
			menu->item_names[i], 
			menu->item_cost_per_unit[i]	
		);
	}
}


void print_order(Order* order){
	for (int i = 0; i < order->num_items; i++){
		fprintf(
			stdout, 
			"%d x (%s)\n", 
			order->item_quantities[i], 
			order->item_codes[i]
		);
	}
}


void print_receipt(Order* order, Menu* menu){
	for (int i = 0; i < order->num_items; i++){
		double item_cost = get_item_cost(order->item_codes[i], menu);
		fprintf(
			stdout, 
			"%d x (%s)\n @$%.2f ea \t %.2f\n", 
			order->item_quantities[i],
			order->item_codes[i], 
			item_cost,
			item_cost * order->item_quantities[i]
		);
	}
	double order_subtotal = get_order_subtotal(order, menu);
	double order_total = get_order_total(order, menu);
	
	fprintf(stdout, "Subtotal: \t %.2f\n", order_subtotal);
	fprintf(stdout, "               -------\n");
	fprintf(stdout, "Tax %d%%: \t$%.2f\n", TAX_RATE, order_total);
	fprintf(stdout, "              ========\n");
}


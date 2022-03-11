#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITEM_CODE_LENGTH 3
#define MAX_ITEM_NAME_LENGTH 100
#define MAX_ITEM_QUANTITY_DIGITS 20

#define MENU_DELIM ","
#define MENU_FNAME "menu.txt"

#define TAX_RATE 13

/*
	Struct type definitions
*/
typedef struct Menu {
	int num_items;
	char** item_codes; 
	char** item_names; 
	double* item_cost_per_unit;
} Menu;

typedef struct Order {
	int num_items;
	char** item_codes;
	int* item_quantities;
} Order;

typedef struct QueueNode {
	Order* order;
	struct QueueNode* next;
} QueueNode;

typedef struct Queue {
	QueueNode* head;
	QueueNode* tail;
} Queue;

typedef struct Restaurant{
	char* name;
	Menu* menu;
	
	int num_completed_orders;
	int num_pending_orders;
	
	Queue* pending_orders;
} Restaurant;

// ----------- Function prototypes -------------
/*
	Intializers to "build" all the
	parts of our restaurant
*/
Restaurant* initialize_restaurant(char* name);
Menu* load_menu(char* fname);
Order* build_order(char* items, char* quantities); 

/*
	Managing our order queue
*/
void enqueue_order(Order* order, Restaurant* restaurant);
Order* dequeue_order(Restaurant* restaurant);

/*
	Getting information about our orders and order status
*/
double get_item_cost(char* item_code, Menu* menu);
double get_order_subtotal(Order* order, Menu* menu);
double get_order_total(Order* order, Menu* menu);
int get_num_completed_orders(Restaurant* restaurant);
int get_num_pending_orders(Restaurant* restaurant);

/*
	Closing down and deallocating memory
*/
void clear_order(Order** order);
void clear_menu(Menu** menu);
void close_restaurant(Restaurant** restaurant);

/* 
	These functions are implemented for you in 
	restaurant.c
*/
void print_menu(Menu* menu);
void print_order(Order* order);
void print_receipt(Order* order, Menu* menu);

/* ------- End of header file -------*/
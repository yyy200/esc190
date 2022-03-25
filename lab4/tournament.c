#include "lab4.h"

int main(){	
	Player* p1 = create_player("Noob_player", "N01");
	Player* p2 = create_player("Beginner0101", "B06");
	
	Player* p3 = create_player("FunnyGuy", "F22");
	Player* p4 = create_player("LaserBeam", "L46");
	
	Player* p5 = create_player("LlamaDog", "L28");
	Player* p6 = create_player("CatPotato", "C26");

	Player* p7 = create_player("PotatoChip", "P16");
	Player* p8 = create_player("Loser1111", "L00");
	
	//Prelims - 4 matches
	PlayerRecord* round1_outcome1 = add_match(
		create_leaf_record(p1), create_leaf_record(p2), 
		10, 13
	);
	PlayerRecord* round1_outcome2 = add_match(
		create_leaf_record(p3), create_leaf_record(p4), 
		5, 13
	);
	PlayerRecord* round1_outcome3 = add_match(
		create_leaf_record(p5), create_leaf_record(p6), 
		2, 13
	);
	PlayerRecord* round1_outcome4 = add_match(
		create_leaf_record(p7), create_leaf_record(p8), 
		13, 0
	);
	
	// Semifinals - 2 matches
	PlayerRecord* round2_outcome1 = add_match(
		round1_outcome1, round1_outcome2, 
		13, 7
	);
	PlayerRecord* round2_outcome2 = add_match(
		round1_outcome3, round1_outcome4, 
		10, 13
	);
	
	// Finals - 1 match
	PlayerRecord* round3_outcome = add_match(
		round2_outcome1, round2_outcome2, 
		8, 13
	);
	
	print_tournament_records(round3_outcome, round3_outcome);
	print_with_rank(round3_outcome);
	
	//Deallocate all memory that was allocated
	clear_tournament_records(&round3_outcome);
	
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	
	return 0;
}
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// for initializing the character static arrays 
// in the Player struct
#define MAX_NAME_LENGTH 100
#define PLAYER_ID_LENGTH 4

// for indexing the games static array in the 
// PlayerRecord struct
#define WINS 0
#define LOSSES 1

typedef struct Player {
	char name[MAX_NAME_LENGTH];
	char id[PLAYER_ID_LENGTH];
} Player;


typedef struct PlayerRecord {
	struct Player* player;
	int game_records[2];
	
	struct PlayerRecord* parent;

	struct PlayerRecord* left_child;
	struct PlayerRecord* right_child;
} PlayerRecord;


Player* create_player(char name[], char id[]);
PlayerRecord* create_leaf_record(Player* p);
PlayerRecord* add_match(PlayerRecord* p1, PlayerRecord* p2, int p1_wins, int p2_wins);
int get_player_rank(char player_id[], PlayerRecord* root);

// provided
void clear_tournament_records(PlayerRecord** root);
void collect_at_rank(PlayerRecord* curr, PlayerRecord* root, Player** players_at_curr_rank, 
	int rank, int* count_el, int* max_el
);
void print_with_rank(PlayerRecord* root);
void print_tournament_records(PlayerRecord* curr, PlayerRecord* root);


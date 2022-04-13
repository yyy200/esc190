#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define KEY 'S' //could be a different character

int bitwise_xor(int value);
char *xor_encrypt(char c);
char xor_decrypt(char *s);
char *gen_code(char *msg);
char *read_code(char *code);
char *compress(char *code);
char *decompress(char *code);
int calc_ld(char *sandy, char *cima);
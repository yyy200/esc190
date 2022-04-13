#include "a2.h"
#include "string.h"

int main(void) {
    // printf("%d\n", bitwise_xor(67));
    // char *bin_string = xor_encrypt('C');
    // printf("%s\n", bin_string);
    // printf("%c\n", xor_decrypt(bin_string));
    // free(bin_string);
    // printf("bin_string: %s\n", xor_encrypt('C'));
    // printf("bin_string length: %lu\n", strlen(xor_encrypt('C')));

    // printf("%c\n", xor_decrypt(xor_encrypt('d')));

    // char ndcode[] =
    // "010101010101010101010101001000010010";
    // char * code = malloc(sizeof(char) * strlen(ndcode) + 1);
    // strcpy(code, ndcode);
    // printf("code: %s\n", code);
    // printf("code 2: %s\n", compress(code));
    // free(code);

    // printf("%s\n", read_code(gen_code("HLLOE WORLD 33")));
    // printf("%d\n", calc_ld("COMMENCE", "CODING"));
    // printf("%d\n", calc_ld("COMMENCE", "PROCRASTINATING"));
    // char * bin_string = malloc(sizeof(char) * 17);    
    // strcpy(bin_string, "1111100000111111");
    // printf("%s\n", decompress(compress(bin_string)));

    char *msg = "Program in C!";
    char *code = gen_code(msg);
    for(int i = 0; i <256; i ++){
        if(code[i] == '1') {
            // print black square
            printf("\033[48;5;%dm  \033[0m", 0);
        }
        else if(code[i] == '0') {
            printf("\033[48;5;%dm  \033[0m", 1000000);
        }
        else {
            printf("  ");
        }

        if((i+1)%16 == 0 )  printf("\n");
    }
    char *decoded = read_code(code);
  free(code);
  free(decoded);
    printf("%s\n", decoded);
    // return 0;
}
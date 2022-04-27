#include "a2.h"

#define ONES {0, 1, 2, 3, 4, 11, 12, 13, 14, 15, 16, 20, 27, 31, 32, 34, 36, 43, 45, 47, 48, 52, 59, 63, 64, 65, 66, 67, 68, 75, 76, 77, 78, 79, 176, 177, 178, 179, 180, 192, 196, 208, 210, 212, 224, 228, 240, 241, 242, 243, 244, 255};
#define ZEROES {17, 18, 19, 28, 29, 30, 33, 35, 44, 46, 49, 50, 51, 60, 61, 62, 193, 194, 195, 209, 211, 225, 226, 227}

int bitwise_xor(int value){
    return value ^ KEY;
}

char * dec_to_bin(int value){
    char *bin_string = malloc(sizeof(char) * 8);
    int i;
    for (i = 0; i < 7; i++) {
        bin_string[i] = ((value >> (6 - i)) & 1) + 48;
    }
    bin_string[7] = '\0';
    return bin_string;
}

char *xor_encrypt(char c){
    return dec_to_bin(bitwise_xor(c));
}


char xor_decrypt(char *s){
    int value = 0;
    for (int i = 0; i < 7; i++) {
        value += (s[i] - 48) << (6 - i);
    }
    return bitwise_xor(value);
}

char *gen_code(char *msg){
    char *code = malloc(sizeof(char) * 257);
    int n = strlen(msg);

    int ones[] = ONES;
    int one = sizeof(ones) / sizeof(int);
    int zeroes[] = ZEROES;
    int zero = sizeof(zeroes) / sizeof(int);

    int i;
    for (i = 0; i < 256; i++) code[i] = 't';
    for(i = 0; i < one; i ++) code[ones[i]] = '1';
    for(i = 0; i < zero; i ++) code[zeroes[i]] = '0';
        
    int index = 0;
    for (i = 0; i < n + 1; i++) {
        char *bin_string = xor_encrypt(msg[i]);
        int j = 0;
        char c = bin_string[j];
        while(c != '\0'){
            if(code[index] == 't'){
                code[index] = c;
                j++;
                c = bin_string[j];
            }
            index ++;
        }
        free(bin_string);
        bin_string = NULL;
    }

    for(index = index; index < 256; index ++)
    {
        if(code[index] == 't') code[index] = '0';
    }

    code[256] = '\0';

    return code;
}

char *read_code(char *code){
    int ones[] = ONES;
    int one = sizeof(ones) / sizeof(int);
    int zeroes[] = ZEROES;
    int zero = sizeof(zeroes) / sizeof(int);

    for(int i = 0; i < one; i ++) code[ones[i]] = 't';
    for(int i = 0; i < zero; i ++) code[zeroes[i]] = 't';

    int index = 0;
    int i = 0;
    int message_index = 0;
    int size = 256 - one - zero;
    char *msg = malloc(sizeof(char) * (size / 8 + 1));
    while(code[index] != '\0') {
        if(code[i] != 't'){
            char *bin_string = malloc(sizeof(char) * 16);
            int j = 0;
            char c = code[index];
            while(c != '\0' && j < 7){
                if(c != 't'){
                    bin_string[j] = c;
                    j++;
                }
                index ++;
                 c = code[index];
            }
            bin_string[j] = '\0';
            if(strcmp(bin_string, "0000000") == 0){
                free(bin_string);
                break;
            }
            char decoded = xor_decrypt(bin_string);
            msg[message_index] = decoded;
            message_index ++;
            free(bin_string);
            i ++;
        }
        i++;
    }
    msg = realloc(msg, sizeof(char) * (message_index + 1));
    msg[message_index] = '\0';
    return msg;
}

char * bin_to_hex(char *bin_string, int n){
    char *hex_string = malloc(sizeof(char) * (n / 4 + 1));

    for(int i = 0; i < n ; i ++){
        bin_string[i] -= 48;
    }

    for (int i = 0; i < n / 4; i++) {
        hex_string[i] = bin_string[i * 4] * 8 + bin_string[i * 4 + 1] * 4 + bin_string[i * 4 + 2] * 2 + bin_string[i * 4 + 3];
        
        if (hex_string[i] < 10) {
            hex_string[i] += 48;
        } 
        else {
            hex_string[i] += 55;
        }
    }

    hex_string[n / 4] = '\0';
    return hex_string;
}

char *compress(char *code){
    int n = strlen(code);
    printf("%d\n", n);
    return bin_to_hex(code, n);
}

char *decompress(char *code){
    int n = strlen(code);
    printf("AHAHAHHAHA\n");
    char *bin_string = malloc(sizeof(char) * n * 4 + 1);
    for (int i = 0; i < n; i++) {
        if (code[i] < 58) {
            code[i] -= 48;
        } else {
            code[i] -= 55;
        }
        bin_string[i * 4] = code[i] / 8 + 48;
        bin_string[i * 4 + 1] = code[i] % 8 / 4 + 48;
        bin_string[i * 4 + 2] = code[i] % 8 % 4 / 2 + 48;
        bin_string[i * 4 + 3] = code[i] % 8 % 4 % 2 + 48;
    }
    bin_string[n * 4] = '\0';
    return bin_string;
}

int min(int a, int b){
    if(a < b) return a;
    return b;
}

int calc_ld(char *sandy, char *cima){
    // calculate the  Levenshtein distance between two strings
    int n = strlen(sandy);
    int m = strlen(cima);
    int **d = malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i < n + 1; i++) {
        d[i] = malloc(sizeof(int) * (m + 1));
    }

    for (int i = 0; i < n + 1; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j < m + 1; j++) {
        d[0][j] = j;
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (sandy[i - 1] == cima[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = 1 + min(d[i - 1][j - 1], min(d[i - 1][j], d[i][j - 1]));
            }
        }
    }

    int minimum = d[n][m];

    for (int i = 0; i < n + 1; i++) {
        free(d[i]);
    }
    free(d);
    return minimum;
}



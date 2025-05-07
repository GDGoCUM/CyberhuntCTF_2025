#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define XOR_KEY 0x5A  // XOR key for encoding/decoding
#define SHIFT_KEY 3   // Shift key for bitwise operations

volatile int stage_one = 17789009;
volatile int stage_two = 65673;
volatile int stage_three = 4321;
volatile int stage_four = 99999; 

char s1[128]; 
char last[128]; 
char s2[128]; 
char flag[128];


char ensure_ascii(char c) {
    return (c % 94) + 32; 
}



void encrypt_stage_one(char *input, char *output, size_t len) {
    int key = 42;
    for (size_t i = 0; i < len - 1; i++) {
        output[i] = ensure_ascii((input[i] ^ (XOR_KEY + key)) + (i % 7));
    }
    output[len - 1] = '\0';
}

void encrypt_stage_two(char *input, char *output, size_t len) {
    for (int i = 0; i < strlen(s1); i++) {
        s1[i] ^= 8;
    }
    int key = 91;
    for (size_t i = 0; i < len - 1; i++) {
        output[i] = ensure_ascii(((input[i] << SHIFT_KEY) | (input[i] >> SHIFT_KEY)) ^ (XOR_KEY + key + i));
    }
    output[len - 1] = '\0';
}

void encrypt_stage_three(char *input, char *output, size_t len) {
    for (size_t i = 0; i < len - 1; i++) {
        output[i] = ensure_ascii(input[i] + 8) ^ 100;
    }
    output[len - 1] = '\0';
}

int check_stage_one() {
    return stage_one == 1234;
}

int check_stage_two() {
    return stage_two == 9999;
}

int check_stage_three() {
    return stage_three == 4321;
}

int check_stage_four() {
    return stage_four == 8888;
}

void read_flag() {
    FILE *file = fopen("flag.txt", "r");  
    if (!file) {
        printf("Error: Could not open flag file!\n");
        return;
    }

    if (!fgets(flag, sizeof(flag), file)) { 
        printf("Error: Could not read flag from file!\n");
    }
    printf("This is a fake flag %s lol !!!",flag);
    fclose(file);  
}


void reveal_flag() {
    char encrypted_string[16];
    char encrypted_stage_two[16];
    char encrypted_stage_three[16];

    char temp[16] = "UselessString";
    encrypt_stage_one(temp, encrypted_string, sizeof(encrypted_string));

    printf("Stage One Bypassed... Encrypting a string now!\n");
    sleep(2);
    printf("Encrypted Key: %s\n", encrypted_string);
    
    if (check_stage_two()) {
        encrypt_stage_two(encrypted_string, encrypted_stage_two, sizeof(encrypted_stage_two));
        printf("Stage Two Bypassed! Checking next condition...\n");

        if (check_stage_three()) {
            encrypt_stage_three(encrypted_string, encrypted_stage_three, sizeof(encrypted_stage_three));
            printf("Stage Three Bypassed! One more to go...\n");
	    read_flag();
            
            if (check_stage_four()) {
                printf("Stage Four Bypassed! Reading flag from file...\n");
                read_file();
                return;
            }
        }
    }

    printf("Not all conditions met!\n");
}

int main() {
    printf("This program does nothing useful... or does it?\n");  

    while (1) {
        if (check_stage_one()) {
            reveal_flag();
            break;
        }
        sleep(1);
    }
    return 0;
}



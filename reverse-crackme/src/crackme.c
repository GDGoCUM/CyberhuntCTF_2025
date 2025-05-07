#include <stdio.h>
#include <string.h>

int main() {
    char input[100];

    printf("Enter the password: ");
    fgets(input , sizeof(input) , stdin);

    input[strcspn(input, "\n")] = 0;
    
    for (int i = 0; i < strlen(input); i++) {
        input[i] ^= 5;
    }
	
    if (strcmp(input, "Mpkq~d6130a0`0``761gdZfwdfnh`x") == 0) {
        printf("Correct! You cracked it!\n");
    } else {
        printf("Incorrect password.\n");
    }

    return 0;
}

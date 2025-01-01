//'SCT_CS_1.C`

//```c
#include <stdio.h>
#include <string.h>

// Function declarations
void encryption(void);
void decryption(void);

// Main function
int main(void) 
{
    int choice = 0;

    printf("\n\t\tCaesar Cipher\n");

    while (choice != 3)
    {
        printf("\n===============================================");
        printf("\n\tEnter your choice from the following");
        printf("\n-----------------------------------------------");
        printf("\n1. Encryption\n2. Decryption\n3. Exit");
        printf("\n-----------------------------------------------\n::: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline left in the input buffer

        printf("===============================================\n");

        switch (choice)
        {
            case 1: 
                encryption();
                break;

            case 2: 
                decryption();
                break;

            case 3: 
                printf("\n\t\tExiting...\n");
                return 0;

            default: 
                printf("\n\nEnter a valid choice!\n\n");
                break;
        }
    }

    return 0;
}

// Encryption function
void encryption(void)
{
    char plaintext[100];
    char ciphertext[100];
    int shift;

    printf("\n\n\t\tEncryption using Caesar Cipher");
    printf("\n-----------------------------------------------\n");
    printf("Enter the plaintext for encryption:\n::: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the shift value:\n::: ");
    scanf("%d", &shift);
    getchar(); // Consume newline

    int cnt = strlen(plaintext) - 1; // Exclude newline
    plaintext[cnt] = '\0';

    for (int i = 0; i < cnt; i++)
    {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            ciphertext[i] = ((plaintext[i] - 'A' + shift) % 26) + 'A';
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            ciphertext[i] = ((plaintext[i] - 'a' + shift) % 26) + 'a';
        else
            ciphertext[i] = plaintext[i];
    }

    ciphertext[cnt] = '\0';
    printf("Encrypted text is: %s\n", ciphertext);
}

// Decryption function
void decryption(void)
{
    char plaintext[100];
    char ciphertext[100];
    int shift;

    printf("\n\n\t\tDecryption using Caesar Cipher");
    printf("\n-----------------------------------------------\n");
    printf("Enter the ciphertext for decryption:\n::: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    printf("Enter the shift value:\n::: ");
    scanf("%d", &shift);
    getchar(); // Consume newline

    int cnt = strlen(ciphertext) - 1; // Exclude newline
    ciphertext[cnt] = '\0';

    for (int i = 0; i < cnt; i++)
    {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
            plaintext[i] = ((ciphertext[i] - 'A' - shift + 26) % 26) + 'A';
        else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z')
            plaintext[i] = ((ciphertext[i] - 'a' - shift + 26) % 26) + 'a';
        else
            plaintext[i] = ciphertext[i];
    }

    plaintext[cnt] = '\0';
    printf("Decrypted text is: %s\n", plaintext);
}
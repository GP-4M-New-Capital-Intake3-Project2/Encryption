#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>

//string a = "qwertyuioplkjhgfdsazxcvbnm";
//string a = "abcdefghijklmnopqrstuvwxyz" ;
char key[26];
char KEY[26];
//string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int n = strlen(argv[1])  ;
        for (int i = 0; i < n; i++)
        {
            if (n < 26)
            {
                printf("Key must contain 26 characters.\n");
                return 1 ;
            }
            if ((!(argv[1][i] >= 'a' && argv[1][i] <= 'z')) && (!(argv[1][i] >= 'A' && argv[1][i] <= 'Z')))
            {
                printf("Key must only contain alphabetic characters.\n") ;
                return 1 ;
            }
            for (int j = 0; j < i; j++)
            {
                if (argv[1][j] ==  argv[1][i])
                {
                    printf("Key must not contain repeated characters.\n") ;
                    return 1 ;
                }
            }
        }
    }
    else
    {
        printf("Usage: ./decryption key\n");
        return 1 ;
    }
    char *key = malloc(strlen(argv[1]) + 1); 
    if (key == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    strcpy(key, argv[1]); 
    for(int j = 0 ; j < 26 ; j++)
    {
        KEY[j] = toupper(argv[1][j]);
    }
    char alphabet[50]= "abcdefghijklmnopqrstuvwxyz";
    char ALPHABET[50]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char plain_text[60] ;
    printf("Enter cipher text: ");
    fgets(plain_text,sizeof(plain_text),stdin);

    int word_length = strlen(plain_text) ;

    char cipher_text[word_length] ;


    for (int j = 0; j < word_length; j++)
    {
        if (isupper(plain_text[j]) && isalpha(plain_text[j]))
        {
            for (int i = 0; i < 26; i++)
            {
                if (KEY[i] == plain_text[j])
                {
                    cipher_text[j] = toupper(ALPHABET[i]) ;
                }
            }
        }
        else if (islower(plain_text[j]) && isalpha(plain_text[j]))
        {
            for (int i = 0; i < 26; i++)
            {
                if (key[i] == plain_text[j])
                {
                    cipher_text[j] = tolower(alphabet[i]) ;
                }
            }
        }
        else
        {
            cipher_text[j] = plain_text[j] ;
        }
    }
    cipher_text[word_length] = '\0'; 
    if (word_length == 1)
    {
        printf("ciphertext: %c\n", cipher_text[0]) ;
    }
    else if (word_length == 2)
    {
        printf("ciphertext: %c%c\n", cipher_text[0], cipher_text[1]) ;
    }

    else if (word_length == 3)
    {
        printf("ciphertext: %c%c%c\n", cipher_text[0], cipher_text[1], cipher_text[2]) ;
    }

    else
    {
        printf("ciphertext: %s\n", cipher_text) ;
        return 0 ;
    }
}

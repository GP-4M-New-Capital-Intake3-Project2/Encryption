#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define KEY "qwertyuioplkjhgfdsazxcvbnm"
#define STRING  "UwqeYRqqqoqoqiYoqiYoqoqoqoqoqoqoqoqoqoqoqYr"


char *substitution_decrypt(const char *key, const char *plain_text, int length);

void subsitution_numbers_decrypt(char *c, int length);

int main(int argc, char *argv[])
{

    int word_length = strlen(STRING);
    char *cipher_text = substitution_decrypt(KEY, STRING, word_length);

    printf("plain_txt: %s\n", cipher_text);
    free(cipher_text);

    return 0;
}

char *substitution_decrypt(const char *key, const char *plain_text, int length)
{
    char alphabet[50] = "abcdefghijklmnopqrstuvwxyz";
    char ALPHABET[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char *cipher_text = malloc(length + 1);
    if (cipher_text == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int j = 0; j < length; j++)
    {
        if (isupper(plain_text[j]) && isalpha(plain_text[j]))
        {
            for (int i = 0; i < 26; i++)
            {
                if (toupper(key[i]) == plain_text[j])
                {
                    cipher_text[j] = toupper(ALPHABET[i]);
                }
            }
        }
        else if (islower(plain_text[j]) && isalpha(plain_text[j]))
        {
            for (int i = 0; i < 26; i++)
            {
                if (tolower(key[i]) == plain_text[j])
                {
                    cipher_text[j] = tolower(alphabet[i]);
                }
            }
        }
        else
        {
            cipher_text[j] = plain_text[j];
        }
    }

    cipher_text[length] = '\0';

    subsitution_numbers_decrypt(cipher_text, length);

    return cipher_text;
}

void subsitution_numbers_decrypt(char *c, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (islower(c[i]))
        {
            // Convert the alphabetic character to the corresponding digit
            c[i] = (c[i] - 'a') + '0';
        }
        else if (c[i] == 'G')
        {
            c[i] = ':';
        }
        else
        {
            c[i] = c[i];
        }
    }
}

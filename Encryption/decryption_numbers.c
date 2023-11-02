#include <stdio.h>
#include <ctype.h>
void subsitution_decrypt(char *c);

int main()
{
    char cipher_txt[300];
    printf("Enter the cipher text: ");
    fgets(cipher_txt, 300, stdin);
    subsitution_decrypt(cipher_txt);
    printf("plain_txt: %s\n", cipher_txt);
    return 0;
}
void subsitution_decrypt(char *c)
{
    while (*c)
    {

        if (islower(*c))
        {
            // Convert the alphabetic character to the corresponding digit
            *c = (*c - 'a') + '0';
        }
        else if (*c == 'G')
        {
            *c = ':';
        }
        else
        {
            *c = *c;
        }
        c++;
    }
}
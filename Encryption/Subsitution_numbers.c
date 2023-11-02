#include <stdio.h>
#include <ctype.h>
void subsitution(char *c);

int main()
{
    char plain_txt[300];
    printf("Enter the plain text: ");
    fgets(plain_txt, 300, stdin);
    subsitution(plain_txt);
    printf("Cipher text: %s\n", plain_txt);
    return 0;
}

void subsitution(char *c)
{
    while (*c)
    {

        if (isdigit(*c))
        {
            // Convert the digit to an alphabetic character
            *c = 'a' + (*c - '0');
        }
        else if (*c == ':')
        {
            *c = 'G';
        }
        else
        {
            *c = *c;
        }
        c++;
    }
}
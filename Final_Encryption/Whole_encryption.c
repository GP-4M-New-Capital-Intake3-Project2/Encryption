#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SUBSTITUTION_KEY "qwertyuioplkjhgfdsazxcvbnm"

void substitution(const char *c, char *result, int length);
void encryption(const char *plain_text, int length, const char *key, FILE *file);

int main()
{
    // Open the file for reading
    FILE *input_file = fopen("DAC.hex", "r");

    // Check if the file was opened successfully
    if (input_file == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    // Open the file for writing
    FILE *output_file = fopen("Encrypt.hex", "w");

    // Check if the file was opened successfully
    if (output_file == NULL)
    {
        fprintf(stderr, "Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    char line[300];

    // Read each line from the file
    while (fgets(line, sizeof(line), input_file) != NULL)
    {
        // Remove newline character if present
        int length = strlen(line);
        if (line[length - 1] == '\n')
        {
            line[length - 1] = '\0';
            length--;
        }

        // Create an array to store the substituted string
        char substituted_text[300];

        // Call substitution function
        substitution(line, substituted_text, length);

        // Print the substituted text
        printf("Cipher text after substitution: %s\n", substituted_text);

        // Pass the substituted string and file pointer to the encryption function
        encryption(substituted_text, length, SUBSTITUTION_KEY, output_file);
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    return 0;
}

void substitution(const char *c, char *result, int length)
{
    int result_ptr = 0;

    while (*c && result_ptr < length)
    {
        if (isdigit(*c))
        {
            // Convert the digit to an alphabetic character
            result[result_ptr] = 'a' + (*c - '0');
        }
        else if (*c == ':')
        {
            result[result_ptr] = 'G';
        }
        // You can add more substitution rules as needed
        else
        {
            result[result_ptr] = *c;
        }
        c++;
        result_ptr++;
    }

    // Add null terminator to the result string
    result[result_ptr] = '\0';
}

void encryption(const char *plain_text, int length, const char *key, FILE *file)
{
    char cipher_text[length];

    char alphabet[50] = "abcdefghijklmnopqrstuvwxyz";
    char ALPHABET[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < length; i++)
    {
        if (isupper(plain_text[i]) && isalpha(plain_text[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (ALPHABET[j] == plain_text[i])
                {
                    cipher_text[i] = toupper(key[j]);
                }
            }
        }
        else if (islower(plain_text[i]) && isalpha(plain_text[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (alphabet[j] == plain_text[i])
                {
                    cipher_text[i] = tolower(key[j]);
                }
            }
        }
        else
        {
            cipher_text[i] = plain_text[i];
        }
    }
    cipher_text[length - 1] = '\0'; // Remove the newline character

    // Write the encrypted text to the file
    fprintf(file, "%s\n", cipher_text);

    if (length == 1)
    {
        printf("ciphertext: %c\n", cipher_text[0]);
    }
    else if (length == 2)
    {
        printf("ciphertext: %c%c\n", cipher_text[0], cipher_text[1]);
    }
    else if (length == 3)
    {
        printf("ciphertext: %c%c%c\n", cipher_text[0], cipher_text[1], cipher_text[2]);
    }
    else
    {
        printf("ciphertext: %s\n", cipher_text);
    }
}

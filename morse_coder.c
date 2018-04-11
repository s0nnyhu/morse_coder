#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cleanBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int getText(char *str, int size) {
    char *enterPosition = NULL;
    if (fgets(str, size, stdin) != NULL) {
        enterPosition = strchr(str, '\n');
        if(enterPosition != NULL) {
            *enterPosition = 0;
        } else {
            cleanBuffer();
        }
        return 1;
    } else {
        cleanBuffer();
        return 0;
    }
}

int main(int argc, char* argv[])
{
    const char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    const char *morse[26] = {".-", "-...", "-.-.", "-..", ".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    char rawText[500];
    int i = 0;
    printf("[Morse_coder]Text to encode >");
    getText(rawText, 500);
    //printf("Vous avez tape : '%s'", rawText);
    while(rawText[i] != '\0') {
        if (rawText[i] == ' ') {
            printf("%s", "|");
            printf("%5s", " ");
        }
        for (int j=0; j <26; j++) {
            if (rawText[i] == alphabet[j]) {
                printf("%s", morse[j]);
                printf("%5s", " ");
            } 
        }
        i++;
    }

    return 0;
}


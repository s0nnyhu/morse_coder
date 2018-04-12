#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    const char alpha_num[36] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    const char *morse[36] = {".-", "-...", "-.-.", "-..", ".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
    char rawText[5000];
    int i = 0;
	int isInArray = 0;

    printf("[Morse_coder]Text to encode >");
    getText(rawText, 5000);

    while(tolower(rawText[i]) != '\0') {
        if (rawText[i] == ' ') {
            printf("%s", "|");
            printf("%5s", " ");
        }
        for (int j=0; j <36; j++) {
            if (tolower(rawText[i]) == alpha_num[j]) {
                printf("%s", morse[j]);
                printf("%5s", " ");
				isInArray = 1;
            }
        }

	if(isInArray == 0 && rawText[i] != ' ') {
                printf("%c", rawText[i]);
                printf("%5s", " ");
	}
        i++;
	isInArray = 0;
    }

    return 0;
}


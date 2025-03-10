#include <stdio.h>
#include <ctype.h>

#define MAX_CHARS 1000000

int main() {
    char text[MAX_CHARS + 1];
    int ch, pos = 0;
    int start_sentence = 1;

    while ((ch = getchar()) != EOF) {
        if (start_sentence && isalpha(ch)) {
            text[pos++] = toupper(ch);
            start_sentence = 0;
        } else if (isalpha(ch)) {
            text[pos++] = tolower(ch);
        } else {
            text[pos++] = ch;
            if (ch == '.' || ch == '?' || ch == '!') {
                start_sentence = 1;
            }
        }
    }

    text[pos] = '\0';
    printf("%s", text);

    return 0;
}

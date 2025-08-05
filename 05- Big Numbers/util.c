#include "util.h"

struct node_st {
    elem info;
    NO *prox;
    NO *ant;
};

char *read_word() {
    char *string = NULL;
    char ch = '\0';
    int count = 0;

    while ((ch = getchar()) == '\r' || ch == '\n');
    if (ch != EOF) {
        ungetc(ch, stdin);
    }

    do {
        ch = getchar();
        string = realloc(string, ++count * sizeof(char));
        string[count - 1] = ch;

    } while(ch != ' ' && ch != EOF);

    string[count - 1] = '\0';

    return (string);
}
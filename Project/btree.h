
#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node
{
    char *word;
    struct Node *left;
    struct Node *right;
}Node;




void checkInput(FILE* plik);
void checkOutput(FILE* plik1, FILE* plik2);
Node *newNode(char input_word[]);
Node *insertNode(Node *root, char input_word[]);
void help();
void legit_check(int c, char *v[], char input[], char output[]);
Node *word_list(FILE* input, Node *root);
void printTree(Node *root, FILE* output_file);

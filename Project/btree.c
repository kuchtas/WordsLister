
#include "btree.h"

void checkInput(FILE* plik) //this function checks if the input file exists
{
    if(!plik)
        {
        printf("Your input file does not exist\n");
        exit(0);
        }
}

void checkOutput(FILE* plik1, FILE* plik2) //this function checks if the output file exists
{
    if(!plik2)
        {
        printf("Your output file does not exist\n");
        fclose(plik1);
        exit(0);
        }
}

Node *insertNode(Node *root, char input_word[]) //main function to operate on the Binary Tree
{
    if(root==NULL) return newNode(input_word); // we create new node if there is none

    if(stricoll(input_word,root->word)<0) //comparing the word inside existing node with the input_word
        {
        root->left=insertNode(root->left,input_word); //if the word is earlier alphabetically we move to the left node
        }
    else if(stricoll(input_word,root->word)>0)
        {
        root->right=insertNode(root->right,input_word);//if the word is earlier alphabetically we move to the left node
        }

    return root;
}


Node *newNode(char input_word[]) //this function creates a new node in the Binary Tree
{
    Node *currentNode=(Node*)malloc(sizeof(Node)); //allocating memory for the node

    currentNode->word=malloc(sizeof(char)*(strlen(input_word)+1));

    strcpy(currentNode->word,input_word);
    currentNode->right=currentNode->left=NULL; //setting potential connections with new nodes

    return currentNode;
}


void printTree(Node *root, FILE* output_file) //printing the tree starting with the left most node
{
    if(root->left!=NULL) printTree(root->left,output_file);
    fprintf(output_file,"%s ",root->word);

    free(root);

    fprintf(output_file,"\n");

    if(root->right!=NULL) printTree(root->right,output_file);
}


void legit_check(int c, char *v[], char input[], char output[]) //this function checks the command line arguments
{
    int a=0;

    if(c!=5) help();
    if(c==5)
    {
    for(a=0;a<4;a++)
        {
        if(strcmp(v[a],"-i")==0) //if the input is equal to "-i" the next argument should be the path to the input file
            {
            strcpy(input,v[a+1]);
            }
        if(strcmp(v[a],"-o")==0) //if the input is equal to "-o" the next argument should be the path to the output file
            {
            strcpy(output,v[a+1]);
            }
        if(strcmp(v[a],"-h")==0)   //if any of the arguments is equal to "-h" the help function should print itself on screen
            {
            help();
            }
        }
    }
}

void help() //help regarding the correct way of sending arguments
{
    printf("It seems like you have either given wrong inputs or asked for help.\nThe right way of entering arguments is as follows: \n");
    printf("<program.exe> -i <input_file.txt> -o <output_file.txt>\n");
    printf("input_file.txt> ---> the path to the input file you wish to work on\n");
    printf("output_file.txt> ---> the path to the output file you wish to have the result in\n");
    exit(0);
}

Node *word_list(FILE* input, Node *root)
{
    char character;
    int i=0;
    char word[128]=" ";

    while(!feof(input))
    {
        character=getc(input); //checking the input file one character at a time

        if(isalpha(character)) //picking only the characters from a-z and A-Z (<ctype.h>)
            {
            word[i]=character; //this loop creates a word we will later check
            i++;
            }
        else
            {
            if(word[0]!='\0'&&!isalpha(character))
                {
                root=insertNode(root,word);
                }
            while(i!=0)
                {
                word[i-1]='\0'; // we have to reset the counter and empty the word container
                i--;
                }
            }
    }
   return root;
}







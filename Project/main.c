#include "btree.h"

int main(int argc, char *argv[])
{
    FILE *input, *output;
    char input_name[128]=" ",output_name[128]=" ";

    Node *root=NULL;

    legit_check(argc,argv,input_name,output_name);

    input=fopen(input_name, "r");
    checkInput(input);
    output=fopen(output_name,"w");
    checkOutput(input, output);

    printTree(word_list(input,root),output);

    fclose(input);
    fclose(output);
    return 0;
}

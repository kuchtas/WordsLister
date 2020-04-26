# WordsLister
Program which lists all of the words from a text file using binary tree.
DISCLAIMER: I have created this project long time ago so it is probably bugged and written poorly, I just want to have it on git to look back at it in some years and laugh. I also remember writing a better version in C++ which additionaly listed all of the lines in which the word was found,
but it seems to be lost somewhere.  

To run the program pass <program-name.exe> –i <path-for-input-file.txt> –o <path-for-output-file.txt> to the command prompt.
Also -h shows help message.

Explanaton(also written long time ago):
The program uses Binary Tree to take out and sort words from the text. The program starts by
checking if the input file exists, otherwise a proper message is printed on the screen and the program
closes. Now, if everything is alright, the program moves one character at a time, merging them into a
word, unless a non-letter character shows up. In such circumstance the word is treated as finished and
the word is added to the Binary Tree.
The algorithm travels through the Tree and checks whether the word appeared before. If it
did, it is ignored. If it didn’t, a new node is created.
These instructions are executed as long as there are characters in the input file.
Later, the Tree is passed to the text file starting with the leftmost node. We move on higher: if this
node has another node connected to it on the right, we move there. The algorithm always strives to
the left lowest node if it is possible. This allows us to print the words alphabetically, which makes it
easier to work with them.

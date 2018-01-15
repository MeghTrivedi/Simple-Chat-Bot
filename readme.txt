MEGH TRIVEDI
0886172
Assignment #4
December 3rd,2017

WHAT THE PROGRAM DOES:
This program allows the user to enter between 1-5 option. The user can enter to add a rule to the binary search tree.They are able to delete,and modify the user rating There are also able to do this special feature where they can Discuss with Eliza or Siri.

HOW TO RUN THE PROGRAM:
1.To run main program. Type in "make" 
2.THEN TYPE MAKE RUN. 


1.To run testMain program. Type in "make testMain"
2.Then do ./bin/runMe

ASSUMPTIONS:
-The user must enter an option between 1-5. If the user clicks any other option,it will go back to the main menu.
-No invaild characters,symbols or numbers.
-The user can't add a word that already exist.
-All the words will be lower case through out the program.
-The file name must be entered at argv[0]
-.txt files must be bin folder in order for the program to work.
-When typing in a keyword, they are a single word, should not be multiple words.
-Most of the program uses defensive programming while only a few doesn't.
-For option 5 the sentence is tokenized by  .!@#$^&*,();?
Most sentences end with . ! or ? and have commas between them.
-When the user clicks 9 , a message saying "Goodbye" and ends the program.
-Does not write to the file only reads in the file.
-When the user clicks 9 the destroyTree is called, which destroys the all nodes in the tree.
-The file must have a keyword and a sentence on the next line in order for the program to read in the file or else program will not work.

LIMITATIONS:
If the file doesn't exist then the program will not work.A simple error message will be displayed.
If you enter spaces or numbers or any invaild characters then the program will not work for a few inputs.
OPTION 5 DOES NOT WORK PROPERLY. IT READS A DISCUSSION ONLY FROM ORIGINAL FILE. IDK WHATS WRONG. 



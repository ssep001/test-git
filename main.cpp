//
//  main.cpp
//  originalstructure
//
//  Created by Amir Jabbari on 9/12/16.
//  Copyright © 2016 Amir Jabbari. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include "word.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    ifstream inputFile;
    inputFile.open("wordFile.txt");
    
    vector<word> vectorOfWords;
    word tempArray;
    
    // word obj ("word", "date", word_count, word_weight, percent_change )
    word tempWord("Apple", "2016-08-31",1,0,0);
    // Taking the first word and adding it to the first index of the vector
    vectorOfWords.push_back(tempWord);
    
    bool found = false;
 
    while(!inputFile.eof()){
        
        found = false;
        inputFile >> tempArray;
        // Comparing the new word from file to the existing words in vector
        for (int j = 0; j < vectorOfWords.size(); j++)
        {   // if the word exist -> increment the word_count
            if(tempArray.wordItself == vectorOfWords[j].wordItself)
            {
                vectorOfWords.at(j).wordCount++;
                found = true;
            }
        }
        if(!found)
        {
            // adding the new word if not in the vector
            vectorOfWords.push_back(tempArray);
            // incrementing the word count of the specific added word
            vectorOfWords.at(vectorOfWords.size()-1).wordCount++;
            
        }
    }
    // printing the words in the vector
    for(int i = 0 ; i < vectorOfWords.size();i++){
        cout << vectorOfWords[i];
    }
    
    for (int j = 0; j < vectorOfWords.size(); j++)
    {
        
    }

    BTree obj(5);
    obj.insert(10);
    
    obj.traverse();
    
    
    
    inputFile.close();
    return 0;
}

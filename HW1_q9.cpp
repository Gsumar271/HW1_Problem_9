#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <algorithm>
#include <math.h>
#include <list>
#include <iomanip>

using namespace std;


//helper function declarations for DeBrujin sequence with array
string getSubsequenceArray(vector<char>* sequence, int from, int length);
void mutateDeBrujinArray(vector<char>* sequence);

//helper function declarations for DeBrujin sequence with linked list
string getSubsequenceList(list<char>* sequence, int from, int length);
void mutateDeBrujinList(list<char>* sequence);

//a driver function which checks for de Brujin sequence 
bool checkIfdeBrujinArray(vector<char>* sequence, int length){
    //size of sequence
    int seqSize;
    string subSequence;

    //a vector for subsquences
    vector<string> subSeqs;
    seqSize = sequence->size();

    for (int i = 0; i < seqSize; i++)
    {   
        //subSeqSize = i+3;
        subSequence = getSubsequenceArray(sequence, i, length);
        //check if subsequence already exists 
        //in the array of subsequences
        if (find(subSeqs.begin(), subSeqs.end(), subSequence) != subSeqs.end())
            return false;
        else
        {
            //if subsequence not in array
            //add it to the array
            subSeqs.push_back(subSequence);
        }
        
    }
    //cout<<"size in the function"<<seqSize<<endl;
    return true;
}

//function to get the subsequence of the main character sequence
//function arguments are sequence, starting position and size of subsequence
string getSubsequenceArray(vector<char>* sequence, int from, int length){
    string sub = "";

    for (int i = 0; i < length; i++)
    {
        sub = sub + (*sequence)[from++];
        //if we reached the end of array
        //start from the front, wrapping 
        //around array
        if (from == sequence->size())
            from = 0; 
    }
    return sub;
}


void mutateDeBrujinArray(vector<char>* sequence){
    //size of sequence
    int seqSize;
    int percent;

    seqSize = sequence->size();

    for (int i = 0; i < seqSize; i++)
    {   
        //get the probabity 
        percent = rand() % 100;
        //if probablity is less than 5
        //switch the character at that point 
        //in sequence
        if (percent < 5){
            if((*sequence)[i] == '0')
                (*sequence)[i] = '1';
            else
            {
                (*sequence)[i] = '0';
            }   
        }
    }
}

bool checkIfdeBrujinList(list<char>* sequence, int length){

    string subSequence;
    //a list for subsquences
    list<string> subSeqs;
    int seqSize = sequence->size();

    for (int i = 0; i < seqSize; i++)
    {
        //subSeqSize = i+3;
        subSequence = getSubsequenceList(sequence, i, length);
        //check if subsequence already exists 
        //in the list of subsequences
        if (find(subSeqs.begin(), subSeqs.end(), subSequence) != subSeqs.end())
            return false;
        else
        {
            //if subsequence not in the list
            //add it to the list
            subSeqs.push_back(subSequence);
        }
    }
    


    return true;
}


string getSubsequenceList(list<char>* sequence, int from, int length){
    string sub = "";
    char c;

    // Initialize iterator for the list 
    list<char>::iterator it = sequence->begin(); 
  
    // Move the iterator to the element from 
    //using STL advance function
    advance(it, from);

    for (int i = 0; i < length; i++)
    {
        c = *it;
        sub = sub + c;
        ++it;

        //if we reached the end of the list
        //start from the front, wrapping 
        //around list
        if (it == sequence->end())
            it = sequence->begin(); 
    }

    return sub;
}

void mutateDeBrujinList(list<char>* sequence){
    
    //size of sequence
    int seqSize;
    int percent;

    // Initialize iterator for the list 
    list<char>::iterator it = sequence->begin(); 

    seqSize = sequence->size();

    for (int i = 0; i < seqSize; i++)
    {   
        //get the probabity 
        percent = rand() % 100;
        //if probablity is less than 5
        //switch the character at that point 
        //in sequence
        if (percent < 5){
            //move iterator to correct position
            advance(it, i);
            if(*it == '0')
                *it = '1';
            else
            {
                *it = '0';
            }   
        }
    }

}

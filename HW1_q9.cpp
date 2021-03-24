/*
By Yevgeniy Sumaryev
3/20/21
*/
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

//a function which checks for de Brujin sequence 
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

//function to get the subsequence of the main character sequence.
//function arguments are the main sequence, starting position and size of subsequence
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

//function to mutate the sequence
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

//function which uses list to check for de Brujin sequence
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

//helper function to get the subsequence
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

//mutate the sequence using list
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


int main(){
    vector<char> vString; 
    list<char> vList;
    int randNum;
    //empty to string to convert from integer
    string numberString = "";
    //char variable needed for int to char conversion
    char c;
    //a variable that defines the length of the sequence
    int kSize;
    kSize = 8;

    // initialize random seed: 
    srand(time(NULL));

    //create random array of 0 and 1 characters
    for (int i = 0; i < kSize; i++)
    {
        randNum = rand() % 2;
        // c = randNum + '0';
        // numberString = numberString + c;
        vString.push_back(randNum + '0');
    }

    //print array sequence
    cout<< "Array: "<<endl;
    for (int j = 0; j < kSize; j++)
    {
        cout<< vString[j] << " ";
        
    }
    cout << endl;


    //create random list of 0 and 1 characters
    for (int i = 0; i < kSize; i++)
    {
        randNum = rand() % 2;
        vList.push_back(randNum + '0');
    }

    // using iterator to print list
    cout<<"List: "<<endl;
    for (auto it = vList.begin(); it !=vList.end(); ++it)
        cout<< *it <<' ';
    cout << endl;

    //time the array structure 
    int counter = 0;
    bool stop = false;
    cout<<"Using Array to test: "<<endl;

    //variable to time the function
    auto start = chrono::system_clock::now();
    while(counter < 100 && !stop) {
        if(!checkIfdeBrujinArray(&vString, 3)){
            mutateDeBrujinArray(&vString);
            cout << "Not deBrujin sequence" << endl;
            for (int j = 0; j < 8; j++)
                {
                    cout << vString[j] << " ";
        
                }
            cout << endl;
            counter++;
         }
         else
         {
             cout << "Found deBrujin sequence with array" << endl;
             stop = true;
         } 
    }
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds_array = end-start;

    
    //time the linked list structure 
    counter = 0;
    stop = false;
    cout<<endl;
    cout<<"Using a list to test: "<<endl;
    //variable to time the function
    start = chrono::system_clock::now();
    while(counter < 100 && !stop) {
        if(!checkIfdeBrujinList(&vList, 3)){
            mutateDeBrujinList(&vList);
            cout << "Not deBrujin sequence" << endl;
            for (auto it = vList.begin(); it !=vList.end(); ++it)
                cout<< *it <<' ';
            cout << endl;
            counter++;
         }
         else
         {
             cout << "Found deBrujin sequence with a list" << endl;
             stop = true;
         } 
    }
    end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds_list = end-start;

    cout << endl;
    cout << "Array elapsed time: " << elapsed_seconds_array.count() << "s\n";
    cout << "List elapsed time: " << elapsed_seconds_list.count() << "s\n";
    cout << endl;

}

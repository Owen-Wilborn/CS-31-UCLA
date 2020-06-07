#include <iostream>
#include <string>
#include <cassert>
using namespace std; 

//Created function to see if a perfect match between string array and word input exist between the two inputs
bool perfectMatch(const string dictionary[], int n, string word)
{
    // Check next if any perfect match occured
    bool Test = false;
    //Iterate through all the spots in the array
    for (int k = 0; k < n; k++)
    {
        //Check if there is a match
        if (word == dictionary[k])
        {
            Test = true;
        }
    }
    //Return the bool
    return Test;
}

//Created function to test is a simple type or perfect match occured in the inputs
int scoreTypo(const string dictionary[], int n, string word)
{
    //set return number variable
    int retnumber = 2;
    //Check first n is greater than 0
    if (n <= 0)
    {
        retnumber = -1;
    }
    // Check next if any perfect match occured
    if (perfectMatch(dictionary, n, word) && retnumber!=-1)
    {
        retnumber = 0;
     }
    // Check next if word can be change such only one error exist
    //Iterate through all positions in the string array and check if any simple typo change in any array position makes a correct match
    for (int k = 0; (k < n && !(retnumber == -1 || retnumber == 0 || retnumber == 1)); k++)
    {
        //First find the position in the string of the first error
        char letterCheck = ' ';
        char letterWord = ' ';
        int errorPoistion = 0;
        bool error = false;
        string check = dictionary[k];
        //first find the location of the first error
        for (int s = 0; ((s < check.size() || s < word.size()) && !error); s++)
        {
            if (s < check.size())
            {
                letterCheck = check[s];
            }
            else
            {
                letterCheck = ' ';
            }
            if (s < word.size())
            {
                letterWord = word[s];
            }
            else
            {
                letterWord = ' ';
            }
            //If the characters are not equal then is the error position, also error position if one string runs out first
            if (letterWord != letterCheck)
            {
                errorPoistion = s;
                error = true;
            }
        }
        //Check if can solve problem by delating the error position in the string
        //Create new string of one less character
        string wordHold = word;
        if (wordHold != "")
        {
            wordHold.resize(wordHold.size() - 1);
        }
        //Make the string all the characters minus the error character
        for (int s = 0; s < (word.size() - 1); s++)
        {
            if (s < errorPoistion)
                wordHold[s] = word[s];
            else
                wordHold[s] = word[s + 1];
        }
        // Check next if any perfect match occured after delating error character
        if (perfectMatch(dictionary, n, wordHold))
        {
            retnumber = 1;
        }
        //Next check adding the error character into the string
        wordHold = word;
        //Make new string hold one more character
        wordHold.resize(wordHold.size() + 1);
        //Add characters to string and add the new character in middle at first error poistion
        for (int s = 0; s < (word.size() + 1); s++)
        {
            if (s < errorPoistion)
                wordHold[s] = word[s];
            else if (s == errorPoistion)
                wordHold[s]=check[s];
            else
                wordHold[s] = word[s-1];
        }
        // Check next if any perfect match occured after delating error character
        if (perfectMatch(dictionary, n, wordHold))
        {
            retnumber = 1;
        }
        //Next check replacing the wrong charater if it fixes it
        //Create new string to hold the word with replaced character
        wordHold = word;
        //Fill new string with all the character but have correct replacement at error first error
        for (int s = 0; s < (word.size()); s++)
        {
            if (s < errorPoistion)
                wordHold[s] = word[s];
            else if (s == errorPoistion)
                wordHold[s] = check[s];
            else
                wordHold[s] = word[s];
        }
        // Check next if any perfect match occured after replacing error character
        if (perfectMatch(dictionary, n, wordHold))
        {
            retnumber = 1;
        }
        //Next check swapping the wrong charater if it fixes it
        wordHold = word;
        //Complete letter swap at the first error position in the string
        for (int s = 0; (s < (word.size()) && (errorPoistion !=check.size()-1)); s++)
        {
            if (s < errorPoistion)
                wordHold[s] = word[s];
            else if (s == errorPoistion)
                wordHold[s] = word[s+1];
            else if (s == errorPoistion+1)
                wordHold[s] = word[s - 1];
            else
                wordHold[s] = word[s];
        }
        // Check next if any perfect match occured after swap error character
        if (perfectMatch(dictionary, n, wordHold))
        {
            retnumber = 1;
        }
    }
    //If make it down here then no perfect match, or simple switch can occur so must return 2
    return retnumber;
}

int main()
{
    // Here are some tests.  You may add more if you wish.
    string dict1[6] = { "february", "pointer", "country", "forty", "conversation", "minuscule" };
    assert(scoreTypo(dict1, 0, "forty") == -1);
    assert(scoreTypo(dict1, 6, "forty") == 0);
    assert(scoreTypo(dict1, 6, "fourty") == 1);
    assert(scoreTypo(dict1, 6, "febuary") == 1);
    assert(scoreTypo(dict1, 6, "miniscule") == 1);
    assert(scoreTypo(dict1, 6, "poitner") == 1);
    assert(scoreTypo(dict1, 6, "conservation") == 2);
    //Test I made to check program
    string owen[1] = {"owen"};
    assert(scoreTypo(owen, 1, "owen") == 0);
    assert(scoreTypo(owen, 1, "owjen") == 1);
    assert(scoreTypo(owen, 1, "own") == 1);
    assert(scoreTypo(owen, 1, "owne") == 1);
    assert(scoreTypo(owen, 1, "oewn") == 1);
    assert(scoreTypo(owen, 1, "owwn") == 1);
    assert(scoreTypo(owen, 1, "oeee") == 2);
    assert(scoreTypo(owen, 1, "owe") == 1);
    assert(scoreTypo(owen, 1, "owene") == 1);
    string owen1[5] = {"hey", "owen"};
    assert(scoreTypo(owen1, 2, "owen") == 0);
    assert(scoreTypo(owen1, 2, "owjen") == 1);
    assert(scoreTypo(owen1, 2, "own") == 1);
    assert(scoreTypo(owen1, 2, "owne") == 1);
    assert(scoreTypo(owen1, 2, "oewn") == 1);
    assert(scoreTypo(owen1, 2, "owwn") == 1);
    assert(scoreTypo(owen1, 2, "oeee") == 2);
    assert(scoreTypo(owen1, 2, "owe") == 1);
    assert(scoreTypo(owen1, 2, "owene") == 1);
    assert(scoreTypo(owen1, 1, "owene") == 2);
    assert(scoreTypo(owen1, 2, "aaa") == 2);
    //If all test work print all tests succeeded
    cout << "All tests succeeded" << endl;
}
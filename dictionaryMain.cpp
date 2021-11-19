#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include<windows.h>
#include"Dictionary.h"


void insertWord(std::map<std::string, EnglishDictionary>& engDict);
void removeWord(std::map<std::string, EnglishDictionary>& engDict);
void searchWord(std::map<std::string, EnglishDictionary> engDict);
void updateWord(std::map<std::string, EnglishDictionary>& engDict);
void display(std::map<std::string, EnglishDictionary> engDict);

int main()
{
    std::map<std::string, EnglishDictionary> engDict;

    int choice;
    bool exit = false;

   

   while (!exit)
   {
       std::cout << "*********** MENU *************" << std::endl;
       std::cout << "1. Insert" << std::endl;
       std::cout << "2. Delete" << std::endl;
       std::cout << "3. Find" << std::endl;
       std::cout << "4. Update" << std::endl;
       std::cout << "5. Display" << std::endl;
       std::cout << "6. Exit" << std::endl;
       std::cout << "Enter your choice: ";
       std::cin >> choice;
       std::wcout << "************************************" << std::endl;

       switch (choice)
       {
       case 1:
           insertWord(engDict);
           break;

       case 2:
           removeWord(engDict);
           break;

       case 3:
           searchWord(engDict);
           break;

       case 4:
           updateWord(engDict);
           break;

       case 5:
           display(engDict);
           break;

       case 6:
           exit = true;
           break;

       default:
           std::cout << "Invalid choice!" << std::endl;
       }
   }

  
    return 0;
} 


void insertWord(std::map<std::string, EnglishDictionary>& engDict)
{
    std::string newWord, newMeaning, newSynonym, newAntonym, newExampleSentence;
    

    std::cout << "Enter a word to insert: ";
    std::getline(std::cin>>std::ws, newWord);

    if (!engDict.count(newWord))
    {
        std::cout << "Enter a meaning of '" << newWord << "' : ";
        std::getline(std::cin>>std::ws, newMeaning);

        std::cout << "Enter a synonym(similar in meaning): ";
        std::getline(std::cin>>std::ws, newSynonym);

        std::cout << "Enter an antonym(opposite in meaning) of the word: ";
        std::getline(std::cin>>std::ws, newAntonym);

       std::cout << "Enter a sentence as an example: ";
        std::getline(std::cin>>std::ws, newExampleSentence);

        EnglishDictionary newEntry(newWord, newMeaning, newSynonym, newAntonym, newExampleSentence);
        engDict.insert(std::pair<std::string, EnglishDictionary>(newWord, newEntry));

        std::cout << "The word \"" << newWord << "\" has been inserted into the dictionary." << std::endl;
    }
    else
    {
        std::cout << "The word \"" << newWord << "\"  already exists in the dictionary." << std::endl;
    }
}

void removeWord(std::map<std::string, EnglishDictionary>& engDict)
{
    std::string word;

    std::cout << "Enter a word to remove: ";
    std::getline(std::cin>>std::ws, word);

    if (engDict.count(word))
    {
        engDict.erase(word);
        std::cout << word << " has been deleted from the dictionary." << std::endl;
    }
    else
    {
        std::cout << word << " cannot be found in the dictionary." << std::endl;
    }
} 


void searchWord(std::map<std::string, EnglishDictionary> engDict)
{
    std::string word;

    std::cout << "\nEnter a word to search: ";
    std::getline(std::cin >> std::ws, word);

    if (engDict.count(word))
    {
        auto itr = engDict.find(word);
        std::cout << "The word " << itr->first << " was found in the dictionary." << std::endl;
        EnglishDictionary ed = itr->second;
        ed.printDetails();
    }
    else
    {
       std::cout << word << " was not found in the dictionary." << std::endl;
    }
}

void updateWord(std::map<std::string, EnglishDictionary>& engDict)
{
    std::string word{}, meaning{}, synonym{}, antonym{}, sentence{};
    size_t choice{ 0u };
    bool exit = false;

    std::cout << "Enter a word to update: ";
    std::getline(std::cin >> std::ws, word);

    if (engDict.count(word))
    {
        auto itr = engDict.find(word);
        

        while (!exit)
        {
            std::cout << "Updating the word " << "'" << itr->first << "'" << std::endl << std::endl;
            std::cout << "What do you want to update\n"
                "1. Word\n"
                "2. Meaning\n"
                "3. Synonym\n"
                "4. Antonym\n"
                "5. Sentence\n";
            std::cout << "Select entry to update: ";
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                std::cout << "Enter new word to update: ";
                std::getline(std::cin >> std::ws, word);
                itr->second.setWord(word);
                break;
            case 2:
                std::cout << "Enter new meaning to update: ";
                std::getline(std::cin >> std::ws, meaning);
                itr->second.setMeaning(meaning);
                break;
            case 3:
                std::cout << "Enter new synonym to update: ";
                std::getline(std::cin >> std::ws, synonym);
                itr->second.setSynonym(synonym);
                break;
            case 4:
                std::cout << "Enter new antonym to update: ";
                std::getline(std::cin >> std::ws, antonym);
                itr->second.setAntonym(antonym);
                break;
            case 5:
                std::cout << "Enter new sentence to update: ";
                std::getline(std::cin >> std::ws, sentence);
                itr->second.setExampleSentence(sentence);
                break;
            case 6:
                exit = true;
            default:
                std::cout << "Invalid entry!" << std::endl;
                break;
            }
        }
        std::cout << "Entry has been updated." << std::endl;
    }
    else
    {
        std::cout << "'"<< word << "' cannot be found in the dictionary." << std::endl;
    }
}

void display(std::map<std::string, EnglishDictionary> engDict)
{
    if (engDict.size() > 0)
    {
        std::cout << "Printing entire English Dictionary";
        std::cout << ".";
        Sleep(1000);
        std::cout << ".";
        Sleep(1000);
        std::cout << ".";
        Sleep(1000);
        std::cout << "." << std::endl;

        for (auto dictWord : engDict)
        {
            EnglishDictionary fullDict = dictWord.second;
            fullDict.printDetails();
        }
    }
    else
    {
        std::cout << "Dictionary is empty!" << std::endl;
    }
}
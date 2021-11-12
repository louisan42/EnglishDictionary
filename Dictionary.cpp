#include<iostream>
#include<string>
#include"Dictionary.h"


EnglishDictionary::EnglishDictionary()
{
    word = "";
    meaning = "";
    synonym = "";
    antonym = "";
    exampleSentence = "";
}
EnglishDictionary::EnglishDictionary(std::string newWord,
    std::string newMeaning, std::string newSynonym,
    std::string newAntonym, std::string newExampleSentence)
{
    word = newWord;
    meaning = newMeaning;
    synonym = newSynonym;
    antonym = newAntonym;
    exampleSentence = newExampleSentence;
}

std::string EnglishDictionary::getWord() const
{
    return word;
}

std::string EnglishDictionary::getMeaning() const
{
    return meaning;
}

std::string EnglishDictionary::getSynonym() const
{
    return synonym;
}

std::string EnglishDictionary::getAntonym() const
{
    return antonym;
}

std::string EnglishDictionary::getExampleSentence() const
{
    return exampleSentence;
}

void EnglishDictionary::setWord(std::string edWord)
{
    word = edWord;
}

void EnglishDictionary::setMeaning(std::string edMeaning)
{
    meaning = edMeaning;
}

void EnglishDictionary::setSynonym(std::string edSynonym)
{
    synonym = edSynonym;
}

void EnglishDictionary::setAntonym(std::string edAntonym)
{
    antonym = edAntonym;
}

void EnglishDictionary::setExampleSentence(std::string edExampleSentence)
{
    exampleSentence = edExampleSentence;
}

void EnglishDictionary::printDetails() const
{
    std::cout << "Word: " << this->getWord() << "\nMeaning: " << this->getMeaning()
        << "\nSynonym: " << this->getSynonym() << "\nAntonym: " << this->getAntonym()
        << "\nExample Sentence: " << this->getExampleSentence() << std::endl;
}
#ifndef DICTIONARY_H
#define DICTIONARY_H



class EnglishDictionary
{
private:
    std::string word;
    std::string meaning;
    std::string synonym;
    std::string antonym;
    std::string exampleSentence;

public:
    
    EnglishDictionary();
    EnglishDictionary(std::string newWord, std::string newMeaning,
        std::string newSynonym, std::string newAntonym,
        std::string newExampleSentence);
    std::string getWord() const;
    std::string getMeaning() const;
    std::string getSynonym() const;
    std::string getAntonym() const;
    std::string getExampleSentence() const;
    void setWord(std::string edWord);
    void setMeaning(std::string edMeaning);
    void setSynonym(std::string edSynonym);
    void setAntonym(std::string edAntonym);
    void setExampleSentence(std::string edExampleSentence);
    void printDetails() const;
};



#endif // !DICTIONARY_H

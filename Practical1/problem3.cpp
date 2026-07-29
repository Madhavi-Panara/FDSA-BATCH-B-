#include<iostream>
#include<string>
using namespace std;

int main()
{
    string sentence, word,longest;
    int i;
    cout<<"Enter a sentence: ";
    getline(cin,sentence);

    sentence=sentence+" ";//to read a space

    for(i=0;i<sentence.length();i++){//gives total no. of characters
        if(sentence[i]!=' '){
            word=word+sentence[i];//add current character yo word..ex..I am then it will read 'a' then word=word+a then similarly m and then space so that would be the word
        }
        else{
          if(word.length()>longest.length()){
                longest=word;
            }
        word="";//reduce the initial word and give the longest
        }
    }

    cout<<"Longest word: "<<longest<<endl;
    cout<<"Length: "<<longest.length()<<endl;

    return 0;
}

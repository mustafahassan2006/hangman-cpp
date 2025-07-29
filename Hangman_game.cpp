#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int cell;
void won();
void lost();
void print_hangman(int);
string word_to_lower(string);
bool is_letter_valid(char);
bool is_char_in_word(string,char);
int main()
{
    int guess_count=0, lost_count=0;
    string word;
    cout<<"Enter the word to be guessed(no spaces): ";
    getline(cin,word);
    word = word_to_lower(word);
    char ans[word.length()];
    for (int i = 0; i < word.length(); i++)
    {
        ans[i]='_';
    }
    ans[word.length()]='\0';
    while (true)
    {
        char character;
        print_hangman(lost_count);
        cout<<"guessed: "<<ans<<endl;
        cout<<endl;
        do
        {
            cout<<"enter a charecter (only a letter): ";
            cin>>character;
            character = tolower(character);
        } while (!(is_letter_valid(character)));
        
        if (is_char_in_word(word,character))
        { 
           ans[cell]=word[cell];
           word[cell]='*';
           guess_count+=1;
           if (guess_count==word.length())
           {
                cout<<"guessed: "<<ans<<endl;
                cout<<"You won";
                won();
                return 0;
           }
           
        }
        else
        {
            lost_count+=1;
            if (lost_count==7)
            {
                print_hangman(lost_count);
                cout<<"you lost";
                lost();
                return 0;
            }
        }      
    }   
}

bool is_char_in_word(string word,char a)
{
   
    for ( int i = 0; i < word.length(); i++)
    {
        if (word[i]==a)
        {
            cell = i;
            return true;
            break;
        }
    }
    return false;   
}
bool is_letter_valid(char a)
{
    if ( a >='a' && a<='z' )
    {
        return true;
    }
    return false;
    
}
string word_to_lower(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i]=tolower(word[i]);
    }
    return word;
}
void print_hangman(int x)
{
    if (x==1){
    cout<<R"(
         ___________
        |           |
        |           |
        |
        |
        |
        |
    )"<<endl;
}
else if(x==2){
    cout<<R"(        
         ___________
        |           |
        |           |
        |           O
        |
        |
        |
    )"<<endl;
}
else if(x==3){
    cout<<R"(        
         ___________
        |           |
        |           |
        |           O
        |          / 
        |
        |
    )"<<endl;
}
else if(x==4){
    cout<<R"(   
         ___________
        |           |
        |           |
        |           O
        |          / \
        |
        |      
    )"<<endl;
}
else if(x==5){
    cout<<R"(
         ___________
        |           |
        |           |
        |           O
        |          /|\
        |
        |   
    )"<<endl;
}
else if(x==6){
    cout<<R"(
         ___________
        |           |
        |           |
        |           O
        |          /|\
        |            \
        |   
    )";
}
else if(x==7){
    cout<<R"(
         ___________
        |           |
        |           |
        |           O
        |          /|\
        |          / \
        |   
    )"<<endl;
}
}
void won()
{
    cout<<R"(

            |              |    ------------    |\      |    |
            |              |    |           |   |  \    |    |
            |              |    |           |   |   \   |    |
            |       /\     |    |           |   |    \  |    |
            |   /       \  |    |           |   |     \ |    
            |/            \|     ------------   |      \|    |


    )";
}
void lost()
{
    cout<<R"(
                |               
                |               |-----------|   |--------   ----------  |
                |               |           |   |               |       |
                |               |           |   ---------       |       |
                |               |           |           |       |       |
                |               |           |           |       |       
                |-----------    ------------    ---------       |       |
    )";
}
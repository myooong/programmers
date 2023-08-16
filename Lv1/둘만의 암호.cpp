#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool IsIn(char ch, string skip){
    if(skip.find(ch) != string::npos)
        return true;
    else
        return false;
}

string solution(string s, string skip, int index) {
    string answer = "";
    char each_word;
    
    for(int i = 0; i < s.length(); i++){
        each_word = s[i];
        
        for(int j = 0; j < index; j++){
            each_word += 1;
            
            while(true){
                if(each_word > 'z')
                    each_word = 'a';
                if(IsIn(each_word,skip))
                    each_word += 1;
                else if(!IsIn(each_word,skip))
                    break;
            }
        }

        s[i] = each_word;
    }
    
    return s;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int i = 0;
    char init_word;
    char next_word;
    int match = 0;
    int no_match = 0;
    string temp_word = "";
    
    while(true){
        i = 0;
        init_word = s[i];
        temp_word = s;

        for(i = 0; i < s.length(); i++){

            next_word = s[i];
            if(init_word == next_word){
                match += 1;
            }
            else if(init_word != next_word){
                no_match += 1;
            }

            if(match == no_match){
                s = s.substr(i+1);
                match = 0;
                no_match = 0;
                answer += 1;
                break;
            }
        }
        
        if(s.length() == 0)
            break;
        else if(s.length() <= 1 || temp_word == s){
            answer += 1;
            break;
        }
    }
        
    return answer;
}
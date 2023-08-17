#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> split(string s, char ch){
    vector<string> temp_string;
    int idx = s.find(ch);
    temp_string.push_back(s.substr(0,idx));
    temp_string.push_back(s.substr(idx));
    
    return temp_string;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<string> temp_answer;
    unordered_map<string, unordered_set<string>> who_report;
    unordered_map<string, int> reported_count;
    unordered_map<string, int>::iterator count_it;
    
    for(string id : id_list){
        temp_answer.push_back(id);
        answer.push_back(0);
    }
    
    for(string name : report){
        who_report[split(name, ' ')[0]].insert(split(name, ' ')[1]);
    }
    
    for(auto it = who_report.begin(); it != who_report.end(); it++){
        for(auto iter = (it->second).begin(); iter != (it->second).end(); iter++) {
            reported_count[*(iter)] += 1;
        }
    }

    for(count_it = reported_count.begin();  count_it != reported_count.end(); ) {
        if (count_it->second < k) {
            count_it = reported_count.erase(count_it);
        }
        else {
            count_it++;
        }
    }
    
    for(pair<string, unordered_set<string>> who_name : who_report){
        for(string who_reported : who_name.second){
            for(pair<string, int> reported : reported_count){  
                if(reported.first == who_reported){
                    answer[find(temp_answer.begin(), temp_answer.end(), who_name.first)-temp_answer.begin()] += 1;
                }
            }   
        }
    }
    return answer;
}
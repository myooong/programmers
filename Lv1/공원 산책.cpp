#include <string>
#include <vector>
#include <iostream>
using namespace std;

void WayCheck(vector<string> park, int W, int H, pair<int,int>& current_position, string route){
    pair<int, int> temp_position = current_position;
    char direction = route[0];
    int block = route[2] - '0';
    
    if(direction == 'E'){
        
        if(current_position.second + block >= W)
            return;
        else{
            for(int i = 0; i < block; i++){
                temp_position.second = temp_position.second + 1;
                if(park[temp_position.first][temp_position.second] == 'X')
                    return;
            }
        }
    }
    else if(direction == 'W'){
        
        if(current_position.second - block < 0)
            return;
        else{
            for(int i = 0; i < block; i++){
                temp_position.second = temp_position.second - 1;
                if(park[temp_position.first][temp_position.second] == 'X')
                    return;
            }
        }
    }
    else if(direction == 'S'){
        
        if(current_position.first + block >= H)
            return;
        else{
            for(int i = 0; i < block; i++){
                temp_position.first = temp_position.first + 1;
                if(park[temp_position.first][temp_position.second] == 'X')
                    return;
            }
        }
    }
    else if(direction == 'N'){
        
        if(current_position.first - block < 0)
            return;
        else{
            for(int i = 0; i < block; i++){
                temp_position.first = temp_position.first - 1;
                if(park[temp_position.first][temp_position.second] == 'X')
                    return;
            }
        }
    }
    current_position = temp_position;
    
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    pair<int, int> current_position;
    
    int H = park.size();
    int W = park[0].length();
    
    for(int i = 0; i < park.size(); i++){
        if(park[i].find('S') != string::npos){
            current_position = {i, park[i].find('S')};
        }
    }
    
    for(int i = 0; i < routes.size(); i++){
        WayCheck(park,W,H,current_position,routes[i]);
    }
    answer.push_back(current_position.first);
    answer.push_back(current_position.second);
    
    return answer;
}
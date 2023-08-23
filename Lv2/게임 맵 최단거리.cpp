#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& maps){
    int up_down[4] = {-1, 1, 0, 0};
    int left_right[4] = {0, 0, -1, 1};
    int nx = 0;
    int ny = 0;
    int current_x = 0;
    int current_y = 0;
    int goal = maps[maps.size()-1][maps[0].size()-1];
    queue<pair<int,int>> q;
    vector<vector<int>> visit;
    vector<int> temp_visit;
    
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[0].size();j++){
            temp_visit.push_back(maps[i][j]);
        }
        visit.push_back(temp_visit);
        temp_visit.clear();
    }
    
    q.push({current_x,current_y});
    visit[current_x][current_y] = 0;
    
    while(!q.empty()){
        current_x = q.front().first;
        current_y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            nx = current_x + up_down[i];
            ny = current_y + left_right[i];
            
            if( (0 <= nx && nx < maps.size()) && (0 <= ny && ny < maps[0].size()) && (visit[nx][ny] == 1)){
                q.push({nx,ny});
                visit[nx][ny] = 0;
                maps[nx][ny] += maps[current_x][current_y];
            }
        }
    }

    if(goal != maps[maps.size()-1][maps[0].size()-1])
        return maps[maps.size()-1][maps[0].size()-1];   
    else if(goal == maps[maps.size()-1][maps[0].size()-1])
        return -1;   
    
}

int solution(vector<vector<int> > maps)
{
    int answer = bfs(maps);
    return answer;
}
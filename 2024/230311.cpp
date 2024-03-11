// 프로그래머스 : 광물 캐기

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v = {{1,1,1},{5,1,1},{25,5,1}};

bool cmp(vector<int>& a, vector<int>& b){
    if(a[2] != b[2]) return a[2] > b[2];
    if(a[1] != b[1]) return a[1] > b[1];
    return a[0] > b[0];
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0, picksCnt = 0;
    for(auto p : picks) picksCnt += p;
    int n = minerals.size();
    n = min(n, picksCnt*5);
    
    int m = min((n+4)/5, picksCnt);
    vector<vector<int>> cost(m, vector<int>(3,0));

    for(int i=0; i<n; i+=5){
        for(int j=i; j<i+5 && j<n; j++){
            if(minerals[j]=="diamond") cost[i/5][0] += v[0][0];
            else if(minerals[j]=="iron") cost[i/5][0] += v[0][1];
            else cost[i/5][0] += v[0][2];
        }
        for(int j=i; j<i+5 && j<n; j++){
            if(minerals[j]=="diamond") cost[i/5][1] += v[1][0];
            else if(minerals[j]=="iron") cost[i/5][1] += v[1][1];
            else cost[i/5][1] += v[1][2];
        }
        for(int j=i; j<i+5 && j<n; j++){
            if(minerals[j]=="diamond") cost[i/5][2] += v[2][0];
            else if(minerals[j]=="iron") cost[i/5][2] += v[2][1];
            else cost[i/5][2] += v[2][2];
        }
    }

    
    sort(cost.begin(), cost.end(), cmp);
    
    for(auto c : cost){
        if(picks[0]>0){
            picks[0]--;
            answer += c[0];
        }
        else if(picks[1]>0){
            picks[1]--;
            answer += c[1];
        }
        else{
            picks[2]--;
            answer += c[2];
        }
    }
    
    
    return answer;
}

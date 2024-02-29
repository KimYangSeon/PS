// 프로그래머스: 요격 시스템
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    if(a[1] != b [1])
        return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), cmp);
    
    int n = targets.size();
    int curEnd = 0;
    
    for(int i=0; i<n; i++){
        if(curEnd <= targets[i][0]){
            answer++;
            curEnd = targets[i][1];
        }
    }

    return answer;
}

// 프로그래머스 : 피로도
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    
    int n = dungeons.size();
    int ans = 0;
    vector<int> v;
    for(int i=0; i<n; i++) v.push_back(i);
    
    do{
        int curK = k;
        int curAns = 0;
        for(int i=0; i<n; i++){
            if(curK >= dungeons[v[i]][0]){
                curK -= dungeons[v[i]][1];
                curAns++;
            }
        }
        ans = max(ans, curAns);
    }while(next_permutation(v.begin(), v.end()));
    
    
    return ans;
}

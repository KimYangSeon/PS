// 프로그래머스 : 혼자 놀기의 달인

#include <vector>
#include <algorithm>
using namespace std;

bool isOpen[101];
vector<int> groupCnt;

int solution(vector<int> cards) {
    int answer = 0;
    int n = cards.size();
    
    for(int i=0; i<n; i++){
        int cnt = 0;
        int boxNum = cards[i]-1;
        if(isOpen[boxNum]) continue;
        
        while(!isOpen[boxNum]){
            isOpen[boxNum] = 1;
            boxNum = cards[boxNum]-1;
            cnt++;
        }
        groupCnt.push_back(cnt);
    }
    
    sort(groupCnt.begin(), groupCnt.end());
    int groupLen = groupCnt.size();
    if(groupLen < 2) answer = 0;
    else answer = groupCnt[groupLen-1] * groupCnt[groupLen-2];
    
    return answer;
}

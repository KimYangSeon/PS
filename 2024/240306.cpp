// 프로그래머스 : 연속된 부분 수열의 합
#include <vector>
using namespace std;

int sum[1000001];

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, 0);

    int n = sequence.size();
    int st = 0;
    int en = 1;
    int ans = 1000001;
    for(int i=1; i<=n; i++) sum[i] = sum[i-1] + sequence[i-1];
    
    while(en <= n){
        if(sum[en] - sum[st] > k) st++;
        else if(sum[en] - sum[st] < k) en++;
        else{
            if(en-st<ans){
                ans = en-st;
                answer[1] = en-1;
                answer[0] = st;
            }
            en++;
        }
    }
    
    
    return answer;
}

// 프로그래머스 : 양궁대회
#include <vector>
using namespace std;

int N;
int ans;
int lian[11];

void solve(vector<int> &apeach, vector<int> &answer, int cnt, int idx){
    if(idx >= 11 && cnt!=N) return;
    
    if(cnt==N){
        int lian_score = 0, apeach_score = 0;
        for(int i=0; i<10; i++){
            if(apeach[i] < lian[i]) lian_score += 10-i;
            else if(apeach[i] != 0) apeach_score += 10-i;
        }
        if(lian_score == apeach_score) return;
        
        if(lian_score - apeach_score > ans){
            ans = lian_score - apeach_score;
            for(int i=0; i<=10; i++) answer[i] = lian[i];
        }
        else if(lian_score - apeach_score == ans){
            for(int i=10; i>=0; i--){
                if(lian[i] > answer[i]){
                    for(int i=0; i<=10; i++) answer[i] = lian[i];
                    break;
                }
                else if(lian[i] < answer[i]) {
                    break;
                }
            }
        }
   
        return;
    }
    
    if(idx < 10 && cnt + apeach[idx] + 1 <= N){
        lian[idx] = apeach[idx] + 1;
        solve(apeach, answer, cnt + apeach[idx] + 1, idx+1);
    }
    
    if(idx==10){
        lian[idx] = N-cnt;
        solve(apeach, answer, N, idx+1);
    }
    
    lian[idx] = 0;
    solve(apeach, answer, cnt, idx+1);
    
    
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(11,0);
    N = n;
    
    solve(info, answer, 0, 0);
    
    if(ans==0){
        vector<int> v(1,-1);
        return v;
    }

    return answer;
}

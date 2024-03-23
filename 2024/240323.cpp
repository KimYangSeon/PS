// 프로그래머스 : 택배 배달과 수거하기
#include <vector>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long ans = 0;
    int d = 0, p = 0;
    
    for(int i=n-1; i>=0; i--){
        int cur, cnt;
        int d_pre = deliveries[i];
        int p_pre = pickups[i];
        deliveries[i] = max(0, deliveries[i] - d);
        pickups[i] = max(0, pickups[i] - p);
        d -= (d_pre - deliveries[i]);
        p -= (p_pre - pickups[i]);
        
        if(deliveries[i] > pickups[i]) cur = deliveries[i];
        else cur = pickups[i];
        
        cnt = cur / cap;
        if(cur % cap != 0) cnt++;
        
        d += (cap * cnt - deliveries[i]); // 없앨 수 있는 택배 개수
        p += (cap * cnt - pickups[i]);
        

        ans += cnt * (i + 1); // i+1거리를 cnt번 다녀옴
    }
    
    return ans * 2;
}

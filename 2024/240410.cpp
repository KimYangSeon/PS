// 프로그래머스 : k진수에서 소수 개수 구하기
// https://school.programmers.co.kr/learn/courses/30/lessons/92335#
#include <vector>

using namespace std;

bool isPrime(long long n){
    if(n<=1) return false;
    for(long long i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}


int solution(int n, int k) {
    int answer = 0;

    long long cur = 0;
    long long p = 1;
    
    while(n){
        int mod = n % k;
        cur += mod * p;
        n /= k;
        p *= 10;
        if(mod == 0){
            if(isPrime(cur)) answer++;
            cur=0;
            p=1;
        }
    }
    cur += n * p;
    if(isPrime(cur)) answer++;
    
    return answer;
}

// 프로그래머스 : 호텔 대실
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int getTime(string str){
    int h = stoi(str.substr(0,2));
    int m = stoi(str.substr(3));
    return h*60+m;
}

int solution(vector<vector<string>> book_time) {
    int answer = 1;
    sort(book_time.begin(), book_time.end());
    
    pq.push(-10);
    
    for(auto b : book_time){
        int st = getTime(b[0]);
        int en = getTime(b[1]);
        
        if(pq.top() + 10 <= st){
            pq.pop();
        }
        pq.push(en);
    }
    
    return pq.size();
}

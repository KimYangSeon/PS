// 프로그래머스 :주차 요금 계산 
// https://school.programmers.co.kr/learn/courses/30/lessons/92341
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> carIn[10000];
vector<int> carOut[10000];

int getTime(string str){
    int h = stoi(str.substr(0,2));
    int m = stoi(str.substr(3,2));
    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    int finalTime = getTime("23:59");
    int maxNum = -1;
    
    for(auto r : records){
        int time = getTime(r.substr(0, 5));
        int num = stoi(r.substr(6, 4));
        string inout = r.substr(11);
        if(inout == "IN" && time != finalTime) carIn[num].push_back(time);
        else if(inout == "OUT") carOut[num].push_back(time);
        maxNum = max(maxNum, num);
    }
    
    for(int i=0; i<=maxNum; i++){
        int cnt = carIn[i].size();
        if(cnt == 0) continue;
        if(cnt != carOut[i].size()) carOut[i].push_back(finalTime);
        int pay = fees[1];
        int parkTime = 0;

        for(int j=0; j<cnt; j++) parkTime += carOut[i][j] - carIn[i][j];
        if(parkTime > fees[0]) pay += (int)(ceil((parkTime - fees[0])/(double)fees[2])) * fees[3];

        answer.push_back(pay);
    }
    
    
    return answer;
}

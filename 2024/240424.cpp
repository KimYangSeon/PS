// 프로그래머스 : 수식 최대화
// https://school.programmers.co.kr/learn/courses/30/lessons/67257
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

char operand[3] = {'*','+','-'};
int p[3] = {0,1,2};

long long ans;
vector<long long> num;
vector<char> op;

int getPriority(char c){
    for(int i=0; i<3; i++){
        if(operand[i]==c){
            return p[i];
        }
    }
}

void calculate(long long a, long long b, char o){
    if(o=='*') num.push_back(a*b);
    else if(o=='+') num.push_back(a+b);
    else if(o=='-') num.push_back(a-b);
}


void solve(string& expression){
    string cur = "";
    for(auto e : expression){
        if(isdigit(e)){
            cur += e;
        }
        else{
            num.push_back(stol(cur));
            cur = "";
            
            while(op.size()>0 &&  getPriority(e) >= getPriority(op.back())){
                long long b = num.back(); num.pop_back();
                long long a = num.back(); num.pop_back();
                calculate(a,b,op.back()); op.pop_back();
            }
            op.push_back(e);
        }
    }
    
    num.push_back(stol(cur));
    while(op.size()>0){
        long long b = num.back(); num.pop_back();
        long long a = num.back(); num.pop_back();
        calculate(a,b,op.back()); op.pop_back();
    }
}

long long solution(string expression) {
    
    do{
        if(num.size()>0) num.pop_back();
        solve(expression);
        ans = max(abs(num[0]), ans);
        //cout << '\n';
    }while(next_permutation(p, p+3));
    
    return ans;
}

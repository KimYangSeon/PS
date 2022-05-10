#include <iostream>
using namespace std;

int n, r, c;

int func(int n, int r, int c){
    if(n==0){
        return 0;
    }

    int a = 1<<(n-1); // 2의 n-1승 

    // 첫번째 사각형 = n-1의 결과 
    // 두번째 사각형 = n-1의 결과 + a * a
    // 세번째 사각형 = n-1의 결과 + a * a * 2
    // 네번째 사각형 = n-1의 결과 + a * a * 3

    if(r<a && c<a) return func(n-1, r, c);
    else if(r<a && c>=a) return func(n-1,r,c-a) + a*a;
    else if(r>=a && c<a) return func(n-1,r-a,c) + a*a*2;
    else return func(n-1,r-a,c-a) + a*a*3;


}

int main()
{

    cin >> n >> r >> c;

    cout<<func(n,r,c);


    return 0;
}

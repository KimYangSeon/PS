#include <iostream>
using namespace std;

int n, r, c;

int func(int n, int r, int c){
    if(n==0){
        return 0;
    }

    int a = 1<<(n-1); // 2�� n-1�� 

    // ù��° �簢�� = n-1�� ��� 
    // �ι�° �簢�� = n-1�� ��� + a * a
    // ����° �簢�� = n-1�� ��� + a * a * 2
    // �׹�° �簢�� = n-1�� ��� + a * a * 3

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

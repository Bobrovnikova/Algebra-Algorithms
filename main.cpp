#include <iostream>
#include <intrin.h>
#include <fstream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "rus");
    int n, e;
    int i, j, q;
    ifstream in("gc_20_1");
    in >> n >> e;
    bool A[n][n];
    for(i=0; i<n; i++){
        for(q=0; q<i; q++)
            A[i][q] = 0;
        A[i][i]=1;
        for(q=i+1; q<n; q++)
            A[i][q] = 0;
    }
    for(q=0; q<e; q++){
        in >> i >> j;
        A[i][j] = 1;
        A[j][i] = 1;
    }
    in.close();
    cout << n << endl;
    int colored [n];
    for(i=0; i<n; i++)
        colored[i]=0;
    int k=1; //���� ������� ���������� ���������
    for(i=0; i<n; i++){
        if(!colored[i]){
            //cout << "Vertex " << i << " is coloured!" << endl;
        //else{
            colored[i] = k;
            while(true){
            for(j=i+1; j<n; j++){
                if(!A[i][j]&&!colored[j])
                    break;
            }
            if(j==n)
                break;
            colored[j]=k;
            for(q=0; q<n; q++)
                A[i][q] = A[i][q]|A[j][q];
            }
            k++;
        }
    }
    cout << k-1;
    return 0;
    }




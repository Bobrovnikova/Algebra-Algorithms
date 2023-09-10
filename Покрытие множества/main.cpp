#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>
#include "head.h"

using namespace std;



int main()
{
    ifstream in("sc_500_0");
    int N, M, i, j, k, flag;
    string nums;
    getline(in, nums);
    stringstream stream(nums);
    stream >> N >> M;
    flag = N;
    vector <int> c(M), sum_row(N);
    vector <bool> x(M);
    vector<vector<int>> T(N, vector<int> (M));


    //заполняем
    for(k=0; k<M; k++){
        getline(in, nums);
        stringstream stream(nums);
        int n;
        stream >> c[k];
        while(stream >> n) {
        T[n][k] = 1;
        }
    }

    for(i=0; i<N; i++)
        sum_row[i] = sum_by_row(*(T.begin()+i));

    //
    vector<int> sum_col(M);
    while(flag>0){

        auto it = min_element(sum_row.begin(), sum_row.end());
        int min_b_idx = distance(sum_row.begin(), it);
        for(i=0; i<M; i++){
            if(T[min_b_idx][i])
                sum_col[i] = sum_by_column(T, N, i);
        }

    int max_A_idx = max_col(M, sum_col, c);
    x[max_A_idx] = 1;

    for(i=0; i<N; i++){
        if(T[i][max_A_idx]){
            for(int j=0; j<M; j++)
                T[i][j]= 0;
            sum_row[i] = INT_MAX;
            flag--;
    }
    }
    for(int j=0; j<M; j++)
                sum_col[j]= 0;
    }
    int cost=0;
    cout << "x = ";
    for(i=0; i<M; i++){
        cost += x[i]*c[i];
        cout << x[i] << " ";
    }

    cout << endl << "Cost = " << cost << endl;
    T.clear();
    sum_col.clear();
    sum_row.clear();
    return 0;
}

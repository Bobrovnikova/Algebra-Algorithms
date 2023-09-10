#include "head.h"
#include <vector>

using namespace std;

int sum_by_row(vector<int> row){
    int sum_of_elems = 0;
    for (auto& n : row) sum_of_elems += n;
    return sum_of_elems;
}

int sum_by_column(vector<vector<int>> A, int row, int column){
    int i, sum_of_elems = 0;
    for(i=0; i<row; i++){
        sum_of_elems += A[i][column];
    }
    return sum_of_elems;
}

int max_col(int M, vector<int> sum_col, vector<int> c){
    int index=-1, res=0, i;
    for(i=0; i<M; i++){
        if((sum_col[i]>res) || (sum_col[i]==res)&&(c[i]<c[index])){
            res = sum_col[i];
            index = i;
        }
    }
    return index;
}

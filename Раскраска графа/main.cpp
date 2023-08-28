#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string S[36] = {"gc_1000_1", "gc_1000_3", "gc_1000_5", "gc_1000_7", "gc_1000_9",
    "gc_100_1", "gc_100_3", "gc_100_5", "gc_100_7", "gc_100_9",
    "gc_20_1", "gc_20_3", "gc_20_5", "gc_20_7", "gc_20_9",
    "gc_250_1", "gc_250_3", "gc_250_5", "gc_250_7", "gc_250_9", "gc_4_1",
    "gc_500_1", "gc_500_3", "gc_500_5", "gc_500_7", "gc_500_9",
    "gc_50_1", "gc_50_3", "gc_50_5", "gc_50_7", "gc_50_9",
    "gc_70_1", "gc_70_3", "gc_70_5", "gc_70_7", "gc_70_9"};
    int n, e;
    int i, j, q, it, it2;
    //string it1;
    ifstream f("���");
    ofstream res("result");
    res << "Test       " << "���    " << "��� " << "%" << endl;
    for(it=0; it<36; it++){
    f >> it2;
    ifstream in(S[it]); //�������� ���� ��� ������
    in >> n >> e; //�������� ����� ������ � ���-�� �����
    bool A[n][n]; //������ ������� ���������
    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            A[i][j] = 0;
        A[i][i]=1;
    }
    for(q=0; q<e; q++) { //������ ��������, ���� ����� ����������
        in >> i >> j;
        A[i][j] = 1;
        A[j][i] = 1;
    }
    in.close();
    //cout << n << endl; //��� ����
    int colored [n];
    for(i=0; i<n; i++)
        colored[i]=0;
    int k=1; //���� ������� ���������� ���������
    for(i=0; i<n; i++) {
        if(colored[i]) continue;
        colored[i] = k;
        bool flag = 0;
        if (i!=n-1) {
			for (j=i+1; j<n; j++) {
				if (!A[i][j] && !colored[j]) {
					flag = 1;
					break;
				}
			}
		}
		else {
			k++; break;
		}
        while(flag) {
            for(j=i+1; j<n-1; j++){
                if(!A[i][j]&&!colored[j])
                    break;
            }
            if(j==n)
                break;
            colored[j]=k;
            for(q=0; q<n; q++)
                if (A[i][q]+A[j][q]!=0) A[i][q]=1;
            flag = 0;
			for (j=i+1; j<n; j++) {
				if (!A[i][j] && !colored[j]) {
					flag = 1;
					break;
				}
			}
        }
        k++;
    }
    //cout << k-1; // ������� ���-�� ������
    res << S[it] << "   " << it2 << "   " << k-1 << "   " << 100*(k - 1 - it2)/it2 << endl;
    }
    f.close();
    res.close();
    return 0;
}

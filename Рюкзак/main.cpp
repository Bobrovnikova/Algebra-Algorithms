#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

int main()
{
    string S[18] = {"ks_4_0", "ks_19_0", "ks_10000_0",
    "ks_1000_0", "ks_100_0", "ks_100_1", "ks_100_2",
    "ks_200_0", "ks_200_1", "ks_300_0", "ks_30_0",
    "ks_400_0", "ks_40_0", "ks_45_0", "ks_500_0",
    "ks_50_0", "ks_50_1", "ks_60_0"};
    ifstream f("МВШ");
    ofstream res;
    res.open("result", ios_base::app);
    ifstream in;
    //res << "Test       " << "МВШ    " << "ВАБ " << "%" << endl;
    int n, K;
    int i, k, it, it2;

    //for(it=0; it<18; it++){

    it = 17;
    for(i=0; i<=it; i++)
        f >> it2;
    //cout << "Mihail: "  << it2 << ";"  << endl;
    in.open(S[it]); //Открываю файл для чтения
    in >> n >> K; //Считываю число предметов и вместимость рюкзака
    cout << "Number of items: " << n << ";" << endl << "Backpack capacity: " << K << ";" << endl;
    vector <int> W(n), P(n);
    vector<vector<int>> F(n+1, vector<int> (K+1));

    for(i=0; i<n; i++){
            in >> P[i] >> W[i];
    }

    for(k=0; k<=K; k++){
                F[0][k] = 0;
        }
    for(i=1; i<=n; i++){
        for(k=0; k<=K; k++){
        if (k >= W[i-1])
            F[i][k] = max(F[i - 1][k], F[i - 1][k - W[i-1]] + P[i-1]);
        else
            F[i][k] = F[i - 1][k];
        }
    }


    cout << "The cost of items in a backpack: " << F[n][K]<< endl;

    k = K;
    vector<bool> Ans(n);
    for (i=n; i>0; i--){
    if (F[i][k] != F[i - 1][k]){
        Ans[i-1] = 1;
        k -= W[i-1];
    }
    }
    for (bool j: Ans)
            cout << j<< " ";
    cout << endl;
    res << S[it] << "   " << it2 << "   " << F[n][K] << "   " << 100*(it2 - F[n][K])/it2 << endl;

    in.close();
    in.clear();
   //}

    f.close();
    res.close();
    return 0;
}

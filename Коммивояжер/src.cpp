#include "head.h"

using namespace std;

double dist(point a, point b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double length(int num_of_nodes, vector<point> path){
    double len = 0;
    int i;
    for(i=0; i<num_of_nodes; i++)
        len += dist(path[i], path[(i+1)%num_of_nodes]);

    return len;
}

void show(vector<point> path){
    for(auto p: path)
        cout << p.index << " ";
}

bool shorter(int v1, int v2, int num_of_nodes, vector<point>& path){

    bool flag = false;

    double init_dist =
          dist(path[v1], path[v1+1])
        + dist(path[v2], path[(v2+1)%num_of_nodes]);

    double new_dist =
            dist(path[v1], path[v2])
        + dist(path[v1+1], path[(v2+1)%num_of_nodes]);
    if( init_dist > new_dist ){
        reverse(path.begin() + v1 + 1, path.begin() + v2 + 1);
        flag = true;
    }
    return flag;
}

void local_search(int num_of_nodes, vector<point>& path){
    int i, j;
    bool flag;
    for(i=0; i<num_of_nodes-2; i++)
        for(j=i+2; j<num_of_nodes; j++){

            flag = shorter(i, j, num_of_nodes, path);

            if(flag){
                j = i+2;
            }
        }
}

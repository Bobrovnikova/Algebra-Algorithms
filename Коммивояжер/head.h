#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

struct point{
    int index;
    double x,y;
};

double dist(point a, point b);

double length(int num_of_nodes, vector<point> path);

void show(vector<point> path);

bool shorter(int v1, int v2, int num_of_nodes, vector<point>& path);

void local_search(int num_of_nodes, vector<point>& path);

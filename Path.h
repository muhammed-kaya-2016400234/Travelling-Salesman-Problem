//
// Created by student on 07.12.2017.
//

#ifndef PROJECT3_PATH_H
#define PROJECT3_PATH_H

using namespace std;
#include <vector>
#include "town.h"
#include <queue>
typedef pair<int,int> iPair;
typedef pair<vector<vector<int>>,vector<int>> mypair;
class Path {

public:
    Path(int v);
    int t;   //number of towns

    void findpath();
    list<iPair> *adj;
    town starting;
    town endtown;
    mypair shortestpath(int starting,vector<int> coinshave);
    vector<vector<int>> jewel;
    vector<vector<vector<int>>> thief ;
    void addthief(int i,int j,int k);
    void addJewel(int i,int j);
    void addUndirectedEdge(int i,int j,int k);
};


#endif //PROJECT3_PATH_H

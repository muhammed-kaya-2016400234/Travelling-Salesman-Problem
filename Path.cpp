//
// Created by student on 07.12.2017.
//
#include <iostream>
#include "Path.h"
#include <queue>
#include <algorithm>
# define INF 0x3f3f3f3f
using namespace std;
Path::Path(int v){
    this->t=v;
    adj = new list<iPair>[v+1];
    jewel.reserve(v+1);
    thief.reserve(v+1);
    for(int i=1;i<v+1;i++){
        thief[i].reserve(v+1);
    }
   // path.reserve(v+1);
}

/*
void Path::findpath(){
    town curr=starting;
    while(curr.id!=endtown.id){
        vector<int> coins;
        vector<town> valid;

        vector<iPair>::iterator it;
        for(it=curr.adj.begin();it!=curr.adj.end();++it){
            if(it->second.size()==0){
                valid.push_back(it->first);
            }else  {
                int coinforthieves;
                for (int i = 0; i < coins.size(); i++) {
                    for(int j=0;j<it->second.size();j++){
                        if(it->second[j]==coins[i]){
                            coinforthieves++;
                            j=it->second.size();
                        }

                    }

                }
                if(coinforthieves==it->second.size()){
                    valid.push_back(it->first);

                }



            }
        }




    }


}*/

mypair Path::shortestpath(int starting,vector<int> coinshave){


    vector< int > pq;
    vector<int> coinwehave=coinshave;          /////////////////////////////////////////////
    vector<int> dist(t+1,INF);
    dist[starting]=0;

     vector<bool> visited(t+1, false);
    // initialize start_node
    pq.push_back( starting);
    vector<vector<int>> path(t+1);
    path[starting].push_back(starting);

    while (!pq.empty())
    {
        int curr_node = pq.front();
        pq.erase(pq.begin(),pq.begin()+1);
        visited[curr_node]=true;
        sort(jewel[curr_node].begin(),jewel[curr_node].end());
        /*for(int y=0;y<jewel[curr_node].size();y++){
            if(find(coinwehave.begin(),coinwehave.end(),jewel[curr_node][y])==coinwehave.end()){
                coinwehave.push_back(jewel[curr_node][y]);

            }
        }*/
        sort(coinwehave.begin(),coinwehave.end());

        list< iPair >::iterator itr;

        for (itr = adj[curr_node].begin(); itr != adj[curr_node].end(); ++itr)
        {


            // Get vertex label and weight of current adjacent
            // of u.

            int curr_neighbor = (*itr).first;
            int curr_weight = (*itr).second;
                sort(coinwehave.begin(),coinwehave.end());
            if(thief[curr_node][curr_neighbor].size()==0||includes(coinwehave.begin(),coinwehave.end(),thief[curr_node][curr_neighbor].begin(),thief[curr_node][curr_neighbor].end())) {

                //  if there is shorted path to curr_neighbor through curr_node



                if (dist[curr_neighbor] > dist[curr_node] + curr_weight) {
                    // update distance of curr_neighbor
                    vector <int>copypath=path[curr_node];
                    //std::cout<<path[curr_node][path[curr_node].size()-1]<<"path"<<std::endl;
                    copypath.push_back(curr_neighbor);
                   // std::cout<<starting<<" "<<curr_node<<" "<<curr_neighbor<<" "<<std::endl;
                    path[curr_neighbor]=copypath;
                    //std::cout<<path[curr_neighbor][path[curr_neighbor].size()-1]<<"path2"<<std::endl;
                    dist[curr_neighbor] = dist[curr_node] + curr_weight;

                    if(!visited[curr_neighbor]){
                        if(std::find(pq.begin(),pq.end(),curr_neighbor)==pq.end()){
                      //  std::cout<<curr_neighbor<<std::endl;
                    pq.push_back(curr_neighbor);}}
                    //std::cout<<"here"<<std::endl;
                   for(int i=0;i<path[curr_neighbor].size();i++)
                   // std::cout<<path[curr_neighbor][i]<<std::endl;


                    if (jewel[curr_neighbor].size() != 0) {

                        vector<int> copy=coinwehave;
                        vector<int>::iterator it;
                        bool check=false;
                        for(it=jewel[curr_neighbor].begin();it!=jewel[curr_neighbor].end();++it){
                            if(find(coinwehave.begin(),coinwehave.end(),*it)==coinwehave.end()){
                                copy.push_back(*it);
                                    check=true;
                            }
                        }

                        sort(copy.begin(),copy.end());
                        if (check) {
                            vector<int> c;
                            vector<vector<int>> p(t+1);
                            p=shortestpath(curr_neighbor, copy).first;
                            int l=p.size();
                            c = shortestpath(curr_neighbor, copy).second;

                           for(int k=1;k<t+1;k++){
                                int a=c[k];

                                if(a+dist[curr_neighbor]<dist[k]){
                                   dist[k]=a+dist[curr_neighbor];
                                    int b=dist[k];

                                  if(!p[k].empty()) {
                                      p[k].insert(p[k].begin(), path[curr_neighbor].begin(),
                                                  path[curr_neighbor].begin() + (path[curr_neighbor].size() - 1));

                                      path[k] = p[k];
                                  }

                                }

                            }

                        }
                    }


                }
            }
        }
    }

return make_pair(path,dist);

}
void Path::addJewel(int i,int j){
    jewel[i].push_back(j);
    sort(jewel[i].begin(),jewel[i].end());                  //??????????????????????????????????????*
}
void Path::addthief(int i, int j, int k) {
    thief[i][j].push_back(k);
    thief[j][i].push_back(k);
    sort(thief[i][j].begin(),thief[i][j].end());           //??????????????????????????????

}
void Path::addUndirectedEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
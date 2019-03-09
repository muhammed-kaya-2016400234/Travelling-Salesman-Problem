
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include "Path.h"
using namespace std;
# define INF 0x3f3f3f3f

template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}
int main(int argc, char* argv[]) {
    // below reads the input file
    // in your next projects, you will implement that part as well
    if (argc != 3) {
        cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
        return 1;
    }

    cout << "input file: " << argv[1] << endl;
    cout << "output file: " << argv[2] << endl;




    ifstream infile(argv[1]);
    string line;

    getline(infile, line);
    vector<string> words;
    split1(line,words);
    int towns=stoi(words[0]);
    Path a(towns);
    int edges=stoi(words[1]);
    int thieves=stoi(words[2]);
    int jeweler=stoi(words[3]);

    for(int i=0;i<jeweler;i++){
        getline(infile, line);
        vector<string> words;
        split1(line,words);
        for(int k=0;k<stoi(words[1]);k++)
        a.addJewel(stoi(words[0]),stoi(words[2+k]));
    }

    for(int i=0;i<edges;i++){
        getline(infile,line);
        vector<string> words;
        split1(line,words);
        a.addUndirectedEdge(stoi(words[0]),stoi(words[1]),stoi(words[2]));

        for(int k=0;k<stoi(words[3]);k++)
            a.addthief(stoi(words[0]),stoi(words[1]),stoi(words[4+k]));

    }




    cout << "input file has been read" << endl;


    std::ofstream myfile;
    myfile.open (argv[2]);


    vector<vector<int>> p;

    vector<int> c;

    p=a.shortestpath(1,c).first;
    if(p[towns].size()==0)
        myfile<<"-1";
    for(int i=0;i<p[towns].size();i++){
       // cout<<" "<<p[towns][i];
        myfile<<p[towns][i]<<" ";
    }

cout<<"done done done"<<endl;
    myfile.close();



    return 0;
}

/*
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include "Path.h"
using namespace std;
# define INF 0x3f3f3f3f

 int main(){


    Path a(3);
     //number of towns
   // int startingdist=0;
    //vector<int> dist(7,INF) ;        //shortest path e parantez içine yolla
    //dist[1]=0;
/*

     a.addUndirectedEdge(1,2,2);
      a.addUndirectedEdge(1,4,2);
      a.addUndirectedEdge(2,3,9);
      a.addUndirectedEdge(2,5,3);
      a.addUndirectedEdge(5,4,5);
      a.addUndirectedEdge(5,6,9);
      a.addUndirectedEdge(4,6,18);
      a.addthief(1,4,2);
      a.addthief(4,5,2);
      //a.addthief(4,5,3);
      a.addthief(5,6,1);
      a.addthief(5,6,2);
      a.addthief(1,4,3);
      a.addJewel(2,2);
      a.addJewel(3,1);
      a.addJewel(3,3);
      */
/*
     a.addUndirectedEdge(1,2,1);
     a.addUndirectedEdge(1,3,1);
     a.addUndirectedEdge(2,3,3);
     a.addJewel(2,1);
     a.addJewel(2,2);
     a.addJewel(3,3);
     a.addthief(1,3,3);
     a.addthief(2,3,1);
     a.addthief(2,3,2);
    vector<vector<int>> p;

    vector<int> c;

    p=a.shortestpath(1,c).first;

    for(int i=0;i<p[3].size();i++){
       cout<<" "<<p[3][i];
    }

    return 0;
    }
*/




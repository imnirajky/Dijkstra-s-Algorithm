#include <bits/stdc++.h>
using namespace std;


int main(){
    int node, edge;
    cin>>node>>edge;
    vector<int> visit(node, 0), distance(node, INT_MAX);
    vector<vector<int>> link(node, vector<int> (node, 0));

    

    for(int i=0; i<edge; i++){
        int a, b, w;
        cin>>a>>b>>w;
        link[a][b] = w;
        link[b][a] = w;
    }

    distance[0] = 0;

    for(int i=0; i<node-1; i++){
        
        int currNode;
        int val = INT_MAX;

        for(int j=0; j<node; j++){
            if(visit[j] == 0 && distance[j]<val){
                currNode = j;
                val = distance[j];
            }
        }

        visit[currNode] = 1;

        for(int k=0; k<node; k++){
            if(link[currNode][k] && visit[k] == 0){
                distance[k] = min(distance[k], (distance[currNode] + link[currNode][k]));
            }
        }
    }


    for(int i=0; i<node; i++){
        cout<<"Shortest Distance to reach city : "<<i<<" is "<<distance[i]<<endl;
    }
}
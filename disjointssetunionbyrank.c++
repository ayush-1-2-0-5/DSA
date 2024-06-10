#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
   vector<int> rank,uparent;

   public:
     DisjointSet(int n){
        rank.resize(n+1,0);
        uparent.resize(n+1);
        for(int i=0;i<=n;++i)
        {
            uparent[i]=i;
        }
     }

     int findPar(int node){
          if(uparent[node]==node)
          return node;
          else
          return uparent[node]=findPar(uparent[node]);
     }

     void UnionbyRank(int u,int v)
     {
        int up_u=findPar(u);
        int up_v=findPar(v);

        if(up_u==up_v)
        return;

        else if(rank[up_u]>rank[up_v])
        {
             uparent[up_v]=up_u;
        }
        else if(rank[up_v]>rank[up_u])
        {
            uparent[up_u]=up_v;
        }

        else{
            uparent[up_v]=up_u;
            rank[up_u]++;
        }

        return;
     }

};

int main(){


    DisjointSet ds(7);

    ds.UnionbyRank(1,2);
    
    ds.UnionbyRank(2,3);
    
    ds.UnionbyRank(4,5);
    
    ds.UnionbyRank(6,7);
    
    ds.UnionbyRank(5,6);
   
   if(ds.findPar(3)==ds.findPar(7))
   cout<<"Same"<<endl;
   else
   cout<<"NOT SAME"<<endl;
    
    ds.UnionbyRank(3,7);

      if(ds.findPar(3)==ds.findPar(7))
   cout<<"SAME"<<endl;
   else
   cout<<"NOT SAME"<<endl;

    return 0;

}
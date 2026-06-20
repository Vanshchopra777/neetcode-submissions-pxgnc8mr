class disjointset{

    public:
    vector<int> parent,size;
    disjointset(int n){
       parent.resize(n);
        size.resize(n,1);

  
          for( int i=0;i<n;i++){
            parent[i]=i;

             }
    }
    int findult_par(int n){
        if(parent[n]==n)return n;

        return parent[n]=findult_par(parent[n]);
    } 

    void unionbysize(int u,int v){
        int ult_u=findult_par(u);
        int ult_v=findult_par(v);

        if(ult_u==ult_v)return ;

        else if(size[ult_u]<size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        else{
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }

    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        disjointset ds(n+1);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            if(ds.findult_par(u)==ds.findult_par(v)) return {u,v};

            ds.unionbysize(u,v);
        }
        return {};
    }
};

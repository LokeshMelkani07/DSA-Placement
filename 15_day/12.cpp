#include<iostream>
#include<unordered_map>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;

// Lecture 97: Kruskal's Algorithm || Disjoint Set || Union by Rank & Path Compression

class DisjointSet{
    vector<int> size,parent, rank;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void RankByUnion(int u,int v){
        int ulti_p_u = findParent(u);
        int ulti_p_v= findParent(v);
        if(ulti_p_u == ulti_p_v )return;
        if(rank[ulti_p_u]<rank[ulti_p_v])
            parent[ulti_p_u] = ulti_p_v;
        else if(rank[ulti_p_u]> rank[ulti_p_v])
            parent[ulti_p_v] = ulti_p_u;
        else{
            parent[ulti_p_v] = ulti_p_u;
            rank[ulti_p_u]++;
        }
    }

    void SizeByUnion(int u,int v){
        int ulti_p_u = findParent(u);
        int ulti_p_v = findParent(v);

        if(ulti_p_u == ulti_p_v) return;
        if(size[ulti_p_u] < size[ulti_p_v]){
            parent[ulti_p_u] = ulti_p_v;
            size[ulti_p_v] += size[ulti_p_u];
        }

        else {
            parent[ulti_p_v] = ulti_p_u;
            size[ulti_p_u] += size[ulti_p_v];
        }

    }
};

int minimumSpanningTree(vector<vector<int>>&adj, int V)
{
        vector<pair<int,pair<int,int>>>edges;
        for(auto it:adj){
          int u = it[0];int v=  it[1];
          int w =it[2];
        edges.push_back({w,{u,v}});
        }
        int mxCnt =0;
    sort(edges.begin(),edges.end());
        DisjointSet st(V);
        for(auto it:edges){
            int w = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if(st.findParent(u)!= st.findParent(v)){ mxCnt+= w;
            st.SizeByUnion(u,v);

            }
        }
        return mxCnt;

}

int main()
{
    return 0;
}
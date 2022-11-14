class Dsu{
    vector<int> parent;
    vector<int> sizes;
    public:
    Dsu(int n){
        parent.resize(n);
        sizes.resize(n,1);
        for(int i=0;i<n;i++) parent[i] = i;
    }
    
    int find_parent(int u){
        if(u==parent[u]) return u;
        return parent[u] = find_parent(parent[u]);
    }
    
    void union_size(int u, int v){
        int parent_u = find_parent(u);
        int parent_v = find_parent(v);
        if(parent_u == parent_v) return;
        
        if(sizes[parent_u]<sizes[parent_v]){
            parent[parent_u] = parent_v;
            sizes[parent_v] += sizes[parent_u];
        } else{
            parent[parent_v] = parent_u;
            sizes[parent_u] += sizes[parent_v];
        }
    }
    
};

class Solution {
public:
    
    int removeStones(vector<vector<int>>& stones) {
        int max_row=0, max_col=0;
        for(auto i: stones){
            max_row = max(max_row, i[0]);
            max_col = max(max_col, i[1]);
        }
        // cout<<max_row<<": "<<max_col<<"\n"
        Dsu ds(max_row + max_col + 2);
        set<int> s;
        for(auto i: stones){
            int node_row = i[0];
            int node_col = i[1] + max_row + 1;
            // cout<<node_row<<" "<<node_col<<"\n";
            ds.union_size(node_row, node_col);
            s.insert(node_row);
            s.insert(node_col);
        }
        int count = 0;
        for(auto i: s){
            if(ds.find_parent(i)==i) count++;
        }
        
        return stones.size() - count;
        return 0;
    }
};
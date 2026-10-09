class Solution {
public:
    bool cyclehai(int src,vector<bool> &vis,vector<bool> &recpath,vector<vector<int>>& edges){
        vis[src] = true;
        recpath[src] = true;

        for(int i =0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            if(u == src ){
                if(!vis[v]){
       if(cyclehai(v, vis, recpath, edges)){
          return true;
         }
        }
       else if(recpath[v]){
        return true;
                }
            }
        }
        recpath[src] = false;
        return false;

    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<bool> recpath(n,false);

        for(int i =0;i<n;i++){
            if(!vis[i]){
                if(cyclehai(i,vis,recpath,edges)){
                   return false;
                }
            }
        }
        return true;
    }
};
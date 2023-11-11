class Graph {
public:
    vector<pair<int,int>>adj[101];
    int size;
    
    Graph(int n, vector<vector<int>>& edges) {
        size=n;
         for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
         } 
    }

    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }

    int shortestPath(int node1, int node2) {
       // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        set<pair<int,int>>st;
        vector<int>dist(size+1,INT_MAX);
        dist[node1]=0;
        //pq.push({0,node1});
        st.insert({0,node1});
        while(!st.empty()){
            auto it = *(st.begin());
            int Nodedist=it.first;
            int node=it.second;
            st.erase(it);
            for(auto it:adj[node]){
                int edwt = it.second;
                int adjNode= it.first;
                if(Nodedist+edwt<dist[adjNode]){
                    if(dist[adjNode]!= INT_MAX)
                        st.erase({dist[adjNode],adjNode});
                    
                    dist[adjNode]=Nodedist+edwt;
                    st.insert({dist[adjNode],adjNode});
                    //pq.push({dist[adjNode],adjNode});
                }
            }
        }
        if(dist[node2]==INT_MAX) return -1;
        return dist[node2];
    }
};
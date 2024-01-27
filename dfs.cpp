void dfs(int vertex)
{
    visit[vertex]=true;
    for(auto child : adj[vertex]){
        if(visit[child]==false){
            dfs(child);
        }
    }
}

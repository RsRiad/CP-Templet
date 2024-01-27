void bfs(int s)
{
    mem(level,-1);
    level[s]=0;
    queue<int >q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v : adj[u])
        {
            if (level[v]==-1)
            {
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
}

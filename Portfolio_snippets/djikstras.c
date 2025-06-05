/**
Function:       djikstras
Description:    Computes the shortest distance from a source vertex to all other vertices using Dijkstra's algorithm
Input param:    int src-    the source vertex
Return Type:    NULL
*/
void djikstras(int src)
{
    for(i=0; i<v; i++)
    {
        visited[i] = 0;
        dist[i] = map[src][i];
        path[i] = src;
    }

    visited[src] = 1;
    for(int loop=0; loop<v; loop++)
    {
        u = min_dist(v);
        distance = dist[u];
        visited[u] = 1;

        for(int x=0; x<v; x++)
        {
            if(!visited[x])
            {
                min = min_between(dist[x],distance+map[u][x]);

                if(min!=dist[x])
                {
                    dist[x] = min;
                    path[x] = u;
                }
            }
        }
    }
    write_slum_log("djikstras",SUCCESS,"Distance between Water Source and houses calculated");
}
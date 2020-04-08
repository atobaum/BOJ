#include <iostream>
#include <vector>
#include <queue>
#define INF 1e8

using namespace std;

int dji(int n, vector<pair<int, int>> *map, int start, int end){
    int dist[n+1];
    fill(dist, dist+n+1, INF);
    
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, start));
    
    while (!q.empty()){
        int here = q.top().second;
        int cost = -q.top().first;
        q.pop();
        if(here == end){
            return cost;
        }
        
        for(int i = 0; i < map[here].size(); ++i){
            int there = map[here][i].first;
            int nextCost = map[here][i].second;
            if(dist[there] > cost + nextCost){
                dist[there] = cost + nextCost;
                q.push(make_pair(-(cost + nextCost), there));    
            }
        }
    }
    return -1;
}

int main() {
    int m, n, start, end;

    cin >> n;
    cin >> m;
    
    vector<pair<int, int>> map[n+1];
    
    int a, b, c;
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
    }
    
    cin >> start >> end;
    cout << dji(n, map, start, end) << endl;
    
    return 0;
}

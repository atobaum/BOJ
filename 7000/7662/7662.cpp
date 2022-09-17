#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
#define mp(a, b) make_pair(a, b)
#define X first
#define Y second

#define FOR(i, a, b) for (int i = a; i < b; i++)

int T;

bool empty(priority_queue<pli> &q, int *used){
    while(!q.empty() && used[q.top().Y]) q.pop();
    return q.empty();
}

ll pop(priority_queue<pli> &q, int *used){
    used[q.top().Y] = 1;
    ll res = q.top().X;
    q.pop();
    return res;
}

void solve(){
    int k, used[1000000]={0,};
    cin>>k;

    priority_queue<pli> q_max, q_min;

    FOR(i, 0, k){
        char op;
        ll t;

        cin>>op>>t;

        if(op == 'I'){
            q_max.push(mp(t, i));
            q_min.push(mp(-t, i));
        } else if(t == 1){
            if(!empty(q_max, used)) pop(q_max, used);
        }else{
            if(!empty(q_min, used)) pop(q_min, used);
        }
    }

    if(empty(q_min, used) || empty(q_max, used)){
        cout<<"EMPTY\n";
    }else{
        cout<<q_max.top().X<<" "<<-q_min.top().X<<"\n";
    }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  cin>>T;
  FOR(i, 0, T) solve();

  return 0;
}


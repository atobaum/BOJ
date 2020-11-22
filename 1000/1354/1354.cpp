#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

ll N, P, Q, X, Y;
map<ll, ll> M;

ll solve(ll i) {
  if (i <= 0)
    return 1;
  if (M.find(i) != M.end())
    return M[i];

  return M[i] = solve(i / P - X) + solve(i / Q - Y);
}

int main() {
  cin >> N >> P >> Q >> X >> Y;

  cout << solve(N) << endl;
  return 0;
}
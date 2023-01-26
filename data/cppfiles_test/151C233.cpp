#include <bits/stdc++.h>
const int N = 5e5 + 5;
const int mod = 1e9 + 7;
const long long int int_max = 1e18;
const long long int int_min = -1e18;
const long double PI = acos(-1);
using namespace std;
void solve() {
  long long int q;
  cin >> q;
  long long int x[q + 2], y[q + 2], type[q + 2];
  memset(y, 0, sizeof(y));
  map<long long int, long long int> par;
  for (long long int i = 1; i <= N; i++) {
    par[i] = i;
  }
  for (long long int i = 1; i <= q; i++) {
    cin >> type[i] >> x[i];
    if (type[i] == 2) cin >> y[i];
  }
  vector<long long int> ans;
  for (long long int i = q; i >= 1; i--) {
    if (type[i] == 1) {
      ans.push_back(par[x[i]]);
    } else {
      par[x[i]] = par[y[i]];
    }
  }
  reverse(ans.begin(), ans.end());
  for (long long int i : ans) cout << i << ' ';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  solve();
}

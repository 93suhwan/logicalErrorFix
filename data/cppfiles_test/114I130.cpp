#include <bits/stdc++.h>
using namespace std;
const long long INFF = 1e18 + 5;
const long long INF = 1e10 + 5;
const long long MX = 1e6 + 5;
const long long MXL = 105;
const long long mod = 1e9 + 7;
const double ERROR = 1e-8;
const long long set_inf = 0x3f3f3f3f;
long long n, m, cur, k;
vector<long long> v[15], ban, its;
pair<long long, vector<long long>> ans;
queue<vector<long long>> q;
set<vector<long long>> st;
void solve() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long u;
    cin >> u;
    its.push_back(u - 1);
    while (u--) {
      long long st;
      cin >> st;
      v[i].push_back(st);
    }
  }
  cin >> m;
  for (long long i = 1; i <= m; i++) {
    vector<long long> vect;
    for (long long j = 0; j < n; j++) {
      long long b;
      cin >> b;
      vect.push_back(b - 1);
    }
    st.insert(vect);
  }
  q.push(its);
  while (!q.empty()) {
    vector<long long> build = q.front();
    q.pop();
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      sum += v[i][build[i]];
    }
    if (sum <= ans.first) continue;
    if (!st.count(build))
      ans = max(ans, {sum, build});
    else {
      for (long long i = 0; i < n; i++) {
        if (its[i] == 0) continue;
        its[i]--;
        if (!st.count(its)) q.push(its);
        its[i]++;
      }
    }
    st.insert(build);
  }
  for (auto i : ans.second) cout << i + 1 << " ";
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
  exit(0);
  ;
}

#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 1e18 + 10;
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first > b.first;
}
void solve() {
  long long n;
  cin >> n;
  vector<vector<long long> > a(n + 1);
  set<long long> rtunderstood;
  vector<long long> b(n + 1);
  long long totu = 0;
  for (long long i = 1; i <= n; i++) {
    long long k;
    cin >> k;
    b[i] = k;
    if (k == 0) rtunderstood.insert(i);
    while (k--) {
      long long ch;
      cin >> ch;
      a[ch].push_back(i);
    }
  }
  if (rtunderstood.empty()) {
    cout << -1 << "\n";
    return;
  }
  long long ans = 0;
  while (!rtunderstood.empty()) {
    auto it = rtunderstood.begin();
    set<long long> nw;
    while (it != rtunderstood.end()) {
      long long cur = *it;
      for (auto x : a[cur]) {
        b[x]--;
        if (b[x] == 0) {
          if (x > cur)
            rtunderstood.insert(x);
          else
            nw.insert(x);
        }
      }
      totu++;
      it++;
    }
    ans++;
    rtunderstood = nw;
  }
  if (totu == n)
    cout << ans << "\n";
  else
    cout << -1 << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(15);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

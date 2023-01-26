#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
vector<bool> prime(MX, true);
void SieveOfEratosthenes() {
  for (int p = 2; p * p <= MX; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= MX; i += p) prime[i] = false;
    }
  }
  prime[1] = false;
}
void solve() {
  int n;
  char a;
  cin >> n >> a;
  string second;
  cin >> second;
  vector<int> v;
  bool flag = 1;
  for (int i = 0; i < n; i++) {
    if (second[i] != a) {
      flag = 0;
      v.push_back(i + 1);
    }
  }
  if (flag) {
    cout << 0 << nl;
    return;
  }
  int ans = 0;
  vector<int> l;
  for (int i = v.size() - 1; i >= 0; i--) {
    if (prime[v[i]]) {
      ans++;
      l.push_back(v[i]);
      if (ans == 2) break;
    }
  }
  if (l.size() == 0) {
    cout << 1 << nl;
    cout << 2 << nl;
    return;
  }
  cout << ans << nl;
  for (int i = 1; i >= 0; i--) cout << l[i] << " ";
  cout << nl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  SieveOfEratosthenes();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

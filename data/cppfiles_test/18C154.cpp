#include <bits/stdc++.h>
using namespace std;
template <typename t>
void Unique(vector<t> &v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
}
template <typename t, typename v>
void mapPrint(map<t, v> const &m) {
  for (auto const &pair : m)
    cout << "{" << pair.first << ": " << pair.second << "}\n";
}
const int mxn = 1e5 + 5;
const int inf = 1 << 31;
const int mod = 1e9 + 7;
bool prime[mxn];
int gcd(int a, int b) {
  if (b > a) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
void SieveOfEratosthenes(int n) {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int> > pairs(n);
  vector<int> vis(2 * n, 0);
  vector<int> unvis;
  for (int i = 0; i < k; i++) {
    cin >> pairs[i].first >> pairs[i].second;
    pairs[i].first -= 1;
    pairs[i].second -= 1;
    vis[pairs[i].first] = vis[pairs[i].second] = 1;
  }
  for (int i = 0; i < 2 * n; i++)
    if (!vis[i]) unvis.push_back(i);
  int sz = unvis.size();
  int ans = 0;
  for (int i = 0; i < sz / 2; i++)
    pairs[i + k] = make_pair(unvis[i], unvis[i + sz / 2]);
  for (int i = 0; i < n; i++)
    if (pairs[i].first < pairs[i].second) swap(pairs[i].first, pairs[i].second);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      int inter = 0;
      if (pairs[i].second < pairs[j].second and
          pairs[j].second < pairs[i].first and pairs[i].first < pairs[j].first)
        inter = 1;
      swap(i, j);
      if (pairs[i].second < pairs[j].second and
          pairs[j].second < pairs[i].first and pairs[i].first < pairs[j].first)
        inter = 1;
      swap(i, j);
      ans += inter;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector<long long int> input(long long int n) {
  vector<long long int> v(n);
  for (auto &a : v) cin >> a;
  return v;
}
bool comp(pair<long long int, long long int> a,
          pair<long long int, long long int> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}
bool comp2(long long int a, long long int b) { return a < b; }
long long int karo(vector<string> &cc, char c, long long int n) {
  long long int i;
  vector<pair<long long int, long long int> > v(n);
  for (i = 0; i < n; i++) {
    long long int count = 0;
    for (auto tit : cc[i]) {
      if (tit == c) count++;
    }
    v[i].first = count;
    v[i].second = cc[i].size() - count;
  }
  sort(v.begin(), v.end(), comp);
  vector<long long int> kit(n);
  for (i = 0; i < n; i++) {
    kit[i] = v[i].first - v[i].second;
  }
  long long int count = 0;
  sort(kit.begin(), kit.end(), greater<long long int>());
  long long int sum = 0;
  for (i = 1; i < n; i++) {
    kit[i] += kit[i - 1];
  }
  for (i = 0; i < n; i++) {
    if (kit[i] <= 0) break;
  }
  return i;
}
void solve() {
  long long int n, i, j, k, l, r, m;
  cin >> n;
  vector<string> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long int ans = -1;
  for (i = 0; i < 5; i++) {
    long long int temp = karo(v, 'a' + i, n);
    ans = max(ans, temp);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int i, j, k, n, m;
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

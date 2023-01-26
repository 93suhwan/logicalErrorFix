#include <bits/stdc++.h>
using namespace std;
bool com(pair<int, int> x, pair<int, int> y) {
  if (x.first == y.first) return x.second < y.second;
  return x.first < y.first;
}
long long int power(long long int x, long long int y) {
  long long int prod = 1;
  while (y) {
    if (y & 1) prod = (prod * x) % 1000000007;
    x = (x * x) % 1000000007;
    y /= 2;
  }
  return prod;
}
const int N = 2e5 + 7;
int tc = 1;
void solve() {
  int n;
  cin >> n;
  int a[n];
  vector<pair<int, pair<int, int>>> ans;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    int mxind = i;
    for (int j = i; j >= 0; j--) {
      if (a[j] > a[mxind]) {
        mxind = j;
      }
    }
    if (mxind == i) continue;
    ans.push_back({mxind + 1, {i + 1, 1}});
    for (int j = mxind; j < i; j++) {
      swap(a[j], a[j + 1]);
    }
  }
  cout << ans.size() << "\n";
  for (auto v : ans)
    cout << v.first << " " << v.second.first << " " << v.second.second << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

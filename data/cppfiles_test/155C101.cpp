#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
const int MOD = 1000000007;
const int MX = INT_MAX;
const int MN = INT_MIN;
void init() {}
void fastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
void solve() {
  int n;
  cin >> n;
  string s;
  vector<pair<long long, long long> > arr(n);
  for (int i = 0; i < (n); i++) {
    int x;
    cin >> x;
    arr[i].first = x;
    arr[i].second = i;
  }
  cin >> s;
  sort(arr.begin(), arr.end());
  long long b = n;
  for (int i = n - 1; i >= 0; i--) {
    if (s[arr[i].second] != '0') {
      arr[i].first = b;
      b -= 1;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[arr[i].second] != '1') {
      arr[i].first = b;
      b -= 1;
    }
  }
  sort(arr.begin(), arr.end(), sortbysec);
  for (int i = 0; i < (n); i++) cout << arr[i].first << " ";
  cout << endl;
}
int main() {
  fastIO();
  init();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

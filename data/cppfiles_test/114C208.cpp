#include <bits/stdc++.h>
using namespace std;
int num(int n) {
  int res = 0;
  while (n > 0) {
    n = n / 10;
    res++;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  long long v[n];
  vector<bool> k(1e6 + 1, 0);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    k[v[i]] = 1;
  }
  sort(v, v + n);
  vector<pair<long long, long long>> pairs;
  for (long long i = 1; i < n; i++) {
    for (long long j = 0; j < i; j++) {
      if (k[v[i] % v[j]] == 0) {
        pairs.push_back({v[i], v[j]});
      }
      if (pairs.size() >= (n / 2)) {
        break;
      }
    }
    if (pairs.size() >= n / 2) {
      break;
    }
  }
  for (long long i = 0; i < pairs.size(); i++) {
    cout << pairs[i].first << " " << pairs[i].second << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}

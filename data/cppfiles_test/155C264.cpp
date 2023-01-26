#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long M = 1e18;
long long qpow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tt = 1;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    int n;
    cin >> n;
    int p[n + 1];
    vector<pair<int, int> > v, v1;
    int q[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
    }
    string second;
    cin >> second;
    int ct = 0;
    for (int i = 0; i < n; i++)
      if (second[i] == '1') ct++;
    for (int i = 0; i < n; i++) {
      if (second[i] == '1') {
        v.push_back({p[i + 1], i + 1});
      } else
        v1.push_back({p[i + 1], i + 1});
    }
    sort(v.begin(), v.end());
    sort(v1.begin(), v1.end());
    int cur = n;
    for (int i = ct - 1; i >= 0; i--) {
      q[v[i].second] = cur--;
    }
    cur = n - ct;
    for (int i = (n - ct) - 1; i >= 0; i--) {
      q[v1[i].second] = cur--;
    }
    for (int i = 1; i <= n; i++) cout << q[i] << " ";
    cout << "\n";
  }
  return 0;
}

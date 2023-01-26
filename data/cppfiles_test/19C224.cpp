#include <bits/stdc++.h>
using namespace std;
const int MN = 100005;
const int MX = 500005;
const int INF = 1000000007;
const int MOD = 998244353;
int a[20];
int n;
bool solve() {
  for (int i = 0; i < n; i++)
    if (a[i] == 0) return 1;
  for (int st = 1; st < (1 << n); st++) {
    int sum;
    vector<int> V;
    for (int i = 0; i < n; i++)
      if (st & (1 << i)) V.push_back(a[i]);
    int sz = V.size();
    for (int st1 = 0; st1 < (1 << sz); st1++) {
      sum = 0;
      for (int i = 0; i < sz; i++) {
        if (st1 & (1 << i))
          sum += V[i];
        else
          sum -= V[i];
      }
      for (int i = 0; i < n; i++)
        if (!(st & (1 << i))) {
          if (sum == a[i]) return 1;
        }
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int Tc;
  for (cin >> Tc; Tc--;) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (solve())
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}

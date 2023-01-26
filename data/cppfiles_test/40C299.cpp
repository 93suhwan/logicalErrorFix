#include <bits/stdc++.h>
using namespace std;
void solve() {
  int m;
  cin >> m;
  int a1[m + 1], b1[m + 1];
  int a[m + 1], b[m + 1];
  vector<int> dp(m + 1);
  a1[0] = 0, b1[0] = 0;
  for (int i = 1; i < m + 1; i += 1) {
    cin >> a1[i];
  }
  for (int i = 1; i < m + 1; i += 1) {
    cin >> b1[i];
  }
  int last = b1[m];
  partial_sum(a1, a1 + m + 1, a);
  partial_sum(b1, b1 + m + 1, b);
  vector<int> v;
  for (int i = 1; i < m + 1; i += 1) {
    int sum1 = 0, sum2 = 0;
    sum1 += (a[m] - a[i]);
    sum2 += (b[i - 1]);
    v.push_back(max(sum1, sum2));
  }
  sort(v.begin(), v.end());
  cout << v[0] << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

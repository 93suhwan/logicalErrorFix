#include <bits/stdc++.h>
using namespace std;
char c[200009];
long long T;
long long n;
long long a[200009];
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> c + 1;
  vector<long long> v[2];
  for (long long i = 1; i <= n; i++) {
    if (c[i] == 'R') {
      v[0].push_back(a[i]);
    }
    if (c[i] == 'B') {
      v[1].push_back(a[i]);
    }
  }
  sort(v[1].begin(), v[1].end());
  sort(v[0].begin(), v[0].end(), greater<long long>());
  long long ok = 0;
  for (long long i = 0; i < v[1].size(); i++) {
    if (v[1][i] < i + 1) ok = 1;
  }
  for (long long i = 0; i < v[0].size(); i++) {
    if (v[0][i] > (n - i)) ok = 1;
  }
  if (ok == 1)
    printf("NO\n");
  else
    printf("YES\n");
}
signed main() {
  cin >> T;
  while (T--) solve();
}

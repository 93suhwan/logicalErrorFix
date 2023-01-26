#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int p[maxn][10];
int q[10];
int n;
void solve() {
  cin >> n;
  for (int i = 1; i <= 5; i++) q[i] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 5; j++) cin >> p[i][j], q[j] += p[i][j];
  int num = 0;
  for (int i = 1; i <= 5; i++)
    if (q[i] >= n / 2) num++;
  if (num < 2) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  return;
}
int main() {
  int __;
  cin >> __;
  while (__--) solve();
}

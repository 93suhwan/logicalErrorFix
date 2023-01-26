#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 1;
long long n, tmp;
bool flag;
void solve() {
  flag = true;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    if (flag && tmp % (i + 2) == 0) flag = false;
  }
  if (flag)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

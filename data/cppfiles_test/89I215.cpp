#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 1;
long long n, tmp;
long long flag, pos;
void solve() {
  flag = 1;
  cin >> n;
  pos = 1;
  for (long long int i = 0; i < n; i++) {
    cin >> tmp;
    if (flag == 1 && tmp % (i + 2) == 0) {
      for (long long j = i + 1; j > pos; j--)
        if (tmp % j != 0) {
          pos = j;
          flag = 2;
          break;
        }
      if (flag == 1) {
        flag = 0;
      }
    }
  }
  if (flag > 0)
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

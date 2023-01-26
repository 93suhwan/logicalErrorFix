#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 1;
int n, arr[N];
bool flag;
void solve() {
  cin >> n;
  for (long long int i = 0; i < n; i++) cin >> arr[i];
  for (long long int i = 0; i < n; i++) {
    flag = false;
    for (int j = 2; j <= i + 2; j++)
      if (arr[i] % j != 0) {
        flag = true;
        break;
      }
    if (!flag) return (void)(cout << "NO\n");
  }
  cout << "YES\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

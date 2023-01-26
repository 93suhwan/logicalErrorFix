#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long dx8[] = {1, 1, 0, -1, -1, -1, 0, 1};
long long dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long dx4[] = {1, 0, -1, 0};
long long dy4[] = {0, 1, 0, -1};
void solve() {
  long long n;
  cin >> n;
  if (n % 3 == 0) {
    cout << n / 3 << " " << n / 3 << "\n";
    ;
    return;
  }
  if (n % 3 == 1) {
    cout << n / 3 + 1 << " " << n / 3 << "\n";
    ;
  } else {
    cout << n / 3 << " " << n / 3 + 1 << "\n";
    ;
    ;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

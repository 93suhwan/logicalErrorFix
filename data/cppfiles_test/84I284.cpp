#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, +1, 0};
int dy[] = {0, +1, 0, -1};
const int mod = 1e9 + 7;
const int X = 1e7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    if (n > s) {
      cout << 0 << '\n';
      continue;
    }
    if (n == 1) {
      cout << s << '\n';
      continue;
    }
    if (n == s) {
      cout << 1 << '\n';
      continue;
    }
    int mid = n / 2;
    int ache = mid + 1;
    int ans = s / ache;
    cout << ans << '\n';
  }
}

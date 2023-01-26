#include <bits/stdc++.h>
using namespace std;
void mian() {
  long long s, n, k;
  cin >> s >> n >> k;
  if (k > s) {
    cout << "NO\n";
    return;
  }
  long long r = s / (2 * k), c = r * k;
  c += min(k - 1, s - r * 2 * k);
  cout << (c >= n ? "NO\n" : "YES\n");
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) mian();
  return 0;
}

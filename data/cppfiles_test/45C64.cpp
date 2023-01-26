#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const int MAXN = 1e5 + 10;
bool inp[MAXN];
void solve() {
  int n;
  cin >> n;
  int c0 = 0, c1 = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x % 2 == 0)
      c0++;
    else
      c1++;
    inp[i] = x % 2;
  }
  if (abs(c0 - c1) > 1) {
    cout << "-1\n";
    return;
  }
  bool want = false;
  if (c1 > c0) want = true;
  int cnt = 0, can = 0;
  for (int i = 0; i < n; ++i) {
    if (inp[i] == want) {
      cnt += abs(i - can);
      can += 2;
    }
  }
  int ans = cnt;
  if (n % 2 == 0) {
    cnt = 0, can = 1;
    for (int i = 0; i < n; ++i) {
      if (inp[i] == want) {
        cnt += abs(i - can);
        can += 2;
      }
    }
  }
  cout << min(ans, cnt) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

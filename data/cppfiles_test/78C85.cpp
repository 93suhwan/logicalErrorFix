#include <bits/stdc++.h>
using namespace std;
using Vi = vector<int>;
using i64 = long long;
using ll = long long;
using Pi = pair<int, int>;
mt19937 mrand(time(0));
int rnd(int x) { return mrand() % x; }
const int N = 500005;
const int M = 40005;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    Vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int TOP = 30;
    Vi bit(TOP);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < TOP; ++j)
        if (a[i] >> j & 1) ++bit[j];
    Vi ans(n + 1);
    for (int i = 0; i < TOP; ++i)
      for (int j = 1; j < n + 1; ++j)
        if (bit[i] % j == 0) ++ans[j];
    for (int i = 1; i < n + 1; ++i)
      if (ans[i] == TOP) cout << i << " ";
    cout << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long N = 300005, M = 1005;
long long t, n, k;
string s;
vector<long long> v[2];
void fun(long long val, long long f1, long long f2) {
  if (val > 1000000000) {
    return;
  }
  v[1].push_back(val);
  fun(val * 10 + f1, f1, f2);
  fun(val * 10 + f2, f1, f2);
}
void fun2(long long val, long long f1) {
  if (val > 1000000000) {
    return;
  }
  v[0].push_back(val);
  fun2(val * 10 + f1, f1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  for (int i = 0; i <= 9; i++) {
    if (i > 0) fun2(i, i);
  }
  sort(v[0].begin(), v[0].end());
  v[1] = v[0];
  for (int i = 0; i <= 9; i++) {
    for (int j = i + 1; j <= 9; j++) {
      if (i > 0) fun(i, i, j);
      fun(j, i, j);
    }
  }
  sort(v[1].begin(), v[1].end());
  while (t--) {
    cin >> n >> k;
    long long high = (long long)v[k - 1].size() - 1, low = 0, mid, ans = 0;
    while (high >= low) {
      mid = (high + low) / 2;
      if (n <= v[k - 1][mid]) {
        ans = v[k - 1][mid];
        high = mid - 1;
      } else
        low = mid + 1;
    }
    cout << ans << "\n";
  }
  return 0;
}

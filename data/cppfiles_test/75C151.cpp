#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int M = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
long long n, pre[M];
pair<long long, long long> d[M];
bool cmp(pair<long long, long long> x, pair<long long, long long> y) {
  return x.second < y.second;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> d[i].first;
      d[i].second = -1e10;
      for (int j = 1; j <= d[i].first; j++) {
        long long x;
        cin >> x;
        if (d[i].second < x - (j - 1)) d[i].second = x - (j - 1);
      }
    }
    sort(d + 1, d + n + 1, cmp);
    long long ans = 0;
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + d[i].first;
      d[i].second++;
      d[i].second -= pre[i - 1];
      ans = max(ans, d[i].second);
    }
    cout << ans << endl;
  }
  return 0;
}

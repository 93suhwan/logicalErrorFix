#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
string b[80];
int dp[80][80];
string a;
signed main(signed argc, char const *argv[]) {
  clock_t c1 = clock();
  b[0] = "1";
  long long base = 2;
  for (long long i = 1; i <= 60; i++) {
    long long ans = base;
    base = base * 2LL;
    vector<int> v;
    int x = i;
    while (ans) {
      v.push_back(ans % 10);
      ans /= 10LL;
    }
    reverse(v.begin(), v.end());
    string t = "";
    for (int j = 0; j < v.size(); j++) {
      t += (char)(v[j] + '0');
    }
    b[i] = t;
  }
  int T;
  cin >> T;
  while (T--) {
    cin >> a;
    int n = a.length();
    int ans = 0x3f3f3f3f;
    for (int k = 0; k <= 60; k++) {
      int m = b[k].length();
      int MIN = 0x3f3f3f3f;
      int cnt = 0;
      if (a == b[k]) {
        ans = 0;
        break;
      }
      for (int i = 0; i < n; i++) {
        if (a[i] == b[k][cnt]) {
          cnt++;
        } else {
          int x = m - cnt;
          MIN = min(n - cnt + x, MIN);
        }
      }
      int x = m - cnt;
      MIN = min(MIN, n - cnt + x);
      ans = min(MIN, ans);
    }
    cout << ans << endl;
  }
end:
  cerr << "Time used:" << clock() - c1 << "ms" << endl;
  return 0;
}

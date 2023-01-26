#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
char b[80][80];
int Len[80];
int dp[80][80];
char a[N];
signed main(signed argc, char const *argv[]) {
  clock_t c1 = clock();
  b[0][0] = '0';
  Len[0] = 1;
  for (int i = 1; i <= 60; i++) {
    long long ans = 1LL << i;
    vector<int> v;
    int x = i;
    while (ans) {
      v.push_back(ans % 10);
      ans /= 10;
    }
    reverse(v.begin(), v.end());
    for (int j = 0; j < v.size(); j++) {
      b[i][j] = (char)(v[j] + '0');
    }
    Len[i] = (int)v.size();
  }
  int T;
  cin >> T;
  while (T--) {
    memset(a, 0, sizeof a);
    scanf("%s", a);
    int n = strlen(a);
    int ans = 0x3f3f3f3f;
    for (int k = 0; k <= 60; k++) {
      int m = Len[k];
      int MIN = 0x3f3f3f3f;
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] == b[k][cnt]) {
          cnt++;
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

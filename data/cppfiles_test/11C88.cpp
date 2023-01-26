#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int maxn = 2e5 + 10;
const int N = 1e5 + 100;
int n, k, x, t;
string s;
int cnt[maxn][10];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
      cin >> s;
      int l = s.length();
      for (int j = 0; j < l; j++) {
        cnt[i][s[j] - 'a' + 1]++;
        cnt[i][0]++;
      }
    }
    int res = 0;
    for (int i = 1; i <= 5; i++) {
      priority_queue<int> Q;
      int sum = 0;
      for (int j = 1; j <= n; j++) {
        Q.push(2 * cnt[j][i] - cnt[j][0]);
      }
      int rr = 0;
      do {
        sum += Q.top();
        Q.pop();
        rr++;
      } while (sum > 0 && !Q.empty());
      if (sum <= 0) rr--;
      res = max(res, rr);
    }
    cout << res << endl;
  }
  return 0;
}

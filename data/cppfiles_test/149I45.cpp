#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
const int64_t N = 1e6 + 10;
int MOD = 998244353;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int64_t n, k;
    int64_t x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    vector<int64_t> a;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
      if (s[i] == s[i - 1])
        cnt++;
      else {
        a.push_back(cnt);
        cnt = 1;
      }
    }
    a.push_back(cnt);
    vector<int64_t> pos(n, 0), ct(n, 0);
    int64_t cur = 1;
    int st = 0;
    if (s[0] == 'a') st = 1;
    int m = a.size();
    for (int i = m - (st == (m % 2)) - 1; i >= 0; i -= 2) {
      for (int u = 0; u <= k * a[i]; u++) {
        pos[i] += cur;
        if (pos[i] >= x) {
          x -= (pos[i] - cur);
          ct[i] = u;
          for (int j = i + 2; j < m; j += 2) {
            int64_t step = pos[j] / (k * a[j] + 1);
            for (int h = 0; h <= k * a[j]; h++) {
              if (step * (h + 1) >= x) {
                ct[j] = h;
                x -= (step * h);
                break;
              }
            }
          }
          break;
        }
      }
      cur *= (k * a[i] + 1);
    }
    string arr = "";
    for (int i = 0; i < m; i++) {
      if ((i % 2) == st) {
        for (int j = 0; j < ct[i]; j++) arr += 'b';
      } else {
        for (int j = 0; j < a[i]; j++) arr += 'a';
      }
    }
    cout << arr << '\n';
  }
}

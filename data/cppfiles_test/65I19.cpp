#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
int v[N];
int ans[N];
long long sum[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  sort(v + 1, v + n + 1);
  string s;
  cin >> s;
  s = " " + s;
  int j = n;
  for (int i = n; i >= 1; i--) {
    if (s[i] != s[i - 1]) {
      if (s[i] == 'L')
        ans[i] = v[j--];
      else
        ans[i] = -v[j--];
    }
  }
  long long sc = 0;
  int auxi = 1;
  for (int i = 1; i <= n; i++) {
    if (ans[i] != 0) {
      sc += 1LL * ans[i];
      continue;
    }
    if (s[i] == 'L') {
      if (sc - v[auxi] <= 0) {
        ans[i] = v[auxi];
        sc += 1LL * v[auxi];
        auxi++;
      } else {
        ans[i] = -v[auxi];
        sc -= 1LL * v[auxi];
        auxi++;
      }
    } else if (s[i] == 'R') {
      if (sc + v[auxi] >= 0) {
        ans[i] = -v[auxi];
        sc -= 1LL * v[auxi];
        auxi++;
      } else {
        ans[i] = v[auxi];
        sc += 1LL * v[auxi];
        auxi++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i] > 0) {
      cout << ans[i] << " L\n";
    } else {
      cout << -ans[i] << " R\n";
    }
  }
  return 0;
}

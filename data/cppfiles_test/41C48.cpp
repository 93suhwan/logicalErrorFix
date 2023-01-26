#include <bits/stdc++.h>
using namespace std;
vector<long long> *adj;
bool *visited;
void solve() {
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  long long data[6][n];
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (i % 3 == 0 && s[i] == 'a') {
      cnt++;
    }
    if (i % 3 == 1 && s[i] == 'b') {
      cnt++;
    }
    if (i % 3 == 2 && s[i] == 'c') {
      cnt++;
    }
    data[0][i] = cnt;
  }
  cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (i % 3 == 0 && s[i] == 'a') {
      cnt++;
    }
    if (i % 3 == 1 && s[i] == 'c') {
      cnt++;
    }
    if (i % 3 == 2 && s[i] == 'b') {
      cnt++;
    }
    data[1][i] = cnt;
  }
  cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (i % 3 == 0 && s[i] == 'b') {
      cnt++;
    }
    if (i % 3 == 1 && s[i] == 'a') {
      cnt++;
    }
    if (i % 3 == 2 && s[i] == 'c') {
      cnt++;
    }
    data[2][i] = cnt;
  }
  cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (i % 3 == 0 && s[i] == 'b') {
      cnt++;
    }
    if (i % 3 == 1 && s[i] == 'c') {
      cnt++;
    }
    if (i % 3 == 2 && s[i] == 'a') {
      cnt++;
    }
    data[3][i] = cnt;
  }
  cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (i % 3 == 0 && s[i] == 'c') {
      cnt++;
    }
    if (i % 3 == 1 && s[i] == 'b') {
      cnt++;
    }
    if (i % 3 == 2 && s[i] == 'a') {
      cnt++;
    }
    data[4][i] = cnt;
  }
  cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (i % 3 == 0 && s[i] == 'c') {
      cnt++;
    }
    if (i % 3 == 1 && s[i] == 'a') {
      cnt++;
    }
    if (i % 3 == 2 && s[i] == 'b') {
      cnt++;
    }
    data[5][i] = cnt;
  }
  for (long long i = 0; i < m; i++) {
    long long ans = n;
    long long l, r;
    cin >> l >> r;
    for (int i = 0; i < 6; i++) {
      if (l != 1)
        ans = min(ans, r - l + 1 - (data[i][r - 1] - data[i][l - 2]));
      else
        ans = min(ans, r - l + 1 - (data[i][r - 1]));
    }
    cout << ans << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

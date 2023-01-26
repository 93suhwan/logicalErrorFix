#include <bits/stdc++.h>
using namespace std;
int arr[1001];
string p2[50];
string cv(unsigned long long i) {
  string res = "";
  while (i != 0) {
    res += (char)(i % 10 + '0');
    i /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}
string cur;
int vis[55][55];
int memo[55][55];
int id = 1;
int ps2;
int dp(int i, int j) {
  if (i == cur.size() || j == p2[ps2].size()) return 0;
  if (vis[i][j] == id) return memo[i][j];
  vis[i][j] = id;
  memo[i][j] = dp(i + 1, j);
  if (cur[i] == p2[ps2][j]) {
    memo[i][j] = max(memo[i][j], dp(i + 1, j + 1) + 1);
  }
  return memo[i][j];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  unsigned long long p = 1;
  p2[0] = "1";
  for (int i = 1; i < 64; i++) {
    p += p;
    p2[i] = cv(p);
    cout << p2[i] << endl;
  }
  long long N;
  while (T--) {
    cin >> N;
    cur = cv(N);
    int ans = 1e9;
    for (int i = 0; i < 64; i++) {
      id++;
      ps2 = i;
      int pq = dp(0, 0);
      ans = min(ans, int(cur.size() - pq + p2[i].size() - pq));
    }
    cout << ans << "\n";
  }
}

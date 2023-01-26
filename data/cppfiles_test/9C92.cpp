#include <bits/stdc++.h>
using namespace std;
long long solve();
vector<long long> a;
string s;
long long n;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
long long in(vector<long long> &a, long long n) {
  long long i = 0, x, sum = 0;
  for (i = 0; i < n; i++) {
    cin >> x;
    a.push_back({x});
  }
  return sum;
}
long long cnt[1001][1001];
long long mat[1001][1001];
long long m;
long long find(long long row, long long curcolumn) {
  if (row == n + 1) return curcolumn;
  long long ans;
  if (mat[row][curcolumn] == 1) {
    mat[row][curcolumn] = 2;
    ans = find(row, curcolumn + 1);
    if (row < n)
      cnt[row][curcolumn] = 1 + cnt[row + 1][curcolumn];
    else
      cnt[row][curcolumn] = 1;
    return ans;
  }
  if (mat[row][curcolumn] == 3) {
    mat[row][curcolumn] = 2;
    ans = find(row, curcolumn - 1);
    if (row < n)
      cnt[row][curcolumn] = 1 + cnt[row + 1][curcolumn];
    else
      cnt[row][curcolumn] = 1;
    return ans;
  }
  if (cnt[row][curcolumn]) {
    ans = find(row + cnt[row][curcolumn], curcolumn);
  } else
    ans = find(row + 1, curcolumn);
  if (row < n)
    cnt[row][curcolumn] = 1 + cnt[row + 1][curcolumn];
  else
    cnt[row][curcolumn] = 1;
  return ans;
}
long long solve() {
  a.clear();
  s.clear();
  long long i = 0, j = 0, k = 0;
  long long flag = 0;
  long long x = 0, y = 0, z = 0;
  cin >> n;
  cin >> m >> k;
  memset(cnt, 0, sizeof(cnt));
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> mat[i][j];
    }
  }
  long long col;
  for (i = 0; i < k; i++) {
    cin >> col;
    cout << find(1, col) << "\n";
  }
  return 0;
}

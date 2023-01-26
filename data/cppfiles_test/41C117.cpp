#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, l, r, curr = 0;
  string s;
  cin >> n >> m;
  cin >> s;
  vector<vector<long long> > pre(6, vector<long long>(n + 1));
  string t = "abc";
  do {
    for (long long i = 0; i < n; i++)
      pre[curr][i + 1] = pre[curr][i] + (s.at(i) != t.at(i % 3));
    curr++;
  } while (next_permutation(t.begin(), t.end()));
  for (long long i = 0; i < m; i++) {
    cin >> l >> r;
    long long ans = n;
    for (long long i = 0; i < 6; i++) ans = min(ans, pre[i][r] - pre[i][l - 1]);
    cout << ans << endl;
  }
}

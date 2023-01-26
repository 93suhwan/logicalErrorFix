#include <bits/stdc++.h>
using namespace std;
const int MAX_ARRAY = 2 * 1e5 + 1;
int differences[6][MAX_ARRAY];
int differencesPrefixes[6][MAX_ARRAY];
int main() {
  string t[6];
  string combinations[] = {"abc", "acb", "bac", "bca", "cab", "cba"};
  for (int i = 0; i < MAX_ARRAY; i++) {
    for (int j = 0; j < 6; j++) {
      t[j] += combinations[j][(i + 1) % 3];
    }
  }
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) {
      differences[j][i] = s[i] != t[j][i];
    }
  }
  for (int j = 0; j < 6; j++) {
    differencesPrefixes[j][0] = differences[j][0];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 6; j++) {
      differencesPrefixes[j][i] =
          differencesPrefixes[j][i - 1] + differences[j][i];
    }
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    int ans = 1e9;
    for (int j = 0; j < 6; j++) {
      int differencesPrefixesStart =
          (l == 0) ? 0 : differencesPrefixes[j][l - 1];
      ans = min(ans, differencesPrefixes[j][r] - differencesPrefixesStart);
    }
    cout << ans << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a, b, d, c, f, e, ek, n, m, k, s, bj, c1, c2, c3, max1, min1;
int main() {
  scanf("%d", &k);
  while (k--) {
    string str1, str2;
    vector<string> vec1[510], vec2[510];
    bj = 0;
    cin >> str1 >> str2;
    n = str1.size();
    for (a = 0; a < n; ++a) {
      for (b = 1; b <= n - a; ++b) {
        vec1[a].push_back(str1.substr(a, b));
      }
    }
    reverse(str1.begin(), str1.end());
    for (a = 0; a < n; ++a) {
      vec2[abs(n - a - 1)].push_back("");
      for (b = 1; b <= n - a; ++b) {
        vec2[abs(n - a - 1)].push_back(str1.substr(a, b));
      }
    }
    for (a = 0; a < n; ++a) {
      for (b = 0; b < vec1[a].size(); ++b) {
        c = vec1[a][b].size() - 1;
        if (a + c - 1 < 0) continue;
        for (d = 0; d < vec2[a + c - 1].size(); ++d) {
          if (vec1[a][b] + vec2[a + c - 1][d] == str2) {
            bj = 1;
            break;
          }
        }
        if (bj) break;
      }
      if (bj) break;
    }
    if (bj)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

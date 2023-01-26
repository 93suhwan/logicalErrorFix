#include <bits/stdc++.h>
using namespace std;
int main() {
  int _t;
  cin >> _t;
  for (int _ = 0; _ < (_t); _++) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> ans;
    int a, b, c, d;
    a = (n + m - 1) / m;
    b = n / m;
    for (int i = 0; i < (1000000); i++) {
      long long X = a * i;
      if ((n - X) % b == 0) {
        c = i;
        d = (n - X) / b;
        break;
      }
    }
    int last = 0;
    for (int i = 0; i < (k); i++) {
      int cur = last;
      for (int j = 0; j < (c); j++) {
        vector<int> t;
        for (int l = 0; l < (a); l++) {
          t.push_back(cur);
          cur++;
          cur %= n;
        }
        ans.push_back(t);
      }
      last = cur;
      for (int j = 0; j < (d); j++) {
        vector<int> t;
        for (int l = 0; l < (b); l++) {
          t.push_back(cur);
          cur++;
          cur %= n;
        }
        ans.push_back(t);
      }
    }
    for (int i = 0; i < (ans.size()); i++) {
      printf("%d", ans[i].size());
      for (int j = 0; j < (ans[i].size()); j++) {
        printf(" %d", ans[i][j] + 1);
      }
      printf("\n");
    }
  }
  return 0;
}

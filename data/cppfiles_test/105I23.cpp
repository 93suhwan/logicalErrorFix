#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> eat(n), M(n), A(n), B(n);
    int val = 0;
    map<int, vector<int>> grp;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d%d", &A[i], &B[i], &M[i]);
      grp[A[i] + B[i] - M[i]].push_back(i);
    }
    for (auto& g : grp) {
      vector<array<int, 3>> ranges;
      for (int i : g.second) {
        int lb = max(M[i] - B[i], 0);
        int ub = min(A[i], M[i]);
        assert(lb <= ub);
        int l = A[i] - ub, r = A[i] - lb;
        ranges.push_back({r, l, i});
      }
      sort(ranges.begin(), ranges.end());
      int las = -1;
      for (auto& r : ranges) {
        if (las >= r[1]) {
          eat[r[2]] = A[r[2]] - las;
          continue;
        }
        ++val;
        las = r[0];
      }
    }
    printf("%d\n", val);
    for (int i = 0; i < n; ++i) {
      printf("%d %d\n", eat[i], M[i] - eat[i]);
    }
  }
}

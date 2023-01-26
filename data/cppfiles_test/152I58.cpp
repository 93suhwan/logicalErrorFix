#include <bits/stdc++.h>
using namespace std;
template <typename T>
class vec : public vector<T> {
 public:
  int delta;
  vec(int n) : vector<T>(2 * n + 1), delta(n) {}
  vec(int n, T x) : vector<T>(2 * n + 1, x), delta(n) {}
  T &operator[](int i) { return vector<T>::operator[](i + delta); }
};
void solve(int test_ind) {
  int n;
  scanf("%d", &n);
  vector<int> a(n), p(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  const int MAX = 1000000000;
  const int MIN = -MAX;
  vector<vector<int> > dp(n, vector<int>(4, MAX));
  vector<vector<int> > prev(n, vector<int>(4, -1));
  dp[0][0] = MIN;
  dp[0][2] = MIN;
  for (int i = 1; i < n; ++i) {
    for (int ind2 = 0; ind2 < 4; ++ind2) {
      int cur = a[i];
      bool first = true;
      if (ind2 < 2) cur = -a[i];
      if (ind2 & 1) first = false;
      int ind = -1;
      for (int ind1 = 0; ind1 < 4; ++ind1) {
        int prvmx, prvsec;
        if (ind1 == 0) {
          prvmx = -a[i - 1];
          prvsec = dp[i - 1][0];
        } else if (ind1 == 1) {
          prvmx = dp[i - 1][1];
          prvsec = -a[i - 1];
        } else if (ind1 == 2) {
          prvmx = a[i - 1];
          prvsec = dp[i - 1][2];
        } else {
          prvmx = dp[i - 1][3];
          prvsec = a[i - 1];
        }
        if (first) {
          if (prvmx < cur) {
            if (prvsec < dp[i][ind2]) {
              dp[i][ind2] = prvsec;
              ind = ind1;
            }
          }
        } else {
          if (prvmx > cur && prvsec < cur) {
            if (dp[i][ind2] > prvmx) {
              dp[i][ind2] = prvmx;
              ind = ind1;
            }
          }
        }
      }
      if (ind != -1) prev[i][ind2] = ind;
    }
  }
  int ind1 = -1;
  for (int ind = 0; ind < 4; ++ind) {
    if (prev[n - 1][ind] != -1) {
      ind1 = ind;
      break;
    }
  }
  if (ind1 == -1) {
    printf("NO\n");
    return;
  }
  for (int i = n - 1; i >= 0; --i) {
    p[i] = ind1 < 2 ? -a[i] : a[i];
    ind1 = prev[i][ind1];
  }
  printf("YES\n");
  for (int i = 0; i < n; ++i) {
    printf("%d ", p[i]);
  }
  printf("\n");
}
int main() {
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve(i);
  }
  return 0;
}

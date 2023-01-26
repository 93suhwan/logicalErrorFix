#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int MAXN = 1e5;
int solve(int ones, int twos, vector<int>& v, int n) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] % 3 == 0) {
      int cand = v[i] / 3;
      if (ones and twos) {
        cand--;
      }
      ans = max(ans, cand);
    } else if (v[i] % 3 == 1) {
      if (ones) {
        ans = max(ans, v[i] / 3);
      } else if (v[i] == 1) {
        return 1e9;
      } else if (twos > 1) {
        ans = max(ans, (v[i] - 4) / 3);
      } else {
        return 1e9;
      }
    } else {
      if (ones > 1) {
        ans = max(ans, v[i] / 3);
      } else if (twos) {
        ans = max(ans, v[i] / 3);
      } else {
        return 1e9;
      }
    }
  }
  return ones + twos + ans;
}
int tc() {
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  sort(v.begin(), v.end());
  int ans = 1e9;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int cand = solve(i, j, v, n);
      ans = min(ans, cand);
    }
  }
  return ans;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", tc());
  }
}

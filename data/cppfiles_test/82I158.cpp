#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int pref[maxn][2][2];
int A[2][2] = {{1, -1}, {-1, 1}};
int query(int lo, int hi) {
  int ret = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      ret += (pref[hi][i][j] - pref[lo - 1][i][j]) * A[i][j];
  return ret;
}
int find(int lo, int hi) {
  int ret = -1;
  int l = lo, r = hi;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    int first = query(l, mid - 1);
    int second = query(mid + 1, r);
    if (first > 0 && second > 0)
      hi = mid - 1;
    else if (first < 0 && second < 0)
      lo = mid + 1;
    else {
      first = abs(first), second = abs(second);
      if (first < second)
        lo = mid + 1;
      else
        ret = mid, hi = mid - 1;
    }
  }
  return ret;
}
void solve() {
  int n, q;
  string s;
  scanf("%d %d", &n, &q);
  cin >> s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) pref[i + 1][j][k] = pref[i][j][k];
    if (s[i] == '+')
      pref[i + 1][0][i & 1]++;
    else
      pref[i + 1][1][i & 1]++;
  }
  for (int i = 0; i < q; i++) {
    int first, second;
    scanf("%d %d", &first, &second);
    int sum = query(first, second);
    if (sum != 0) {
      if (sum % 2 == 0)
        sum = 2;
      else
        sum = 1;
    }
    printf("%d\n", sum);
    if (sum == 1) printf("%d\n", find(first, second));
    if (sum == 2) printf("%d %d\n", first, find(first + 1, second));
  }
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int LN = 19;
const int N = 100005;
int n, numQ, a[N], b[N], d[N];
long long sumD[N], res[N], mn[LN][N], mx[LN][N];
pair<pair<int, int>, int> q[N];
long long getMin(int l, int r) {
  int k = log2(r - l + 1);
  return min(mn[k][l], mn[k][r - (1 << k) + 1]);
}
long long getMax(int l, int r) {
  int k = log2(r - l + 1);
  return max(mx[k][l], mx[k][r - (1 << k) + 1]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> numQ;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    d[i] = b[i] - a[i];
    sumD[i] = sumD[i - 1] + d[i];
    mn[0][i] = mx[0][i] = sumD[i];
  }
  for (int j = 1; j < LN; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      mn[j][i] = min(mn[j - 1][i], mn[j - 1][i + (1 << (j - 1))]);
      mx[j][i] = max(mx[j - 1][i], mx[j - 1][i + (1 << (j - 1))]);
    }
  }
  for (int i = 1; i <= numQ; i++) {
    int l, r;
    cin >> l >> r;
    q[i] = {{l, r}, i};
  }
  for (int i = 1; i <= numQ; i++) {
    int l = q[i].first.first;
    int r = q[i].first.second;
    int id = q[i].second;
    if (sumD[r] - sumD[l - 1] != 0) {
      res[id] = -1;
    } else {
      long long minVal = getMin(l, r) - sumD[l - 1];
      long long maxVal = getMax(l, r) - sumD[l - 1];
      if (minVal < 0)
        res[id] = -1;
      else
        res[id] = maxVal;
    }
  }
  for (int i = 1; i <= numQ; i++) {
    cout << res[i] << '\n';
  }
}

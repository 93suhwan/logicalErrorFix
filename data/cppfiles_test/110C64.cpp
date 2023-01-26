#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void pr(Args... args) {}
using ll = long long;
const char nl = '\n';
const int MX = 2e5 + 10;
const int INF = 1e9 + 10;
int n;
array<int, 3> a[MX];
void flip() {
  for (int i = 0; i < n; i++) swap(a[i][0], a[i][1]);
}
void flip2() {
  for (int i = 0; i < n; i++) a[i][0] = INF - a[i][0];
}
bool works(int k) {
  int one = n / 3;
  priority_queue<int> three;
  priority_queue<int, vector<int>, greater<int>> two;
  for (int i = n - 1, j = n - 1; i >= 0; i = j) {
    while (j >= 0 && a[i][0] == a[j][0]) {
      if (a[j][2] == 0) --one;
      if (a[j][2] == 1) two.push(a[j][1]);
      if (a[j][2] == 2) three.push(a[j][1]);
      if (((int)(two.size())) > k) two.pop();
      if (((int)(three.size())) > k) three.pop();
      --j;
    }
    if (one >= k && ((int)(two.size())) == k && ((int)(three.size())) == k &&
        two.top() > three.top()) {
      return true;
    }
  }
  return false;
}
int pre[MX], suf[MX];
bool works2(int k) {
  fill_n(pre, n + 1, 0);
  fill_n(suf, n + 1, 0);
  for (int i = 0; i < n; i++) {
    if (a[i][2] == 0) pre[i + 1]++;
    if (a[i][2] == 2) suf[i]++;
  }
  for (int i = 0; i < n; i++) {
    pre[i + 1] += pre[i];
  }
  for (int i = n - 1; i >= 0; --i) {
    suf[i] += suf[i + 1];
  }
  int cur = 0;
  for (int i = 0, j = 0, l = 0, r = 0; i < n; i++) {
    while (j < n && cur < k) {
      cur += a[j][2] == 1;
      j++;
    }
    while (a[l][0] < a[i][0]) l++;
    while (r < n && a[r][0] <= a[j - 1][0]) r++;
    if (cur == k && pre[l] >= k && suf[r] >= k) {
      return true;
    }
    if (a[i][2] == 1) --cur;
  }
  return false;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
    --a[i][2];
  }
  int ans = 0;
  for (int rep = 0; rep < 2; rep++) {
    for (int rep2 = 0; rep2 < 2; rep2++) {
      sort(a, a + n);
      vector<int> perm(3), iperm(3);
      iota(perm.begin(), perm.end(), 0);
      do {
        for (int i = 0; i < 3; i++) {
          iperm[perm[i]] = i;
        }
        for (int i = 0; i < n; i++) {
          a[i][2] = perm[a[i][2]];
        }
        int lo = 0, hi = n / 3 + 1;
        while (hi - lo > 1) {
          int mid = (lo + hi) / 2;
          if (works(mid) || works2(mid)) {
            lo = mid;
          } else {
            hi = mid;
          }
        }
        ans = max(ans, lo);
        for (int i = 0; i < n; i++) {
          a[i][2] = iperm[a[i][2]];
        }
      } while (next_permutation(perm.begin(), perm.end()));
      flip2();
    }
    flip();
  }
  cout << ans * 3 << nl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int te = 1;
  while (te--) {
    solve();
  }
}

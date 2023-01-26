#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 1100000;
int l[MAXN], r[MAXN];
int f[MAXN], ld[MAXN], rd[MAXN];
void Build(int t, int depth) {
  f[t] = ld[t] = rd[t] = MAXN;
  if (depth == 0) return;
  l[t] = t + t;
  r[t] = t + t + 1;
  Build(t + t, depth - 1);
  Build(t + t + 1, depth - 1);
}
void Update(int t, int B) {
  f[t] = min(f[l[t]], f[r[t]]);
  f[t] = min(f[t], rd[l[t]] + ld[r[t]] + 1);
  if (ld[l[t]] == MAXN) {
    ld[t] = min(MAXN, ld[r[t]] + (1 << B));
  } else {
    ld[t] = ld[l[t]];
  }
  if (rd[r[t]] == MAXN) {
    rd[t] = min(MAXN, rd[l[t]] + (1 << B));
  } else {
    rd[t] = rd[r[t]];
  }
}
void Add(int t, int B, int a) {
  if (B == -1) {
    ld[t] = rd[t] = 0;
    return;
  }
  if (a >> B & 1) {
    Add(r[t], B - 1, a);
  } else {
    Add(l[t], B - 1, a);
  }
  Update(t, B);
}
void Change(int t, int B, int depth) {
  if (depth == 0) {
    swap(l[t], r[t]);
    Update(t, B);
    return;
  }
  Change(l[t], B - 1, depth - 1);
  Change(r[t], B - 1, depth - 1);
  Update(t, B);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  Build(1, k);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    Add(1, k - 1, a);
  }
  if (k == 1) {
    cout << 1 << " " << 1 << endl;
    return 0;
  }
  vector<int> mask{0, 2, 3, 1};
  for (int i = 3; i <= k; ++i) {
    for (int j = (1 << (i - 1)) - 1; j >= 0; --j) {
      mask.push_back(mask[j]);
    }
    for (int j = 0; j < (1 << (i - 1)); ++j) {
      mask[j] = mask[j] << 1;
    }
    for (int j = (1 << (i - 1)); j < (1 << i); ++j) {
      mask[j] = (mask[j] << 1) | 1;
    }
  }
  vector<int> ans(1 << k);
  ans[0] = f[1];
  for (int i = 1; i < (1 << k); ++i) {
    int t = 0;
    while (((mask[i] ^ mask[i - 1]) >> t & 1) == 0) ++t;
    Change(1, k - 1, k - 1 - t);
    ans[mask[i]] = f[1];
  }
  for (int i : ans) cout << i << " ";
  cout << endl;
  return 0;
}

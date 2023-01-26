#include <bits/stdc++.h>
using namespace std;
const int NM_MAX = 1000000;
const int AB_MAX = 1000000000;
int t;
int n, m;
int a[NM_MAX + 2];
int b[NM_MAX + 2];
struct SGTNode {
  int minVal;
  int lazy;
};
SGTNode operator+(const SGTNode &u, const SGTNode &v) {
  return SGTNode{min(u.minVal, v.minVal), 0};
}
void operator+=(SGTNode &u, const int &v) {
  u.minVal += v;
  u.lazy += v;
}
SGTNode SGT[NM_MAX * 4 + 2];
void split(int node) {
  int lSon = node * 2, rSon = node * 2 + 1;
  SGT[lSon] += SGT[node].lazy;
  SGT[rSon] += SGT[node].lazy;
  SGT[node].lazy = 0;
}
void build(int node, int l, int r) {
  if (l == r) {
    SGT[node].minVal = 0;
    SGT[node].lazy = 0;
    return;
  }
  split(node);
  int mid = (l + r) / 2;
  int lSon = node * 2, rSon = node * 2 + 1;
  build(lSon, l, mid);
  build(rSon, mid + 1, r);
  SGT[node] = SGT[lSon] + SGT[rSon];
}
void build() { build(1, 1, n + 1); }
void update(int node, int l, int r, int ul, int ur, int uval) {
  if (ul <= l && r <= ur) {
    SGT[node] += uval;
    return;
  }
  split(node);
  int mid = (l + r) / 2;
  int lSon = node * 2, rSon = node * 2 + 1;
  if (ul <= mid) update(lSon, l, mid, ul, ur, uval);
  if (mid + 1 <= ur) update(rSon, mid + 1, r, ul, ur, uval);
  SGT[node] = SGT[lSon] + SGT[rSon];
}
void update(int ul, int ur, int uval) { update(1, 1, n + 1, ul, ur, uval); }
int p[NM_MAX + 2];
int asmall[NM_MAX + 2];
int BIT[NM_MAX + 2];
void BITupdate(int val) {
  for (int i = val; i >= 1; i -= i & -i) BIT[i]++;
}
int BITquery(int val) {
  int cnt = 0;
  for (int i = val; i <= n; i += i & -i) cnt += BIT[i];
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(b + 1, b + m + 1);
    build();
    for (int i = 1; i <= n; i++) update(i + 1, n + 1, +1);
    for (int i = 1; i <= n; i++) p[i] = i;
    sort(p + 1, p + n + 1,
         [&](const int &i, const int &j) { return a[i] < a[j]; });
    {
      int curr = 0;
      for (int i = 1; i <= n; i++) {
        if (i == 1 || a[p[i]] > a[p[i - 1]]) curr++;
        asmall[p[i]] = curr;
      }
    }
    long long answer = 0;
    int l = 0, r = 0;
    for (int i = 1; i <= m; i++) {
      while (r < n && a[p[r + 1]] <= b[i]) {
        r++;
        update(p[r] + 1, n + 1, -1);
      }
      while (l < r && a[p[l + 1]] < b[i]) {
        l++;
        update(1, p[l], +1);
      }
      answer += SGT[1].minVal;
    }
    for (int i = 1; i <= n; i++) {
      answer += BITquery(asmall[i] + 1);
      BITupdate(asmall[i]);
    }
    for (int i = 1; i <= n; i++) BIT[i] = 0;
    cout << answer << "\n";
  }
  return 0;
}

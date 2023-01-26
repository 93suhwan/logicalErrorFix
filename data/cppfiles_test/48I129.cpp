#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const long long inf = 1e17 + 5;
struct SegmentTree {
  int l, r;
  long long minPref, maxPref, maxDiff, maxNeeded;
  SegmentTree *L, *R;
  SegmentTree()
      : L(nullptr),
        R(nullptr),
        minPref(inf),
        maxPref(0),
        maxDiff(0),
        maxNeeded(0) {}
  SegmentTree(int l, int r) : SegmentTree() {
    this->l = l;
    this->r = r;
  }
  void recalc() {
    minPref = min(L->minPref, R->minPref);
    maxPref = max(L->maxPref, R->maxPref);
    maxDiff = max(L->maxDiff, R->maxDiff);
    maxNeeded = max(L->maxNeeded, R->maxNeeded);
  }
  void build(long long *pref, long long *a, long long *b, long long *needed) {
    if (l == r) {
      minPref = maxPref = pref[l];
      maxDiff = abs(a[l] - b[l]);
      maxNeeded = needed[l];
      return;
    }
    L = new SegmentTree(l, (l + r) / 2);
    R = new SegmentTree((l + r) / 2 + 1, r);
    L->build(pref, a, b, needed);
    R->build(pref, a, b, needed);
    recalc();
  }
  long long queryMinPref(int ql, int qr) {
    if (l >= ql && r <= qr) return minPref;
    if (r < ql || l > qr) return inf;
    return min(L->queryMinPref(ql, qr), R->queryMinPref(ql, qr));
  }
  long long queryMaxPref(int ql, int qr) {
    if (l >= ql && r <= qr) return maxPref;
    if (r < ql || l > qr) return 0;
    return max(L->queryMaxPref(ql, qr), R->queryMaxPref(ql, qr));
  }
  long long queryMaxDiff(int ql, int qr) {
    if (l >= ql && r <= qr) return maxDiff;
    if (r < ql || l > qr) return 0;
    return max(L->queryMaxDiff(ql, qr), R->queryMaxDiff(ql, qr));
  }
  long long queryMaxNeeded(int ql, int qr) {
    if (l >= ql && r <= qr) return maxNeeded;
    if (r < ql || l > qr) return 0;
    return max(L->queryMaxNeeded(ql, qr), R->queryMaxNeeded(ql, qr));
  }
};
int n;
long long a[MAXN], b[MAXN];
long long needed[MAXN];
long long pref[MAXN];
SegmentTree *T = nullptr;
void init() {
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += b[i] - a[i];
    pref[i] = sum;
  }
  int waiting = 0;
  long long last = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < b[i])
      waiting++;
    else if (a[i] > b[i]) {
      if (waiting == 0)
        last += a[i] - b[i];
      else {
        last = max(last, a[i] - b[i]);
        waiting = 0;
      }
      needed[i] = last;
    }
  }
  T = new SegmentTree(0, n - 1);
  T->build(pref, a, b, needed);
}
long long getMinPref(int l, int r) { return T->queryMinPref(l, r); }
long long getMaxPref(int l, int r) { return T->queryMaxPref(l, r); }
long long getMaxDiff(int l, int r) { return T->queryMaxDiff(l, r); }
long long getMaxNeeded(int l, int r) { return T->queryMaxNeeded(l, r); }
void doQuery() {
  int l, r;
  cin >> l >> r;
  l--;
  r--;
  if (l == r) {
    if (a[l] == b[l])
      cout << "0" << '\n';
    else
      cout << "-1" << '\n';
    return;
  }
  long long toSub = ((l == 0) ? 0 : pref[l - 1]);
  long long minVal = getMinPref(l, r) - toSub;
  if (minVal != 0)
    cout << "-1" << '\n';
  else
    cout << getMaxNeeded(l, r) << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int Q;
  cin >> n >> Q;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  init();
  while (Q--) doQuery();
}

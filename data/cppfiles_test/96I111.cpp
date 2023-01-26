#include <bits/stdc++.h>
using namespace std;
const int MaxN = 2e5;
long long t[4 * MaxN];
long long getSum(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) {
    return t[v];
  }
  int mid = (tl + tr) / 2;
  return getSum(v * 2, tl, mid, l, min(r, mid)) +
         getSum(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
}
void setVal(int v, int tl, int tr, int pos, long long val) {
  if (tl == tr) {
    t[v] = val;
    return;
  }
  int mid = (tl + tr) / 2;
  if (pos <= mid)
    setVal(v * 2, tl, mid, pos, val);
  else
    setVal(v * 2 + 1, mid + 1, tr, pos, val);
  t[v] = t[v * 2] + t[v * 2 + 1];
}
int a[MaxN];
long long f(long long totalLen, long long ignoredLen) {
  return ignoredLen * (ignoredLen + 1) / 2 +
         ignoredLen * (totalLen - ignoredLen);
}
int main(int argc, const char* argv[]) {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> a[i];
  set<pair<int, int>> segs;
  auto addSeg = [&](int l, int r) {
    segs.insert({l, r});
    int len = r - l + 1;
    setVal(1, 0, n - 1, l, len * 1ll * (len + 1) / 2);
  };
  auto removeSeg = [&](int l, int r) {
    segs.erase({l, r});
    setVal(1, 0, n - 1, l, 0);
  };
  auto getSeg = [&](int pos) {
    auto it = segs.lower_bound({pos, n});
    it--;
    return *it;
  };
  auto tryMerge = [&](int idx1, int idx2) {
    if (idx1 < 0 || idx1 >= n) return;
    if (idx2 < 0 || idx2 >= n) return;
    auto seg1 = getSeg(idx1);
    auto seg2 = getSeg(idx2);
    if (seg1 == seg2) return;
    if (a[idx1] <= a[idx2]) {
      removeSeg(seg1.first, seg1.second);
      removeSeg(seg2.first, seg2.second);
      addSeg(seg1.first, seg2.second);
    }
  };
  auto trySeparate = [&](int idx1, int idx2) {
    if (idx1 < 0 || idx1 >= n) return;
    if (idx2 < 0 || idx2 >= n) return;
    auto seg1 = getSeg(idx1);
    auto seg2 = getSeg(idx2);
    if (seg1 != seg2) return;
    if (a[idx1] > a[idx2]) {
      removeSeg(seg1.first, seg1.second);
      addSeg(seg1.first, idx1);
      addSeg(idx2, seg1.second);
    }
  };
  int l = 0;
  for (int i = 0; i < n; ++i) {
    if (i > 0 && a[i] < a[i - 1]) {
      addSeg(l, i - 1);
      l = i;
    }
  }
  addSeg(l, n - 1);
  for (int qq = 0; qq < q; ++qq) {
    int type;
    cin >> type;
    if (type == 1) {
      int pos, val;
      cin >> pos >> val;
      pos--;
      a[pos] = val;
      tryMerge(pos - 1, pos);
      trySeparate(pos - 1, pos);
      tryMerge(pos, pos + 1);
      trySeparate(pos, pos + 1);
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      auto it1 = segs.lower_bound({l, 0});
      if (it1->first != l) it1--;
      auto it2 = segs.lower_bound({r, n});
      it2--;
      int lLeft = it1->first;
      int rLeft = it1->second;
      int lRight = it2->first;
      int rRight = it2->second;
      if (rLeft < l) lLeft = lRight;
      long long totalSum = 0;
      if (lLeft != lRight) {
        totalSum = getSum(1, 0, n - 1, lLeft, rRight);
        totalSum -= f(rLeft - lLeft + 1, l - lLeft);
        totalSum -= f(rRight - lRight + 1, rRight - r);
      } else {
        totalSum = getSum(1, 0, n - 1, lLeft, rRight);
        totalSum -= f(rLeft - lLeft + 1, rLeft - lLeft + 1 - (r - l + 1));
      }
      cout << totalSum << "\n";
    }
  }
  return 0;
}

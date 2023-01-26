#include <bits/stdc++.h>
using namespace std;
const int MaxN = 200 * 1000;
const int MaxVal = 300 * 1000 + 1;
pair<long long, long long> tCountSum[4 * MaxVal];
pair<long long, long long> CountSumNumbers(int v, int tl, int tr, int l,
                                           int r) {
  if (l > r) return {0, 0};
  if (l == tl && r == tr) {
    return tCountSum[v];
  }
  int mid = (tl + tr) / 2;
  auto left = CountSumNumbers(v * 2, tl, mid, l, min(r, mid));
  auto right = CountSumNumbers(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
  return {left.first + right.first, left.second + right.second};
}
long long CountNumbers(int l, int r) {
  if (l > r) return 0;
  l = max(l, 0);
  r = min(r, MaxVal - 1);
  return CountSumNumbers(1, 0, MaxVal - 1, l, r).first;
}
long long SumNumbers(int l, int r) {
  if (l > r) return 0;
  l = max(l, 0);
  r = min(r, MaxVal - 1);
  return CountSumNumbers(1, 0, MaxVal - 1, l, r).second;
}
pair<long long, long long> CountSumNumbers(int l, int r) {
  if (l > r) return {0, 0};
  l = max(l, 0);
  r = min(r, MaxVal - 1);
  return CountSumNumbers(1, 0, MaxVal - 1, l, r);
}
void AddNumber(int v, int tl, int tr, long long val) {
  if (tl == tr) {
    tCountSum[v].first++;
    tCountSum[v].second += val;
    return;
  }
  int mid = (tl + tr) / 2;
  if (val <= mid) {
    AddNumber(v * 2, tl, mid, val);
  } else {
    AddNumber(v * 2 + 1, mid + 1, tr, val);
  }
  tCountSum[v].first = tCountSum[v * 2].first + tCountSum[v * 2 + 1].first;
  tCountSum[v].second = tCountSum[v * 2].second + tCountSum[v * 2 + 1].second;
}
void AddNumber(int x) { AddNumber(1, 0, MaxVal - 1, x); }
pair<long long, long long> tCountSumForward[4 * MaxVal];
pair<long long, long long> tAddForward[4 * MaxVal];
void push(int v) {
  if (tAddForward[v].first != 0 || tAddForward[v].second != 0) {
    if (v * 2 < MaxVal) {
      tAddForward[v * 2].first += tAddForward[v].first;
      tAddForward[v * 2].second += tAddForward[v].second;
    }
    if (v * 2 + 1 < MaxVal) {
      tAddForward[v * 2 + 1].first += tAddForward[v].first;
      tAddForward[v * 2 + 1].second += tAddForward[v].second;
    }
    tAddForward[v].first = 0;
    tAddForward[v].second = 0;
  }
}
pair<long long, long long> GetCountSumForward(int v, int tl, int tr, int pos) {
  if (tl == tr) {
    return tCountSumForward[v];
  }
  push(v);
  int mid = (tl + tr) / 2;
  if (pos <= mid)
    return GetCountSumForward(v * 2, tl, mid, pos);
  else
    return GetCountSumForward(v * 2 + 1, mid + 1, tr, pos);
}
pair<long long, long long> GetCountSumForward(int val) {
  if (val < 0 || val >= MaxVal) return {0, 0};
  return GetCountSumForward(1, 0, MaxVal - 1, val);
}
void AddGetValueForward(int v, int tl, int tr, int l, int r, long long addSum) {
  if (l > r) return;
  if (l == tl && r == tr) {
    tAddForward[v].first++;
    tAddForward[v].second += addSum;
    tCountSumForward[v].first++;
    tCountSumForward[v].second += addSum;
    return;
  }
  push(v);
  int mid = (tl + tr) / 2;
  AddGetValueForward(v * 2, tl, mid, l, min(r, mid), addSum);
  AddGetValueForward(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r, addSum);
  tCountSumForward[v].first =
      tCountSumForward[v * 2].first + tCountSumForward[v * 2 + 1].first;
  tCountSumForward[v].second =
      tCountSumForward[v * 2].second + tCountSumForward[v * 2 + 1].second;
}
void AddGetValueForward(int l, int r, long long addSum) {
  l = max(l, 0);
  r = min(r, MaxVal - 1);
  AddGetValueForward(1, 0, MaxVal - 1, l, r, addSum);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  vector<long long> res(n, 0);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    res[i] += a[i] * CountNumbers(a[i] + 1, MaxVal);
    res[i] += SumNumbers(1, a[i] - 1);
    auto tmp2 = GetCountSumForward(a[i]);
    res[i] += a[i] * tmp2.first - tmp2.second;
    for (long long mult = 1; a[i] * mult <= MaxVal; ++mult) {
      auto tmp = CountSumNumbers(a[i] * mult, a[i] * (mult + 1) - 1);
      res[i] += tmp.second - a[i] * mult * tmp.first;
      AddGetValueForward(a[i] * mult, a[i] * (mult + 1) - 1, a[i] * mult);
    }
    AddNumber(a[i]);
    if (i > 0) res[i] += res[i - 1];
  }
  for (int i = 0; i < n; ++i) cout << res[i] << " ";
  cout << endl;
  return 0;
}

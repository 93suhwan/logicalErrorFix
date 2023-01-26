#include <bits/stdc++.h>
using namespace std;
const int MaxN = 200 * 1000;
const int MaxVal = 300 * 1000 + 1;
struct MyPair {
  int first;
  long long second;
};
MyPair tCountSum[4 * MaxVal];
MyPair CountSumNumbers(int v, int tl, int tr, int l, int r) {
  if (l > r) return {0, 0};
  if (l == tl && r == tr) {
    return tCountSum[v];
  }
  int mid = (tl + tr) / 2;
  auto left = CountSumNumbers(v * 2, tl, mid, l, min(r, mid));
  auto right = CountSumNumbers(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
  return {left.first + right.first, left.second + right.second};
}
int CountNumbers(int l, int r) {
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
MyPair CountSumNumbers(int l, int r) {
  if (l > r) return {0, 0};
  l = max(l, 0);
  r = min(r, MaxVal - 1);
  return CountSumNumbers(1, 0, MaxVal - 1, l, r);
}
void AddNumber(int v, int tl, int tr, int val) {
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
MyPair tCountSumForward[4 * MaxVal];
MyPair tAddForward[4 * MaxVal];
void push(int v) {
  if (tAddForward[v].first != 0 || tAddForward[v].second != 0) {
    if (v * 2 < 4 * MaxVal) {
      tAddForward[v * 2].first += tAddForward[v].first;
      tAddForward[v * 2].second += tAddForward[v].second;
    }
    if (v * 2 + 1 < 4 * MaxVal) {
      tAddForward[v * 2 + 1].first += tAddForward[v].first;
      tAddForward[v * 2 + 1].second += tAddForward[v].second;
    }
    tCountSumForward[v].first += tAddForward[v].first;
    tCountSumForward[v].second += tAddForward[v].second;
    tAddForward[v].first = 0;
    tAddForward[v].second = 0;
  }
}
MyPair GetCountSumForward(int v, int tl, int tr, int pos) {
  if (tl == tr) {
    push(v);
    return tCountSumForward[v];
  }
  push(v);
  int mid = (tl + tr) / 2;
  if (pos <= mid)
    return GetCountSumForward(v * 2, tl, mid, pos);
  else
    return GetCountSumForward(v * 2 + 1, mid + 1, tr, pos);
}
MyPair GetCountSumForward(int val) {
  if (val < 0 || val >= MaxVal) return {0, 0};
  return GetCountSumForward(1, 0, MaxVal - 1, val);
}
void AddGetValueForward(int v, int tl, int tr, int l, int r, int addSum) {
  if (l > r) return;
  if (l == tl && r == tr) {
    tAddForward[v].first++;
    tAddForward[v].second += addSum;
    push(v);
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
void AddGetValueForward(int l, int r, int addSum) {
  l = max(l, 0);
  r = min(r, MaxVal - 1);
  AddGetValueForward(1, 0, MaxVal - 1, l, r, addSum);
}
bool used[MaxVal];
MyPair forw[MaxVal];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<long long> res(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    res[i] += a[i] * 1ll * CountNumbers(a[i] + 1, MaxVal);
    res[i] += SumNumbers(1, a[i] - 1);
    auto tmp2 = GetCountSumForward(a[i]);
    res[i] += a[i] * 1ll * tmp2.first - tmp2.second;
    res[i] += a[i] * 1ll * forw[a[i]].first - forw[a[i]].second;
    if (a[i] <= 100) {
      for (int mult = 1; a[i] * mult <= MaxVal; ++mult) {
        int temp = a[i] * mult;
        for (int x = a[i] * mult; x < a[i] * (mult + 1); ++x) {
          if (used[x]) {
            res[i] += x - temp;
          }
          forw[x].first++;
          forw[x].second += temp;
        }
      }
    } else {
      for (int mult = 1; a[i] * mult <= MaxVal; ++mult) {
        auto tmp = CountSumNumbers(a[i] * mult, a[i] * (mult + 1) - 1);
        res[i] += tmp.second - a[i] * 1ll * mult * tmp.first;
        AddGetValueForward(a[i] * mult, a[i] * (mult + 1) - 1, a[i] * mult);
      }
    }
    AddNumber(a[i]);
    used[a[i]] = true;
    if (i > 0) res[i] += res[i - 1];
  }
  for (int i = 0; i < n; ++i) cout << res[i] << " ";
  cout << endl;
  return 0;
}

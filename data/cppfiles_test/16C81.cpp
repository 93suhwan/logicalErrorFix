#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigMod(T p, T e, T M) {
  T ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T modInverse(T a, T M) {
  return bigMod(a, M - 2, M);
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / gcd(a, b)) * b;
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > v;
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      v.push_back(make_pair(x, i));
    }
    sort(v.begin(), v.end());
    vector<pair<int, int> > res;
    while (v[n - 1].first) {
      int lo = 0, hi = n - 1, mid, ans = -1;
      while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (v[mid].first < v[n - 1].first)
          lo = mid + 1;
        else {
          ans = mid;
          hi = mid - 1;
        }
      }
      int target1 = ans;
      lo = 0, hi = target1 - 1, mid, ans = -1;
      while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (v[mid].first < v[target1 - 1].first or !v[mid].first)
          lo = mid + 1;
        else {
          ans = mid;
          hi = mid - 1;
        }
      }
      int target2 = ans;
      if (target2 == -1 && target1 < n - 1) {
        target2 = target1 + 1;
      }
      if (target2 == -1) break;
      res.push_back(make_pair(v[target1].second, v[target2].second));
      v[target1].first--;
      v[target2].first--;
    }
    printf("%d\n", (int)res.size());
    for (int i = 0; i < res.size(); i++) {
      printf("%d %d\n", res[i].first, res[i].second);
    }
  }
  return 0;
}

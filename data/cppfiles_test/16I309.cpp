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
    int i = n - 1;
    vector<pair<int, int> > ans;
    while (i > 0) {
      int j = i - 1;
      while (j >= 0 && v[i].first > 0) {
        int mn = min(v[i].first, v[j].first);
        v[i].first -= mn;
        v[j].first -= mn;
        j--;
        if (!mn) continue;
        for (int k = 0; k < mn; k++) {
          ans.push_back(make_pair(v[i].second, v[j + 1].second));
        }
      }
      int k = j + 1;
      while (k >= 0 && !v[k].first) k--;
      i = k;
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }
  return 0;
}

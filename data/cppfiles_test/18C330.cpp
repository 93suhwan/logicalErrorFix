#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T POW(T B, T P) {
  if (P == 0) return 1;
  if (P & 1)
    return B * POW(B, P - 1);
  else
    return SQR(POW(B, P / 2));
}
template <class T>
inline T BMOD(T p, T e, T m) {
  T ret = 1;
  while (e) {
    if (e & 1) ret = (ret * p) % m;
    p = (p * p) % m;
    e >>= 1;
  }
  return (T)ret;
}
template <typename T>
inline T ModInv(T b, T m) {
  return BMOD(b, m - 2, m);
}
template <typename T>
inline T ABS(T a) {
  if (a < 0)
    return -a;
  else
    return a;
}
template <typename T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <typename T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
int dx[] = {-1, -1, 1, 1, 1, 0, -1, 0};
int dy[] = {-1, 1, -1, 1, 0, 1, 0, -1};
int n, k;
bool mp[202];
int main() {
  int t, tc = 1;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    memset(mp, 0, sizeof mp);
    vector<pair<int, int> > chords;
    int cnt = 0;
    for (int i = 0; i < k; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      if (u > v) swap(u, v);
      for (pair<int, int> pr : chords) {
        bool isbetween = (u >= pr.first && u <= pr.second);
        if (isbetween != (v >= pr.first && v <= pr.second)) {
          cnt++;
        }
      }
      mp[u] = mp[v] = 1;
      chords.push_back(make_pair(u, v));
    }
    vector<int> pt;
    for (int i = 1; i <= 2 * n; i++) {
      if (!mp[i]) {
        pt.push_back(i);
      }
    }
    int c = pt.size() / 2;
    for (int i = 0; i < n - k; i++) {
      int a = pt[i];
      int b = pt[n - k + i];
      for (pair<int, int> pr : chords) {
        bool isbetween = (a >= pr.first && a <= pr.second);
        if (isbetween != (b >= pr.first && b <= pr.second)) {
          cnt++;
        }
      }
      mp[a] = mp[b] = 1;
      chords.push_back(make_pair(a, b));
    }
    printf("%d", cnt), puts("");
  }
  return 0;
}

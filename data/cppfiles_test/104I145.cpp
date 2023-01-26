#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T>
void ckmn(T& a, T b) {
  a = min(a, b);
}
template <typename T>
void ckmx(T& a, T b) {
  a = max(a, b);
}
void rd(int& x) { scanf("%i", &x); }
void rd(long long& x) { scanf("%lld", &x); }
void rd(char* x) { scanf("%s", x); }
void rd(double& x) { scanf("%lf", &x); }
void rd(string& x) { scanf("%s", &x); }
template <typename T1, typename T2>
void rd(pair<T1, T2>& x) {
  rd(x.first);
  rd(x.second);
}
template <typename T>
void rd(vector<T>& x) {
  for (T& i : x) rd(i);
}
template <typename T, typename... A>
void rd(T& x, A&... args) {
  rd(x);
  rd(args...);
}
template <typename T>
void rd() {
  T x;
  rd(x);
  return x;
}
int ri() {
  int x;
  rd(x);
  return x;
}
template <typename T>
vector<T> rv(int n) {
  vector<T> x(n);
  rd(x);
  return x;
}
template <typename T>
void ra(T a[], int n, int st = 1) {
  for (int i = 0; i < n; ++i) rd(a[st + i]);
}
template <typename T1, typename T2>
void ra(T1 a[], T2 b[], int n, int st = 1) {
  for (int i = 0; i < n; ++i) rd(a[st + i]), rd(b[st + i]);
}
template <typename T1, typename T2, typename T3>
void ra(T1 a[], T2 b[], T3 c[], int n, int st = 1) {
  for (int i = 0; i < n; ++i) rd(a[st + i]), rd(b[st + i]), rd(c[st + i]);
}
void re(vector<int> E[], int m, bool dir = 0) {
  for (int i = 0, u, v; i < m; ++i) {
    rd(u, v);
    E[u].push_back(v);
    if (!dir) E[v].push_back(u);
  }
}
template <typename T>
void re(vector<pair<int, T>> E[], int m, bool dir = 0) {
  for (int i = 0, u, v; i < m; ++i) {
    T w;
    rd(u, v, w);
    E[u].push_back({v, w});
    if (!dir) E[v].push_back({u, w});
  }
}
int main() {
  for (int t = ri(); t--;) {
    int n = ri();
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) rd(a[i]);
    int cnt1 = 0;
    for (int i = 1; i <= n; i++) cnt1 += a[i] == 1;
    if (cnt1 == n || cnt1 % 2 == 1)
      printf("NO\n");
    else {
      vector<int> ans;
      int carry = 0, ed = n;
      while (ed > 0 && a[ed] == 0) ed--;
      for (int i = 1, j; i <= ed; i = j) {
        for (j = i; j <= n && a[j] == 1; j++)
          ;
        if (i == j) {
          j++;
          carry = 0;
          continue;
        }
        if ((j - i + carry) % 2 == 1) {
          carry = j - i + carry;
          while (j + 1 <= ed && a[j] == 0 && a[j + 1] == 0) {
            ans.push_back(j - 1);
            a[j] = 1;
            a[j + 1] = 1;
            j += 2;
            carry += 2;
          }
          if (j <= ed && a[j] == 1) {
          } else
            carry = 0;
        } else
          carry = 0;
      }
      cnt1 = 0;
      for (int i = 1; i <= n; i++) cnt1 += a[i] == 1;
      if (cnt1 == n || cnt1 % 2 == 1)
        printf("NO\n");
      else {
        printf("YES\n");
        int before = 0;
        for (int i = 1; i <= n - 2; i++) {
          if (before % 2 == 0 && a[i] + a[i + 1] + a[i + 2] == 2) {
            ans.push_back(i);
            a[i] = 0;
            a[i + 1] = 0;
            a[i + 2] = 0;
            int j = i - 2;
            while (j > 0 && a[j] + a[j + 1] + a[j + 2] == 2) {
              ans.push_back(j);
              a[j] = 0;
              a[j + 1] = 0;
              a[j + 2] = 0;
            }
          } else if (a[i] == 1)
            before++;
        }
        printf("%i\n", ans.size());
        for (int i : ans) printf("%i ", i);
        printf("\n");
      }
    }
  }
  return 0;
}

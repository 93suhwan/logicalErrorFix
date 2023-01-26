#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int gcd(int a, int b) {
  while (b > 0) {
    int p = a % b;
    a = b;
    b = p;
  }
  return a;
}
long long bexp(long long a, int b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long bexpM(long long a, int b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % M;
    a = (a * a) % M;
    b >>= 1;
  }
  return res;
}
long long nCk(int n, int k) {
  long long res = 1;
  for (int i = k + 1; i < n + 1; i++) res = res * i;
  long long p = 1;
  for (int i = 2; i < n - k + 1; i++) p = p * i;
  res = res / p;
  return res;
}
long long nCkM(int n, int k) {
  long long res = 1;
  for (int i = k + 1; i < n + 1; i++) res = (res * i) % M;
  long long p = 1;
  for (int i = 2; i < n - k + 1; i++) p = (p * i) % M;
  res = (res * bexpM(p, M - 2)) % M;
  return res;
}
const int N = 2e5;
int st[N][18];
int q(int l, int s, int n) {
  int i = 0;
  while ((1 << (i + 1)) < s) i++;
  return gcd(st[l][i], st[l - (1 << i) + s][i]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int u;
  cin >> u;
  for (int g = 0; g < u; g++) {
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    n--;
    for (int i = 0; i < n; i++) {
      st[i][0] = abs(a[i + 1] - a[i]);
    }
    for (int i = 1; i < log2(n); i++) {
      for (int j = 0; j < n - (1 << (i - 1)); j++) {
        st[j][i] = gcd(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
      }
    }
    int l = 1;
    int r = n;
    while (l < r) {
      int m = (l + r + 1) / 2;
      int b[n - m + 1];
      for (int i = 0; i < n - m + 1; i++) {
        b[i] = q(i, m, n);
      }
      bool bo = 1;
      for (int i = 0; i < n - m + 1; i++) {
        if (b[i] != 1) bo = 0;
      }
      if (bo)
        r = m - 1;
      else
        l = m;
    }
    bool bo = 1;
    for (int i = 0; i < n; i++) {
      if (st[i][0]) bo = 0;
    }
    if (bo)
      cout << "1\n";
    else
      cout << l + 1 << "\n";
  }
}

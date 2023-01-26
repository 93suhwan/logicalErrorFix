#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
template <typename... T>
void rd(T&... args) {
  ((cin >> args), ...);
}
template <typename... T>
void ql(T&&... args) {
  ((cout << args << ' '), ...);
}
template <typename... T>
void sd(T&&... args) {
  ((cout << args << '\n'), ...);
}
const char bye = '\n';
const int element = 1e5 + 4;
long long gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long fact(long long n) {
  long long prod = 1;
  for (long long i = 2; i <= n; i++) {
    prod *= i;
  }
  return prod;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
void precision(int a) { cout << setprecision(a) << fixed; }
long long n;
int32_t d[element];
void gashiNa() {
  rd(n);
  vector<int> c(n), b(n);
  ;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  };
  b = c;
  sort(b.begin(), b.end());
  int32_t it = 1, cnt{0};
  while (c != b) {
    if (it % 2 != 0) {
      for (int i = 0; i < n - 2; i += 2) {
        if (c[i] > c[i + 1]) swap(c[i], c[i + 1]);
      }
    } else {
      for (int i = 1; i < n - 1; i += 2) {
        if (c[i] > c[i + 1]) swap(c[i], c[i + 1]);
      }
    }
    it++;
    cnt++;
  }
  sd(cnt);
}
int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long TEST{1};
  cin >> TEST;
  while (TEST--) {
    gashiNa();
  }
  return 0;
}

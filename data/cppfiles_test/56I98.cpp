#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx")
using namespace std;
const int64_t inf = 1000000005;
const int64_t P = 1e9 + 7;
const int N = 2e5 + 7;
int64_t pw(int64_t a, int64_t n) {
  int64_t r = 1;
  a %= P;
  while (n > 0) {
    if (n % 2) r = (r * a) % P;
    a = (a * a) % P;
    n /= 2;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  unordered_map<int64_t, int64_t> a1, a2, a3;
  int k;
  cin >> k;
  int n;
  cin >> n;
  int64_t v;
  string ss;
  std::vector<int64_t> S, RR;
  int V;
  for (int i = 0; i < n; ++i) {
    cin >> v >> ss;
    V = v;
    while (V > 0) {
      S.push_back(V);
      V /= 2;
    }
    RR.push_back(v);
    if (ss == "white" || ss == "yellow") {
      a2[v] = 0;
      a3[v] = 0;
    }
    if (ss == "green" || ss == "blue") {
      a1[v] = 0;
      a3[v] = 0;
    }
    if (ss == "red" || ss == "orange") {
      a2[v] = 0;
      a1[v] = 0;
    }
  }
  int64_t b1, b2, b3, c1, c2, c3;
  int64_t f = 0;
  int64_t u = (1LL << (k - 1));
  int64_t U = (1LL << (k - 1));
  sort(S.begin(), S.end());
  ;
  sort(RR.begin(), RR.end());
  ;
  int64_t z;
  S.erase(unique(S.begin(), S.end()), S.end());
  reverse(S.begin(), S.end());
  for (auto t : S) {
    if (t == 0) break;
    if (t >= U) {
      if (a1.count(t) == 0) a1[t] = 1;
      if (a2.count(t) == 0) a2[t] = 1;
      if (a3.count(t) == 0) a3[t] = 1;
      continue;
    }
    while (t < u) {
      u /= 2;
      f++;
    }
    z = (1LL << f) - 2;
    b1 = (2 * pw(4, z)) % P;
    b2 = b1;
    b3 = b1;
    c1 = b1;
    c2 = b1;
    c3 = b1;
    if (a1.count(t * 2 + 1) == 1) {
      b1 = a1[t * 2 + 1];
      b2 = a2[t * 2 + 1];
      b3 = a3[t * 2 + 1];
    }
    if (a1.count(t * 2) == 1) {
      c1 = a1[t * 2];
      c2 = a2[t * 2];
      c3 = a3[t * 2];
    }
    if (a1.count(t) == 0) a1[t] = ((b2 + b3) * (c2 + c3)) % P;
    if (a2.count(t) == 0) a2[t] = ((b1 + b3) * (c1 + c3)) % P;
    if (a3.count(t) == 0) a3[t] = ((b2 + b1) * (c2 + c1)) % P;
    if (binary_search(RR.begin(), RR.end(), t) == false) {
      a2[t] = (a2[t] * 2) % P;
      a1[t] = (a1[t] * 2) % P;
      a3[t] = (a3[t] * 2) % P;
    }
  }
  cout << (a1[1] + a2[1] + a3[1]) % P;
}

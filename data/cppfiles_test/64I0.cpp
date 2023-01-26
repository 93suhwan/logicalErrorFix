#include <bits/stdc++.h>
using namespace std;
int MOD, PR, V[500001] = {1};
int mul(int a, int b, int p = MOD) { return 1LL * a * b % p; }
int fast_pow(int a, int b, int p = MOD) {
  int ret = 1;
  for (; b; b >>= 1) {
    if (b & 1) ret = mul(ret, a, p);
    a = mul(a, a);
  }
  return ret;
}
void GeneratePrimes(unordered_set<int> &s, int n) {
  while (n % 2 == 0) {
    s.insert(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      s.insert(i);
      n = n / i;
    }
  }
  if (n > 2) s.insert(n);
}
int findPrimitiveRoot(int n) {
  unordered_set<int> s;
  int ETF = n - 1;
  GeneratePrimes(s, ETF);
  for (int r = 2; r <= ETF; r++) {
    bool flag = false;
    for (auto it = s.begin(); it != s.end(); it++) {
      if (fast_pow(r, ETF / (*it)) == 1) {
        flag = true;
        break;
      }
    }
    if (flag == false) return r;
  }
  return -1;
}
bool prime(int N) {
  for (int i = 2; 1LL * i * i <= N; i++)
    if (N % i == 0) return false;
  return true;
}
int get_value(int s, int e) {
  return mul(
      fast_pow(fast_pow(V[s - 1], fast_pow(10, e - s + 1, MOD - 1)), MOD - 2),
      V[e]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ((void)0);
  ((void)0);
  ((void)0);
  mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> upd(100000000, 1000000000);
  string s, t;
  int N, K, R = 1;
  while (!prime(MOD = upd(mt)))
    ;
  PR = findPrimitiveRoot(MOD);
  assert(PR > -1);
  cin >> s >> t;
  N = s.size();
  K = t.size();
  for (int i = 0; i < N; i++) {
    V[i + 1] = mul(fast_pow(V[i], 10), fast_pow(PR, s[i] - '0'));
  }
  for (int i = 0; i < K; i++)
    R = mul(fast_pow(R, 10), fast_pow(PR, t[i] - '0'));
  for (int i = 2 * K - 2; i <= N; i++) {
    if (i >= 2 * K - 2) {
      if (R ==
          mul(get_value(i - K + 2, i), get_value(i - 2 * K + 3, i - K + 1))) {
        cout << i - 2 * K + 3 << ' ' << i - K + 1 << '\n'
             << i - K + 2 << ' ' << i << '\n';
        break;
      }
    }
    if (i >= 2 * K - 1) {
      if (R ==
          mul(get_value(i - K + 2, i), get_value(i - 2 * K + 2, i - K + 1))) {
        cout << i - 2 * K + 2 << ' ' << i - K + 1 << '\n'
             << i - K + 2 << ' ' << i << '\n';
        break;
      }
      if (R == mul(get_value(i - K + 1, i), get_value(i - 2 * K + 2, i - K))) {
        cout << i - 2 * K + 2 << ' ' << i - K << '\n'
             << i - K + 1 << ' ' << i << '\n';
        break;
      }
    }
    if (i >= 2 * K) {
      if (R == mul(get_value(i - K + 1, i), get_value(i - 2 * K + 1, i - K))) {
        cout << i - 2 * K + 1 << ' ' << i - K << '\n'
             << i - K + 1 << ' ' << i << '\n';
        break;
      }
    }
  }
  return 0;
}

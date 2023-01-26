#include <bits/stdc++.h>
using namespace std;
int MOD, PR, V[500001] = {1}, C[500001] = {1};
int mul(int a, int b, int p = MOD) { return 1LL * a * b % p; }
int fast_pow(int a, int b, int p = MOD) {
  int ret = 1;
  for (; b; b >>= 1) {
    if (b & 1) ret = mul(ret, a, p);
    a = mul(a, a, p);
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
  return mul(fast_pow(V[s - 1], C[e - s + 1]), V[e]);
}
vector<int> SA, LCP, Rank;
void SuffixArray(const string &s) {
  int N = s.size(), M = 127, H = 0;
  vector<int> temp(2 * N), cnt(max(128, N + 1)), g(2 * N), ng(2 * N);
  SA.resize(N);
  LCP.resize(N);
  Rank.resize(N);
  for (int i = 0; i < N; i++) g[SA[i] = i] = s[i];
  for (int l = 1; l < N; l <<= 1) {
    fill(cnt.begin(), cnt.end(), 0);
    for (int i = 0; i < N; i++) cnt[g[i + l]]++;
    for (int i = 1; i <= M; i++) cnt[i] += cnt[i - 1];
    for (int i = N - 1; i >= 0; i--) temp[--cnt[g[i + l]]] = i;
    fill(cnt.begin(), cnt.end(), 0);
    for (int i = 0; i < N; i++) cnt[g[i]]++;
    for (int i = 1; i <= M; i++) cnt[i] += cnt[i - 1];
    for (int i = N - 1; i >= 0; i--) SA[--cnt[g[temp[i]]]] = temp[i];
    ng[SA[0]] = 1;
    for (int i = 1; i < N; i++)
      ng[SA[i]] = ng[SA[i - 1]] + (g[SA[i - 1]] == g[SA[i]]
                                       ? g[SA[i - 1] + l] < g[SA[i] + l]
                                       : g[SA[i - 1]] < g[SA[i]]);
    g = ng;
    if ((M = ng[SA[N - 1]]) == N) break;
  }
  for (int i = 0; i < N; i++) g[Rank[SA[i]] = temp[SA[i]] = i] = s[i];
  for (int i = 0; i < N; i++) {
    if (temp[i]) {
      int j = SA[temp[i] - 1];
      while (g[i + H] == g[j + H]) H++;
      LCP[temp[i]] = H;
    }
    H = max(H - 1, 0);
  }
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
  string s, t, v;
  int N, K, R = 1, vv;
  while (!prime(MOD = upd(mt)))
    ;
  PR = findPrimitiveRoot(MOD);
  assert(PR > -1);
  vv = mul(MOD - 2, 10, MOD - 1);
  cin >> s >> t;
  N = s.size();
  K = t.size();
  v = t + ' ' + s;
  SuffixArray(v);
  for (int i = Rank[0] - 1; i >= 0; i--) LCP[i] = min(LCP[i], LCP[i + 1]);
  for (int i = Rank[0] + 2; i < v.size(); i++) LCP[i] = min(LCP[i], LCP[i - 1]);
  for (int i = 0; i < N; i++) {
    V[i + 1] = mul(fast_pow(V[i], 10), fast_pow(PR, s[i] - '0'));
    C[i + 1] = mul(C[i], vv, MOD - 1);
  }
  for (int i = 0; i < K; i++)
    R = mul(fast_pow(R, 10), fast_pow(PR, t[i] - '0'));
  for (int i = 1; i <= N; i++) {
    int lv;
    if (Rank[i + K] < Rank[0])
      lv = LCP[Rank[i + K] + 1];
    else
      lv = LCP[Rank[i + K]];
    if (i + K - 1 <= N && i > K - lv - 1 &&
        mul(get_value(i, i + K - 1), get_value(i - K + lv + 1, i - 1)) == R) {
      cout << i - K + lv + 1 << ' ' << i - 1 << '\n'
           << i << ' ' << i + K - 1 << '\n';
      break;
    }
    if (i + K - 1 <= N && i > K - lv &&
        mul(get_value(i, i + K - 1), get_value(i - K + lv, i - 1)) == R) {
      cout << i - K + lv << ' ' << i - 1 << '\n'
           << i << ' ' << i + K - 1 << '\n';
      break;
    }
    if (i + 2 * K - lv - 2 <= N &&
        mul(get_value(i, i + K - 1), get_value(i + K, i + 2 * K - lv - 2)) ==
            R) {
      cout << i << ' ' << i + K - 1 << '\n'
           << i + K << ' ' << i + 2 * K - lv - 2 << '\n';
      break;
    }
    if (i + 2 * K - lv - 1 <= N &&
        mul(get_value(i, i + K - 1), get_value(i + K, i + 2 * K - lv - 1)) ==
            R) {
      cout << i << ' ' << i + K - 1 << '\n'
           << i + K << ' ' << i + 2 * K - lv - 1 << '\n';
      break;
    }
    if (i - 2 * K + 3 > 0 && mul(get_value(i - K + 2, i),
                                 get_value(i - 2 * K + 3, i - K + 1)) == R) {
      cout << i - 2 * K + 3 << ' ' << i - K + 1 << '\n'
           << i - K + 2 << ' ' << i << '\n';
      break;
    }
  }
  return 0;
}

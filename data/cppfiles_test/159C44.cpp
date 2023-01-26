#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
void go(int n, std::vector<int> kill) {
  printf("%d\n", n - kill.size());
  std::vector<int> tk(n + 1, 1);
  for (auto x : kill) tk[x] = 0;
  for (int i = 1; i < n + 1; i++)
    if (tk[i]) printf("%d ", i);
  exit(0);
}
const int N = 1000002;
int state[N];
std::vector<int> mindiv(N + 1, 0);
int cur;
void proc(int m) {
  while (m != 1) {
    int p = mindiv[m];
    cur -= state[p];
    state[p] ^= 1;
    cur += state[p];
    m /= p;
  }
}
int main() {
  vector<long long> pr;
  std::vector<int> isp(N + 1, 0);
  for (int i = 2; i <= N; ++i) {
    if (mindiv[i] == 0) {
      mindiv[i] = i;
      pr.push_back(i);
      isp[i] = 1;
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= mindiv[i] && i * pr[j] <= N;
         ++j)
      mindiv[i * pr[j]] = pr[j];
  }
  int n;
  scanf("%d", &n);
  std::vector<int> fl(N, 0);
  if ((n / 2) % 2) state[2] ^= 1;
  for (int i = 1; i < N; i++) {
    int m = i;
    while (m != 1) {
      int p = mindiv[m];
      fl[p] ^= 1;
      m /= p;
    }
    if (i == n / 2) {
      for (int j = 0; j < N; j++) state[j] ^= fl[j];
    }
    if (n % 2 == 1 && i == n) {
      for (int j = 0; j < N; j++) state[j] ^= fl[j];
    }
  }
  for (int i = 0; i < N; i++) cur += state[i];
  if (cur == 0) go(n, {});
  int curwas = cur;
  for (int i = 0; i < N; i++) fl[i] = state[i];
  for (int i = 1; i < n + 1; i++) {
    int m = i;
    while (m != 1) {
      int p = mindiv[m];
      cur -= fl[p];
      fl[p] ^= 1;
      cur += fl[p];
      m /= p;
    }
    if (cur == 0) go(n, {i});
  }
  if (n % 2 == 0) {
    go(n, {n / 2, 2});
  }
  if ((n / 2) % 2 == 0) go(n, {n, n / 2});
  for (int i = 0; i < N; i++) state[i] = 0;
  state[2] = 1;
  cur = 1;
  int cur1 = n;
  int cur2 = n / 2;
  for (int r = n; r >= n - 1200; r--) {
    if (r < 1) break;
    for (int l = n / 2 - 1200; l < n / 2 + 1200; l++) {
      if (l < 1 || l > n) continue;
      while (cur1 > r) proc(cur1--);
      while (cur1 < r) proc(++cur1);
      while (cur2 > l) proc(cur2--);
      while (cur2 < l) proc(++cur2);
      if (cur == 0) go(n, {cur1, cur2});
    }
  }
  go(n, {n, n / 2, 2});
}

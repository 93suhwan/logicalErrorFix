#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int sum() { return 0; }
template <typename T, typename... Args>
T sum(T a, Args... args) {
  return a + sum(args...);
}
template <typename... T>
void read(T &...args) {
  ((cin >> args), ...);
}
template <typename... T>
void write(string delimiter, T &&...args) {
  ((cout << args << delimiter), ...);
}
template <typename T>
void readContainer(T &t) {
  for (auto &e : t) {
    read(e);
  }
}
template <typename T>
void writeContainer(string delimiter, T &t) {
  for (const auto &e : t) {
    write(delimiter, e);
  }
  write("\n");
}
template <typename... T>
void printer(T &&...args) {
  ((cout << args << " "), ...);
}
int n, t, m;
vector<int> fac(N);
vector<unsigned long long> p(N), f(N);
map<unsigned long long, int> ch;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  read(n);
  mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
  iota(fac.begin(), fac.end(), 0);
  for (int i = 2; i <= n; i++)
    if (fac[i] == i) {
      for (int j = i; j <= n; j += i) fac[j] = i;
      p[i] = rnd();
    }
  for (int i = 2; i <= n; i++) {
    f[i] = f[i - 1];
    int x = i;
    while (x > 1) {
      f[i] = f[i] ^ (p[fac[x]]);
      x /= fac[x];
    }
    ch[f[i]] = i;
  }
  auto solve = [&](int n) -> vector<int> {
    unsigned long long ans = 0;
    for (int i = 2; i <= n; i++) ans ^= f[i];
    if (ans == 0) return {};
    if (ch.count(ans)) return {ch[ans]};
    for (int i = 2; i <= n; i++) {
      unsigned long long x = ans ^ f[i];
      if (ch.count(x)) return {ch[x], i};
    }
    return {2, n, n / 2};
  };
  auto ans = solve(n);
  cout << n - ans.size() << endl;
  for (int i = 1; i <= n; i++) {
    if (find(ans.begin(), ans.end(), i) == ans.end()) cout << i << ' ';
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
const int N = 1e6 + 5;
int n;
mt19937_64 rnd(int(time(0)));
ull fac[N], prv[N], target;
int pr[N];
void sieve(int n) {
  static bool vis[N];
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) pr[++pr[0]] = i, prv[i] = rnd();
    for (int j = 1; j <= pr[0] && pr[j] * i <= n; j++) {
      vis[pr[j] * i] = 1;
      if (i % pr[j] == 0) break;
    }
  }
}
ull get(int x) {
  ull v = 0;
  for (int i = 1; i <= pr[0] && 1ll * pr[i] * pr[i] <= x; i++) {
    if (x % pr[i] == 0) {
      while (x % pr[i] == 0) {
        v ^= prv[pr[i]];
        x /= pr[i];
      }
    }
  }
  if (x != 1) v ^= prv[x];
  return v;
}
void init() {
  sieve(n);
  for (int i = 1; i <= n; i++) fac[i] = get(i);
  for (int i = n; i >= 1; i -= 2) target ^= fac[i];
}
bool check1() {
  ull cur = 0;
  for (int i = 1; i <= n; i++) {
    cur ^= fac[i];
    if (cur == target) {
      printf("%d\n", n - 1);
      for (int j = 1; j <= n; j++) {
        if (j != i) printf("%d ", j);
      }
      return true;
    }
  }
  return false;
}
bool check2() {
  map<ull, int> mp;
  ull cur = 0;
  for (int i = 1; i <= n; i++) {
    cur ^= fac[i];
    if (mp.count(target ^ cur)) {
      int j = mp[target ^ cur];
      printf("%d\n", n - 2);
      for (int k = 1; k <= n; k++) {
        if (k != i && k != j) printf("%d ", k);
      }
      return true;
    }
    mp[cur] = i;
  }
  return false;
}
bool check3() {
  assert(n % 4 == 3);
  printf("%d\n", n - 3);
  --n;
  for (int i = 1; i <= n; i++)
    if (i != 2 && i != n / 2) printf("%d ", i);
  return true;
}
int main() {
  scanf("%d", &n);
  if (n == 1) {
    puts("1\n1");
    return 0;
  }
  init();
  (check1() || check2() || check3());
  return 0;
}

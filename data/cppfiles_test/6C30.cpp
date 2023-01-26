#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
vector<int> fac[MAXN];
int prime[MAXN];
bool flag[MAXN];
int phi[MAXN];
int a[MAXN];
int tot = 0;
int n;
const int mod = 1e9 + 7;
int Mul(int a, int b) { return 1ll * a * b % mod; }
int Add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int Minus(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
void euler() {
  phi[1] = 1;
  for (int i = 2; i < MAXN; i++) {
    if (!flag[i]) {
      prime[tot++] = i;
      phi[i] = i - 1;
    }
    for (int j = 0; j < tot && 1ll * i * prime[j] < MAXN; j++) {
      flag[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = prime[j] * phi[i];
        break;
      } else {
        phi[i * prime[j]] = (prime[j] - 1) * phi[i];
      }
    }
  }
}
int cnt[MAXN];
vector<int> usd;
int cal(int x) {
  for (int i = x; i < MAXN; i += x) {
    for (auto it : fac[a[i]]) {
      cnt[it]++;
      usd.push_back(it);
    }
  }
  int res = 0;
  for (auto it : usd) {
    res = Add(res, Mul(phi[it], Mul(cnt[it], cnt[it])));
    cnt[it] = 0;
  }
  usd.clear();
  return res;
}
int main() {
  euler();
  for (int i = 1; i < MAXN; i++) {
    for (int j = i; j < MAXN; j += i) {
      fac[j].push_back(i);
    }
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res = Add(res, Mul(phi[i], cal(i)));
  }
  printf("%d", res);
  return 0;
}

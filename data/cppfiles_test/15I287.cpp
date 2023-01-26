#include <bits/stdc++.h>
using namespace std;
const long long MOD = (1e9 + 7);
const long long MAX_VALEURS = (101);
vector<long long> Voisins[MAX_VALEURS];
long long Fact[MAX_VALEURS];
long long InvFact[MAX_VALEURS];
long long Occ[MAX_VALEURS];
long long nbNoeuds, taille;
long long Expo(long long a, long long n) {
  long long ans = 1, cur = a;
  for (long long i = 1; i <= n; i <<= 1, cur = (cur * cur) % MOD) {
    if (n & i) ans = (ans * cur) % MOD;
  }
  return ans;
}
void Dfs(long long noeud, long long pere, long long dist) {
  Occ[dist]++;
  for (long long dest : Voisins[noeud]) {
    if (dest != pere) Dfs(dest, noeud, dist + 1);
  }
  return;
}
void Init() {
  Fact[0] = 1;
  for (long long i = 1; i < MAX_VALEURS; i++) {
    Fact[i] = (Fact[i - 1] * i) % MOD;
  }
  InvFact[MAX_VALEURS - 1] = Expo(Fact[MAX_VALEURS - 1], MOD - 2);
  for (long long i = MAX_VALEURS - 1; i > 0; i--) {
    InvFact[i - 1] = (InvFact[i] * i) % MOD;
  }
  return;
}
long long Choose(long long k, long long n) {
  return (Fact[n] * ((InvFact[k] * InvFact[n - k]) % MOD)) % MOD;
}
void Solve() {
  scanf("%lld %lld", &nbNoeuds, &taille);
  for (long long i = 0; i < nbNoeuds; i++) {
    Voisins[i].clear();
  }
  for (long long i = 1; i < nbNoeuds; i++) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    Voisins[--a].push_back(--b);
    Voisins[b].push_back(a);
  }
  if (taille == 2) {
    printf("%lld\n", Choose(taille, nbNoeuds));
    return;
  }
  long long ans = 0;
  for (long long i = 0; i < nbNoeuds; i++) {
    fill_n(Occ, nbNoeuds, 0LL);
    Dfs(i, i, 0);
    for (long long d = 0; d < nbNoeuds; d++) {
      ans += (taille <= Occ[d]) ? Choose(taille, Occ[d]) : 0;
    }
    ans %= MOD;
  }
  printf("%lld\n", ans);
  return;
}
signed main() {
  Init();
  long long nbTests = 1;
  scanf("%lld", &nbTests);
  while (nbTests--) {
    Solve();
  }
  return 0;
}

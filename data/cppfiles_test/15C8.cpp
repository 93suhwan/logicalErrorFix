#include <bits/stdc++.h>
using namespace std;
const long long MOD = (1e9 + 7);
const long long MAX_VALEURS = (101);
vector<long long> Voisins[MAX_VALEURS];
long long Occ[MAX_VALEURS];
long long DP[MAX_VALEURS][MAX_VALEURS];
long long nbNoeuds, taille;
void Dfs(long long noeud, long long pere, long long dist) {
  Occ[dist]++;
  for (long long dest : Voisins[noeud]) {
    if (dest != pere) Dfs(dest, noeud, dist + 1);
  }
  return;
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
    printf("%lld\n", (nbNoeuds * (nbNoeuds - 1)) / 2);
    return;
  }
  long long ans = 0;
  for (long long i = 0; i < nbNoeuds; i++) {
    for (long long j = 0; j < nbNoeuds; j++) {
      fill_n(DP[j], nbNoeuds, 0LL);
      DP[j][0] = 1;
    }
    for (long long dest : Voisins[i]) {
      fill_n(Occ, nbNoeuds, 0LL);
      Dfs(dest, i, 1);
      for (long long d = 0; d < nbNoeuds; d++) {
        for (long long j = nbNoeuds - 1; j > 0; j--) {
          DP[d][j] += DP[d][j - 1] * Occ[d];
          DP[d][j] %= MOD;
        }
      }
    }
    for (long long d = 0; d < nbNoeuds; d++) {
      ans += DP[d][taille];
    }
    ans %= MOD;
  }
  printf("%lld\n", ans);
  return;
}
signed main() {
  long long nbTests = 1;
  scanf("%lld", &nbTests);
  while (nbTests--) {
    Solve();
  }
  return 0;
}

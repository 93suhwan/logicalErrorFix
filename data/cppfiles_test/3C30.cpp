#include <bits/stdc++.h>
using namespace std;
const long long MAX_VALEURS = (200 * 1000 + 2);
long long Tree[2 * MAX_VALEURS];
long long Fenwick[MAX_VALEURS];
pair<long long, long long> Order[MAX_VALEURS];
pair<long long, long long> Inter[2 * MAX_VALEURS];
long long Lignes[MAX_VALEURS];
long long Colonnes[MAX_VALEURS];
long long BornesLignes[MAX_VALEURS];
long long BornesColonnes[MAX_VALEURS];
pair<long long, long long> Pile[MAX_VALEURS];
long long fin = 0;
long long nbLignes, nbColonnes, target;
long long GetMax(long long gauche, long long droite, long long val) {
  long long ans = 0;
  for (gauche += val, droite += val; gauche < droite;
       gauche >>= 1, droite >>= 1) {
    if (gauche & 1) ans = max(ans, Tree[gauche++]);
    if (droite & 1) ans = max(ans, Tree[--droite]);
  }
  return ans;
}
void Add(long long i) {
  long long d = i & 1 ? -1 : 1;
  i >>= 1;
  for (long long a = Colonnes[i]; a < MAX_VALEURS; a |= (a + 1))
    Fenwick[a] += d;
  return;
}
long long GetSum(long long i) {
  long long ans = 0;
  for (++i; i > 0; i &= (i - 1)) ans += Fenwick[i - 1];
  return ans;
}
void Read() {
  scanf("%lld %lld %lld", &nbLignes, &nbColonnes, &target);
  for (long long i = 1; i <= nbLignes; i++) {
    scanf("%lld", &Lignes[i]);
  }
  Lignes[0] = Lignes[nbLignes + 1] = 1 << 30;
  nbLignes += 2;
  for (long long i = 1; i <= nbColonnes; i++) {
    scanf("%lld", &Colonnes[i]);
  }
  Colonnes[0] = Colonnes[nbColonnes + 1] = 1 << 30;
  nbColonnes += 2;
  for (long long i = 0; i < nbLignes; i++) {
    Tree[i + nbLignes] = Lignes[i];
    Order[i] = {Lignes[i], i};
  }
  sort(Order, Order + nbLignes);
  for (long long i = nbLignes - 1; i > 0; i--) {
    Tree[i] = max(Tree[2 * i], Tree[2 * i + 1]);
  }
  Pile[fin++] = {-1, 0};
  for (long long i = 0; i < nbLignes; i++) {
    while (Pile[fin - 1].first > Lignes[i]) fin--;
    BornesLignes[i] = GetMax(Pile[fin - 1].second, i, nbLignes);
    Pile[fin++] = {Lignes[i], i + 1};
  }
  fin = 0;
  Pile[fin++] = {-1, nbLignes};
  for (long long i = nbLignes - 1; i >= 0; i--) {
    while (Pile[fin - 1].first >= Lignes[i]) fin--;
    BornesLignes[i] =
        min(BornesLignes[i], GetMax(i, Pile[fin - 1].second, nbLignes));
    Pile[fin++] = {Lignes[i], i};
  }
  for (long long i = 0; i < nbColonnes; i++) {
    Tree[i + nbColonnes] = Colonnes[i];
  }
  for (long long i = nbColonnes - 1; i > 0; i--) {
    Tree[i] = max(Tree[2 * i], Tree[2 * i + 1]);
  }
  fin = 0;
  Pile[fin++] = {-1, 0};
  for (long long i = 0; i < nbColonnes; i++) {
    while (Pile[fin - 1].first > Colonnes[i]) fin--;
    BornesColonnes[i] = GetMax(Pile[fin - 1].second, i, nbColonnes);
    Pile[fin++] = {Colonnes[i], i + 1};
  }
  fin = 0;
  Pile[fin++] = {-1, nbColonnes};
  for (long long i = nbColonnes - 1; i >= 0; i--) {
    while (Pile[fin - 1].first >= Colonnes[i]) fin--;
    BornesColonnes[i] =
        min(BornesColonnes[i], GetMax(i, Pile[fin - 1].second, nbColonnes));
    Pile[fin++] = {Colonnes[i], i};
  }
  for (long long i = 0; i < nbLignes; i++) {
    BornesLignes[i] = max(BornesLignes[i], Lignes[i]);
  }
  for (long long i = 0; i < nbColonnes; i++) {
    BornesColonnes[i] = max(BornesColonnes[i], Colonnes[i]);
    Inter[2 * i] = {target - BornesColonnes[i], 2 * i};
    Inter[2 * i + 1] = {target - Colonnes[i], 2 * i + 1};
  }
  sort(Inter, Inter + 2 * nbColonnes);
  long long cur = 0;
  long long ans = 0;
  for (long long i = 0; i < nbLignes; i++) {
    while (cur < 2 * nbColonnes && Inter[cur].first < Order[i].first)
      Add(Inter[cur++].second);
    ans += GetSum(target - Order[i].first) -
           GetSum(target - BornesLignes[Order[i].second]);
  }
  printf("%lld\n", ans);
  return;
}
signed main() {
  Read();
  return 0;
}

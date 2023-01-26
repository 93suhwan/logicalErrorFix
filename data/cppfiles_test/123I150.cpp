#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17;
long long n, k, niv[200005];
vector<int> muchii[200005];
bool isleaf[200005], used[200005];
long long red, blue, par[200005];
vector<int> line;
int timp, in[200005], out[200005];
struct date {
  long long minim, best;
} arb[1000005];
long long lazy[1000005];
void dfs(int nod) {
  if (nod == 1) niv[nod] = 1;
  timp++;
  line.push_back(nod);
  in[nod] = timp;
  for (auto i : muchii[nod])
    if (i != par[nod]) {
      niv[i] = niv[nod] + 1;
      par[i] = nod;
      dfs(i);
    }
  out[nod] = timp;
  if (in[nod] == out[nod]) isleaf[nod] = 1;
}
void prop(int nod) {
  long long val = lazy[nod];
  arb[nod * 2].minim += val;
  arb[nod * 2 + 1].minim += val;
}
void update(int nod, int st, int dr, int a, int b, int val) {
  if (lazy[nod] != 0 && st != dr) prop(nod);
  lazy[nod] = 0;
  if (st >= a && dr <= b) {
    arb[nod].minim += val;
    if (st == dr) {
      if (isleaf[st])
        arb[nod].best = st;
      else
        arb[nod].best = INF;
    } else
      lazy[nod] += val;
    return;
  }
  int mij = (st + dr) / 2;
  if (a <= mij) update(nod * 2, st, mij, a, b, val);
  if (b > mij) update(nod * 2 + 1, mij + 1, dr, a, b, val);
  arb[nod].minim = arb[nod].best = -INF;
  if (arb[nod * 2].best <= n && arb[nod * 2].minim > arb[nod].minim)
    arb[nod] = arb[nod * 2];
  if (arb[nod * 2 + 1].best <= n && arb[nod * 2 + 1].minim > arb[nod].minim)
    arb[nod] = arb[nod * 2 + 1];
}
int main() {
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    muchii[a].push_back(b);
    muchii[b].push_back(a);
  }
  line.push_back(0);
  dfs(1);
  for (int i = 1; i <= n; i++) update(1, 1, n, i, i, niv[i]);
  long long ans = -INF;
  blue = n;
  red = 0;
  long long white;
  while (blue > 0 && red <= k) {
    white = n - red - blue;
    if (blue != n) ans = max(ans, white * (red - blue));
    long long nod = arb[1].best;
    red++;
    while (nod > 0 && !used[nod]) {
      used[nod] = 1;
      update(1, 1, n, in[nod], out[nod], -1);
      blue--;
      nod = par[nod];
    }
  }
  for (; red <= k && blue == 0; red++) {
    white = n - red - blue;
    ans = max(ans, white * (red - blue));
  }
  cout << ans;
  return 0;
}

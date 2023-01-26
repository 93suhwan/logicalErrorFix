#include <bits/stdc++.h>
using namespace std;
struct el {
  long long w[6];
};
const int MOD = 1e9 + 7;
int k;
const int MK = 70;
long long emptyWays[MK];
bitset<6> allColors;
long long pow2[MK];
int layer(int i) { return upper_bound(pow2, pow2 + MK, i) - pow2; }
bool has(map<int, el>& forced, int val) {
  return forced.find(val) != forced.end();
}
long long ways(map<int, el>& w, int ind, int col) {
  return w.find(ind) == w.end() ? emptyWays[k - layer(ind) + 1] : w[ind].w[col];
}
long long calcWays(int v, int col, map<int, el>& w) {
  if (layer(v) == k) return 1;
  long long totWays = 0;
  for (int l = 0; l < 6; ++l)
    for (int r = 0; r < 6; ++r) {
      if (l / 2 != col / 2 && r / 2 != col / 2) {
        totWays = (totWays + ways(w, 2 * v, l) * ways(w, 2 * v + 1, r)) % MOD;
      }
    }
  return totWays;
}
string cols[6] = {"white", "yellow", "green", "blue", "red", "orange"};
signed main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  allColors.set();
  int n;
  cin >> k >> n;
  emptyWays[1] = 1;
  for (int i = 2; i <= k; ++i)
    emptyWays[i] = (16 * (emptyWays[i - 1] * emptyWays[i - 1] % MOD)) % MOD;
  pow2[0] = 1;
  for (int i = 1; i < MK; ++i) pow2[i] = 2 * pow2[i - 1];
  map<int, el> forcedWays;
  map<int, int> forcedCols;
  map<string, int> ind;
  for (int i = 0; i < 6; ++i) ind[cols[i]] = i;
  for (int i = 0; i < n; ++i) {
    int nod;
    string s;
    cin >> nod >> s;
    int ci = ind[s];
    if (forcedCols.find(nod) != forcedCols.end()) {
      cout << "0\n";
      return 0;
    }
    forcedCols[nod] = ci;
  }
  set<int> pq;
  for (auto i : forcedCols) pq.insert(i.first);
  while (!pq.empty()) {
    int i = *pq.rbegin();
    if (!has(forcedWays, i)) {
      for (int c = 0; c < 6; ++c)
        forcedWays[i].w[c] = calcWays(i, c, forcedWays);
    }
    if (forcedCols.find(i) != forcedCols.end()) {
      int only = forcedCols[i];
      for (int c = 0; c < 6; ++c)
        if (c != only) forcedWays[i].w[c] = 0;
    }
    if (i > 1) pq.insert(i / 2);
    pq.erase(i);
  }
  if (forcedWays.find(1) != forcedWays.end()) {
    long long tot = 0;
    for (long long c : forcedWays[1].w) tot = (tot + c) % MOD;
    cout << tot << '\n';
  } else {
    cout << emptyWays[k] << '\n';
  }
}

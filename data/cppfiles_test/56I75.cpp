#include <bits/stdc++.h>
using namespace std;
const int K = 61;
const int Mod = 1e9 + 7;
int k;
long long cnt[K];
string colors[6] = {"white", "yellow", "green", "blue", "red", "orange"};
int inv[6] = {1, 0, 3, 2, 5, 4};
map<long long, int> color;
set<long long> nodes;
map<long long, map<int, int>> memo;
int getIndex(string s) {
  for (int i = 0; i < 6; i++) {
    if (s == colors[i]) {
      return i;
    }
  }
  return -1;
}
long long solve(long long node, int lastColor, int lev) {
  if (lev == k) {
    return 1;
  }
  if (nodes.count(node) == 0) {
    return lastColor == -1 ? 6 * cnt[lev + 1] % Mod : cnt[lev];
  }
  if (memo.count(node) && memo[node].count(lastColor)) {
    return memo[node][lastColor];
  }
  if (color.count(node)) {
    if (lastColor == color[node] || lastColor == inv[color[node]]) {
      return 0;
    }
    return memo[node][lastColor] = solve(node * 2, color[node], lev + 1) *
                                   solve(node * 2 + 1, color[node], lev + 1) %
                                   Mod;
  }
  long long ans = 0;
  for (int col = 0; col < 6; col++) {
    if (lastColor == col || lastColor == inv[col]) {
      continue;
    }
    ans = (ans + solve(2 * node, col, lev + 1) *
                     solve(2 * node + 1, col, lev + 1) % Mod) %
          Mod;
  }
  return memo[node][lastColor] = ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> k;
  int m;
  cin >> m;
  while (m--) {
    long long idx;
    string c;
    cin >> idx >> c;
    color[idx] = getIndex(c);
    while (idx > 0) {
      nodes.insert(idx);
      idx >>= 1;
    }
  }
  cnt[k] = cnt[k + 1] = 1;
  cnt[k - 1] = 4;
  for (int i = k - 2; i > 0; i--) {
    cnt[i] = 4 * cnt[i + 1] % Mod * cnt[i + 1] % Mod;
  }
  long long ans = 0;
  cout << solve(1, -1, 0) << endl;
  return 0;
}

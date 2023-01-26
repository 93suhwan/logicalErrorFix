#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5 + 5, ml = 18;
int n, k, cnt, L[mx], R[mx], dep[mx], nxt[mx], node[mx], up[mx][ml], dupe[mx],
    bad[mx];
string tmpS;
vector<char> S, ans;
void inorder(int cur) {
  int l = L[cur], r = R[cur];
  for (int i = 1; i < ml; i++) up[cur][i] = up[up[cur][i - 1]][i - 1];
  up[l][0] = up[r][0] = cur;
  dep[l] = dep[r] = dep[cur] + 1;
  if (l) inorder(l);
  node[++cnt] = cur;
  S[cnt] = tmpS[cur];
  if (r) inorder(r);
}
void fillBad(int cur) {
  if (bad[cur]) return;
  bad[cur] = 1;
  if (L[cur]) fillBad(L[cur]);
  if (R[cur]) fillBad(R[cur]);
}
int main() {
  cin >> n >> k >> tmpS;
  for (int i = 1; i < n + 1; i++) cin >> L[i] >> R[i];
  tmpS = " " + tmpS;
  S.resize(n + 1);
  inorder(1);
  for (int i = n - 1; i; i--) {
    if (S[i] != S[i + 1])
      nxt[i] = i + 1;
    else
      nxt[i] = nxt[i + 1];
  }
  bad[0] = dupe[0] = 1;
  for (int i = 1; i < n; i++) {
    int cur = node[i], anc = cur;
    if (bad[cur] or dupe[cur]) continue;
    if (S[i] > S[nxt[i]]) {
      fillBad(cur);
      continue;
    }
    for (int x = ml - 1; ~x; x--)
      if (!dupe[up[anc][x]]) anc = up[anc][x];
    int cst = dep[cur] - dep[anc] + 1;
    if (cst > k) continue;
    k -= cst;
    while (!dupe[cur]) dupe[cur] = 1, cur = up[cur][0];
  }
  for (int i = 1; i < n + 1; i++) {
    ans.push_back(S[i]);
    if (dupe[node[i]]) ans.push_back(S[i]);
  }
  for (char c : ans) cout << c;
}

#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5 + 5;
int n, k, cnt, L[mx], R[mx], elem[mx], nxt[mx];
bool dupe[mx];
string tmpStr;
vector<char> S;
void build(int cur) {
  if (~L[cur]) build(L[cur]);
  S.push_back(tmpStr[cur]);
  elem[cur] = cnt++;
  if (~R[cur]) build(R[cur]);
}
bool inorder(int cur, int cst) {
  int spos = elem[cur];
  if (~L[cur]) dupe[spos] = inorder(L[cur], cst + 1);
  if (!dupe[spos] and S[spos] < S[nxt[spos]] and cst <= k) {
    dupe[spos] = 1;
    k -= cst;
  }
  if (~R[cur] and dupe[spos]) inorder(R[cur], 1);
  return dupe[spos];
}
int main() {
  cin >> n >> k >> tmpStr;
  for (int i = 0; i < n; i++) cin >> L[i] >> R[i], L[i]--, R[i]--;
  build(0);
  nxt[n - 1] = n - 1;
  for (int i = n - 2; ~i; i--) nxt[i] = (S[i] != S[i + 1]) ? i + 1 : nxt[i + 1];
  inorder(0, 1);
  for (int i = 0; i < n; i++) {
    cout << S[i];
    if (dupe[i]) cout << S[i];
  }
}

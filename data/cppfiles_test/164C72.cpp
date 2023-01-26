#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
vector<int> inord;
void liz(vector<int>& p, int ind, vector<bool>& isd) {
  isd[ind] = 1;
  if (p[ind] + 1 && !isd[p[ind]]) liz(p, p[ind], isd);
}
void inorder(vector<int>& l, vector<int>& r, vector<int>& gov, int ind, int g) {
  if (l[ind] + 1) inorder(l, r, gov, l[ind], g + 1);
  inord.push_back(ind);
  gov[ind] = g;
  if (r[ind] + 1) inorder(l, r, gov, r[ind], g + 1);
}
void solve(vector<int>& l, vector<int>& r, vector<int>& gov, vector<bool>& isd,
           int ind, int& k, int gol, vector<int>& p, vector<bool>& iw) {
  if (l[ind] + 1) solve(l, r, gov, isd, l[ind], k, gol, p, iw);
  if (!isd[ind] && iw[ind] && gov[ind] - gol <= k) {
    k -= gov[ind] - gol;
    liz(p, ind, isd);
  }
  if (isd[ind]) gol = gov[ind];
  if (isd[ind])
    if (r[ind] + 1) solve(l, r, gov, isd, r[ind], k, gol, p, iw);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> l(n), r(n), p(n, -1), gov(n, 0);
  for (int i = 0; n > i; ++i) {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
    if (l[i] + 1) p[l[i]] = i;
    if (r[i] + 1) p[r[i]] = i;
  }
  inorder(l, r, gov, 0, 0);
  vector<bool> iw(n);
  char lk = s[inord[n - 1]];
  for (int i = n - 2; i >= 0; --i) {
    iw[inord[i]] = s[inord[i]] < lk;
    if (i > 0 && s[inord[i]] != s[inord[i - 1]]) lk = s[inord[i]];
  }
  vector<bool> isd(n);
  solve(l, r, gov, isd, 0, k, -1, p, iw);
  string s2;
  for (int i = 0; n > i; ++i) {
    s2.push_back(s[inord[i]]);
    if (isd[inord[i]]) s2.push_back(s[inord[i]]);
  }
  cout << s2;
  return 0;
}

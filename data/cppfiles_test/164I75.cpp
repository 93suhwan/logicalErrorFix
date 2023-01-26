#include <bits/stdc++.h>
using namespace std;
int n, k;
int l[200100], r[200100];
int p[200100];
bool db[200100];
bool du[200100];
string x;
string f = "";
vector<int> v;
void go(int cr) {
  if (l[cr] != 0) go(l[cr]);
  f += x[cr];
  v.push_back(cr);
  if (r[cr] != 0) go(r[cr]);
}
int ch(int cr, int first) {
  if (first > k) return k + 10;
  if (cr == 0 || db[cr] == 1) return 0;
  if (du[cr])
    return k + 1;
  else
    return ch(p[cr], first + 1) + 1;
}
void go2(int cr) {
  if (cr == 0 || db[cr] == 1) return;
  db[cr] = 1;
  k--;
  go2(p[cr]);
}
int main() {
  cin >> n >> k >> x;
  x = '0' + x;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    p[l[i]] = i;
    p[r[i]] = i;
  }
  go(1);
  int s[200100];
  int nxt = 0;
  for (int i = f.size() - 1; i >= 0; i--) {
    s[i] = nxt;
    if (i > 0) {
      if (f[i] == f[i - 1]) continue;
      nxt = f[i] - 'a';
    }
  }
  for (int i = 0; i < f.size(); i++) {
    if (s[i] > f[i] - 'a') {
      int gg = ch(v[i], 1);
      if (gg <= k) {
        go2(v[i]);
      }
    }
    du[v[i]] = 1;
  }
  for (int i = 0; i < f.size(); i++) {
    cout << f[i];
    if (db[v[i]] == 1) cout << f[i];
  }
  return 0;
}

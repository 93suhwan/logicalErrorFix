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
bool gr[200100];
int go2(int cr, int d) {
  int dk = 0;
  if (l[cr] != 0) {
    dk = go2(l[cr], d + 1);
  }
  if (!dk) {
    if (k >= d && gr[cr]) {
      k -= d;
      dk = 1;
    }
  }
  if (r[cr] != 0 && dk) {
    go2(r[cr], 1);
  }
  if (dk) db[cr] = 1;
  return dk;
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
    if (f[i] - 'a' < s[i]) {
      gr[v[i]] = 1;
    }
  }
  go2(1, 1);
  for (int i = 0; i < f.size(); i++) {
    cout << f[i];
    if (db[v[i]] == 1) cout << f[i];
  }
  return 0;
}

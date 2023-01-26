#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  long long k, x, n, m1, m2, q, a, b, c, m;
  string s, a1, a3;
  for (long long i = 0; i < t; i++) {
    cin >> n;
    vector<vector<long long>> v(n);
    for (long long j = 0; j < n; j++) {
      cin >> a;
      for (long long k = 0; k < a; k++) {
        cin >> b;
        v[j].push_back(b);
      }
    }
    cin >> m;
    map<vector<long long>, long long> ma;
    ma.clear();
    vector<vector<long long>> vv;
    for (long long j = 0; j < m; j++) {
      long long g;
      vector<long long> temp;
      for (long long k = 0; k < n; k++) {
        cin >> g;
        temp.push_back(g);
      }
      ma[temp]++;
      vv.push_back(temp);
    }
    vector<long long> temp;
    for (long long j = 0; j < n; j++) {
      temp.push_back(v[j].size());
    }
    if (m == 0) {
      for (long long j = 0; j < n; j++) {
        cout << v[j].size() << " ";
      }
      continue;
    }
    if (ma[temp] == 0) {
      for (long long j = 0; j < n; j++) {
        cout << v[j].size() << " ";
      }
      continue;
    }
    vector<vector<long long>> sto;
    for (long long j = 0; j < m; j++) {
      for (long long k = 0; k < n; k++) {
        long long c = vv[j][k];
        if (c == 1)
          continue;
        else
          c--;
        vv[j][k] = c;
        if (ma[vv[j]] == 0) {
          sto.push_back(vv[j]);
          ma[vv[j]]++;
        }
      }
    }
    long long ans = 0;
    long long ke = -1;
    for (long long j = 0; j < sto.size(); j++) {
      long long tem = 0;
      for (long long k = 0; k < n; k++) {
        tem += v[k][sto[j][k] - 1];
      }
      if (ans <= tem) {
        ans = tem;
        ke = j;
      }
    }
    for (long long k = 0; k < n; k++) {
      cout << sto[ke][k] << " ";
    }
  }
}

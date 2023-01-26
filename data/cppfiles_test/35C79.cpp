#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int t, n, q;
int v[1000010];
string s;
vector<int> pd[1000010];
vector<int> cod[1000010];
int p[1000010], siz;
set<int> ses;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 2; i < 1000010; i++) {
    if (!p[i]) {
      for (int j = i; j < 1000010; j += i) {
        p[j] = 1;
        pd[j].push_back(i);
      }
    }
  }
  cin >> n;
  for (int i = 0; i < n; i++) cin >> v[i];
  cin >> s;
  long long ris = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '/') {
      for (auto j : pd[v[i]]) {
        cod[j].push_back(i);
        ses.insert(i);
      }
      if (v[i] == 1) {
        int mim = n;
        if (ses.size()) mim = *ses.begin();
        ris += mim - i;
      }
    } else {
      int kek = v[i], mim = n;
      for (auto j : pd[v[i]]) {
        while (kek % j == 0 && cod[j].size()) {
          int k = cod[j].back();
          v[k] /= j;
          if (v[k] == 1) {
            ses.erase(ses.find(k));
          }
          if (v[k] % j) {
            cod[j].pop_back();
          }
          kek /= j;
        }
      }
      if (ses.size()) mim = *ses.begin();
      ris += mim - i;
    }
  }
  cout << ris << "\n";
}

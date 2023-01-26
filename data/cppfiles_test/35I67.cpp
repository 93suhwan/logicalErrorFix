#include <bits/stdc++.h>
using namespace std;
vector<int> pr(1000001, 1);
vector<vector<int> > pv(1000001, vector<int>());
int main() {
  for (int i = 2; i < 1000001; i++) {
    if (pr[i] == 1) {
      for (int j = i; j < 1000001; j += i) {
        pr[j] = i;
      }
    }
  }
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> fix(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    fix[i] = i;
  }
  string b;
  cin >> b;
  for (int i = n - 1; i >= 0; i--) {
    if (b[i] == '*') {
      int v = a[i];
      while (v > 1) {
        int p = pr[v];
        v /= p;
        if (!pv[p].empty()) {
          fix[pv[p].back()] = i;
          pv[p].pop_back();
        }
      }
    } else {
      int v = a[i];
      while (v > 1) {
        int p = pr[v];
        v /= p;
        pv[p].push_back(i);
      }
    }
  }
  for (int i = 0; i < 1000001; i++) {
    while (!pv[i].empty()) {
      fix[pv[i].back()] = -1;
      pv[i].pop_back();
    }
  }
  int right = -1;
  long long out = 0;
  for (int left = 0; left < n; left++) {
    while (right < n - 1) {
      if (fix[right + 1] < left) break;
      right++;
    }
    out += right - left + 1;
    if (right < left) right = left;
  }
  cout << out << '\n';
}

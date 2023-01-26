#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(15);
  int n, m;
  cin >> n >> m;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  int B = sqrt(m);
  vector<vector<int>> small(B, vector<int>(B));
  vector<int> small_begin(B);
  vector<vector<int>> big(n);
  vector<int> ans(m);
  for (int i = 0; i < m; ++i) {
    int op, k;
    cin >> op >> k;
    --k;
    if (x[k] + y[k] < B) {
      if (op == 1) {
        small_begin[k] = i;
        int b = x[k] + y[k];
        for (int j = y[k]; j < b; ++j) {
          small[b][(small_begin[k] + j) % b] += 1;
        }
      } else {
        int b = x[k] + y[k];
        for (int j = y[k]; j < b; ++j) {
          small[b][(small_begin[k] + j) % b] -= 1;
        }
      }
    } else {
      big[k].push_back(i);
    }
    for (int b = 2; b < B; ++b) {
      ans[i] += small[b][i % b];
    }
  }
  vector<int> imos(m + 1);
  for (int i = 0; i < n; ++i) {
    if (big[i].size() % 2 == 1) {
      big[i].push_back(m);
    }
    for (int j = 0; j < big[i].size(); j += 2) {
      int b = big[i][j];
      int e = big[i][j + 1];
      int s = b;
      while (s + x[i] < e) {
        ++imos[s + x[i]];
        --imos[min(s + x[i] + y[i], m)];
        s += x[i] + y[i];
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    ans[i] += imos[i];
    imos[i + 1] += imos[i];
    cout << ans[i] << "\n";
  }
}

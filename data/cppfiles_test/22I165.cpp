#include <bits/stdc++.h>
using namespace std;
inline int nxt() {
  int x;
  scanf("%d", &x);
  return x;
}
void solve() {
  int n = nxt(), k = nxt();
  vector<vector<int>> ops(k);
  for (int i = 0; i < k; ++i) {
    ops[i].resize(nxt());
    for (auto& x : ops[i]) {
      x = nxt() - 1;
    }
    sort((ops[i]).begin(), (ops[i]).end());
  }
  vector<vector<int>> already(k);
  vector<int> cnt(k, 0);
  vector<char> used(n);
  for (int i = 0; i < k; ++i) {
    for (int j : ops[i]) {
      if (!used[j]) {
        used[j] = 1;
        cnt[i] += 1;
      } else {
        already[i].push_back(j);
      }
    }
  }
  if (accumulate((cnt).begin(), (cnt).end(), 0) < n && n > 1) {
    cout << "REJECTED\n";
    return;
  }
  vector<char> vec(n);
  function<void(int)> rec = [&](int i) {
    if (i == k) {
      if (!is_sorted((vec).begin(), (vec).end())) {
        cout << "REJECTED\n";
        exit(0);
      }
      return;
    }
    int cur = 0;
    for (int j : already[i]) {
      cur += vec[j];
    }
    for (int cn = 0; cn <= cnt[i]; ++cn) {
      for (int j = 0; j < (int)ops[i].size(); ++j) {
        vec[ops[i][j]] = j >= (int)ops[i].size() - cur - cn;
      }
      rec(i + 1);
    }
  };
  rec(0);
  cout << "ACCEPTED\n";
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

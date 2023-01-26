#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string N = to_string(n);
    set<char> have;
    int p = N.size();
    for (int i = 0; i < (int)N.size(); i++) {
      have.insert(N[i]);
      if ((int)have.size() == k + 1) {
        p = i;
        have.erase(N[i]);
        break;
      }
    }
    if (p == (int)N.size()) {
      cout << N << "\n";
      continue;
    }
    assert((int)have.size() == k);
    vector<string> ans;
    for (auto v : have) {
      string base;
      base += v;
      string t = N.substr(0, p);
      if (t.size() < N.size()) {
        t += base;
      }
      while (t.size() < N.size()) {
        t += *have.begin();
      }
      ans.push_back(t);
    }
    const string INF = "9999999999999999999999";
    string my_ans = INF;
    for (auto s : ans) {
      if (s >= N) {
        my_ans = min(my_ans, s);
      }
    }
    if (my_ans == INF) {
      for (int d = 0; d < (int)N.size(); d++) {
        string t = N.substr(0, d);
        t += N[d] + 1;
        set<char> have;
        for (int i = 0; i < d; i++) {
          have.insert(N[i]);
        }
        have.insert(N[d] + 1);
        if ((int)have.size() < k) {
          have.insert('0');
        }
        if ((int)have.size() > k) {
          continue;
        }
        while (t.size() < N.size()) {
          t += *have.begin();
        }
        if (t >= N) {
          my_ans = min(my_ans, t);
        }
      }
    }
    cout << my_ans << "\n";
  }
  return 0;
}

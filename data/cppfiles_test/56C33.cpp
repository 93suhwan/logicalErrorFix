#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  map<long long, map<char, long long>> ans;
  long long k, n;
  cin >> k >> n;
  map<long long, char> fix;
  vector<long long> adj[k + 1];
  for (int i = 0; i < n; i++) {
    long long a;
    string s;
    cin >> a >> s;
    long long b = a, cnt = 0;
    while (b) {
      b = b >> 1;
      cnt++;
    }
    adj[cnt].push_back(a);
    fix[a] = s[0];
  }
  char all[] = {'w', 'y', 'g', 'b', 'r', 'o'};
  char ded = fix[-1];
  vector<long long> node;
  for (int j = k; j > 0; j--) {
    vector<long long> cur = node;
    node.clear();
    for (long long v : cur) {
      node.push_back(v >> 1);
    }
    for (auto u : adj[j]) node.push_back(u);
    sort(node.begin(), node.end());
    node.erase(unique(node.begin(), node.end()), node.end());
    for (long long v : node) {
      if (j == k) {
        char c = fix[v];
        ans[v][c] = ans[v]['#'] = 1;
        continue;
      }
      ans[v]['#'] = 1;
      long long cele1, cele2;
      cele1 = v << 1, cele2 = (v << 1) + 1;
      if (!ans[cele1]['#']) cele1 = 0;
      if (!ans[cele2]['#']) cele2 = 0;
      ans[v]['#'] = 1;
      for (int i = 0; i < 6; i++) {
        if (fix[v] != ded && fix[v] != all[i]) continue;
        char opp;
        if (i % 2)
          opp = all[i - 1];
        else
          opp = all[i + 1];
        long long res = 0;
        for (int l = 0; l < 6; l++) {
          if (all[l] == all[i] || all[l] == opp) continue;
          res = (res + ans[cele2][all[l]]) % mod;
        }
        for (int l = 0; l < 6; l++) {
          if (all[l] == all[i] || all[l] == opp) continue;
          ans[v][all[i]] =
              (ans[v][all[i]] + (res * ans[cele1][all[l]]) % mod) % mod;
        }
      }
    }
    if (j == k) {
      for (int i = 0; i < 6; i++) {
        ans[0][all[i]] = 1;
      }
      ans[0]['#'] = 1;
    } else {
      long long sev[7];
      for (int i = 0; i < 6; i++) {
        char opp;
        if (i % 2)
          opp = all[i - 1];
        else
          opp = all[i + 1];
        long long res = 0;
        for (int l = 0; l < 6; l++) {
          if (all[l] == all[i] || all[l] == opp) continue;
          res = (res + ans[0][all[l]]) % mod;
        }
        sev[i] = (res * res) % mod;
      }
      for (int i = 0; i < 6; i++) {
        ans[0][all[i]] = sev[i];
      }
    }
  }
  long long x = 0;
  for (int i = 0; i < 6; i++) {
    x = (x + ans[1][all[i]]) % mod;
  }
  cout << x << "\n";
  return 0;
}

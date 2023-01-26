#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
const long long mod = 1e9 + 7;
const int maxn = 2e5 + 10;
long long exp(long long x, long long pow) {
  if (pow == 0) {
    return 1;
  } else if (pow == 1) {
    return x;
  } else if (pow % 2 == 0) {
    return exp((x * x) % mod, pow / 2);
  } else if (pow % 2 == 1) {
    return (x * exp((x * x) % mod, (pow - 1) / 2)) % mod;
  }
}
int main() {
  long long k, n;
  cin >> k >> n;
  map<string, int> cmap;
  cmap["white"] = 0;
  cmap["green"] = 1;
  cmap["red"] = 2;
  cmap["yellow"] = 3;
  cmap["blue"] = 4;
  cmap["orange"] = 5;
  long long max_node = (1 << k) - 1;
  set<long long> set_nodes;
  map<long long, string> mp;
  long long one_choices = 6;
  for (int i = 0; i < n; i++) {
    long long node;
    string s;
    cin >> node >> s;
    set_nodes.insert(node);
    mp[node] = s;
  }
  map<long long, vector<long long>> m;
  for (auto [node, s] : mp) {
    if (node == 1) {
      one_choices = 1;
    }
    if (2 * node <= max_node) {
      if (set_nodes.find(2 * node) == set_nodes.end()) {
        m[2 * node].push_back(cmap[s]);
      } else {
        if ((cmap[mp[2 * node]] == cmap[mp[node]]) ||
            (cmap[mp[2 * node]] == (cmap[mp[node]] + 3) % 6)) {
          cout << 0 << endl;
          return 0;
        }
      }
    }
    if (2 * node + 1 <= max_node) {
      if (set_nodes.find(2 * node + 1) == set_nodes.end()) {
        m[2 * node + 1].push_back(cmap[s]);
      } else {
        if ((cmap[mp[2 * node + 1]] == cmap[mp[node]]) ||
            (cmap[mp[2 * node + 1]] == (cmap[mp[node]] + 3) % 6)) {
          cout << 0 << endl;
          return 0;
        }
      }
    }
    if (node > 1) {
      if (set_nodes.find(node / 2) == set_nodes.end()) {
        m[node / 2].push_back(cmap[s]);
      } else {
        if ((cmap[mp[node / 2]] == cmap[mp[node]]) ||
            (cmap[mp[node / 2]] == (cmap[mp[node]] + 3) % 6)) {
          cout << 0 << endl;
          return 0;
        }
      }
    }
  }
  vector<int> new_choices;
  for (auto [node, colors] : m) {
    set<int> avail_colors = {0, 1, 2, 3, 4, 5};
    for (auto c : colors) {
      avail_colors.erase(c);
      avail_colors.erase((c + 3) % 6);
    }
    new_choices.push_back(avail_colors.size());
    if (node == 1) {
      one_choices = avail_colors.size();
    }
  }
  long long ans = 1;
  for (auto choices : new_choices) {
    ans *= (long long)choices;
    ans %= mod;
  }
  ans *= exp(4, (1LL << k) - 2 - (long long)new_choices.size() - (long long)n +
                    (one_choices == 1 ? 1 : 0));
  ans %= mod;
  ans *= one_choices;
  ans %= mod;
  cout << ans << endl;
}

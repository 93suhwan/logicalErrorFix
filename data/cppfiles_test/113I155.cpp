#include <bits/stdc++.h>
using namespace std;
template <typename T>
void show(vector<T> x) {
  for (auto e : x) {
    cout << e << " ";
  }
  cout << endl;
}
template <typename T1>
void showPair(vector<pair<T1, T1>> x) {
  for (auto e : x) {
    cout << e.first << " " << e.second << endl;
  }
}
template <typename T2>
void showSet(set<T2> x) {
  for (auto e : x) {
    cout << e << " ";
  }
  cout << endl;
}
template <typename T3>
void showMultiSet(multiset<T3> x) {
  for (auto e : x) {
    cout << e << " ";
  }
  cout << endl;
}
template <typename T4>
void showSetPair(set<T4> x) {
  for (auto e : x) {
    cout << "{" << e.first << " " << e.second << "}, ";
  }
  cout << endl;
}
template <typename T5>
void showSinglePair(pair<T5, T5> P) {
  cout << P.first << " " << P.second << "\n";
}
vector<long long> dx = {1, -1};
bool isValid(long long i, long long n) { return (i >= 0 && i < n); }
long long seal(long long a, long long b) {
  if (a < 0 && b < 0) {
    return (a + b - 1) / b;
  }
  if (a < 0 || b < 0) {
    return (a / b);
  }
  return (a + b - 1) / b;
}
const long long mod = 998244353;
void dfs(long long u, vector<vector<long long>>& gr, vector<bool>& vis,
         vector<long long>& d) {
  for (auto v : gr[u]) {
    if (!vis[v]) {
      d.push_back(v);
      vis[v] = 1;
      dfs(v, gr, vis, d);
    }
  }
}
void solve() {
  long long x[2], p[2];
  cin >> x[0] >> p[0];
  cin >> x[1] >> p[1];
  long long digits[2];
  for (long long i = 0; i < 2; i++) {
    digits[i] = 0;
    while (x[i] > 0) {
      if (x[i] % 10 == 0) {
        p[i]++;
        x[i] = x[i] / 10;
      } else {
        break;
      }
    }
    digits[i] = p[i];
    long long y = x[i];
    while (y > 0) {
      y = y / 10;
      digits[i]++;
    }
  }
  if (digits[0] == digits[1]) {
    string s[2];
    s[0] = to_string(x[0]);
    s[1] = to_string(x[1]);
    if (s[0] == s[1]) {
      cout << "=\n";
      return;
    } else {
      for (long long i = 0; i < s[0].size() && s[1].size(); i++) {
        if (s[0][i] == s[1][i]) continue;
        if (s[0][i] > s[1][i]) {
          cout << ">\n";
          return;
        } else {
          cout << "<\n";
          return;
        }
        if (s[0].size() > s[1].size()) {
          cout << ">\n";
          return;
        } else if (s[0].size() < s[1].size()) {
          cout << "<\n";
          return;
        }
      }
    }
  } else if (digits[0] < digits[1]) {
    cout << "<\n";
  } else {
    cout << ">\n";
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}

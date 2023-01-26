#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const long long INF = 2e18;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<char> order;
    long long n = s.size();
    set<char> used;
    map<char, long long> ct;
    for (long long i = n - 1; i >= 0; i--) {
      if (!used.count(s[i])) order.push_back(s[i]);
      used.insert(s[i]);
      ct[s[i]]++;
    }
    bool bad = false;
    long long m = order.size();
    long long x = 0;
    for (long long i = 0; i < m; i++) {
      if (ct[order[i]] % (m - i) != 0) {
        bad = true;
        break;
      }
      x += ct[order[i]] / (m - i);
    }
    if (bad)
      cout << -1 << "\n";
    else {
      reverse(order.begin(), order.end());
      string a = s.substr(0, x), b = "";
      for (auto it : order) {
        b += a;
        string curr = "";
        for (auto& jt : a) {
          if (jt == it) continue;
          curr += jt;
        }
        a = curr;
      }
      if (s != b)
        cout << -1 << "\n";
      else {
        cout << s.substr(0, x) << " ";
        for (auto it : order) cout << it;
        cout << "\n";
      }
    }
  }
  return 0;
}

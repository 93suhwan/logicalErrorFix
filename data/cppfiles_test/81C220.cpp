#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
void count(long long int a, long long int b, set<long long int> &s) {
  long long int n = (a + b + 1) / 2;
  for (long long int i = 0; i < n + 1; i++) {
    long long int al = n - i;
    long long int aw = i;
    long long int bl = a - i;
    if (i <= a && bl <= n - (a + b) % 2) {
      long long int brk = al + bl;
      s.insert(brk);
    }
  }
}
bool yes(long long int mid, vector<vector<long long int>> &adj,
         vector<pair<long long int, long long int>> &halla) {
  for (long long int i = 0; i < (adj).size(); i++) {
    for (long long int j = 0; j < (adj[halla[i].second]).size(); j++) {
      if (mid <= adj[halla[i].second][j]) return false;
      mid++;
    }
  }
  return true;
}
int main() {
  fastio();
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<long long int> p(n + 1, 0);
    for (long long int i = 0; i < n; i++) {
      if (s[i] == '+')
        p[i + 1]++;
      else
        p[i + 1]--;
      p[i + 1] -= p[i];
    }
    for (long long int i = 0; i < q; i++) {
      long long int l, r;
      cin >> l >> r;
      long long int y = p[r] - p[l - 1];
      if (y == 0)
        cout << 0;
      else if ((r - l + 1) % 2)
        cout << 1;
      else
        cout << 2;
      cout << "\n";
      ;
    }
    cout << "\n";
    ;
  }
  return 0;
}

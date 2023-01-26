#include <bits/stdc++.h>
using namespace std;
long long int rate(vector<vector<int>> &a, vector<int> &b) {
  long long int str = 0;
  for (int i = 0; i <= a.size() - 1; i++) {
    str += a[i][b[i]];
  }
  return str;
}
string ban_string(vector<int> &b) {
  string s = "";
  for (int i = 0; i <= b.size() - 1; i++) {
    s += to_string(b[i]);
    s += '-';
  }
  return s;
}
void r(vector<vector<int>> &a, vector<int> &b, unordered_set<string> &checked,
       unordered_set<string> &banned, vector<int> &best_b,
       long long int &best_str) {
  string bs = ban_string(b);
  if (checked.find(bs) == checked.end()) {
    if (banned.find(bs) == banned.end()) {
      long long int r = rate(a, b);
      if (r >= best_str) {
        best_str = r;
        best_b = b;
      }
    }
  }
  for (int i = 0; i <= a.size() - 1; i++) {
    if (b[i] + 1 < a[i].size()) {
      b[i]++;
      string _bs = ban_string(b);
      if (banned.find(_bs) == banned.end()) {
        r(a, b, checked, banned, best_b, best_str);
      }
      b[i]--;
    }
  }
  checked.insert(bs);
}
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  vector<int> c(n);
  for (int i = 0; i <= n - 1; i++) {
    cin >> c[i];
    a[i].resize(c[i]);
    for (int j = 0; j <= c[i] - 1; j++) {
      cin >> a[i][j];
    }
  }
  int m;
  cin >> m;
  if (m == 0) {
    long long int sum = 0;
    for (int i = 0; i <= n - 1; i++) {
      sum += a[i].back();
    }
    cout << sum << "\n";
    return;
  }
  queue<vector<int>> q;
  unordered_set<string> banned;
  unordered_set<string> checked;
  vector<vector<int>> b(m, vector<int>(n));
  vector<int> best_b(n, 0);
  long long int best_str = -1;
  for (int i = 0; i <= m - 1; i++) {
    for (int j = 0; j <= n - 1; j++) {
      cin >> b[i][j];
      b[i][j]--;
    }
    string bs = ban_string(b[i]);
    banned.insert(bs);
  }
  for (int i = 0; i <= m - 1; i++) {
    for (int j = 0; j <= n - 1; j++) {
      if (b[i][j] - 1 >= 0) {
        b[i][j]--;
        string bs = ban_string(b[i]);
        if (banned.find(bs) == banned.end()) {
          r(a, b[i], checked, banned, best_b, best_str);
        }
        b[i][j]++;
      }
    }
  }
  for (int i = 0; i <= m - 1; i++) {
    r(a, b[i], checked, banned, best_b, best_str);
  }
  for (int i = 0; i <= n - 1; i++) {
    cout << best_b[i] + 1 << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}

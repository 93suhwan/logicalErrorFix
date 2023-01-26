#include <bits/stdc++.h>
using namespace std;
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
int ord[12], qtd[12];
bool adj[15][15];
bool check(string &s) {
  for (int i = 0; i < (int)s.size(); i++) {
    ord[i] = i;
  }
  sort(ord, ord + (int)s.size(), [&](int a, int b) { return s[a] < s[b]; });
  for (int i = 0; i < (int)s.size(); i += 2) {
    if (i + 2 == (int)s.size()) {
      if (!adj[ord[i]][ord[i + 1]]) return false;
    } else {
      int a = ord[i];
      int b = ord[i + 1];
      int c = ord[i + 2];
      int d = ord[i + 3];
      if (!((adj[a][c] && adj[b][d]) || (adj[a][d] && adj[b][c]))) {
        return false;
      }
    }
  }
  return true;
}
array<char, 12> normalize(string &s) {
  for (int i = 0; i <= 6; i++) {
    ord[i] = 0;
  }
  array<char, 12> ss;
  for (int i = 0, cnt = 0; i < (int)s.size(); i++) {
    if (!ord[s[i] - '0']) ord[s[i] - '0'] = ++cnt;
    ss[i] = char('0' + ord[s[i] - '0']);
  }
  return ss;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a - 1][b - 1] = adj[b - 1][a - 1] = true;
  }
  string s;
  for (int i = 1; i <= n / 2; i++) {
    s.push_back(char('0' + i));
    s.push_back(char('0' + i));
  }
  set<array<char, 12>> vis;
  queue<array<char, 12>> q;
  do {
    if (check(s)) {
      array<char, 12> ns = normalize(s);
      if (!vis.count(ns)) {
        q.push(ns);
        vis.insert(ns);
      }
    }
  } while (next_permutation(s.begin(), s.end()));
  while (!q.empty()) {
    auto ss = q.front();
    q.pop();
    char mx = '0';
    for (int i = 0; i < n; i++) {
      mx = max(mx, ss[i]);
    }
    qtd[mx - '0']++;
    array<char, 12> aux;
    for (char i = '1'; i <= mx; i++) {
      for (char j = char(i + 1); j <= mx; j++) {
        for (int l = 0; l < n; l++) {
          aux[l] = (ss[l] == j ? i : (ss[l] > j ? char(ss[l] - 1) : ss[l]));
        }
        if (!vis.count(aux)) {
          q.push(aux);
          vis.insert(aux);
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n / 2; i++) {
    long long cost = 1;
    for (int j = k; j >= k - i + 1; j--) {
      cost *= j;
    }
    ans += qtd[i] * cost;
  }
  cout << ans << '\n';
  return 0;
}

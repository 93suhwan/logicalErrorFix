#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long N = 2e6 + 9;
long long Min(long long a, long long b) { return a > b ? b : a; }
long long Max(long long a, long long b) { return a > b ? a : b; }
long long swapp(long long &a, long long &b) {
  long long temp = a;
  a = b;
  b = temp;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
string mp[N], vis[N];
struct node {
  long long x, y;
};
long long dx[4] = {0, 0, 1, -1};
long long dy[4] = {1, -1, 0, 0}, n, m;
bool inmap(long long x, long long y) {
  if (x < 1 || x > n) return 0;
  if (y < 1 || y > m) return 0;
  return 1;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> mp[i];
      mp[i] = "?" + mp[i];
      vis[i] = mp[i];
    }
    long long lx, ly;
    for (int i = 1; i <= n; i++)
      for (int k = 1; k <= m; k++)
        if (mp[i][k] == 'L') {
          lx = i, ly = k;
          break;
        }
    queue<node> q;
    q.push({lx, ly});
    while (!q.empty()) {
      node p = q.front();
      q.pop();
      if (vis[p.x][p.y] == '+') continue;
      vis[p.x][p.y] = '+';
      long long tx[4], ty[4], ttx[4], tty[4], cnt = 0;
      for (int i = 0; i < 4; i++) {
        tx[i] = p.x + dx[i];
        ty[i] = p.y + dy[i];
        if (!inmap(tx[i], ty[i]) || mp[tx[i]][ty[i]] == '#') continue;
        cnt = 0;
        for (int k = 0; k < 4; k++) {
          ttx[k] = tx[i] + dx[k];
          tty[k] = ty[i] + dy[k];
          if (inmap(ttx[k], tty[k]) && mp[ttx[k]][tty[k]] != '#') cnt++;
        }
        if (cnt <= 2 && vis[tx[i]][ty[i]] != '+') q.push({tx[i], ty[i]});
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int k = 1; k <= m; k++)
        if (mp[i][k] == 'L' || mp[i][k] == '#')
          cout << mp[i][k];
        else {
          if (vis[i][k] == '+')
            cout << vis[i][k];
          else
            cout << mp[i][k];
        }
      cout << "\n";
    }
  }
  return 0;
}

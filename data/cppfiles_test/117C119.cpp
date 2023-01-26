#include <bits/stdc++.h>
using namespace std;
long long inf = 1e19, mod = 1e9 + 7;
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2) res = (res * a) % mod;
    b /= 2;
    a = (a * a) % mod;
  }
  return res;
}
long long isprm(long long num) {
  for (long long i = 2; i * i <= num; i++)
    if (num % i == 0) return 0;
  return 1;
}
long long par[1005], rn[1005], sz[1005], ma = -1;
long long fin(long long num) {
  if (par[num] != num) par[num] = fin(par[num]);
  return par[num];
}
long long uni(long long a, long long b) {
  long long par1 = fin(a), par2 = fin(b);
  if (par1 == par2) return 0;
  if (rn[par1] < rn[par2]) {
    par[par1] = par2;
    sz[par2] += sz[par1];
    ma = max(ma, sz[par2]);
  } else if (rn[par1] > rn[par2]) {
    par[par2] = par1;
    sz[par1] += sz[par2];
    ma = max(ma, sz[par1]);
  } else {
    par[par2] = par1;
    sz[par1] += sz[par2];
    rn[par1]++;
    ma = max(ma, sz[par1]);
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  vector<pair<long long, long long>> itr = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  pair<long long, long long> curr;
  pair<long long, long long> nex;
  queue<pair<long long, long long>> qu;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    string arr[n];
    for (auto &it : arr) cin >> it;
    long long pos[n][m], vis[n][m];
    long long sum = 0, flg = 0;
    for (long long i = 0; i < n; i++)
      for (long long j = 0; j < m; j++) {
        vis[i][j] = 0;
        pos[i][j] = 0;
        if (arr[i][j] == 'L') qu.push({i, j});
        if (arr[i][j] == '.')
          for (long long k = 0; k < 4; k++) {
            nex = {i + itr[k].first, j + itr[k].second};
            if (!(nex.first < n && nex.second < m && nex.first >= 0 &&
                  nex.second >= 0))
              continue;
            if (arr[nex.first][nex.second] != '#') pos[i][j]++;
          }
      }
    curr = qu.front();
    vis[curr.first][curr.second] = 1;
    while (!qu.empty()) {
      curr = qu.front();
      qu.pop();
      sum = 0;
      flg = 0;
      for (long long i = 0; i < 4; i++) {
        nex = {curr.first + itr[i].first, curr.second + itr[i].second};
        if (!(nex.first < n && nex.second < m && nex.first >= 0 &&
              nex.second >= 0))
          continue;
        if (vis[nex.first][nex.second] || arr[nex.first][nex.second] == '#')
          continue;
        pos[nex.first][nex.second]--;
        if (pos[nex.first][nex.second] <= 1)
          qu.push(nex), vis[nex.first][nex.second] = 1;
      }
    }
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (arr[i][j] == 'L')
          cout << arr[i][j];
        else if (vis[i][j] && pos[i][j] <= 1)
          cout << "+";
        else
          cout << arr[i][j];
      }
      cout << "\n";
    }
  }
  return 0;
}

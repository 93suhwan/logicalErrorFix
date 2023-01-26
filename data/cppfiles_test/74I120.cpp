#include <bits/stdc++.h>
using namespace std;
int n, a[1003];
map<pair<int, int>, int> mp;
vector<int> v[2];
bool vis[1003];
void calc(int x, int y) {
  v[1].clear();
  for (int i = 0; i < n; i++)
    if (i < 22 && (x & (1 << i)))
      v[0].push_back(i), vis[i] = 1;
    else if (i < 22 && (y & (1 << i))) {
      v[1].push_back(i);
      vis[i] = 1;
    }
  int nw = 0;
  cout << "YES\n";
  for (int i = 0; i < 2 * v[0].size(); i++) {
    cout << nw << ' ';
    nw = v[i % 2][i / 2] - nw;
  }
  for (int i = 0; i < n; i++)
    if (!vis[i]) cout << a[i] << ' ';
  exit(0);
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v[a[i] & 1].push_back(i);
  }
  if (n == 2) {
    if (a[0] == a[1]) {
      cout << "YES\n";
      cout << 0 << ' ' << a[0];
    } else
      cout << "NO";
    return 0;
  }
  if (n == 3) {
    if (v[0].size() % 2 == 0 && a[0] != a[1] && a[0] != a[2] && a[1] != a[2]) {
      cout << "NO";
      return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (a[i] == a[j]) {
          cout << 0 << ' ' << a[i] << ' ' << a[3 - i - j];
          return 0;
        }
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    sum /= 2;
    for (int i = 0; i < n; i++) cout << sum - a[i] << ' ';
    return 0;
  }
  int hasfixed = -1, sum = 0;
  if (v[0].size()) {
    cout << "YES\n";
    sum = a[v[0][0]];
    vis[v[0][0]] = 1;
    if (v[0].size() > 2) {
      sum += a[v[0][1]] + a[v[0][2]];
      vis[v[0][1]] = 1;
      vis[v[0][2]] = 1;
    } else {
      sum += a[v[1][0]] + a[v[1][1]];
      vis[v[1][0]] = 1;
      vis[v[1][1]] = 1;
    }
    sum /= 2;
    hasfixed = sum - a[v[0][0]];
    for (int i = 0; i < n; i++)
      if (vis[i])
        cout << sum - a[i] << ' ';
      else
        cout << a[i] - hasfixed << ' ';
    cout << endl;
  }
  for (int i = 0; i < (1 << min(n, 22)); i++) {
    int cnt = 0, Cnt = __builtin_popcount(i);
    for (int j = 0; j < min(n, 22); j++)
      if (i & (1 << j)) cnt += a[j];
    if (mp[make_pair(Cnt, cnt)]) {
      int gcd = i & mp[make_pair(Cnt, cnt)];
      i ^= gcd;
      mp[make_pair(Cnt, cnt)] ^= gcd;
      calc(i, mp[make_pair(Cnt, cnt)]);
    } else
      mp[make_pair(Cnt, cnt)] = i + 1;
  }
  cout << "NO";
}

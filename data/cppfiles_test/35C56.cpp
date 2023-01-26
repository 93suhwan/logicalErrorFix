#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> fac[1000005];
bool comp[1000005];
int n;
int arr[1000005];
vector<pair<int, int>> pos[1000005];
string s;
map<int, int> good[1000005];
long long ans = 0;
vector<int> p;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 2; i <= 1000000; i++) {
    if (comp[i]) {
      continue;
    }
    for (int j = i; j <= 1000000; j += i) {
      comp[j] = true;
      int x = j, cnt = 0;
      while (x % i == 0) {
        x /= i;
        cnt++;
      }
      fac[j].push_back({i, cnt});
    }
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    for (pair<int, int> j : fac[arr[i]]) {
      pos[j.first].push_back({i, j.second});
    }
  }
  cin >> s;
  for (int i = 2; i <= 1000000; i++) {
    vector<int> k = {0};
    for (int j = 0; j < pos[i].size(); j++) {
      int x = pos[i][j].first;
      if (s[x - 1] == '*') {
        for (int it = 1; it <= pos[i][j].second; it++) {
          k.push_back(x);
        }
      } else {
        for (int it = 2; it <= pos[i][j].second and k.size() > 1; it++) {
          k.pop_back();
        }
        good[i][x] = k[k.size() - 1];
        if (k.size() > 1) {
          k.pop_back();
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    p.push_back(i);
    if (s[i - 1] == '/') {
      int x = 2e9;
      for (pair<int, int> j : fac[arr[i]]) {
        x = min(x, good[j.first][i]);
      }
      while (p.size() > 0 and p[p.size() - 1] > x) {
        p.pop_back();
      }
    }
    long long siz = p.size();
    ans += siz;
  }
  cout << ans << "\n";
  return 0;
}

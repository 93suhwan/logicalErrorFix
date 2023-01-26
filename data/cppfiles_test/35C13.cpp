#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10, M = 1e6 + 137;
int pr[M], a[M], till[M], res[M];
string op;
map<int, int> mp[M];
void merge(int i, int j) {
  if (mp[i].size() < mp[j].size()) {
    mp[i].swap(mp[j]);
  }
  for (pair<long long, long long> u : mp[j]) mp[i][u.first] += u.second;
  mp[j].clear();
}
bool divide(int i, int j) {
  for (pair<long long, long long> u : mp[j]) {
    if (mp[i][u.first] < u.second) return 0;
  }
  for (pair<long long, long long> u : mp[j]) mp[i][u.first] -= u.second;
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fill(pr, pr + M, INF);
  for (int i = 2; i <= 1e6; i++) {
    if (pr[i] == INF) {
      for (int j = i; j <= 1e6; j += i) pr[j] = min(pr[j], i);
    }
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int x = a[i];
    while (x > 1) {
      mp[i][pr[x]]++;
      x /= pr[x];
    }
  }
  cin >> op;
  for (int i = 0; i < n; i++) {
    if (op[i] == '/' && a[i] == 1) op[i] = '*';
  }
  till[n] = n;
  long long ans = 0;
  for (int i = n - 1; ~i; i--) {
    if (op[i] == '*') {
      till[i] = i + 1;
      while (till[i] != n) {
        if (till[till[i]] != till[i]) {
          merge(i, till[i]);
          till[i] = till[till[i]];
        } else {
          if (divide(i, till[i])) {
            till[i] = till[i] + 1;
          } else {
            break;
          }
        }
      }
    } else {
      till[i] = i;
    }
    ans += till[i] - i;
  }
  cout << ans;
}

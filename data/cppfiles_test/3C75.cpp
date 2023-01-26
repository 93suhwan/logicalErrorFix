#include <bits/stdc++.h>
using namespace std;
long long to_num(string second) {
  long long ans = 0, mul = 1;
  reverse(second.begin(), second.end());
  for (int i = 0; i <= (int)second.size() - 1; i++)
    ans += mul * (second[i] - '0'), mul *= 10;
  return ans;
}
long long tot(string second, int id, int X) {
  if (id == second.size()) {
    if (to_num(second) % 25 == 0) return 1;
    return 0;
  }
  long long ans = 0;
  if (second[id] == '_') {
    if (id) second[id] = '0', ans += tot(second, id + 1, X);
    for (int i = 1; i <= 9; i++)
      second[id] = '0' + i, ans += tot(second, id + 1, X);
  } else if (second[id] == 'X') {
    if (X == -1) {
      if (id) second[id] = '0', ans += tot(second, id + 1, 0);
      for (int i = 1; i <= 9; i++)
        second[id] = '0' + i, ans += tot(second, id + 1, i);
    } else
      second[id] = '0' + X, ans = tot(second, id + 1, X);
  } else
    ans = tot(second, id + 1, X);
  return ans;
}
void solve1(string second) {
  if ((int)second.size() == 1) {
    if (second[0] == '0' || second[0] == 'X' || second[0] == '_')
      cout << 1;
    else
      cout << 0;
    return;
  }
  if (second[0] == '0') {
    cout << 0;
    return;
  }
  cout << tot(second, 0, -1);
}
void solve() {
  string second;
  cin >> second;
  int n = second.size();
  if (n <= 2) {
    solve1(second);
    return;
  }
  int ans = 0, flag;
  char X;
  for (int i = pow(10, n - 1); i < pow(10, n); i += 25) {
    string t = to_string(i);
    flag = 1, X = 'a';
    for (int j = 0; j <= n - 1; j++) {
      if (second[j] != '_' && second[j] != 'X' && second[j] != t[j]) {
        flag = 0;
        break;
      }
      if (second[j] == 'X' && X != 'a') {
        if (t[j] != X) {
          flag = 0;
          break;
        }
      } else if (second[j] == 'X')
        X = t[j];
    }
    ans += flag;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<long long int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  long long int sur = 0;
  vector<int> ans;
  for (int mask = 0; mask < (1 << (n - 1)); mask++) {
    int lo = 1, hi = m;
    int lo2 = 1, hi2 = m;
    vector<int> cnt(m, 0);
    vector<bool> stat(n);
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i))
        stat[i] = true;
      else
        stat[i] = false;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '1') {
          cnt[j] += (stat[i] ? 1 : -1);
        }
      }
    }
    set<pair<int, int>> temp1, temp2;
    vector<int> tempAns(m, -1), tempAns2(m, -1);
    for (int i = 0; i < m; i++) {
      if (cnt[i] > 0)
        temp1.insert(make_pair(-cnt[i], i));
      else if (cnt[i] < 0)
        temp2.insert(make_pair(cnt[i], i));
    }
    for (auto it : temp1) {
      int index = it.second;
      tempAns[index] = hi--;
      tempAns2[index] = lo2++;
    }
    for (auto it : temp2) {
      int index = it.second;
      tempAns[index] = lo++;
      tempAns2[index] = hi2--;
    }
    for (int i = 0; i < m; i++) {
      if (tempAns[i] == -1) {
        tempAns[i] = lo++;
        tempAns2[i] = lo2++;
      }
    }
    long long int checkSur = 0, checkSur2 = 0;
    for (int i = 0; i < n; i++) {
      long long int score = 0;
      long long int score2 = 0;
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '1') {
          score += tempAns[j];
          score2 += tempAns2[j];
        }
      }
      checkSur += abs(a[i] - score);
      checkSur2 += abs(a[i] - score2);
    }
    if (checkSur > sur || mask == 0) {
      sur = checkSur;
      ans = move(tempAns);
    }
    if (checkSur2 > sur) {
      sur = checkSur2;
      ans = move(tempAns2);
    }
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

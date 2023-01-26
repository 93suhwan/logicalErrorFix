#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
bool mini(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
bool maxi(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
const int N = 1e6 + 5;
const int oo = 1e9;
const long long ooo = 1e18;
const int mod = 1e9 + 7;
const long double pi = 3.14159265359;
vector<vector<int>> a, minpre, minsuf, maxpre, maxsuf;
vector<int> row[N];
int n, m;
char ans[N];
void solve() {
  cin >> n >> m;
  a.assign(n + 2, vector<int>(m + 2, 0));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  minpre = minsuf = maxpre = maxsuf = a;
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
      maxi(maxpre[i][j], maxpre[i][j - 1]);
      mini(minpre[i][j], minpre[i][j - 1]);
    }
    for (int j = m - 1; j >= 1; j--) {
      maxi(maxsuf[i][j], maxsuf[i][j + 1]);
      mini(minsuf[i][j], minsuf[i][j + 1]);
    }
  }
  for (int k = 1; k < m; k++) {
    vector<int> val;
    multiset<int> red, blue;
    for (int i = 1; i <= n; i++) {
      ans[i] = 'R';
      red.insert(maxsuf[i][k + 1]);
    }
    for (int i = 1; i <= n; i++) {
      val.push_back(minpre[i][k] + 1);
      val.push_back(maxpre[i][k] + 1);
    }
    sort((val).begin(), (val).end());
    val.resize(unique((val).begin(), (val).end()) - val.begin());
    for (int x : val) row[x].clear();
    for (int i = 1; i <= n; i++) {
      row[minpre[i][k] + 1].push_back(-i);
      row[maxpre[i][k] + 1].push_back(i);
    }
    int cnt = n;
    for (int x : val) {
      for (int ind : row[x]) {
        if (ind < 0) {
          int i = -ind;
          red.erase(red.find(maxsuf[i][k + 1]));
          ans[i] = 0;
          cnt--;
        } else {
          int i = ind;
          blue.insert(minsuf[i][k + 1]);
          ans[i] = 'B';
          cnt++;
        }
      }
      if (blue.size() && red.size() && cnt == n) {
        if (*blue.begin() > *prev(red.end())) {
          cout << "YES\n";
          for (int i = 1; i <= n; i++) cout << ans[i];
          cout << " ";
          cout << k << "\n";
          return;
        }
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

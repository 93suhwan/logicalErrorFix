#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long, long>;
using plll = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vll = vector<ll>;
bool check(vector<vector<bool>>& table, int ff, int ss) {
  int left = 0, right = 0, mid = 0;
  for (int i = 0; i < table.size(); ++i) {
    if (table[i][ff] && table[i][ss]) {
      mid++;
    } else if (table[i][ff]) {
      left++;
    } else if (table[i][ss]) {
      right++;
    } else {
      return false;
    }
  }
  return !(left > table.size() / 2 || right > table.size() / 2);
}
void solve() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    vector<vector<bool>> table(n, vector<bool>(5));
    for (auto& line : table) {
      for (int j = 0; j < 5; ++j) {
        int tmp;
        cin >> tmp;
        line[j] = tmp == 1;
      }
    }
    bool found = false;
    for (int ff = 0; ff < 4 && !found; ++ff) {
      for (int ss = ff + 1; ss < 5 && !found; ++ss) {
        found = check(table, ff, ss);
      }
    }
    if (found) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}

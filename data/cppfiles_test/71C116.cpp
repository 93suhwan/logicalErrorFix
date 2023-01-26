#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
set<pair<int, string>> S;
void search(string cur, int i, int j) {
  S.insert({cur.size(), cur});
  if (cur.size() >= 10) return;
  if (cur.size() || i != 0) search(cur + char(i + '0'), i, j);
  if (cur.size() != 0 || j != 0) search(cur + char(j + '0'), i, j);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 0; i <= 9; ++i)
    for (int j = i; j <= 9; ++j) search("", i, j);
  int tt;
  cin >> tt;
  while (tt--) {
    string n, temp = "";
    int k;
    cin >> n >> k;
    if (k == 1) {
      for (int i = 1; i <= 9; ++i) {
        for (int j = 0; j < n.size(); ++j) {
          temp += char(i + '0');
        }
        if (temp >= n) {
          cout << temp;
          break;
        }
        temp = "";
      }
    } else {
      cout << S.lower_bound({n.size(), n})->second;
    }
    cout << '\n';
  }
}

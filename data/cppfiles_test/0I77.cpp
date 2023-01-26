#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int p = 0;
bool comp(string &x, string &y) { return x[p] > y[p]; }
bool comp2(string &x, string &y) { return x[p] < y[p]; }
template <typename T>
void printv(T &a) {
  for (auto it = a.begin(); it != a.end(); ++it) cout << *it << ' ';
  cout << '\n';
}
void sol2() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  map<string, int> mp;
  string s[n];
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    mp[s[i]] = i + 1;
  }
  sort(s, s + n, comp2);
  for (int i = 1; i < m; ++i) {
    int last = 0;
    for (int j = 1; j < n; ++j) {
      if (s[j][i - 1] != s[j - 1][i - 1]) {
        p = i;
        if (i % 2) {
          sort(s + last, s + j, comp);
        } else {
          sort(s + last, s + j, comp2);
        }
        last = j;
      }
    }
    if (i % 2) {
      sort(s + last, s + n, comp);
    } else {
      sort(s + last, s + n, comp2);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << mp[s[i]] << ' ';
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  sol2();
  return 0;
}

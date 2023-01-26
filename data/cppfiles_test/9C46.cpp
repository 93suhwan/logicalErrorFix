#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VL = vector<LL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
void dout() { cerr << endl; }
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
  cerr << H << ' ';
  dout(T...);
}
const int MAX = 1 << 10;
int a[MAX][MAX];
set<int> s[MAX];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) {
      cin >> a[i][j];
      if (a[i][j] != 2) s[j].insert(i);
    }
  while (k--) {
    int c;
    cin >> c;
    c--;
    int r = 0;
    while (true) {
      auto it = s[c].lower_bound(r);
      if (it == s[c].end()) break;
      int nr = *it;
      int& na = a[nr][c];
      s[c].erase(it);
      if (na == 1) {
        c++;
      } else {
        assert(na == 3);
        c--;
      }
      na = 2;
      r = nr;
    }
    cout << c + 1 << " ";
  }
  cout << "\n";
}

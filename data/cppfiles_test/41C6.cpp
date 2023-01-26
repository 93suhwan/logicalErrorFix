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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k, n;
  cin >> n >> k;
  int pw = 1, c = 0;
  while (pw < n) {
    pw *= k;
    c++;
  }
  for (int i = (0); i < (n); ++i) {
    int x = i;
    for (int j = (0); j < (c); ++j) {
      a[i][j] = x % k;
      x /= k;
    }
  }
  cout << c << "\n";
  for (int i = (0); i < (n); ++i) {
    for (int j = (i + 1); j < (n); ++j) {
      int col = 0;
      while (a[i][col] >= a[j][col]) col++;
      cout << col + 1 << " ";
    }
  }
}

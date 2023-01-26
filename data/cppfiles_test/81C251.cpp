#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int UP = 31500;
const double PI = acos(-1.0);
const double eps = -1e8;
struct node {
  int val;
  int idx;
  bool operator<(const node& B) const {
    return val == B.val ? idx < B.idx : val < B.val;
  }
};
vector<node> rep;
char c[N];
int sum[N];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    cin >> c + 1;
    for (int i = 1; i <= n; i++) {
      if (c[i] == '+')
        sum[i] = sum[i - 1] + 1 * pow(-1, i - 1);
      else
        sum[i] = sum[i - 1] - 1 * pow(-1, i - 1);
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      int x = sum[r] - sum[l - 1];
      if (!x)
        cout << "0" << '\n';
      else if (x % 2)
        cout << "1" << '\n';
      else
        cout << "2" << '\n';
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
void init_code() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
int main() {
  init_code();
  vector<int> v1, temp;
  map<int, int> m1;
  long long int diff, i, j, n, a, one, mid, b,
      count = 0, q, p, k, left, c = INT_MAX, d, pos, ans = INT_MAX, flag = 0, m,
      r;
  double tot = 0;
  string s;
  char ch;
  cin >> q;
  while (q--) {
    cin >> n;
    p = sqrt(n);
    if (n > (p * p)) {
      p = p + 1;
    }
    mid = (p * p) - (p - 1);
    if (n == mid) {
      cout << p << " " << 1 << endl;
    } else if (n > mid) {
      cout << p << " " << (p - (n - mid)) << endl;
    } else if (n < mid) {
      cout << (p - (mid - n)) << " " << p << endl;
    }
  }
}

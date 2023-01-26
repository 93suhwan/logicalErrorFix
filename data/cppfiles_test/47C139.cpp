#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
const int max_n = 10011, inf = 1000111222;
long long n, a[max_n], k, test_a[max_n];
bool debug = false;
int query(int x, int y, bool is_and) {
  if (is_and) {
    cout << "and ";
  } else {
    cout << "or ";
  }
  cout << x + 1 << " " << y + 1 << endl;
  if (debug) {
    cout << (is_and ? (test_a[x] & test_a[y]) : (test_a[x] | test_a[y]))
         << "\n";
    return is_and ? (test_a[x] & test_a[y]) : (test_a[x] | test_a[y]);
  }
  int ans;
  cin >> ans;
  return ans;
}
void find_abc() {
  int ab_a = query(0, 1, 1);
  int ac_a = query(0, 2, 1);
  int ab_o = query(0, 1, 0);
  int ac_o = query(0, 2, 0);
  int bc_a = query(1, 2, 1);
  int val_a = (ab_o & ac_o) - (bc_a) + (ab_a & ac_a);
  if (debug) {
    assert(val_a == test_a[0]);
  }
  a[0] = val_a;
  a[1] = val_a ^ (ab_o - ab_a);
  a[2] = val_a ^ (ac_o - ac_a);
}
int solve() {
  find_abc();
  for (int i = 3; i < n; ++i) {
    int and_val = query(0, i, 1);
    int or_val = query(0, i, 0);
    a[i] = a[0] ^ (or_val - and_val);
  }
  sort(a, a + n);
  return a[k - 1];
}
int main() {
  cin >> n >> k;
  int debug_ans = -1;
  if (debug) {
    for (int i = 0; i < n; ++i) {
      test_a[i] = i + 1;
    }
    debug_ans = test_a[k - 1];
    random_shuffle(test_a, test_a + n);
  }
  int ans = solve();
  cout << "finish " << ans << endl;
  if (debug && ans != debug_ans) {
    cout << "WA!!!\n" << ans << " " << debug_ans << "\n";
  }
  return 0;
}

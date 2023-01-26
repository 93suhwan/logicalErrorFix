#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long x = 1;
  long long num = 1;
  long long h = 0;
  while (num < n) {
    num += x;
    if (num < k) {
      x = num;
    } else {
      x = k;
      h++;
      break;
    }
    h++;
  }
  if (num < n) {
    long long c = num - n;
    h += ceil(c / k);
  }
  cout << h << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

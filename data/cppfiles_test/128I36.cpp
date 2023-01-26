#include <bits/stdc++.h>
using namespace std;
vector<long long> primos;
vector<long long> existe(1e5, 0);
void hallar_criba() {
  long long i, j;
  existe[1] = 1;
  for (i = 2; i <= sqrt(1e9); i++) {
    if (existe[i] == false) {
      existe[i] = true;
      primos.push_back(i);
      for (j = i + i; j <= sqrt(1e9);) {
        existe[j] = true;
        j += i;
      }
    }
  }
  primos.pop_back();
}
void solve() {
  long long n;
  cin >> n;
  n--;
  long long x = *(upper_bound(primos.begin(), primos.end(), n) - 1);
  long long y;
  if (n - x == 1 || n == x) {
    x = *(upper_bound(primos.begin(), primos.end(), n) - 2);
    y = n - x;
  } else {
    y = n - x;
  }
  cout << x << " " << y << " " << 1 << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  hallar_criba();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

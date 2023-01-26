#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
const long long INF = 1e18;
const long double EPS = 1e-9;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long random(long long a, long long b) {
  return uniform_int_distribution<long long>(a, b)(rng);
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long tt;
  cin >> tt;
  vector<long long> a;
  long long i = 1;
  while ((int)a.size() < 1000) {
    if (i % 3 != 0 && i % 10 != 3) {
      a.push_back(i);
    }
    i++;
  }
  while (tt--) {
    long long k;
    cin >> k;
    cout << a[k - 1] << '\n';
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9 + 7, MAX = 1e6 + 5;
const long long INF = 1e18 + 5;
int main() {
  int n;
  double p;
  cin >> n >> p;
  long long prob = (int)(p * 10000 + 0.5);
  long long ways = prob * n * (n - 1) * (n - 2);
  for (int i = 0; i <= n; i++) {
    long long way = 0;
    way += (long long)i * (i - 1) * (i - 2) + 3ll * i * (i - 1) * (n - i);
    way += 3ll * i * (n - i) * (n - i - 1) / 2;
    if (way * 10000 >= ways) {
      cout << i << endl;
      return 0;
    }
  }
}

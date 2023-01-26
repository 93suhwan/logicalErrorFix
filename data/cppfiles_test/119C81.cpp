#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 2 * 1e18 + 100;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (long long q = 0; q < t; q++) {
    int n;
    cin >> n;
    std::vector<long long> vec(n);
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      sum += temp - 1;
    }
    int out = sum % n == 0 ? 0 : 1;
    cout << out << endl;
  }
}

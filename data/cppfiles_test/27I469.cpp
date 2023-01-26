#include <bits/stdc++.h>
using namespace std;
long long int SUM(long long int n) { return ((n * (n + 1)) >> 1); }
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  long long int itr_i, itr_j, itr_l, itr_k;
  long long int testCases, num_n, num_k, num_m, minimum;
  cin >> testCases;
  while (testCases--) {
    cin >> num_n >> num_m >> num_k;
    num_k -= 2;
    if (num_k <= 0 or num_m < (num_n - 1)) {
      cout << "NO"
           << "\n";
      continue;
    }
    minimum = SUM(num_n - 1) - SUM(num_k - 1);
    if (num_m >= minimum)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}

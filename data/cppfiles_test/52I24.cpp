#include <bits/stdc++.h>
using namespace std;
vector<int> a;
void decToBinary(long long n) {
  a.clear();
  while (n > 0) {
    a.push_back(n % 2);
    n = n / 2;
  }
}
int main() {
  const unsigned int M = 1000000007;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    decToBinary(k);
    unsigned long long sum = 0, po = 1;
    for (auto it = a.begin(); it != a.end(); it++) {
      if (*it == 0) {
        po = po * n;
      } else {
        sum = sum + (po % M);
        po = po * n;
      }
    }
    sum = sum % M;
    cout << sum << "\n";
  }
}

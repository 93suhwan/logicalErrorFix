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
    int count = 0;
    long long n, k, po = 1;
    cin >> n >> k;
    decToBinary(k);
    long long sum = 0, add;
    for (auto it = a.begin(); it != a.end(); it++) {
      if (*it == 0) {
        po = po * n;
      } else {
        sum = sum + po;
        po = po * n;
      }
    }
    sum = sum % M;
    cout << sum << "\n";
  }
}

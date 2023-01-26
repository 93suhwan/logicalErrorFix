#include <bits/stdc++.h>
using namespace std;
int main() {
  const long long MOD = 1000000007;
  int t;
  cin >> t;
  for (int _t = 0; _t < t; _t++) {
    int n;
    cin >> n;
    int k;
    cin >> k;
    int binary_k[32];
    int powers_of_two[32];
    powers_of_two[0] = 1;
    for (int i = 1; i < 32; i++) {
      powers_of_two[i] = powers_of_two[i - 1] * 2;
    }
    for (int i = 31; i >= 0; i--) {
      binary_k[i] = k / powers_of_two[i];
      k %= powers_of_two[i];
    }
    long long counter = 0;
    long long kth_power_of_n = 1;
    for (int i = 0; i < 32; i++) {
      counter += binary_k[i] * kth_power_of_n;
      counter %= MOD;
      kth_power_of_n *= n;
      kth_power_of_n %= MOD;
    }
    cout << counter << endl;
  }
}

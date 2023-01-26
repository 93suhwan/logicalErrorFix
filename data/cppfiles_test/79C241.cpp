#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int flag = 0;
    string t;
    for (int i = 0; i < n; i++) {
      int x = s[i] - '0';
      if (x != 2 && x != 3 && x != 5 && x != 7) {
        t = s[i];
        flag++;
        break;
      }
    }
    if (flag > 0) {
      cout << 1 << "\n";
      cout << t << "\n";
      continue;
    }
    vector<string> not_primes;
    for (int i = 1; i < 100; i++) {
      if (!is_prime(i)) {
        not_primes.push_back(to_string(i));
      }
    }
    sort(not_primes.begin(), not_primes.end());
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        string k;
        k += s[i];
        k += s[j];
        auto it = lower_bound(not_primes.begin(), not_primes.end(), k);
        if (*it == k) {
          t = k;
          break;
        }
      }
    }
    cout << 2 << "\n";
    cout << t << "\n";
  }
}

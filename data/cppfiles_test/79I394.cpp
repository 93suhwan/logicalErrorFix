#include <bits/stdc++.h>
using namespace std;
vector<long long> primes;
void PrintPrimes(long long y, long long x) {
  bool isPrime = true;
  for (int t = y; t <= x; t++) {
    if (t == 2 || t == 3) primes.push_back(t);
    for (int i = 2; i * i <= t; i++) {
      if (t % i == 0) {
        break;
      } else if (i + 1 > sqrt(t)) {
        primes.push_back(t);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    string s;
    cin >> s;
    vector<long long> v;
    long long num = -1;
    long long sum = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
      if ((s[i] - '0') % 10 == 2 || (s[i] - '0') % 10 == 5 ||
          (s[i] - '0') % 10 == 3 || (s[i] - '0') % 10 == 7) {
        v.push_back((s[i] - '0') % 10);
        sum += (s[i] - '0') % 10;
      } else {
        num = (s[i] - '0') % 10;
      }
    }
    if (v.size() != k) {
      cout << 1 << "\n";
      cout << num << "\n";
    } else {
      bool nflag = true;
      long long ans1, ans2;
      for (int i = 0; i < v.size(); i++) {
        if (v[i] == 2) {
          for (int j = i + 1; j < v.size(); j++) {
            if (v[j] == 7 || v[j] == 3 || v[j] == 5 || v[j] == 2) {
              ans1 = v[j];
              ans2 = v[i];
              nflag = false;
              break;
            }
          }
        } else if (v[i] == 7) {
          for (int j = i + 1; j < v.size(); j++) {
            if (v[j] == 2 || v[j] == 7) {
              ans1 = v[j];
              ans2 = v[i];
              nflag = false;
              break;
            }
          }
        } else if (v[i] == 5) {
          for (int j = i + 1; j < v.size(); j++) {
            if (v[j] == 2 || v[j] == 7 || v[j] == 5 || v[j] == 3) {
              ans1 = v[j];
              ans2 = v[i];
              nflag = false;
              break;
            }
          }
        } else if (v[i] == 3) {
          for (int j = i + 1; j < v.size(); j++) {
            if (v[j] == 3) {
              ans1 = v[j];
              ans2 = v[i];
              nflag = false;
              break;
            }
          }
        }
        if (!nflag) break;
      }
      if (nflag) {
        cout << k << "\n";
        cout << s << "\n";
      } else {
        cout << 2 << "\n";
        cout << ans1 << ans2 << "\n";
      }
    }
  }
}

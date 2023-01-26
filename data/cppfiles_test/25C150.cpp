#include <bits/stdc++.h>
using namespace std;
bool prime[10000007];
void SieveOfEratosthenes() {
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p * p <= 10000007; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= 10000007; i += p) prime[i] = false;
    }
  }
}
long long int check(string s1, string s2, long long int i, long long int j) {
  if (j == s2.length()) return 1;
  long long int op1 = 0, op2 = 0;
  if (i - 1 >= 0 && s2[j] == s1[i - 1]) {
    op1 = check(s1, s2, i - 1, j + 1);
  }
  if (!op1 && i + 1 < s1.length() && s1[i + 1] == s2[j])
    op2 = check(s1, s2, i + 1, j + 1);
  else if (op1) {
    return 1;
  }
  return op1 || op2;
}
void solve() {
  string s1, s2, str;
  cin >> s1 >> s2;
  long long int k = 0;
  long long int ch = s2[0];
  for (long long int i = 0; i < s1.length(); i++) {
    if (s1[i] == ch) {
      for (long long int j = i; j < s1.length(); j++) {
        string sample;
        for (long long int k = i; k <= j; k++) {
          sample += s1[k];
          if (sample == s2) {
            cout << "YES"
                 << "\n";
            return;
          }
        }
        for (long long int x = j - 1; x >= 0; x--) {
          sample += s1[x];
          if (sample == s2) {
            cout << "YES"
                 << "\n";
            return;
          }
        }
      }
    }
  }
  cout << "NO"
       << "\n";
}
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
signed main() {
  init_code();
  long long int t = 1;
  cin >> t;
  long long int i = 1;
  while (t--) {
    solve();
    i++;
  }
  return 0;
}

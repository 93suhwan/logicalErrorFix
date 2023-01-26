#include <bits/stdc++.h>
long long hui;
using namespace std;
string s;
bool is_prime[1000];
void solve() {
  for (long long i = 0; i < hui; i++) {
    if (s[i] == '1' || s[i] == '4' || s[i] == '8' || s[i] == '9' ||
        s[i] == '6') {
      cout << "1" << endl << s[i] << endl;
      return;
      break;
    }
  }
  for (long long j = 0; j < hui; j++) {
    for (long long f = j + 1; f < hui; f++) {
      if (!is_prime[10 * (s[j] - '0') + s[f] - '0']) {
        cout << "2" << endl << s[j] << s[f] << endl;
        return;
      }
    }
  }
}
int main() {
  long long t;
  cin >> t;
  is_prime[0] = false;
  for (long long j = 1; j < 100; j++) {
    is_prime[j] = true;
    for (long long f = 2; f * f <= j; f++) {
      if (j % f == 0 && j != 2) {
        is_prime[j] = false;
        break;
      }
    }
  }
  for (long long i = 0; i < t; i++) {
    cin >> hui;
    cin >> s;
    solve();
  }
  return 0;
}

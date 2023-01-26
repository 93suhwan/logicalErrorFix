#include <bits/stdc++.h>
using namespace std;
void findNonPrime(int n, vector<bool>& prime, vector<int>& nonPrime) {
  nonPrime.push_back(1);
  for (int i = 2; i < n; i++) {
    if (prime[i] == true) {
      for (int j = 2 * i; j < n; j += i) {
        prime[j] = false;
      }
    }
  }
  for (int i = 3; i < n; i++) {
    if (prime[i] == false) {
      nonPrime.push_back(i);
    }
  }
}
bool findString(string s, string t) {
  int j = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == t[j]) {
      j++;
    }
    if (j == t.size()) {
      return true;
    }
  }
  return false;
}
int main() {
  vector<int> nonPrime;
  vector<bool> prime(102, true);
  findNonPrime(100, prime, nonPrime);
  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    int k;
    cin >> k;
    string s;
    cin >> s;
    string ans = "";
    for (int i = 0; i < nonPrime.size(); i++) {
      string t = to_string(nonPrime[i]);
      bool res = findString(s, t);
      if (res == true) {
        ans = t;
        break;
      }
    }
    cout << ans.size() << '\n';
    cout << ans << '\n';
  }
  return 0;
}

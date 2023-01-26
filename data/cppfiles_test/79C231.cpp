#include <bits/stdc++.h>
using namespace std;
bool izprime(long long n) {
  if (n == 1) return false;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void fun() {
  long long n;
  string s;
  cin >> n;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (!izprime(s[i] - 48)) {
      cout << 1 << endl;
      cout << (s[i] - 48) << endl;
      return;
    }
  }
  for (int i = 0; i < s.length(); i++) {
    for (int j = i + 1; j < s.length(); j++) {
      int x = s[i] - 48;
      int y = s[j] - 48;
      if (!izprime(x * 10 + y)) {
        cout << 2 << endl;
        cout << x * 10 + y << endl;
        return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) fun();
}

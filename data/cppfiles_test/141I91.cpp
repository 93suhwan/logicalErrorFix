#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
long long pow(long long p, long long n) {
  if (n == 0) return 1;
  if (n == 1) return p;
  long long temp = pow(p, n / 2);
  temp *= temp;
  if (n) temp *= p;
  return temp;
}
void solve() {
  long long a, s;
  cin >> a >> s;
  string temp;
  while (a > 0 && s > 0) {
    int comp = a % 10;
    int comp2 = s % 10;
    a /= 10;
    s /= 10;
    if (comp <= comp2) {
      temp += to_string(comp2 - comp);
    } else {
      int extra;
      if (s > 0) {
        extra = s % 10;
        s /= 10;
        extra = extra * 10 + comp2;
      }
      if (extra - comp < 10)
        temp += to_string(extra - comp);
      else {
        cout << "-1\n";
        return;
      }
    }
  }
  while (s > 0) {
    int comp2 = s % 10;
    s /= 10;
    temp += to_string(comp2);
  }
  if (a > 0) {
    cout << "-1\n";
    return;
  }
  reverse(temp.begin(), temp.end());
  while (temp[0] == '0') temp = temp.substr(1);
  cout << temp << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

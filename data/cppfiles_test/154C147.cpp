#include <bits/stdc++.h>
using namespace std;
string bintoString(long long x) { return bitset<64>(x).to_string(); }
inline int power(int a, int b) {
  int x = 1;
  while (b) {
    if (b & 1) x *= a;
    a *= a;
    b >>= 1;
  }
  return x;
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    if (a == b) {
      if (c % 2 == 0)
        cout << "YES"
             << "\n";
      else {
        cout << "NO"
             << "\n";
      }
    } else if (a == c) {
      if (b % 2 == 0)
        cout << "YES"
             << "\n";
      else {
        cout << "NO"
             << "\n";
      }
    } else if (b == c) {
      if (a % 2 == 0)
        cout << "YES"
             << "\n";
      else {
        cout << "NO"
             << "\n";
      }
    } else {
      long long m = max(a, max(b, c));
      if (m == a + c || m == b + c || m == a + b)
        cout << "YES"
             << "\n";
      else {
        cout << "NO"
             << "\n";
      }
    }
  }
  return 0;
}

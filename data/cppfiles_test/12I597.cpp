#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
void settings() __attribute__((constructor));
void eval(bool condition) { cout << (condition ? "yes" : "no") << '\n'; }
void Eval(bool condition) { cout << (condition ? "Yes" : "No") << '\n'; }
void EVAL(bool condition) { cout << (condition ? "YES" : "NO") << '\n'; }
int ipow(int a, int n) {
  if (n == 0) return 1;
  int x = ipow(a, n / 2);
  if (n % 2 == 0) return x * x;
  return x * x * a;
}
template <typename T>
ostream& operator<<(ostream& stream, const vector<T>& v) {
  for (auto elem : v) stream << elem << " ";
  return stream;
}
template <typename T>
istream& operator>>(istream& stream, vector<T>& v) {
  for (auto& elem : v) stream >> elem;
  return stream;
}
void settings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    bool res = false;
    if (n % 2 == 0 && m % 2 == 0 && k % 2 == 0)
      res = true;
    else if (n % 2 == 0 && k % 2 == 0 && k < n * m / 2)
      res = true;
    else if (m % 2 == 0 && n * m / 2 % 2 == k % 2)
      res = true;
    EVAL(res);
  }
  return 0;
}

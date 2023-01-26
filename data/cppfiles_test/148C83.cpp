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
  long long t;
  cin >> t;
  while (t--) {
    long long w, h;
    cin >> w >> h;
    long long k;
    cin >> k;
    long long diff1;
    for (long long i = 0; i < k; i++) {
      long long tmp;
      cin >> tmp;
      if (i == 0)
        diff1 = -tmp;
      else if (i == k - 1)
        diff1 += tmp;
    }
    cin >> k;
    long long diff2;
    for (long long i = 0; i < k; i++) {
      long long tmp;
      cin >> tmp;
      if (i == 0)
        diff2 = -tmp;
      else if (i == k - 1)
        diff2 += tmp;
    }
    cin >> k;
    long long diff3;
    for (long long i = 0; i < k; i++) {
      long long tmp;
      cin >> tmp;
      if (i == 0)
        diff3 = -tmp;
      else if (i == k - 1)
        diff3 += tmp;
    }
    cin >> k;
    long long diff4;
    for (long long i = 0; i < k; i++) {
      long long tmp;
      cin >> tmp;
      if (i == 0)
        diff4 = -tmp;
      else if (i == k - 1)
        diff4 += tmp;
    }
    cout << max(diff1 * h, max(diff2 * h, max(diff3 * w, diff4 * w))) << '\n';
  }
  return 0;
}

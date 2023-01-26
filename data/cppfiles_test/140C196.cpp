#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
long long cube(long long n) {
  long long i;
  for (i = 1;; i++)
    if (i * i * i > n) return i - 1;
}
long long powsix(long long n) {
  long long i;
  for (i = 1;; i++)
    if (i * i * i * i * i * i > n) return i - 1;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long i, j, n;
    cin >> n;
    long long squares = sqrt(n);
    long long cubes = cube(n);
    long long both = powsix(n);
    cout << squares + cubes - both << endl;
  }
}

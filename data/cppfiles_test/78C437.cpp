#include <bits/stdc++.h>
using namespace std;
template <class T>
void minimize(T &A, T B) {
  A = min(A, B);
}
template <class T>
void maximize(T &A, T B) {
  A = max(A, B);
}
const long long maxsize = 100000;
const long long mod = 1e9 + 9;
const long long base = 311;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void inti() {
  freopen(
      "c"
      ".inp",
      "r", stdin);
  freopen(
      "c"
      ".out",
      "w", stdout);
}
int t;
long long l, r;
void nhap() {
  cin >> t;
  while (t--) {
    cin >> l >> r;
    long long m = r / 2 + 1;
    if (m < l) {
      cout << r % l << endl;
    } else {
      cout << r % m << endl;
    }
  }
}
int main() {
  fastio();
  nhap();
}

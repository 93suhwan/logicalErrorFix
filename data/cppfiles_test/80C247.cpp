#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
const int INF = 1005000000;
const long long MOD = 1000000007LL;
int ni() {
  int x;
  cin >> x;
  return x;
}
long long nl() {
  long long x;
  cin >> x;
  return x;
}
double nd() {
  double x;
  cin >> x;
  return x;
}
string next() {
  string x;
  cin >> x;
  return x;
}
bool prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int Q = ni();
  for (int q = 0; q < (Q); q++) {
    int N = ni();
    string s = next();
    int L = -1;
    int R = -1;
    for (int i = 0; i < (N); i++) {
      if (s[i] == '0') {
        if (L == -1) L = i;
        R = i;
      }
    }
    if (L == -1) {
      int H = N / 2;
      cout << 1 << ' ' << H << ' ' << H + 1 << ' ' << 2 * H << '\n';
    } else if ((N - (L + 1)) >= N / 2) {
      cout << L + 1 << ' ' << N << ' ' << L + 2 << ' ' << N << '\n';
    } else {
      cout << 1 << ' ' << R + 1 << ' ' << 1 << ' ' << R << '\n';
    }
  }
}

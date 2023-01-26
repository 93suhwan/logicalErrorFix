#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 6 * 1e2 + 1, INF = 1e9;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; ++i) {
      string s = "";
      for (long long j = 0; j <= i; ++j) {
        s += "()";
      }
      for (long long j = i + 1; j < n; ++j) {
        s = '(' + s + ')';
      }
      cout << s << '\n';
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << "()"
         << "\n";
    return;
  }
  n = n + 1;
  string s = "()";
  for (int i = 0; i < n; ++i) {
    for (int j = n - 1; j > i; j--) {
      cout << "(";
    }
    for (int k = 1; k <= i; ++k) {
      cout << s;
    }
    for (int j = n - 1; j > i; j--) {
      cout << ")";
    }
    cout << "\n";
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

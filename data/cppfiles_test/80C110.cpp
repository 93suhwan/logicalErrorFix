#include <bits/stdc++.h>
using namespace std;
constexpr long long N = 200120;
constexpr long long D = 200;
constexpr long double EPS = 1e-10;
ofstream fout;
ifstream fin;
long long n, m, sz;
int fl;
void solve() {
  long long a, b;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < (n / 2); i++) {
    if (s[i] == '0') {
      cout << i + 1 << " " << n << " " << i + 2 << " " << n << "\n";
      return;
    }
  }
  for (int i = ((n + 1) / 2); i < (n); i++) {
    if (s[i] == '0') {
      cout << 1 << " " << i + 1 << " " << 1 << " " << i << "\n";
      return;
    }
  }
  cout << 1 << " " << n / 2 << " " << (n + 1) / 2 + 1 << " " << n << "\n";
}
signed main(int argc, char *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(14);
  cout.fixed;
  int t = 1;
  srand(time(0));
  fout.precision(14);
  fout.fixed;
  cin >> t;
  while (t--) {
    solve();
  }
  fout.close();
  fin.close();
}

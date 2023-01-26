#include <bits/stdc++.h>
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const long long int int_max = 1e18;
using namespace std;
void file_i_o() {
  ios::sync_with_stdio(false), cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  long long int indx = -1;
  for (long long int i = 0; i <= n - 1; i++) {
    if (s[i] == '0') {
      indx = i;
      break;
    }
  }
  if (indx == -1) {
    cout << "1 " << s.length() - 1 << " 2 " << s.length() << endl;
    return;
  }
  if (indx < ceil((n * 1.0) / 2)) {
    cout << indx + 1 << " " << n << " " << indx + 2 << " " << n << endl;
  } else {
    cout << "1 " << indx + 1 << " 1 " << indx << endl;
  }
}
int main(int argc, char const *argv[]) {
  file_i_o();
  long long int t;
  t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
string second;
void num_to_str(int num) {
  if (num) {
    num_to_str((num - 1) / 26);
    second += ('a' + (num - 1) % 26);
  }
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, x, k, d = 0, c = 0, f = 0;
    string s;
    cin >> n >> s;
    string p = s;
    sort(s.begin(), s.end());
    for (long long i = 0; i < n; i++) {
      if (s[i] != p[i]) d++;
    }
    cout << d << endl;
  }
}

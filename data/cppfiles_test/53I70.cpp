#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    long long n;
    char c;
    cin >> n >> c;
    string second;
    cin >> second;
    vector<long long> pos;
    for (long long i = 0; i < n; i++)
      if (second[i] != c) pos.push_back(i);
    if (pos.size() == 0) {
      cout << "0\n";
    } else if (pos.back() < (n - 1)) {
      cout << "1\n" << n << '\n';
    } else {
      cout << "2\n" << (n - 1) << ' ' << n << '\n';
    }
  }
}

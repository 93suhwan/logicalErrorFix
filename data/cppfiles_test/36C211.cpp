#include <bits/stdc++.h>
using namespace std;
void nitro() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool f4(int a, int b) { return a > b; }
bool f1(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
void clear(std::queue<long long int> &q) {
  std::queue<long long int> empty;
  std::swap(q, empty);
}
void solve() {
  long long int n;
  cin >> n;
  if (n == 1) {
    cout << "a" << '\n';
    return;
  }
  if (n % 2 != 0) {
    for (int(i) = 0; (i) < ((n / 2 - 1)); (i)++) {
      cout << "a";
    }
    cout << "bc";
    for (int(i) = 0; (i) < (n / 2); (i)++) {
      cout << "a";
    }
  } else {
    for (int(i) = 0; (i) < ((n / 2 - 1)); (i)++) {
      cout << "a";
    }
    cout << "b";
    for (int(i) = 0; (i) < (n / 2); (i)++) {
      cout << "a";
    }
  }
  cout << '\n';
}
signed main() {
  nitro();
  long long int t;
  cin >> t;
  for (int(i) = 0; (i) < (t); (i)++) {
    solve();
  }
}

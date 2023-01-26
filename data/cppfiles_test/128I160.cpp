#include <bits/stdc++.h>
using namespace std;
long long inf = std::numeric_limits<long long>::max();
void setIO(string name = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (name != "") {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
int main() {
  setIO("");
  long long T;
  cin >> T;
  cin.ignore();
  while (T--) {
    long long n;
    cin >> n;
    if (n & 1) {
      long long k = (n - 1) / 2;
      long long alpha = (n - 3) / 2;
      cout << 1 << " " << alpha << " "
           << " " << (2 * k - alpha) << "\n";
    } else {
      cout << 1 << " " << 2 << " " << n - 3 << "\n";
    }
  }
  return 0;
}

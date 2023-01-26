#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    long long s, n, k;
    cin >> s >> n >> k;
    if (s == k)
      cout << "YES" << endl;
    else if (s < k)
      cout << "NO" << endl;
    else {
      long long v = n + (n / k) * k;
      if (v > s)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}

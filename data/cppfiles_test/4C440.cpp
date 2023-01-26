#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int p;
    cin >> p;
    cout << (p - 1) / 2 << " " << p - 1 << '\n';
  }
}

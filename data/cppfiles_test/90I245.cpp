#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 7;
bool pri(int a) {
  if (a == 1) return 0;
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      return 0;
    }
  }
  return 1;
}
long long n, m, t, a[200000];
string s;
int main() {
  ios_base::sync_with_stdio(0);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    cout << n + m << "\n";
  }
  return 0;
}

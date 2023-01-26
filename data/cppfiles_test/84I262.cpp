#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
void YN(bool b) { cout << (b ? "YES" : "NO") << '\n'; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t, n, s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    cout << s / n << '\n';
  }
}

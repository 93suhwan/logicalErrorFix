#include <bits/stdc++.h>
using namespace std;
void SMG() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long h = (n) * -1;
    cout << h - 1 << " " << n << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  SMG();
  return 0;
}

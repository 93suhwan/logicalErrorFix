#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long int ll_inf = 0x3f3f3f3f3f3f3f3f;
const long long int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    long long int sum = a + 2 * b + 3 * c;
    if (sum & 1) {
      puts("1");
    } else {
      puts("0");
    }
  }
  return 0;
}

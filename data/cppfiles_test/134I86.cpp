#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000000000 + 1e8;
const long long LINF = 8000000000000000000;
long long gcd(long long a, long long b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
void solve() {
  int n;
  cin >> n;
  long long chet_gcd, nechet_gcd;
  cin >> chet_gcd >> nechet_gcd;
  vector<int> arr(n);
  arr[0] = chet_gcd;
  arr[1] = nechet_gcd;
  for (int i = 2; i < n; i++) {
    long long a;
    cin >> a;
    arr[i] = a;
    if (i % 2 == 0) {
      int gc = gcd(chet_gcd, a);
      chet_gcd = gc;
    } else {
      int gc = gcd(nechet_gcd, a);
      nechet_gcd = gc;
    }
  }
  bool flag = true;
  for (int i = 1; i < n; i += 2) {
    if (arr[i] % chet_gcd == 0) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << chet_gcd << '\n';
    return;
  }
  flag = true;
  for (int i = 0; i < n; i += 2) {
    if (arr[i] % nechet_gcd == 0) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << nechet_gcd << '\n';
    return;
  } else
    cout << 0 << '\n';
}
int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tst = 1;
  cin >> tst;
  while (tst--) {
    solve();
  }
}

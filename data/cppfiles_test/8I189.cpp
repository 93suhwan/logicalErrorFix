#include <bits/stdc++.h>
using namespace std;
multimap<long long int, long long int> mmp;
void ans() {
  long long int i, j, k, a, b, c, p, q, r, m, n, t, x, sum = 0, cnt = 0,
                                                       flag = 0;
  cin >> n;
  if (n == 1) {
    cout << "1"
         << " "
         << "0" << endl;
    return;
  }
  if (n == 2) {
    cout << "0"
         << " "
         << "1" << endl;
    return;
  }
  k = n / 3;
  a = (n - k);
  a = (a + 1) / 2;
  cout << k << " " << a << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int k = 1;
  cin >> k;
  while (k--) {
    ans();
  }
}

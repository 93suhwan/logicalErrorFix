#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int a[maxn];
signed main() {
  int t;
  int n;
  int k;
  cin >> n >> k;
  int num = n / 3;
  int num1 = n % 3;
  int cnt = 0;
  for (int i = 0; i < num; i++) {
    cout << "and"
         << " " << i * 3 + 1 << " " << i * 3 + 2 << endl;
    fflush(stdout);
    int cnt1, cnt2, cnt3, cnt4, cnt5, cnt6;
    cin >> cnt1;
    cout << "or"
         << " " << i * 3 + 1 << " " << i * 3 + 2 << endl;
    fflush(stdout);
    cin >> cnt2;
    cout << "and"
         << " " << i * 3 + 1 << " " << i * 3 + 3 << endl;
    fflush(stdout);
    cin >> cnt3;
    cout << "or"
         << " " << i * 3 + 1 << " " << i * 3 + 3 << endl;
    fflush(stdout);
    cin >> cnt4;
    cout << "and"
         << " " << i * 3 + 2 << " " << i * 3 + 3 << endl;
    fflush(stdout);
    cin >> cnt5;
    cout << "or"
         << " " << i * 3 + 2 << " " << i * 3 + 3 << endl;
    fflush(stdout);
    cin >> cnt6;
    int sum1 = cnt1 + cnt2;
    int sum2 = cnt3 + cnt4;
    int sum3 = cnt5 + cnt6;
    a[++cnt] = (sum1 + sum2 - sum3) / 2;
    a[++cnt] = (sum1 + sum3 - sum2) / 2;
    a[++cnt] = (sum2 + sum3 - sum1) / 2;
  }
  if (num1 == 2) {
    int cnt1, cnt2, cnt3, cnt4;
    cout << "and"
         << " " << n << " " << n - 2 << endl;
    fflush(stdout);
    cin >> cnt1;
    cout << "or"
         << " " << n << " " << n - 2 << endl;
    fflush(stdout);
    cin >> cnt2;
    a[++cnt] = (cnt1 + cnt2 - a[num * 3]);
    cout << "and"
         << " " << n - 1 << " " << n - 2 << endl;
    fflush(stdout);
    cin >> cnt3;
    cout << "or"
         << " " << n - 1 << " " << n - 2 << endl;
    fflush(stdout);
    cin >> cnt4;
    a[++cnt] = (cnt3 + cnt4 - a[num * 3]);
  } else if (num1 == 1) {
    int cnt1, cnt2, cnt3, cnt4;
    cout << "and"
         << " " << n << " " << n - 1 << endl;
    fflush(stdout);
    cin >> cnt1;
    cout << "or"
         << " " << n << " " << n - 1 << endl;
    fflush(stdout);
    cin >> cnt2;
    a[++cnt] = (cnt1 + cnt2 - a[num * 3]);
  }
  sort(a + 1, a + 1 + cnt);
  cout << "finish"
       << " " << a[k] << endl;
  fflush(stdout);
  return 0;
}

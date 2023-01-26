#include <bits/stdc++.h>
using namespace std;
const int AKA = 5e7 + 5;
int frq[AKA];
int arr[300005];
int a[300005];
vector<int> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ts;
  cin >> ts;
  while (ts--) {
    long long n;
    cin >> n;
    int diff = n % 3;
    n -= diff;
    int c1, c2;
    c1 = n / 3;
    c2 = (n - c1) / 2;
    if ((c1 + diff) + 2 * c2 == n + diff && abs((c1 + diff) - c2) <= 1)
      cout << c1 + diff << " " << c2 << endl;
    else
      cout << c1 << " " << (c2 + diff / 2) << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long arr[200005];
int main() {
  cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
  long long n, c;
  cin >> n;
  while (n--) {
    cin >> c;
    long long j = 0;
    long long u = 1;
    while (true) {
      if (pow(u, 2) <= c)
        j++;
      else
        break;
      u++;
    }
    cout << j << endl;
  }
  return 0;
}

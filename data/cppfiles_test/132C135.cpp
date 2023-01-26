#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long mod = 1000000007;
  int t;
  cin >> t;
  while (t--) {
    vector<long long> v(6, 0);
    long long sum;
    for (long long i = 0; i < 7; i++) {
      if (i < 6)
        cin >> v[i];
      else
        cin >> sum;
    }
    long long a, b, c;
    long long l, r;
    int flag = 0;
    for (long long i = 0; i < v.size() - 2; i++) {
      l = i + 1;
      r = v.size() - 1;
      while (l < r) {
        if (v[i] + v[l] + v[r] == sum) {
          a = v[i];
          b = v[l];
          c = v[r];
          flag = 1;
        } else if (v[i] + v[l] + v[r] < sum)
          l++;
        else
          r--;
        if (flag == 1) break;
      }
      if (flag == 1) break;
    }
    cout << a << " " << b << " " << c << endl;
  }
  return 0;
}

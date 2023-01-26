#include <bits/stdc++.h>
using namespace std;
long long n, a, b, flag;
vector<long long> v;
signed main() {
  cin >> n;
  while (n--) {
    cin >> a >> b;
    v.clear();
    bool flag = 1;
    while (b) {
      long long t1 = a % 10, t2 = b % 10;
      if (t2 >= t1)
        v.push_back(t2 - t1);
      else {
        t2 = b % 100;
        b /= 10;
        if (t2 > t1 && t2 >= 10 && t2 <= 19)
          v.push_back(t2 - t1);
        else {
          flag = 0;
          puts("-1");
          break;
        }
      }
      a /= 10, b /= 10;
    }
    if (a && flag) {
      flag = 0;
      puts("-1");
    }
    if (!flag) continue;
    while (v.back() == 0) v.pop_back();
    while (!v.empty()) {
      cout << v.back();
      v.pop_back();
    }
    cout << endl;
  }
}

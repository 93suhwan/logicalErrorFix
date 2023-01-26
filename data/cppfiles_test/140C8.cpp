#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
  long long n, c;
  cin >> n;
  while (n--) {
    cin >> c;
    set<long long> t;
    long long a = 1, coutter = 0;
    while (true) {
      if (a * a <= c)
        t.insert(a * a);
      else
        break;
      if (a * a * a <= c) t.insert(a * a * a);
      a++;
    }
    cout << t.size() << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(51);
long long ask(long long a, long long b, long long c) {
  cout << "? " << a << ' ' << b << ' ' << c << endl;
  long long p;
  cin >> p;
  return p;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, bad = 0, good = 0;
    cin >> n;
    vector<long long> type(n + 1);
    for (long long i = 1; i <= n; i += 3) {
      type[i] = ask(i, i + 1, i + 2);
    }
    for (long long i = 1; i <= n; i += 3) {
      if (type[i] != type[i + 3]) {
        type[i + 1] = ask(i + 1, i + 2, i + 3),
                 type[i + 2] = ask(i + 2, i + 3, i + 4);
        for (long long j = i; j < i + 3; j++) {
          if (type[j] != type[j + 1]) {
            if (type[j] == 0) {
              bad = j, good = j + 3;
            } else {
              bad = j + 3, good = j;
            }
          }
        }
        break;
      }
    }
    vector<long long> arr{bad};
    for (long long i = 1; i <= n; i += 3) {
      if ((i - 1) / 3 == (bad - 1) / 3 || (i - 1) / 3 == (good - 1) / 3) {
        for (long long j = i; j < i + 3; j++) {
          if (bad == j || good == j) {
            continue;
          }
          if (ask(good, bad, j) == 0) {
            arr.emplace_back(j);
          }
        }
      } else if (type[i] == 0) {
        if (ask(i, i + 1, good) == 0) {
          arr.emplace_back(i);
          arr.emplace_back(i + 1);
          if (ask(i + 2, good, bad) == 0) arr.emplace_back(i + 2);
        } else {
          arr.emplace_back(i + 2);
          if (ask(i, good, bad) == 0)
            arr.emplace_back(i);
          else
            arr.emplace_back(i + 1);
        }
      } else {
        if (ask(i, i + 1, bad) == 1) {
          if (ask(i + 2, good, bad) == 0) arr.emplace_back(i + 2);
        } else {
          if (ask(i, good, bad) == 0)
            arr.emplace_back(i);
          else
            arr.emplace_back(i + 1);
        }
      }
    }
    cout << "! " << arr.size() << ' ';
    for (auto to : arr) cout << to << ' ';
    cout << endl;
  }
  return 0;
}

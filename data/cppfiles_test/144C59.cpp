#include <bits/stdc++.h>
using namespace std;
const int SI = 3e5 + 7;
long long INF = 8e18 + 7;
int MOD = 1e9 + 7;
int T = 1;
long long n, m, k;
set<long long> se;
deque<long long> q;
void solver() {
  while (q.size()) q.pop_back();
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) q.push_back(i);
  while (k--) {
    long long mm = n % m;
    se.clear();
    for (int i = 1; i <= n; i++) se.insert(i);
    while (mm--) {
      cout << (n + m - 1) / m << " ";
      for (int i = 0; i < (n + m - 1) / m; i++) {
        cout << q.front() << " ";
        q.push_back(q.front());
        se.erase(q.front());
        q.pop_front();
      }
      cout << "\n";
    }
    mm = m - n % m;
    for (int i = 1; i <= mm; i++) {
      cout << n / m << " ";
      for (int i = 0; i < n / m; i++)
        cout << *se.begin() << " ", se.erase(se.begin());
      cout << "\n";
    }
  }
}
int main() {
  cin >> T;
  while (T--) solver();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int t;
long long n, res;
int main() {
  cin >> t;
  while (t--) {
    vector<long long> s;
    cin >> res >> n;
    long long tmp = n % 4;
    while (tmp--) {
      s.push_back(n--);
    }
    for (int i = s.size() - 1; i >= 0; i--) {
      if (abs(res) % 2 == 0)
        res -= s[i];
      else
        res += s[i];
    }
    cout << res << "\n";
  }
  return 0;
}

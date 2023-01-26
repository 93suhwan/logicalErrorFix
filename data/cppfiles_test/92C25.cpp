#include <bits/stdc++.h>
using namespace std;
static int aQWEs = []() -> int {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();
long long int sqrt(long long int p) {
  long long int low = 1, high = p, mid;
  while (low < high) {
    mid = (low + high + 1) / 2;
    if (mid * mid > p) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  return low;
}
long long int power(long long int a, long long int p,
                    long long int m = 1000000007) {
  a %= m;
  long long int val = 1;
  while (p > 0) {
    if (p & 1) {
      val = (val * a) % m;
    }
    a = (a * a) % m;
    p >>= 1;
  }
  return (val);
}
void adjust(pair<int, string> &p, char c) {
  for (auto &a : p.second) {
    if (a != c) {
      a = c;
      p.first++;
    }
  }
}
int main() {
  long long int i, j;
  int T = 1;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.length();
    if (n == 1) {
      cout << s << "\n";
      continue;
    }
    s[0] = s[n - 1] = s[0];
    cout << s << "\n";
  }
}

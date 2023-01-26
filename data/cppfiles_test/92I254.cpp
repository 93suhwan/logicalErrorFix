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
    if (n == 2) {
      if (s[0] == s[1]) {
        cout << s << "\n";
      } else {
        cout << "aa\n";
      }
      continue;
    }
    vector<pair<int, string>> v(3, make_pair(0, s));
    v[0].first += (v[0].second[0] != 'a');
    v[0].first += (v[0].second[n - 1] != 'a');
    v[0].second[0] = v[0].second[n - 1] = 'a';
    for (i = 1; i < n - 1; ++i) {
      if (v[0].second[i] == 'b') break;
    }
    if (i >= n - 1) {
      v[0].first += 1;
      v[0].second[1] = 'b';
    }
    adjust(v[1], 'a');
    adjust(v[2], 'b');
    cout << min_element(v.begin(), v.end())->second << "\n";
  }
}

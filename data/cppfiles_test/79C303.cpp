#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
unsigned long long min(unsigned long long x, unsigned long long y) {
  if (x < y) return x;
  return y;
}
unsigned long long max(unsigned long long x, unsigned long long y) {
  if (x < y) return y;
  return x;
}
long long min(long long x, long long y) {
  if (x < y) return x;
  return y;
}
long long max(long long x, long long y) {
  if (x < y) return y;
  return x;
}
double min(double x, double y) {
  if (x < y) return x;
  return y;
}
double max(double x, double y) {
  if (x < y) return y;
  return x;
}
unsigned long long gcd(unsigned long long x, unsigned long long y) {
  if (!x) return y;
  if (!y) return x;
  if (x > y) swap(x, y);
  return gcd(x, y % x);
}
unsigned long long inv(unsigned long long a, unsigned long long c) {
  if (a == 1) {
    return 1;
  }
  return ((c - (c / a)) * inv(c % a, c)) % c;
}
void printv(vector<int> &a) {
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << " END\n";
}
bool check(string s) {
  int num = 0;
  for (char &i : s) {
    num = num * 10 + (i - '0');
  }
  for (int i = 2; i <= sqrt(num); ++i) {
    if (num % i == 0) return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int ans = -1;
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < k; ++i) {
      int x = s[i] - '0';
      if ((x != 2) && (x != 3) && (x != 5) && (x != 7)) {
        ans = x;
        break;
      }
      if (x == 2) {
        a++;
      } else if (x == 3) {
        b++;
      } else if (x == 5) {
        c++;
      } else if (x == 7) {
        d++;
      }
    }
    if (ans != -1) {
      cout << "1\n" << ans << "\n";
      continue;
    }
    if (a > 1) {
      cout << "2\n"
           << "22\n";
      continue;
    } else if (b > 1) {
      cout << "2\n"
           << "33\n";
      continue;
    } else if (c > 1) {
      cout << "2\n"
           << "55\n";
      continue;
    } else if (d > 1) {
      cout << "2\n"
           << "77\n";
      continue;
    }
    string final;
    for (int i = 1; i < (1 << k); ++i) {
      string cur;
      for (int j = 0; j < k; ++j) {
        if ((i >> j) & 1) cur += s[j];
      }
      if (check(cur)) {
        if ((final.empty()) || (cur.size() < final.size())) {
          final = cur;
        }
      }
    }
    cout << final.size() << "\n";
    cout << final << "\n";
  }
  return 0;
}

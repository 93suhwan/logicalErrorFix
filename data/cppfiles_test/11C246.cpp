#include <bits/stdc++.h>
using namespace std;
vector<bool> pu(100006 + 1, false);
vector<long long int> pr;
vector<long long int> prevprime(100006 + 1, 1);
char c;
class dop {
 public:
  long long int n, p, q, r, k, z;
  string s;
  void get();
};
void seive() {
  for (long long int i = 2; (i) <= 100006; i++) {
    if (!pu[i]) {
      prevprime[i] = i;
      for (long long int j = (2 * i); j <= 100006; j += i) {
        if (!pu[j]) {
          prevprime[j] = i;
        }
        pu[j] = true;
      }
      pr.push_back(i);
    }
  }
}
long long int power(long long int x, long long int n) {
  long long int res = 1;
  while (n > 0) {
    if (n & 1) {
      res = ((res % 1000000007) * (x % 1000000007)) % 1000000007;
    }
    n = n >> 1;
    x = ((x % 1000000007) * (x % 1000000007)) % 1000000007;
  }
  return res;
}
long long int inv(long long int x) { return power(x, 1000000007 - 2); }
void factor(long long int x) {
  while (x != 1) {
    long long int div = prevprime[x];
    while (prevprime[x] == div) {
      x /= div;
    }
  }
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
bool comp(string s, string v) {
  int p, q;
  p = 0;
  q = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == c) {
      p++;
    } else {
      p--;
    }
  }
  for (int i = 0; i < v.length(); i++) {
    if (v[i] == c) {
      q++;
    } else {
      q--;
    }
  }
  if (p > 0) {
    return true;
  }
  if (q > 0) {
    return false;
  }
  return p >= q;
}
int check(string s, char c) {
  int p, q;
  p = 0;
  q = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == c) {
      p++;
    } else {
      p--;
    }
  }
  return p;
}
void dop::get() {
  cin >> n;
  vector<vector<long long int> > a(5, vector<long long int>(n, 0));
  for (int i = 0; i < n; i++) {
    cin >> s;
    a[0][i] = check(s, 'a');
    a[1][i] = check(s, 'b');
    a[2][i] = check(s, 'c');
    a[3][i] = check(s, 'd');
    a[4][i] = check(s, 'e');
  }
  for (int i = 0; i < 5; i++) {
    sort(a[i].begin(), a[i].end());
  }
  p = 0;
  for (int i = 0; i < 5; i++) {
    q = 0;
    r = 0;
    for (int j = n - 1; j >= 0; j--) {
      q += a[i][j];
      if (q > 0) {
        r++;
      }
    }
    p = max(p, r);
  }
  cout << p << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  dop obj[t];
  for (long long int i = 0; i < t; i++) {
    obj[i].get();
  }
  return 0;
}

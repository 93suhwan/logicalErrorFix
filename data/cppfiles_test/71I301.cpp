#include <bits/stdc++.h>
using namespace std;
string numbertoString(long long int n) {
  string s = "";
  while (n > 0) {
    long long int d = n % 10;
    char ch = '0' + d;
    s += ch;
    n /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long int binexp(long long int x, long long int n) {
  if (n == 0)
    return 1ll;
  else if (n & 1ll) {
    return (x * binexp(x, n - 1));
  } else {
    long long int y = binexp(x, n / 2);
    return (y * y);
  }
}
long long int stringtonumber(string s) {
  long long int num = 0;
  long long int len = s.length();
  for (long long int i = 0; i < s.length(); i++) {
    long long int dig = s[i] - '0';
    long long int temp = binexp(10, len - i - 1) * dig;
    num += temp;
  }
  return num;
}
void Helper(long long int n, long long int k) {
  string s = numbertoString(n);
  vector<long long int> vec;
  if (k == 2) {
    for (long long int a = 0; a < 10; a++) {
      for (long long int b = 0; b < 10; b++) {
        string t = "";
        bool ok = false;
        long long int mn = min(a, b), mx = max(a, b);
        long long int pos = 0;
        bool f = true;
        while (pos < s.length()) {
          long long int d = s[pos] - '0';
          pos++;
          if (ok) {
            char ch = '0' + mn;
            t += ch;
          } else {
            if ((mn >= d) and (!ok)) {
              char ch = '0' + mn;
              t += ch;
              if (mn > d) ok = true;
            } else if ((mn >= d) and (ok)) {
              char ch = '0' + mn;
              t += ch;
            } else if ((mx >= d) and (ok)) {
              char ch = '0' + mx;
              t += ch;
            } else if ((mx >= d) and (!ok)) {
              char ch = '0' + mx;
              t += ch;
              if (mx > d) ok = true;
            } else {
              if (!ok) {
                f = false;
                break;
              } else {
                char ch = '0' + mn;
                t += ch;
              }
            }
          }
        }
        if (f) {
          long long int num = stringtonumber(t);
          if (num >= n) vec.push_back(num);
        }
      }
    }
  } else if (k == 1) {
    for (long long int a = 0; a < 10; a++) {
      string t = "";
      for (long long int j = 0; j < s.length(); j++) {
        char ch = '0' + a;
        t += ch;
      }
      long long int num = stringtonumber(t);
      if (num >= n) vec.push_back(num);
    }
  }
  long long int ans = *min_element(vec.begin(), vec.end());
  cout << ans << "\n";
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    Helper(n, k);
  }
}

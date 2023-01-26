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
    long long int temp = binexp(10, len - i - 1) * (s[i] - '0');
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
        bool ok = false;
        string t = "";
        long long int mn = min(a, b), mx = max(a, b);
        for (long long int pos = 0; pos < s.length(); pos++) {
          if (ok) {
            char ch = '0' + mn;
            t += ch;
          } else {
            if (mn >= (s[pos] - '0')) {
              long long int digs_left = s.length() - pos - 1;
              string left = "";
              char ch = '0' + mn;
              left += ch;
              for (long long int times = 0; times < digs_left; times++) {
                char ch = '0' + mx;
                left += ch;
              }
              long long int mx_pos = 0;
              if (!left.empty()) mx_pos = stringtonumber(left);
              string gus = "";
              if (pos <= (n - 1)) gus = s.substr(pos, digs_left);
              long long int shawn = 0;
              if (!gus.empty()) shawn = stringtonumber(gus);
              if (shawn > mx_pos) {
                char ch = '0' + mx;
                t += ch;
                long long int cur = s[pos] - '0';
                if (mx > cur) ok = true;
              } else {
                char ch = '0' + mn;
                t += ch;
                long long int cur = s[pos] - '0';
                if (mn > cur) ok = true;
              }
            } else {
              char ch = '0' + mx;
              t += ch;
              if (mx > (s[pos] - '0')) ok = true;
            }
          }
        }
        long long int val = stringtonumber(t);
        if (val >= n) vec.push_back(val);
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

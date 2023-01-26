#include <bits/stdc++.h>
using namespace std;
void solve1() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (char ch = 'A'; ch <= 'Z'; ch++) {
    int f = n;
    int l = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == ch) {
        f = min(f, i);
        l = max(l, i);
      }
    }
    for (int i = f; i <= l; i++) {
      if (s[i] != ch) {
        cout << "NO"
             << "\n";
        return;
      }
    }
  }
  cout << "YES"
       << "\n";
}
void solve() {
  long long n;
  cin >> n;
  long long k = 0;
  priority_queue<long long> Q1, Q2, Q3, Q4, Q5;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    long long a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
    for (long long i = 0; i < s.length(); i++) {
      if (s[i] == 'a') {
        a1++;
      }
      if (s[i] == 'b') {
        a2++;
      }
      if (s[i] == 'c') {
        a3++;
      }
      if (s[i] == 'd') {
        a4++;
      }
      if (s[i] == 'e') {
        a5++;
      }
    }
    Q1.push(2 * a1 - s.length());
    Q2.push(2 * a2 - s.length());
    Q3.push(2 * a3 - s.length());
    Q4.push(2 * a4 - s.length());
    Q5.push(2 * a5 - s.length());
  }
  long long result = 0;
  long long x = 0, a2 = 0;
  for (long long i = 0; i < n; i++) {
    x = x + Q1.top();
    Q1.pop();
    if (x > 0) {
      a2++;
    } else {
      break;
    }
  }
  result = max(result, a2);
  x = 0;
  a2 = 0;
  for (long long i = 0; i < n; i++) {
    x = x + Q2.top();
    Q2.pop();
    if (x > 0) {
      a2++;
    } else {
      break;
    }
  }
  result = max(result, a2);
  x = 0;
  a2 = 0;
  for (long long i = 0; i < n; i++) {
    x = x + Q3.top();
    Q3.pop();
    if (x > 0) {
      a2++;
    } else {
      break;
    }
  }
  result = max(result, a2);
  x = 0;
  a2 = 0;
  for (long long i = 0; i < n; i++) {
    x = x + Q4.top();
    Q4.pop();
    if (x > 0) {
      a2++;
    } else {
      break;
    }
  }
  result = max(result, a2);
  x = 0;
  a2 = 0;
  for (long long i = 0; i < n; i++) {
    x = x + Q5.top();
    Q5.pop();
    if (x > 0) {
      a2++;
    } else {
      break;
    }
  }
  result = max(result, a2);
  cout << result << "\n";
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}

#include <bits/stdc++.h>
using namespace std;
const long MOD = 1000000007;
const long MAXN = 1e5 + 10;
void testcase() {
  string a, b;
  cin >> a >> b;
  sort(a.begin(), a.end());
  if (b != "abc") {
    cout << a;
  } else {
    long long cnta = 0;
    long long cntb = 0;
    long long cntc = 0;
    for (long long i = 0; i < a.size(); i++) {
      cnta += (a[i] == 'a');
      cntb += (a[i] == 'b');
      cntc += (a[i] == 'c');
    }
    long long sum = cnta + cntb + cntc;
    if (cnta == 0 || cntb == 0 || cntc == 0) {
      while (cnta--) {
        cout << 'a';
      }
      while (cntb--) {
        cout << 'b';
      }
      while (cntc--) {
        cout << 'c';
      }
    } else {
      while (cnta--) {
        cout << 'a';
      }
      while (cntc--) {
        cout << 'c';
      }
      while (cntb--) {
        cout << 'b';
      }
    }
    for (long long i = sum; i < a.size(); i++) {
      cout << a[i];
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  while (n--) {
    testcase();
    cout << "\n";
  }
}

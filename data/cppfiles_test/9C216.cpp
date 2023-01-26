#include <bits/stdc++.h>
long long b[200];
using namespace std;
int main() {
  long long n;
  cin >> n;
  while (n--) {
    memset(b, 0, sizeof(b));
    string a;
    cin >> a;
    long long s = 0;
    for (int i = 0; i < a.size(); i++) {
      if (b[a[i]] <= 1) {
        s++;
        b[a[i]]++;
      }
    }
    cout << s / 2 << endl;
  }
}

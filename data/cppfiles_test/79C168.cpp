#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long T;
  cin >> T;
read:
  while (T--) {
    string s;
    long long n;
    cin >> n;
    cin >> s;
    long long ar[10] = {0};
    long long cnt2 = 0, cnt3 = 0, cnt5 = 0, cnt7 = 0;
    long long cnt2i, cnt3i, cnt5i, cnt7i;
    for (long long i = 0; i < n; i++) {
      ar[s[i] - '0']++;
      long long k = s[i] - '0';
      if (k == 2) {
        cnt2++;
        cnt2i = i;
      } else if (k == 3) {
        cnt3++;
        cnt3i = i;
      } else if (k == 5) {
        cnt5++;
        cnt5i = i;
      } else if (k == 7) {
        cnt7++;
        cnt7i = i;
      }
    }
    long long a[5] = {1, 4, 6, 8, 9};
    for (long long i = 0; i < 5; i++) {
      if (ar[a[i]] >= 1) {
        cout << 1 << endl;
        cout << a[i] << endl;
        goto read;
      }
    }
    long long b[4] = {2, 3, 5, 7};
    for (long long i = 0; i < 4; i++) {
      if (ar[b[i]] >= 2) {
        cout << 2 << endl;
        cout << b[i] << b[i] << endl;
        goto read;
      }
    }
    if (cnt2 >= 1 && cnt5 >= 1) {
      cout << 2 << endl;
      if (cnt2i > cnt5i) {
        cout << s[cnt5i] << s[cnt2i] << endl;
      } else {
        cout << s[cnt2i] << s[cnt5i] << endl;
      }
    } else if (cnt2 >= 1 && cnt3 >= 1 && cnt2i > cnt3i) {
      cout << 2 << endl;
      cout << s[cnt3i] << s[cnt2i] << endl;
    } else if (cnt2 >= 1 && cnt7 >= 1) {
      cout << 2 << endl;
      if (cnt2i > cnt7i) {
        cout << s[cnt7i] << s[cnt2i] << endl;
      } else {
        cout << s[cnt2i] << s[cnt7i] << endl;
      }
    } else if (cnt3 >= 1 && cnt5 >= 1 && cnt3i < cnt5i) {
      cout << 2 << endl;
      cout << s[cnt3i] << s[cnt5i] << endl;
    } else if (cnt5 >= 1 && cnt7 >= 1) {
      cout << 2 << endl;
      if (cnt7i > cnt5i) {
        cout << s[cnt5i] << s[cnt7i] << endl;
      } else {
        cout << s[cnt7i] << s[cnt5i] << endl;
      }
    }
  }
  return 0;
}

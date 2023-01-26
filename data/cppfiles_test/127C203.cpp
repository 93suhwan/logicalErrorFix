#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0 || b == 0) return a ^ b;
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
void doit() {
  string s, t;
  cin >> s >> t;
  if (t != "abc") {
    sort(s.begin(), s.end());
    cout << s << "\n";
    return;
  } else {
    int arr[27] = {0};
    for (auto i : s) {
      arr[(int)i - (int)'a']++;
    }
    if (arr[0] != 0 && arr[1] != 0 && arr[2] != 0) {
      while (arr[0] != 0) {
        cout << (char)('a' + 0);
        arr[0]--;
      }
      while (arr[2] != 0) {
        cout << (char)('a' + 2);
        arr[2]--;
      }
      while (arr[1] != 0) {
        cout << (char)('a' + 1);
        arr[1]--;
      }
    } else {
      for (int i = 0; i < 3; i++) {
        while (arr[i] != 0) {
          cout << (char)('a' + i);
          arr[i]--;
        }
      }
    }
    for (int i = 3; i < 26; i++) {
      while (arr[i] != 0) {
        cout << (char)('a' + i);
        arr[i]--;
      }
    }
  }
  cout << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  while (n--) {
    doit();
  }
  return 0;
}

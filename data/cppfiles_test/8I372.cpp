#include <bits/stdc++.h>
using namespace std;
void getIndex(vector<int> v, int K) {
  auto it = find(v.begin(), v.end(), K);
  if (it != v.end()) {
    int index = it - v.begin();
    cout << index << endl;
  } else {
    cout << "-1" << endl;
  }
}
bool isPrime(int n) {
  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
bool isSor(vector<int> vec) {
  vector<int> vec2 = vec;
  sort(vec2.begin(), vec2.end());
  if (vec == vec2) return true;
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a = n / 3;
    if (n % 3 == 0) {
      cout << a << " " << a << endl;
    } else {
      cout << a << " " << a + 1 << endl;
    }
  }
}
int maidfghdasfgn() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    int ans = 0;
    while (!isSor(vec)) {
      for (int i = 0; i < n - 1; i++) {
        if (vec[i] > vec[i + 1]) {
          int aa = vec[i];
          vec[i] = vec[i + 1];
          vec[i + 1] = aa;
        }
      }
      ans++;
    }
    if (ans != 0) ans++;
    cout << ans << endl;
    cout << "HELLO" << endl;
    for (int i : vec) cout << i << endl;
  }
  return 0;
}
int mfghjfddsfghain() {
  string s;
  cin >> s;
  bool allCaps = true;
  for (int i = 1; i < s.length(); i++) {
    if (!isupper(s[i])) allCaps = false;
  }
  if (allCaps) {
    if (isupper(s[0])) {
      transform(s.begin(), s.end(), s.begin(), ::tolower);
      cout << s << endl;
    } else {
      transform(s.begin(), s.end(), s.begin(), ::tolower);
      s[0] = toupper(s[0]);
      cout << s << endl;
    }
  } else
    cout << s << endl;
  return 0;
}
int masdfghdsfsin() {
  int a, b, c;
  cin >> a >> b >> c;
  int a1, a2, a3, a4, a5, a6;
  a1 = a + b * c;
  a2 = a * b + c;
  a3 = (a + b) * c;
  a4 = a * (b + c);
  a5 = a + b + c;
  a6 = a * b * c;
  cout << max(max(max(max(max(a1, a2), a3), a4), a5), a6) << endl;
  return 0;
}
int masdfgdfghin() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (n == 1) {
    cout << 1 << endl;
  } else {
    int ans = 0, len = 0;
    for (int i = 1; i < n; i++) {
      if (arr[i] >= arr[i - 1]) {
        len++;
        if (i == n - 1) {
          len++;
        }
        ans = max(ans, len);
      } else {
        len++;
        ans = max(ans, len);
        len = 0;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
int sdfgsdfgmain() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    while (q--) {
      int ans = 0;
      int l, r;
      cin >> l >> r;
      bool pos = true;
      for (int i = l - 1; i < r; i++) {
        if (s[i] == '+') {
          if (pos) {
            ans += 1;
          } else
            ans -= 1;
        } else {
          if (pos)
            ans += -1;
          else
            ans -= -1;
        }
        pos = !pos;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
int madsfgain() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    string s;
    cin >> k >> s;
    string ans = "";
    for (char c : s) {
      ans.push_back(c);
      if (!isPrime(stoi(ans)) && stoi(ans) != 1) {
        cout << ans.length() << endl;
        cout << ans << endl;
        break;
      }
    }
  }
  return 0;
}
int maasdfagasdfin() {
  int n;
  cin >> n;
  while (n--) {
    int l, r;
    cin >> l >> r;
    if (l == r)
      cout << 0 << endl;
    else if (r / 2 >= l)
      cout << r % (r / 2 + 1) << endl;
    else
      cout << r % l << endl;
  }
  return 0;
}

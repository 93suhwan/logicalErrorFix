#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, b, c, e, d, m, i, j, k, t, T, r, l;
  long long int x;
  cin >> T;
  for (t = 1; t <= T; t++) {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    l = s1.length();
    char ch[l];
    for (i = 0; i < l; i++) {
      ch[i] = s1[i];
    }
    sort(ch, ch + l);
    if (s2 == "abc") {
      map<char, long long int> mp;
      for (i = 0; i < l; i++) {
        mp[ch[i]]++;
      }
      if (mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1) {
        a = mp['a'];
        vector<char> v;
        for (i = 0; i < a; i++) {
          v.push_back('a');
        }
        a = mp['c'];
        for (i = 0; i < a; i++) {
          v.push_back('c');
        }
        a = mp['b'];
        for (i = 0; i < a; i++) {
          v.push_back('b');
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
          if (it->first == 'a' || it->first == 'b' || it->first == 'c') {
            continue;
          } else {
            char ch1 = it->first;
            a = it->second;
            for (i = 0; i < a; i++) {
              v.push_back(ch1);
            }
          }
        }
        for (i = 0; i < l; i++) {
          cout << v[i];
        }
        cout << endl;
      } else {
        for (i = 0; i < l; i++) {
          cout << ch[i];
        }
        cout << endl;
      }
    } else {
      for (i = 0; i < l; i++) {
        cout << ch[i];
      }
      cout << endl;
    }
  }
  return 0;
}

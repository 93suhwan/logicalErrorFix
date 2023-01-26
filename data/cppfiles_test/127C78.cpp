#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string t;
    cin >> t;
    set<char> set_s;
    map<char, int> m;
    for (int i = 0; i < s.size(); i++) {
      m[s[i]]++;
      set_s.insert(s[i]);
    }
    vector<char> v;
    sort(s.begin(), s.end());
    if (t != "abc") {
      cout << s << endl;
      ;
    } else {
      if (m['a'] != 0 && m['b'] != 0 && m['c'] != 0) {
        for (int i = 0; i < m['a']; i++) {
          v.push_back('a');
        }
        for (int i = 0; i < m['c']; i++) {
          v.push_back('c');
        }
        for (int i = 0; i < m['b']; i++) {
          v.push_back('b');
        }
        for (int i = 0; i < m['d']; i++) {
          v.push_back('d');
        }
        for (int i = 0; i < m['e']; i++) {
          v.push_back('e');
        }
        for (int i = 0; i < m['f']; i++) {
          v.push_back('f');
        }
        for (int i = 0; i < m['g']; i++) {
          v.push_back('g');
        }
        for (int i = 0; i < m['h']; i++) {
          v.push_back('h');
        }
        for (int i = 0; i < m['i']; i++) {
          v.push_back('i');
        }
        for (int i = 0; i < m['j']; i++) {
          v.push_back('j');
        }
        for (int i = 0; i < m['k']; i++) {
          v.push_back('k');
        }
        for (int i = 0; i < m['l']; i++) {
          v.push_back('l');
        }
        for (int i = 0; i < m['m']; i++) {
          v.push_back('m');
        }
        for (int i = 0; i < m['n']; i++) {
          v.push_back('n');
        }
        for (int i = 0; i < m['o']; i++) {
          v.push_back('o');
        }
        for (int i = 0; i < m['p']; i++) {
          v.push_back('p');
        }
        for (int i = 0; i < m['q']; i++) {
          v.push_back('q');
        }
        for (int i = 0; i < m['r']; i++) {
          v.push_back('r');
        }
        for (int i = 0; i < m['s']; i++) {
          v.push_back('s');
        }
        for (int i = 0; i < m['t']; i++) {
          v.push_back('t');
        }
        for (int i = 0; i < m['u']; i++) {
          v.push_back('u');
        }
        for (int i = 0; i < m['v']; i++) {
          v.push_back('v');
        }
        for (int i = 0; i < m['w']; i++) {
          v.push_back('w');
        }
        for (int i = 0; i < m['x']; i++) {
          v.push_back('x');
        }
        for (int i = 0; i < m['y']; i++) {
          v.push_back('y');
        }
        for (int i = 0; i < m['z']; i++) {
          v.push_back('z');
        }
        for (auto element : v) {
          cout << element;
        }
        cout << endl;
      } else {
        cout << s << endl;
      }
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
int main() {
  fastIO();
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 1; i <= N; i++) {
      if (s[i - 1] != '?') v.push_back(i - 1);
    }
    if ((int)v.size() == 0) {
      bool blue = true;
      for (int i = 1; i <= N; i++) {
        if (blue)
          cout << "B";
        else
          cout << "R";
        blue = !blue;
      }
      continue;
    }
    bool blue = true;
    if (s[v[0]] == 'B') blue = false;
    for (int i = v[0] - 1; i >= 0; i--) {
      if (blue)
        s[i] = 'B';
      else
        s[i] = 'R';
      blue = !blue;
    }
    for (int i = 0; i < (int)v.size() - 1; i++) {
      blue = true;
      if (s[v[i]] == 'B')
        blue = false;
      else
        blue = true;
      for (int j = v[i] + 1; j <= v[i + 1] - 1; j++) {
        if (blue)
          s[j] = 'B';
        else
          s[j] = 'R';
        blue = !blue;
      }
    }
    blue = true;
    if (s[v.back()] == 'B')
      blue = false;
    else
      blue = true;
    for (int i = v.back() + 1; i < (int)s.size(); i++) {
      if (blue)
        s[i] = 'B';
      else
        s[i] = 'R';
      blue = !blue;
    }
    cout << s << "\n";
  }
}

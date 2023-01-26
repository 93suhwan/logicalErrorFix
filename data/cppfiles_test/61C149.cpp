#include <bits/stdc++.h>
using namespace std;
void print(vector<long long>& v) {
  for (auto element : v) {
    cout << element << " ";
  }
  cout << '\n';
}
void print(vector<vector<long long> >& v) {
  for (auto vec : v) {
    print(vec);
  }
}
void print(vector<vector<vector<long long> > >& v) {
  for (auto vec : v) {
    print(vec);
  }
}
void print(pair<long long, long long>& p) {
  cout << "(" << p.first << "," << p.second << ") ";
}
void print(pair<long long, char>& p) {
  cout << "(" << p.first << "," << p.second << ") ";
}
void print(vector<pair<long long, long long> >& v) {
  for (auto p : v) {
    print(p);
  }
  cout << '\n';
}
void print(vector<pair<long long, char> >& v) {
  for (auto p : v) {
    print(p);
  }
  cout << '\n';
}
void print(vector<vector<pair<long long, long long> > >& v) {
  for (auto p : v) {
    print(p);
  }
  cout << '\n';
}
void print(vector<string>& v) {
  for (auto s : v) {
    cout << s << '\n';
  }
}
void print(vector<bool>& v) {
  for (auto b : v) {
    cout << b << " ";
  }
  cout << '\n';
}
void print(vector<vector<bool> >& v) {
  for (auto b : v) {
    print(b);
  }
}
void print(unordered_set<long long>& u) {
  for (auto i = u.begin(); i != u.end(); ++i) cout << (*i) << " ";
  cout << '\n';
}
void print(vector<unordered_set<long long> >& v) {
  for (auto u : v) {
    print(u);
  }
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long powerMOD(long long x, long long y) {
  long long result = 1;
  while (y) {
    if (y & 1) result = result * x % 1000000007;
    y = y / 2;
    x = x * x % 1000000007;
  }
  return result;
}
void solve() {
  long long N;
  cin >> N;
  string s;
  cin >> s;
  int known = 0;
  for (known = 0; known < N; ++known) {
    if (s[known] != '?') break;
  }
  if (known == N) {
    s[0] = 'B';
    known = 0;
  }
  for (int i = known - 1; i >= 0; --i) {
    if (s[i] == '?') {
      if (s[i + 1] == 'R')
        s[i] = 'B';
      else
        s[i] = 'R';
    }
  }
  for (int i = known + 1; i < N; ++i) {
    if (s[i] == '?') {
      if (s[i - 1] == 'R')
        s[i] = 'B';
      else
        s[i] = 'R';
    }
  }
  cout << s << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

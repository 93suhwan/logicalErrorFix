#include <bits/stdc++.h>
using namespace std;
void _print(long long w) { cerr << w; }
void _print(int w) { cerr << w; }
void _print(string w) { cerr << w; }
void _print(char w) { cerr << w; }
void _print(long double w) { cerr << w; }
void _print(double w) { cerr << w; }
void _print(unsigned long long w) { cerr << w; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
const int MAX_N = 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> freq(n + 1, 0), fill(n + 1, 0);
  for (int i = 0; i < n; i++) cin >> v[i], freq[v[i]]++;
  vector<int> freq1 = freq;
  sort(v.begin(), v.end());
  ;
  ;
  int last_pos = -1;
  vector<int> temp;
  for (int i = 0; i <= n; i++) {
    ;
    if (freq[i] > 1) last_pos = i;
    if (freq[i] == 0) {
      if (freq[last_pos] <= 1) {
        while (freq[last_pos] <= 1) {
          if (last_pos < 0) {
            last_pos = -1;
            break;
          }
          last_pos--;
        }
      };
      if (last_pos == -1) {
        fill[i] = -1;
      } else {
        fill[i] = (i > 0 ? fill[i - 1] : 0) + (i - last_pos);
        freq[last_pos]--;
      }
    } else {
      fill[i] = (i > 0 ? fill[i - 1] : 0);
    };
  }
  for (int i = 0; i < n + 1; i++) {
    if (i == 0) {
      cout << freq1[0] << " ";
      continue;
    }
    if (fill[i - 1] == -1) {
      cout << -1 << " ";
    } else {
      cout << fill[i - 1] + freq1[i] << " ";
    }
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}

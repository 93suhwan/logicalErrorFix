#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:268435456")
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
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
int binarySearch(int s[], int n, int key) {
  int l = 0, r = n - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (s[m] == key) {
      return m;
    } else if (s[m] > key) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return -1;
}
long long power(long long x, long long y) {
  if (y == 0) return 1;
  if (y % 2 == 0) {
    long long temp = power(x, y / 2);
    return (temp * temp) % 1000000007;
  } else {
    return (x * power(x, y - 1)) % 1000000007;
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int l = 1, r = 1;
  for (int i = 1; i < n; i++)
    if (a[i] > a[i - 1])
      l++;
    else
      break;
  for (int i = n - 2; i >= 0; i--)
    if (a[i] > a[i + 1])
      r++;
    else
      break;
  int lpointer = 0, rpointer = n - 1;
  bool turn = 1, win = 0;
  while (lpointer < rpointer) {
    if (a[lpointer] == a[rpointer]) {
      if (l % 2 == 1 || r % 2 == 1) {
        win = 1;
      }
      if (win) {
        if (turn) {
          cout << "Alice" << endl;
        } else {
          cout << "Bob" << endl;
        }
      } else {
        if (!turn) {
          cout << "Alice" << endl;
        } else {
          cout << "Bob" << endl;
        }
      }
      return;
    } else if (a[lpointer] < a[rpointer]) {
      if (r % 2 == 1) {
        if (turn) {
          cout << "Alice" << endl;
        } else {
          cout << "Bob" << endl;
        }
        return;
      } else if (l == 0) {
        if (!turn) {
          cout << "Alice" << endl;
        } else {
          cout << "Bob" << endl;
        }
        return;
      } else {
        l--;
        lpointer++;
      }
    } else if (a[lpointer] > a[rpointer]) {
      if (l % 2 == 1) {
        if (turn) {
          cout << "Alice" << endl;
        } else {
          cout << "Bob" << endl;
        }
        return;
      } else if (r == 0) {
        if (!turn) {
          cout << "Alice" << endl;
        } else {
          cout << "Bob" << endl;
        }
        return;
      } else {
        r--;
        rpointer--;
      }
    }
    turn = !turn;
  }
  if (turn) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

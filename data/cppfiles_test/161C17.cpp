#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
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
vector<long long> sieve(int n) {
  int* arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
void solve1(int ttc) {
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  vector<bool> rem(n + 1);
  for (int i = 1; i <= n; i++) {
    rem[i] = true;
  }
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    a.push_back(make_pair(l, r));
  }
  sort(a.begin(), a.end());
  for (int i = n - 1; i >= 0; i--) {
    int fir = a[i].first;
    int sec = a[i].second;
    if (fir == sec) {
      rem[fir] = false;
      cout << fir << " " << sec << " " << fir << "\n";
    } else if (rem[sec]) {
      rem[sec] = false;
      cout << fir << " " << sec << " " << sec << "\n";
    } else if (rem[fir] and fir != 1) {
      cout << fir << " " << sec << " " << fir << "\n";
      rem[fir] = false;
    } else {
      int f = 1;
      for (int i = 2; i < n; i++) {
        if (rem[i]) {
          rem[i] = false;
          cout << fir << " " << sec << " " << i << "\n";
          f = 0;
        }
      }
      if (f) cout << fir << " " << sec << " " << fir << "\n";
    }
  }
  cout << "\n";
}
map<pair<int, int>, bool> m;
pair<int, int> a[N];
map<pair<int, int>, int> ans;
void get(int s, int n) {
  if (s == n) {
    ans[{s, n}] = s;
    return;
  }
  for (int i = s; i <= n; i++) {
    if (i == s) {
      if (m[{i + 1, n}]) {
        ans[{s, n}] = i;
        get(i + 1, n);
        break;
      }
    } else if (i == n) {
      if (m[{s, i - 1}]) {
        ans[{s, n}] = i;
        get(s, i - 1);
        break;
      }
    } else {
      if (m[{s, i - 1}] && m[{i + 1, n}]) {
        ans[{s, n}] = i;
        get(s, i - 1);
        get(i + 1, n);
        break;
      }
    }
  }
}
int n;
void solve() {
  cin >> n;
  m.clear();
  ans.clear();
  int s = 1, en = n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    m[{a[i].first, a[i].second}] = true;
  }
  get(s, n);
  for (auto it : m) {
    if (ans[it.first]) {
      cout << it.first.first << " " << it.first.second << " " << ans[it.first]
           << "\n";
    }
  }
}
void get(int ttc) {
  int n;
  cin >> n;
  vector<pair<int, pair<int, int>>> a;
  vector<bool> rem(n + 1);
  for (int i = 1; i <= n; i++) {
    rem[i] = true;
  }
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    a.push_back(make_pair(l + r, make_pair(l, r)));
  }
  sort(a.begin(), a.end());
  ;
  vector<pair<int, pair<int, int>>> ans = a;
  for (int i = 0; i < n; i++) {
    int l = ans[i].second.first;
    int r = ans[i].second.second;
    if (i <= n - 1) {
      int l1 = ans[i + 1].second.first;
      int r1 = ans[i + 1].second.second;
      if (l1 + r1 == l + r) {
        if (r1 == i + 1) {
          ans[i + 1].first = i + 1;
        } else {
          ans[i].first = i + 1;
        }
      }
      ans[i].first = i + 1;
      i++;
      continue;
    }
    ans[i].first = i + 1;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i].second.first << " " << ans[i].second.second << " "
         << ans[i].first << "\n";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int ttc = 1;
  cin >> ttc;
  for (int i = 1; i <= ttc; i++) {
    solve();
  }
  return 0;
}

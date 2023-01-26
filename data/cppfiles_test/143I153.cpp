#include <bits/stdc++.h>
using namespace std;
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
void showpq(priority_queue<int> gq) {
  priority_queue<int> g = gq;
  while (!g.empty()) {
    cerr << '\t' << g.top();
    g.pop();
  }
  cerr << '\n';
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
void solve() {
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> ar(n);
    map<int, int> count;
    set<int> numbers;
    priority_queue<int> great;
    vector<int> ans;
    int minVal = 0;
    bool possible = true;
    for (int i = 0; i < n; i++) {
      cin >> ar[i];
      numbers.insert(ar[i]);
      count[ar[i]]++;
    }
    sort((ar).begin(), (ar).end());
    for (int i = 0; i <= n; i++) {
      if (count[i] > 1) great.push(i);
      if (i == 0) {
        if (count[i] > 0) {
          ans.push_back(count[i] + minVal);
        } else {
          ans.push_back(0);
          possible = false;
        }
      } else if (i == n && possible) {
        if (count[i] > 0) {
          ans.push_back(-1);
        } else {
          ans.push_back(minVal);
        }
      } else if (count[i] > 0 && possible) {
        ans.push_back(count[i] + minVal);
      } else if (possible) {
        ans.push_back(minVal);
        if (great.size() == 0)
          possible = false;
        else {
          int curr = great.top();
          great.pop();
          count[i] = 1;
          count[curr]--;
          minVal += i - curr;
          if (count[curr] > 1) great.push(curr);
        }
      } else {
        ans.push_back(-1);
      }
    };
    for (auto i : ans) cout << i << " ";
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}

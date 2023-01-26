#include <bits/stdc++.h>
using namespace std;
void debug(long long int n) {
  cout << n;
  cout << '\n';
}
void debug(double n) {
  cout << n;
  cout << '\n';
}
void debug(string n) {
  cout << n;
  cout << '\n';
}
void debug(char n) {
  cout << n;
  cout << '\n';
}
void debug(vector<long long int> a) {
  for (long long int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
}
void debug(vector<double> a) {
  for (long long int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
}
void debug(vector<string> a) {
  for (long long int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
}
void debug(vector<pair<long long int, long long int>> a) {
  for (long long int i = 0; i < a.size(); i++) {
    cout << a[i].first << " " << a[i].second;
    cout << '\n';
  }
}
void debug(vector<pair<double, double>> a) {
  for (long long int i = 0; i < a.size(); i++) {
    cout << a[i].first << " " << a[i].second;
    cout << '\n';
  }
}
void debug(vector<pair<string, string>> a) {
  for (long long int i = 0; i < a.size(); i++) {
    cout << a[i].first << " " << a[i].second;
    cout << '\n';
  }
}
void debug(vector<vector<long long int>> a) {
  for (long long int i = 0; i < a.size(); i++) {
    for (long long int j = 0; j < a[i].size(); j++) cout << a[i][j] << " ";
    cout << '\n';
  }
}
void debug(vector<vector<double>> a) {
  for (long long int i = 0; i < a.size(); i++) {
    for (long long int j = 0; j < a[i].size(); j++) cout << a[i][j] << " ";
    cout << '\n';
  }
}
void debug(vector<vector<string>> a) {
  for (long long int i = 0; i < a.size(); i++) {
    for (long long int j = 0; j < a[i].size(); j++) cout << a[i][j] << " ";
    cout << '\n';
  }
}
void debug(vector<vector<char>> a) {
  for (long long int i = 0; i < a.size(); i++) {
    for (long long int j = 0; j < a[i].size(); j++) cout << a[i][j] << " ";
    cout << '\n';
  }
}
void debug(unordered_map<long long int, long long int> a) {
  for (auto e : a) {
    cout << e.first << " " << e.second;
    cout << '\n';
  }
}
void debug(unordered_map<double, double> a) {
  for (auto e : a) {
    cout << e.first << " " << e.second;
    cout << '\n';
  }
}
template <typename T>
bool isprime(T n) {
  for (long long int i = 2; i <= (T)sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
template <typename T1, typename T2>
bool fs(pair<T1, T2> &a, pair<T1, T2> &b) {
  if (a.first < b.first) return 1;
  if (a.first > b.first) return 0;
  return a.second < b.second;
}
template <typename T1, typename T2>
bool sf(pair<T1, T2> &a, pair<T1, T2> &b) {
  if (a.second < b.second) return 1;
  if (a.second > b.second) return 0;
  return a.first < b.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1)
      cout << -1 << ' ' << -1;
    else {
      long long int ind = -1;
      for (long long int i = 0; i < n - 1; i++) {
        if (s[i] == 'a' && s[i + 1] == 'b') {
          ind = i + 1;
          break;
        }
        if (s[i] == 'b' && s[i + 1] == 'a') {
          ind = i + 1;
          break;
        }
      }
      cout << ind << ' ' << ind + 1;
    }
    cout << '\n';
    ;
  }
  return 0;
}

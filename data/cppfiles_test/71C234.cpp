#include <bits/stdc++.h>
using namespace std;
const int m_x[] = {-1, 0, 0, 1};
const int m_y[] = {0, -1, 1, 0};
template <typename T, typename S>
ostream& operator<<(ostream& output, const pair<T, S>& to_print) {
  output << to_print.first << ":" << to_print.second;
  return output;
}
template <typename T, typename S>
ostream& operator<<(ostream& output, const map<T, S>& to_print) {
  for (typename map<T, S>::const_iterator it = to_print.begin();
       it != to_print.end(); it++)
    output << *it << endl;
  return output;
}
template <typename T>
ostream& operator<<(ostream& output, const vector<T>& to_print) {
  for (typename vector<T>::const_iterator it = to_print.begin();
       it != to_print.end(); it++)
    output << *it << " ";
  return output;
}
template <typename T>
ostream& operator<<(ostream& output, const set<T>& to_print) {
  for (typename set<T>::const_iterator it = to_print.begin();
       it != to_print.end(); it++)
    output << *it << " ";
  return output;
}
template <typename T>
ostream& operator<<(ostream& output, const multiset<T>& to_print) {
  for (typename multiset<T>::const_iterator it = to_print.begin();
       it != to_print.end(); it++)
    output << *it << " ";
  return output;
}
void decAt(map<char, int>& cnt, char c) {
  cnt[c]--;
  if (cnt[c] == 0) cnt.erase(c);
}
void replaceSuffix(string& n, int pref, char c) {
  for (int i = pref; i < n.length(); i++) n[i] = c;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string n;
    int k;
    cin >> n >> k;
    map<char, int> cnt;
    int pref = 0;
    while (pref < n.length()) {
      if (cnt.count(n[pref]))
        cnt[n[pref++]]++;
      else {
        if (cnt.size() == k) break;
        cnt[n[pref++]]++;
      }
    }
    if (pref == n.length())
      cout << n << "\n";
    else {
      while (true) {
        if (n[pref] == '9')
          decAt(cnt, n[--pref]);
        else {
          if (cnt.size() < k) {
            cnt[++n[pref]]++;
            replaceSuffix(n, pref + 1,
                          cnt.size() < k ? '0' : cnt.begin()->first);
            break;
          } else {
            map<char, int>::iterator it = cnt.upper_bound(n[pref]);
            if (it == cnt.end())
              decAt(cnt, n[--pref]);
            else {
              n[pref] = it->first;
              replaceSuffix(n, pref + 1, cnt.begin()->first);
              break;
            }
          }
        }
      }
      cout << n << "\n";
    }
  }
  return 0;
}

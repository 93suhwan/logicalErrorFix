#include <bits/stdc++.h>
using namespace std;
template <typename type_first, typename type_second>
ostream& operator<<(ostream& out, const pair<type_first, type_second> P) {
  out << '{' << P.first << ',' << P.second << '}';
  return out;
}
template <typename type_iterator>
string ite2string(type_iterator begin, type_iterator end) {
  stringstream out;
  bool inserted = false;
  out << '[';
  while (begin != end) {
    out << *begin << ", ";
    inserted = true;
    begin++;
  }
  string ans = out.str();
  if (inserted) {
    ans.pop_back();
    ans.pop_back();
  }
  return ans + ']';
}
template <class stream, class iterable,
          class begin = decltype(begin(declval<iterable>()))>
stream& operator<<(stream& out, const iterable I) {
  out << ite2string(I.begin(), I.end());
  return out;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  unsigned int n;
  cin >> n;
  vector<unsigned int> a(n);
  for (auto& i : a) cin >> i;
  unsigned int l_inc = 1, r_inc = 1;
  for (; l_inc < n and a[l_inc] > a[l_inc - 1]; l_inc++)
    ;
  for (; r_inc < n and a[n - r_inc] < a[n - r_inc - 1]; r_inc++)
    ;
  ;
  ;
  if (l_inc == n and r_inc == n) {
    if (n % 2 == 0) {
      cout << "Bob" << '\n';
    } else {
      cout << "Alice" << '\n';
    }
    exit(0);
  }
  unsigned int li = 0, ri = n - 1;
  bool alice = true;
  int last = -1;
  while (true) {
    ;
    if (l_inc == 0 or last >= int(a[ri])) {
      if (r_inc % 2 == 1) {
        if (alice) {
          cout << "Alice" << '\n';
        } else {
          cout << "Bob" << '\n';
        }
      } else {
        if (alice) {
          cout << "Bob" << '\n';
        } else {
          cout << "Alice" << '\n';
        }
      }
      break;
    }
    if (r_inc == 0 or last >= int(a[li])) {
      if (l_inc % 2 == 1) {
        if (alice) {
          cout << "Alice" << '\n';
        } else {
          cout << "Bob" << '\n';
        }
      } else {
        if (alice) {
          cout << "Bob" << '\n';
        } else {
          cout << "Alice" << '\n';
        }
      }
      break;
    }
    if (a[li] > a[ri]) {
      if (l_inc % 2 == 1) {
        if (alice) {
          cout << "Alice" << '\n';
        } else {
          cout << "Bob" << '\n';
        }
        break;
      } else {
        r_inc--;
        ri--;
      }
    } else if (a[ri] > a[li]) {
      if (r_inc % 2 == 1) {
        if (alice) {
          cout << "Alice" << '\n';
        } else {
          cout << "Bob" << '\n';
        }
        break;
      } else {
        l_inc--;
        li++;
      }
    } else {
      if (r_inc % 2 == 1 or l_inc % 2 == 1) {
        if (alice) {
          cout << "Alice" << '\n';
        } else {
          cout << "Bob" << '\n';
        }
        break;
      } else {
        if (alice) {
          cout << "Bob" << '\n';
        } else {
          cout << "Alice" << '\n';
        }
      }
      break;
    }
    alice = !alice;
  }
  return 0;
}

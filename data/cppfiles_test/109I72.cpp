#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << "{" << p.first << "," << p.second << "}";
  return os;
}
class A {
 public:
  int x;
  A(int x) {
    cout << ("constructor A:" + to_string(x)) << " mem:" << this << endl;
    this->x = x;
  }
  A(const A &a) {
    cerr << "line " << 31 << " : "
         << "\"copy constructor A\""
         << " --> " << ("copy constructor A") << endl;
    x = a.x;
  }
  A &operator=(const A &a) {
    cerr << "line " << 35 << " : "
         << "\"assignment operator A\""
         << " --> " << ("assignment operator A") << endl;
    x = a.x;
    return *this;
  }
  A *clone() { return new A(*this); }
  ~A() {
    cout << ("destructor A:" + to_string(x)) << " mem:" << this << endl;
    x = -1;
  }
  bool operator==(const A &a) const {
    cerr << "line " << 45 << " : "
         << "\"equivalence operator\""
         << " --> " << ("equivalence operator") << endl;
    return x == a.x;
  }
  bool operator!=(const A &a) const {
    cerr << "line " << 49 << " : "
         << "\"non eq operator\""
         << " --> " << ("non eq operator") << endl;
    return x == a.x;
  }
  bool operator<(const A &a) const { return x < a.x; }
  friend ostream &operator<<(ostream &os, const A &a) {
    return os << "A.x=" << a.x;
  }
};
class mapCmp {
 public:
  bool operator()(A *a, A *b) const { return *(a) < *(b); }
};
class uniqCmp {
 public:
  bool operator()(const unique_ptr<A> &lhs, const unique_ptr<A> &rhs) const {
    return *lhs < *rhs;
  }
};
ostream &operator<<(ostream &os, const unique_ptr<A> &a) {
  return os << (*(a));
}
void testuniqpointer() {
  map<unique_ptr<A>, int, uniqCmp> mp;
  A *a = new A(3);
  A *b = new A(1);
  cerr << "line " << 77 << " : "
       << "a"
       << " --> " << (a) << endl;
  cerr << "line " << 78 << " : "
       << "b"
       << " --> " << (b) << endl;
  unique_ptr<A> ua(a);
  unique_ptr<A> ub(b);
  cerr << "line " << 81 << " : "
       << "*(ua)"
       << " --> " << (*(ua)) << endl;
  cerr << "line " << 82 << " : "
       << "*(ub)"
       << " --> " << (*(ub)) << endl;
  mp[move(ua)] = 1;
  mp[move(ub)] = 2;
  cerr << "line " << 85 << " : "
       << "&mp"
       << " --> " << (&mp) << endl;
  for (const pair<const unique_ptr<A>, int> &i : mp) {
    cout << i << " ";
  }
  cout << endl;
  {
    unique_ptr<A> uc(new A(3));
    if (mp.find(uc) != mp.end()) {
      cerr << "line " << 93 << " : "
           << "\"found\""
           << " --> " << ("found") << endl;
    } else
      cerr << "line " << 95 << " : "
           << "\"not found\""
           << " --> " << ("not found") << endl;
    {
      cerr << "line " << 97 << " : "
           << "mp[move(uc)]"
           << " --> " << (mp[move(uc)]) << endl;
      cerr << "line " << 98 << " : "
           << "\"outofscope\""
           << " --> " << ("outofscope") << endl;
    }
  }
  cerr << "line " << 101 << " : "
       << "&mp"
       << " --> " << (&mp) << endl;
  for (const pair<const unique_ptr<A>, int> &i : mp) {
    cout << i << " ";
  }
  cout << endl;
}
void testnormalpointer() {
  map<A *, int, mapCmp> mp;
  A *a = new A(3);
  A *b = new A(1);
  mp[a] = 1;
  mp[b] = 2;
  cerr << "line " << 113 << " : "
       << "&mp"
       << " --> " << (&mp) << endl;
  for (auto i : mp) {
    cout << i << " ";
  }
  cout << endl;
  A *c = new A(1);
  cerr << "line " << 119 << " : "
       << "c"
       << " --> " << (c) << endl;
  if (mp.find(c) == mp.end()) {
    cerr << "line " << 121 << " : "
         << "\"not found\""
         << " --> " << ("not found") << endl;
  } else
    cerr << "line " << 123 << " : "
         << "\"found\""
         << " --> " << ("found") << endl;
  cerr << "line " << 124 << " : "
       << "mp[c]"
       << " --> " << (mp[c]) << endl;
  mp[c] = 3;
  A *d = c->clone();
  cerr << "line " << 127 << " : "
       << "mp[d]"
       << " --> " << (mp[d]) << endl;
  cerr << "line " << 128 << " : "
       << "&mp"
       << " --> " << (&mp) << endl;
  for (auto i : mp) {
    cout << i << " ";
  }
  cout << endl;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  testnormalpointer();
  return 0;
}

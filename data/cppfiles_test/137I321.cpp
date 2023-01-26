#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define pb push_back
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << '{' << p.first << ", " << p.second << '}';
}
template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c) {
  os << '[';
  for (auto it = c.begin(); it != c.end(); ++it)
    os << &", "[2 * (it == c.begin())] << *it;
  return os << ']';
}
#define _NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define _FE_0(_CALL, ...)
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                             \
  _NTH_ARG(dummy, ##__VA_ARGS__, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1, _FE_0)     \
  (MACRO, ##__VA_ARGS__)
#define out(x) #x " = " << x << "; "
#define dbg(...)                                                              \
  cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
ld PI=acos(-1);

/*
    ordered_set o_set;
    order_of_key (k) : Number of items strictly smaller than k .
    find_by_order(k) : K-th element in a set (counting from zero). return an iterator
*/
const long long N = 2e5+5 , M = 9e9+7 , OO = 1e18 , M1 = 1e9+7 , M2 = 1e9+9 , p1 = 31 , p2 = 47;

string bin(ll x){
    string ans = "";
    while(x){
        if (x % 2) ans += '1';
        else ans += '0';
        x /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool check(string str1, string str2){
    int n = str1.size(), m = str2.size();
    deque<int> found;
    for (int i = 0; i <= m - n; i++){
        if (str2.substr(i, n) == str1) found.pb(i);
    }
    if (found.size() == 0) return 0;
    for (auto x : found){
        for (int i = 0; i < x; ++i){
            if (str2[i] != '1' || str2.back() == '0') return 0;
        }
        for (int i = x + n; i < m; ++i){
            if (str2[i] != '1') return 0;
        }
    }
    return 1;
}

void test_case(){

    ll x, y; cin >> x >> y;
    bool ans = false;
    string str1 = bin(x);
    string str2 = bin(y);
    //cout << str1 << endl;
    //cout << str2 << endl;
    string tmp1 = str1, tmp2 = str2;
    ans |= check(tmp1, tmp2);
    while(tmp1.back() == 0){
        tmp1.pop_back();
    }
    ans |= check(tmp1, tmp2);
    reverse(tmp1.begin(), tmp1.end());
    ans |= check(tmp1, tmp2);
    str1 = str1 + '1';
    reverse(str1.begin(), str1.end());
    ans |= check(str1, str2);
    if (ans) cout << "YES\n";
    else cout << "NO\n";



}


int main() {

    FIO
    //freopen("xmore.in", "rt", stdin);
    //freopen("lepus.out", "wt", stdout);
    int tc = 1;
    //cin >> tc;
    while(tc--){
        test_case();
    }

    return 0;
}

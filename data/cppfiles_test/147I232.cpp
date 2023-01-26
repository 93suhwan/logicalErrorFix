#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T> bool ckmin(T& a, const T& b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T& a, const T& b) {return a < b ? a = b, 1 : 0;}

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define F0R(i,a) for(int i = 0; i < a; i++)
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define newl "\n"
#define pb push_back
#define f first 
#define s second

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << "\n", 0;
#define bug(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " " <<


int main() { FAST

    int T;
    cin >> T;
    F0R(t, T) {
        string str;
        cin >> str;
        int n = sz(str);
        bool pref_same = true;
        bool suff_same = true;
        F0R(i, n - 2) {
            pref_same &= (str[i] == str[i + 1]);
            suff_same &= (str[i + 1] == str[i + 2]);
        }
        if ((pref_same || suff_same) && str[n - 1] != str[0]) {
            cout << "NO" << newl;
        } else {
            cout << "YES" << newl;
        }
    }    

    return 0;
}

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;

const int inf = 1e9;
const ll llinf = 1e18;
const int mod = 1e9 + 7;
const double PI = acos(-1);

struct chash {
    const uint64_t C = ll(2e18*PI)+71;
    const int RANDOM = rand();
    ll operator()(ll x) const {
        return __builtin_bswap64((x^RANDOM)*C);
    }
};

template<class K> using sset =  tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
template<class K, class V> using gphash = gp_hash_table<K, V, chash, equal_to<K>, direct_mask_range_hashing<>, linear_probe_fn<>, hash_standard_resize_policy< hash_exponential_size_policy<>, hash_load_check_resize_trigger<>, true> >;

inline ll ceil0(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
}

inline ll floor0(ll a, ll b) {
    return a / b - ((a ^ b) < 0 && a % b);
}

void setIO() {
    ios_base::sync_with_stdio(0); cin.tie(0);
}

ll arr[300000], n, k;

bool check(ll x){
    ll sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    if(sum - x <= k) return true;
    ll sub = 0;
    for(int i = n - 1; i >= 1; i--){
        sub += arr[i];
        ll cur = (k - sum + sub + arr[0]);
        if(cur >= 0) cur /= n - i + 1;
        else cur = floor0(cur, n - i + 1);
        if(arr[0] - cur + n - i <= x) return true;
    } 
    return false;
}

int main(){
    setIO();
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        ll l = 0, r = 2e9;
        while(l < r){
            ll mid = (l + r)/2;
            //if(n == 7) cout << l << " " << r << " " << mid << endl;
            if(check(mid)){
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l << endl;
    }
}
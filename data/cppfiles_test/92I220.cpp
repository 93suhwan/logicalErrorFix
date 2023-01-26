#include <bits\stdc++.h>
#define Lnnnb return 0;
#define ll long long

using namespace std;
void init();
ll t,n;
char a[202];

void scan(){
    cin >> a+1 ;
    n = strlen(a+1);
}

void solve(){
    ll ab = 0 , ba = 0 , aa = 0;
    ll minn = 4e18 , l , r , num;
    for(ll i = 1 ; i <= n ; ++i)aa += (a[i] == 'a');
    for(ll i = 1 ; i <= n-1 ; ++i){
        if( (a[i] == 'a' && a[i+1] == 'b') || (a[i] == 'b' && a[i+1] == 'a')){
            num = i;
            if(minn > num){
                minn = num;
                l = 1;
                r = i;
            }
            ab += (a[i] == 'a' && a[i+1] == 'b');
            ba += (a[i] == 'b' && a[i+1] == 'a');
            break;
        }
    }
    for(ll i = n ; i >= 2 ; --i){
        if( (a[i-1] == 'a' && a[i] == 'b') || (a[i-1] == 'b' && a[i] == 'a')){
            num = n-i+1;
            if(minn > num){
                minn = num;
                l = i;
                r = n;
            }
            ab += (a[i-1] == 'a' && a[i] == 'b');
            ba += (a[i-1] == 'b' && a[i] == 'a');
            break;
        }
    }
    if(ab == ba)cout << a+1 << endl ;
    else {
        if(ab){
            if(l == 1){
                for(ll i = l ; i <= r ; i += 2)
                    a[i] = 'b';
            }else {
                for(ll i = r ; i >= l ; i -= 2)
                    a[i] = 'a';
            }
        }else {
            if(l == 1){
                for(ll i = l ; i <= r ; i += 2)
                    a[i] = 'a';
            }else {
                for(ll i = r ; i >= l ; i -= 2)
                    a[i] = 'b';
            }
        }
        cout << a+1 << endl ;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ///t = 1;
    cin >> t ;
    while(t--){
        scan();
        solve();
        init();
    }
    Lnnnb
}

void init(){
    memset(a,0,sizeof(a));
}



/*
#include <bits\stdc++.h>
#define Lnnnb return 0;
#define ll long long

using namespace std;
void init();
ll t,n,k,a[2020],ten[20],ok[20],num[20],jj[20];

void scan(){
    cin >> n >> k ;
    for(ll i = 1 ; i <= n ; ++i)
        cin >> a[i] , ok[a[i]] = 1;
}

void solve(){
    if(!ok[0]){
        cout << 1 << endl ;
    }else {
        ll now = k , sum = k;
        while(1){
            ll re = 1;
            for(ll j = 1 ; j <= 9 ; ++j){
                if(!ok[j])continue;
                ll ned = ten[j]-1;
                if(sum > ned){
                    ll can = sum - ned;
                    now += can*ned;
                    sum -= can;
                    re = 0;
                    cout << can << endl ;
                    break;
                }
            }
            if(re)break;
        }
        cout << now+1 << endl ;
    }
}

int main(){
    ten[0] = 1;
    for(ll i = 1 ; i <= 9 ; ++i)
        ten[i] = ten[i-1]*10;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ///t = 1;
    cin >> t ;
    while(t--){
        scan();
        solve();
        init();
    }
    Lnnnb
}

void init(){
    memset(ok,0,sizeof(ok));
    memset(num,0,sizeof(num));
}
*/

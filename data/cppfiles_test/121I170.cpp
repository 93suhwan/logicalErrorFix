/*


😡😡😡😡😡😡😡
😁I'm so angry!😁
💀💀💀💀💀💀💀
😑😤😤😤😤😤😑
  🔥✂✂✂✂✂🔥
😡😡😡😡😡😡😡
*/
#include<bits/stdc++.h>
/*
Created By Tornado2004
*/
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define debug(x) cout << '[' << #x << " is: " << x << "] " << endl;
#define imod(a , n) (a % n + n ) % n

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define inF freopen("facebookinput.txt","r",stdin );
#define outF freopen("facebookoutput.txt" , "w" , stdout ) ;
#define sor(v) sort(v.begin() , v.end());
#define print(v) for(auto f : v ) cout << f << " " ;
#define rsor(v) sort(v.rbegin() , v.rend());
#define rev(v) reverse(v.begin() , v.end());
#define scan(v)for(auto &it : v)cin >> it ;

#define ll long long
#define int ll
#define logar(x , y) log(x) / log(y)
#define __sum(n) n * (n + 1) / 2
#define __lcm(a , b) a / __gcd(a , b) * b
#define pii pair<int , int >
const int N = 5e3 + 1 ,  M = N * 4 , MX = 2e4 + 40;
const ll MOD = 1e9+ 7 , oo = 1e9 + 9 , OO = 1e18 , mod = MOD ;
const double pi = acos(-1) , eps = 1e-17 ;
// 49 .. 21/11/2021
//37
// (a ^ b / c ) % mod = (a ^ b ) % MOD * (c ^ (mod - 2)) % mod
// m is prime --> (a ^ m) % m = a % m

int di[] = {0 , 0 , 1 , -1};
int dj[] = {1 , -1 , 0 , 0};


int32_t main()
{   //inF;
    //inF;outF;
    fastio;



    int t ;
    cin >> t ;


    while(t--){
        int n ;
        string a , b ;
        cin >> n >> a >> b ;



        int ok = 0 , ntok = 0 ;
        int onesinok = 0 , onesinnt = 0 ;

        for(int i = 0;i< n ; i ++){
            if(a[i] == b[i]){

                ok ++ ;

                if(a[i] == '1')onesinok ++ ;
            }
            else {
                ntok ++ ;
                if(a[i] == '1')onesinnt ++ ;
            }


        }
        int zok = ok - onesinok , znt = ntok - onesinnt ;
        int mn = oo ;

        if(zok == onesinok || zok == onesinok - 1)mn = ok;
        if(znt == onesinnt || znt == onesinnt - 1)mn = min(mn , ntok);
        if(mn == oo)cout << -1 ;
        else cout << mn ;

        cout << '\n';
    }
}

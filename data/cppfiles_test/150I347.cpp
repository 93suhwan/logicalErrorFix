#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector <int> vi;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
typedef map <int,int> mi;
typedef set<int> si;
typedef multiset<int> msi;
 
int M = 1e9+7;
ll INF = 1e18;
int NUM = 998244353;
 
#define nl <<"\n"
#define pb push_back
#define pr make_pair
#define ci cin>>
#define co cout<<
#define space <<" "
#define precision(n) std::cout << std::setprecision(n);
#define all(v) v.begin(),v.end()
#define fi first
#define se second
 
 
ll power(ll a , ll b ,ll p){      //a^b modulo p
    ll res=1,temp=a;
    if(b<=0)
        return 1;
    while(b){
        if(b%2){
            res=(res*temp)%p;
            b--;
        }
        else{
            b/=2;
            temp=(temp*temp)%p;
        }
    }
    return res;
}
 
ll inverse(ll a, ll p){
    return power(a, p-2,p);
}
 
//--------------------------------------------------------------------------------------------------//
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
 
    int t=1;
    ci t;
    while(t--){
        int n;
        ci n;
        int arr[n];
        for(int i=0;i<n;i++){
            ci arr[i];
        }
        sort(arr,arr+n);
        int approx3 = arr[n-1]/3,ans=M;
        for(int cnt1=0;cnt1<=2;cnt1++){
            for(int cnt2=0;cnt2<=2;cnt2++){
                if(cnt1+2*cnt2>=3)
                    continue;
                for(int cnt3 = max(approx3-1,0);cnt3<=approx3;cnt3++){
                    int temp = cnt1+cnt2+cnt3;
                    if(temp>=ans)
                        continue;
                    else{
                        // co cnt1 space<<cnt2 space<<cnt3 nl;
                        int mark[n]={};
                        for(int i=0;i<n;i++){
                            for(int j=0;j<=cnt1;j++){//count1
                                for(int k=0;k<=cnt2;k++){//count2
                                    int rem = arr[i]-j-2*k;
                                    if(rem>=0 && rem%3==0 && rem/3 <=cnt3){
                                        mark[i]=1;
                                    }
                                }
                            }
                        }
                        int fl=1;
                        for(int i=0;i<n;i++){
                            if(mark[i]==0){
                                fl=0;
                                break;
                            }
                        }
                        if(fl){
                            ans=temp;
                        }
                    }
                }
            }
        }
        co ans nl;
    }
    return 0;
}
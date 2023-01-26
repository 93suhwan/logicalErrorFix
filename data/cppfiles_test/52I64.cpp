#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);
#define input cin.tie(NULL);
#define output cout.tie(NULL);
#define MOD 1000000007
#define lli long long int
#define rep(i, m, n) for (auto i = m; i < n; i++)
#define pb push_back
#define fr first
#define sc second
#define pi 3.141592653589793238
#define Setpre(n) cout<<fixed<<setprecision(n)

using namespace std;

auto ask(lli k){
    vector <lli> index;
    lli b=1;
    lli i=0;
    while(b<=1e9){
        index.push_back(i);
        i=i+1;
        b=b*2;
    }

    auto it=index.begin();
    while(k>=pow(2,(*it))){
        it++;
        // cout<<"hihi "<<k<<' '<<(*it)<<endl;
    }
    auto low=it;
    low--;
    auto high=it;

    return (*low);
}

lli modFact(lli n, lli p)
{
    // if (n >= MOD)
    //     return 0;
 
    lli result = 1;
    for (lli i = 1; i <= p; i++)
        result = (result * n) % MOD;
 
    return result;
}

lli power(lli x, lli y,lli p)
{
    lli res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main(){
    fast input output


    int t;
    cin>>t;

    while(t--){
        lli n,k;
        cin>>n>>k;

        vector <lli> v;
        lli a=1;
        while(a<=1e9){
            v.push_back(a);
            a=a*n;
        }

        // vector <lli> index;
        // lli b=1;
        // lli i=0;
        // while(b<=1e9){
        //     index.push_back(i);
        //     i=i+1;
        //     b=b*2;
        // }

        // auto it=index.begin();
        // while(k>=pow(2,(*it))){
        //     it++;
        //     // cout<<"hihi "<<k<<' '<<(*it)<<endl;
        // }
        // auto low=it;
        // low--;
        // auto high=it;
        // // high++;
        // cout<<pow(2,(*low))<<' '<<k<<' '<<pow(2,(*high))<<endl;
        // lli x=ask(k);
        // cout<<"rara "<<ask(k)<<' '<<pow(2,ask(k))<<endl;

        lli ans=n%MOD;

        // if(k==pow(2,(*high))){
        //     cout<<pow(ans,(*high))<<endl;
        // }
        // else{

        // }

        lli sum=0;

        while(k>0){
            // cout<<"raju "<<ask(k)<<' '<<pow(2,ask(k))<<endl;
            lli t=power(n,log2(k),MOD);
            t=t%MOD;
            sum+=t;
            // sum=sum%MOD;
            k=k-pow(2,log2(k));
            // cout<<"hihi "<<k<<' '<<sum<<endl;
        }

        cout<<sum%MOD<<endl;
        // cout<<"hihi "<<modFact(2,30)+modFact(2,29);
    }
    return 0;
}
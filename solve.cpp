#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=1;i<=n;i++) a[i-1]=i;
    vector<int> juft;
    vector<int> toq;
    for(auto x:a){
        if(x%2){
            toq.push_back(x);
        }
        else{
            juft.push_back(x);
        }
    }
    sort(toq.begin(),toq.end());
    sort(juft.begin(),juft.end());
    if(n>1 and n<=3) cout<<"NO SOLUTION";
    else if(n==1) cout<<1;
    else{
        for(auto x:juft){
            cout<<x<<" ";
        } 
        for(auto x:toq) cout<<x<<" ";
        
    }
}
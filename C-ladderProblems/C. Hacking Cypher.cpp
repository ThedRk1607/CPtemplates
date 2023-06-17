
void solve(){
  ll c = 0, n = 0, p=1, i;
    vector<ll> d(1<<21,0);
    string m;
    cin>>m;
    n = m.size();
    ll a,b;
    cin>>a>>b;
    for (i=n-1; i>=0; i--) 
    {
        d[i] = ((m[i] - '0') * p + d[i + 1]) % b;
        p = p * 10 % b;
    }
    for (i=1; i<n; i++) 
    {
        c = (c * 10 + m[i - 1] - '0') % a;
        if (!c && !d[i] && m[i] != '0') 
        {
            cout<<"YES\n";
            printf("%s\n%s\n", m.substr(0,i).c_str(), m.substr(i).c_str());
            return ;
        }
    }

cout<<"NO\n";
}

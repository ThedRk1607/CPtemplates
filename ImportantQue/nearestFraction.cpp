
  int a,b,n;
    cin >>a>>b>> n;
     if (n>= b)
    {
        printf( " %d/%d\n " ,a/gcd(a,b),b/ gcd(a,b));
         return   ;
    }
    double x = a* 1.0 / b* 1.0 ;
     int ans1 = 0 , ans2 = 1 ;
     for ( int i= 1 ;i<=n;i++ )
    {
        int l = 0 , r = 100000 ;
         while (l<= r)
        {
            int mid = (l+r)/ 2 ;
             if (mid* 1.0 /(i* 1.0 )>=x)r=mid- 1 ;
             else l=mid+ 1 ;
        }
        if (fabs((l- 1 )* 1.0 /(i* 1.0 )-x)<fabs((ans1* 1.0 )/(ans2* 1.0 )- x))
            ans1 = l- 1 , ans2 = i;
         if (fabs((l)* 1.0 /(i* 1.0 )-x)<fabs((ans1* 1.0 )/(ans2* 1.0 )- x))
            ans1 = l, ans2 = i;
    }
    printf( " %d/%d\n " ,ans1/gcd(ans1,ans2),ans2/ gcd(ans1,ans2));
}

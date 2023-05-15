ll Xor(ll a, ll b) {
 return a * (a & 1) ^ b * !(b & 1) ^ !!(((a ^ b) + 1) & 2);
}

//facts
f(4*k) = 4*k
f(4*k + 1) = 1
f(4*k + 2) = 4*k + 3
f(4*k + 3) = 0 
  //
  (4k)^(4k+1)^(4k+2)^(4k+3) = 0
  
  //
  def f(x):
    if x % 4 == 3:
        return 0
    elif x % 4 == 0:
        return x
    elif x % 4 == 1:
        return x^(x-1)
    elif x % 4 == 2:
        return x^(x-1)^(x-2)
 
print(f(b) ^ f(a-1))
        //Range sum;  
     ll range(ll L) {
  switch (L & 3) {
  case 0: return L;
  case 1: return 1;
  case 2: return L + 1;
  case 3: return 0;
  }
  return 0;
}
 ll ans = range(B) ^ range(A-1);

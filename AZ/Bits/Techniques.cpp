string getbitstr(int x){
	string cur="";
	while(x){
		if(x%2)cur+='1';
		else cur+='0';
		x/=2;
	}
	if(cur=="")cur='0';
	reverse(all(cur));
	return cur;
}

int sum_of_bits(int x){
	int ans=0;
	int tot=x+1;
	rep(i,0,60){
		int full=(tot/(1LL<<(i+1)));
		int left=tot%(1LL<<(i+1));
		int extra=max(left-(1<<i),0LL);
		ans+=full*(1LL<<i)+extra;
	}
	return ans;
}

int tot_bits_till(int x){
	int ans=0,len=1,num=1;
	while(num<=x){
		int sametill=(num*2)-1;
		if(sametill<=x){
			ans+=len*(sametill-num+1);
			num=sametill+1;
			len++;
		}else{
			ans+=len*(x-num+1);
			break;
		}
	}
	return ans+1; //extra for zero 

}


void solve(){
  //reverse bits;
	unsigned int x=13;
	//x|=(1<<30);
	cout<<(bitset<32>(x))<<nl;

	x=((x&0xFFFF0000)>>16)| ((x&0x0000FFFF)<<16);
	x=((x&0xFF00FF00)>>8)|  ((x&0x00FF00FF)<<8);
	x=((x&0xF0F0F0F0)>>4)|  ((x&0x0F0F0F0F)<<4);
	x=((x&0xCCCCCCCC)>>2)|  ((x&0x33333333)<<2);
	x=((x&0xAAAAAAAA)>>1)|  ((x&0x55555555)<<1);

	cout<<(bitset<32>(x))<<nl;


}
	
	

int rangeBitwiseAnd(int m, int n) {

            // if m !==n that means one of the bits is 0 so keep right shifting 
           //untill all the bits in both are same  and when they are same number of 
           //shift will be equal to number of bits not same just right shift it then

            int s = 0;
            while(m !=n){
                m =  m>>1;
                n = n>>1;

                s++;
            }
             return (m<<s);
        }

int rangeBitwiseAnd(int m,int n){
	int ans=0;
	for(int bit=30;bit>=0;bit--){
		if((m&(1<<bit))!=(n&(1<<bit)))break;
		else {
			ans|=(m&(1<<bit));
		}
	}
	return ans;
}


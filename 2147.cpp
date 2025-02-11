class Solution {
    public:
        int numberOfWays(string corridor) {
            int zeroSeat=1;
            int oneSeat=0;
            int twoSeat=0;
            int mod=1e9+7;
            for(char &ch:corridor){
                if(ch=='S'){
                    zeroSeat=(zeroSeat+twoSeat)%mod;
                    twoSeat=oneSeat;
                    oneSeat=zeroSeat;
                    zeroSeat=0;
                }
                else zeroSeat=(zeroSeat+twoSeat)%mod;
            }
            return twoSeat;
        }
    };
class Solution {
    public:
        int knightDialer(int n) {
            const int mod=1e9+7;
            vector<long long> curPos(10,1);
            for(int i=2;i<=n;i++){
                vector<long long> newPos(10);
                newPos[0]=(curPos[6]+curPos[4])%mod;
                newPos[1]=(curPos[6]+curPos[8])%mod;
                newPos[2]=(curPos[7]+curPos[9])%mod;
                newPos[3]=(curPos[4]+curPos[8])%mod;
                newPos[4]=(curPos[0]+curPos[3]+curPos[9])%mod;
                newPos[5]=0;
                newPos[6]=(curPos[0]+curPos[1]+curPos[7])%mod;
                newPos[7]=(curPos[2]+curPos[6])%mod;
                newPos[8]=(curPos[1]+curPos[3])%mod;
                newPos[9]=(curPos[2]+curPos[4])%mod;
                curPos=newPos;
            }
            long long ans=0;
            for(int i=0;i<10;i++) ans=(ans+curPos[i])%mod;
            return ans;
        }
    };
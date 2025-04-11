class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            int num=i;
            int n=i;
            int c=0,sumfirst=0, sumlast=0;
            while(num>0){
                num=num/10;
                c++;
            }
            if(c%2!=0)
            continue;

            for(int j=0;j<c/2;j++){
                int d=n%10;
                sumfirst+=d;
                n=n/10;
            }

            for(int k=c/2;k<=c;k++){
                int d=n%10;
                sumlast+=d;
                n=n/10;
            }
            if(sumfirst==sumlast)
            count++;

        }

        return count;
    }
};
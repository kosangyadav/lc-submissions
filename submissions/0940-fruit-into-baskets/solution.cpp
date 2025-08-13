class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i = 0, j = 1;
        int a = fruits[0], b = -1 , c;

        for( ; j<=n-1; j++){
            if(fruits[j] != a){
                b = fruits[j];
                break;
            }
        }

        if(b == -1) return n;

        int maxFruits = 0;

        for( ; j < n; j++ ){

            if( fruits[j] == a || fruits[j] == b ) continue;

            maxFruits = max(maxFruits, j - i);

            a = fruits[j-1];
            b = fruits[j];

            for(int k = j-2; k >= i; k--){
                if( fruits[k] != a ){
                    i = k + 1;
                    break;
                }
            }

        }
        // if(j==n) j--;
        maxFruits = max(maxFruits, j - i);

        // cout<<i<<" "<<j<<endl;
        return maxFruits;
    }
};

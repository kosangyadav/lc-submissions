class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, output = INT_MIN, j = height.size()-1;

        while( i < j ){
            int minHeight = min( height[i], height[j] );
            int area = abs(j-i)*minHeight;
            output = max( output,area );

            if( height[i] > height[j] ){
                for( ; i < j; j--){
                    if( height[j] > minHeight ) break;
                }
            } else {
                for( ; i < j; i++ ){
                    if( height[i] > minHeight ) break;
                }
            }
        }

        return output;
    }
};

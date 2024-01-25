class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int x = text1.length();
        int y = text2.length();
        int[][] LCScount = new int[x+1][y+1];
        
        for(int i=0;i<=x; i++){
            LCScount[i][0] = 0;
        }
        for(int j=0;j<=y;j++){
            LCScount[0][j] = 0;
        }
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(text1.charAt(i-1)==text2.charAt(j-1)){
                    LCScount[i][j] = LCScount[i-1][j-1] + 1;
                }
                else{
                    LCScount[i][j] = Math.max(LCScount[i-1][j],LCScount[i][j-1]);
                }
            }
        }
        return LCScount[x][y];
    }
}
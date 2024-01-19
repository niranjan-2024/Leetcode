class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int mini = Integer.MAX_VALUE;

        int row = matrix.length;
        int col = matrix[0].length;

        int[] prev = new int[col];
        Arrays.fill(prev,-1);

        for(int j=0;j<col;j++){
            prev[j] = matrix[0][j];
        }

        for(int rows=1;rows<row;rows++){
            int[] curr = new int[col];
            for(int cols=0;cols<col;cols++){
                
                int leftUp = matrix[rows][cols];
                if(cols>0){
                    leftUp = leftUp + prev[cols-1];
                }
                else{
                    leftUp = (int)1e9;
                }

                int up = matrix[rows][cols] + prev[cols];

                int rightUp = matrix[rows][cols];
                if(cols<col-1){
                    rightUp = rightUp + prev[cols+1];
                }
                else{
                    rightUp = (int)1e9;
                }

                curr[cols] = Math.min(up,Math.min(leftUp,rightUp));
            }
            prev = curr;
        }

        for(int i=0;i<col;i++){
            mini = Math.min(mini,prev[i]);
        }

        return mini;
    }
}
class Solution {
    
    public class pair{
        int row;
        int col;
        int height;
        
        public pair(int row,int col,int height){
            this.row = row;
            this.col = col;
            this.height = height;
        }
    }
    
    public int trapRainWater(int[][] heights) {
        if(heights == null || heights.length == 0 || heights[0].length == 0){
            return 0;
        }
        
        PriorityQueue<pair> q = new PriorityQueue<>(1, new Comparator<pair>(){
            public int compare(pair a,pair b){
                return a.height - b.height;
            }
        });
        
        int m = heights.length;
        int n = heights[0].length;
        
        boolean[][] visited = new boolean[m][n];
        
        for(int i=0;i<m;i++){
            q.offer(new pair(i,0,heights[i][0]));
            visited[i][0] = true;
            q.offer(new pair(i,n-1,heights[i][n-1]));
            visited[i][n-1] = true;
        }
        
        for(int i=0;i<n;i++){
            q.offer(new pair(0,i,heights[0][i]));
            visited[0][i] = true;
            q.offer(new pair(m-1,i,heights[m-1][i]));
            visited[m-1][i] = true;
        }
        
        int[][] direction = new int[][]{{-1,0},{1,0},{0,-1},{0,1}};
        int result = 0;
        
        while(!q.isEmpty()){
            pair p = q.poll();
            
            for(int[] currentDir : direction){
                int row = p.row + currentDir[0];
                int col = p.col + currentDir[1];
                
                if(row>=0 && row<m && col>=0 && col<n && !visited[row][col]){
                    visited[row][col] = true;
                    result += Math.max(0,p.height-heights[row][col]);
                    q.offer(new pair(row,col,Math.max(heights[row][col],p.height)));
                }
            }
        }
        
        return result;
    }
}
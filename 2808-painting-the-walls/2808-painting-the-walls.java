class Solution {
    int[][] dp = new int[501][501];
    
    public long fun(int[] cost, int[] time, int i, int wallReamining) {
        if (wallReamining <= 0) return 0;
        if (i >= cost.length) return Integer.MAX_VALUE;
        if (dp[i][wallReamining] != 0) return dp[i][wallReamining];
        long notTake = fun(cost, time, i + 1, wallReamining);
        long take = cost[i] + fun(cost, time, i + 1, wallReamining - time[i] - 1);
        return dp[i][wallReamining] = (int)Math.min(notTake, take);
    }
    
    public int paintWalls(int[] cost, int[] time) {
        return (int)fun(cost, time, 0, time.length);
    }
}
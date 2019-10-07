// Dynammic programming
import java.util.Arrays;

public class HouseRobber {

    public int hammingDistance(int x, int y) {
        int count = 0;
        String first = Integer.toBinaryString(x);
        String second = Integer.toBinaryString(y);

        if(first.length() > second.length()){
            second = pad(second, first.length() - second.length());
        }
        else{
            first = pad(first, second.length() - first.length());
        }

        for(int i=0;i<first.length();i++){
            if(first.charAt(i) != second.charAt(i))
                count++;
        }

        return count;
    }

    public String pad(String string, int num){
        StringBuilder temp = new StringBuilder(string);

        for(int i=0;i<num;i++){
            temp.append('0');
        }

        return temp.toString();
    }

    public int rob(int[] nums) {
        int[] memo = new int[nums.length+1];
        Arrays.fill(memo, -1);
        return robRecursive(0, nums, memo);
    }

    public int robRecursive(int index, int[] nums, int[] memo){
        // find recurrence relation for robber:
        // rob[i] = max(rob[i-2] + current, rob[i-1])

        if(index < 0)
            return 0;
        else if(memo[index] >= 0){
            return memo[index];
        }
        else {
            int answer = Math.max(robRecursive(index - 2, nums, memo) + nums[index], robRecursive(index - 1, nums, memo));
            memo[index] = answer;
            return answer;
        }
    }
}

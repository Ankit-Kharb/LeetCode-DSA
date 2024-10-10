public class Solution {
    public int MaxWidthRamp(int[] nums) {
        
        int size = nums.Length;

        Stack myStack = new Stack();
        for(int i=0;i<size;i++)
        {
            if(myStack.Count == 0)
            myStack.Push(i);

            if(nums[(int)myStack.Peek()] > nums[i])
            myStack.Push(i);
        }

        int ans = 0;
        for(int i = size-1;i>=0;i--)
        {
            while(myStack.Count>0 && nums[(int)myStack.Peek()] <= nums[i])
            {
                ans = Math.Max(ans, (i-(int)myStack.Peek()));
                myStack.Pop();
            }
        }
        return ans;
    }
}
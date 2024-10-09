/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode DetectCycle(ListNode head) {
        
        if(head == null)
            return head;

        ListNode slow = head;
        ListNode fast = head;

        while(fast != null)
        {
            slow = slow.next;
            fast = fast.next;

            if(slow == null || fast == null)
            return null;

            fast = fast.next;

            if(slow == fast)
            {
                //Console.WriteLine($"{slow.val} {fast.val} {head.val}");
                slow = head;
                while(slow != fast)
                {
                    slow = slow.next;
                    fast = fast.next;
                }
                return slow;
            }
        }    
        return null;
    }
}
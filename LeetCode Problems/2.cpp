/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) { val = x; }
 * }
 */
class Solution {

    public void give(ListNode l, Queue<Integer> queue) {
        ListNode current = l;
        //stack = new Stack<>();

        while (current != null) {
            queue.add(current.val);
            current = current.next;
        }
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Queue<Integer> first = new LinkedList<>();
        Queue<Integer> second = new LinkedList<>();
        
        give (l1, first);
        give (l2, second);

        int leftOver, carry = 0;
        Queue<Integer> end = new LinkedList <>();
        
        while (!first.isEmpty() && !second.isEmpty()) {
            int current = carry + first.poll() + second.poll();
            leftOver = current % 10;
            carry = current/10;
            
            end.add (leftOver);
        }
        
        if (!first.isEmpty() && second.isEmpty()) {
            while (!first.isEmpty()) {
                int current = carry + first.poll();
                leftOver = current % 10;
                carry = current/10;
                
                end.add (leftOver);
            }
        }
        
        else if (first.isEmpty() && !second.isEmpty()) {
            while (!second.isEmpty()) {
                int current = carry + second.poll();
                leftOver = current % 10;
                carry = current/10;
                
                end.add (leftOver);
            }
        }
        
        if (carry != 0) {
            end.add (carry);
        }
        
        ListNode result = null;
        ListNode now = result;
        
        while (!end.isEmpty()) {
            ListNode toAdd = new ListNode(end.poll());
            
            if (result == null) {
                result = toAdd;
                now = result;
            } else {
                now.next = toAdd;
                now = now.next;
            }
        }
        
        return result;
    }
}

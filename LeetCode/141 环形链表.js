/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/*141 环形链表*/

/**
 * @param {ListNode} head
 * @return {boolean}
 */

/* *
 * 思路：
 * 设p每次走两步，q每次走一步。
 * 那么当链表没有环时，p一定比q先走完整个链表，即先指向null，然后q指向null。
 * 当链表有环时，p先进入环，q也进入环，那么p与q一定会相遇。举例如下：
 * p：4，q：3
 * p：3，q：4
 * p：2，q：2   可以看到，此时p与q指向同一个节点。说明环存在。
 */
var hasCycle = function(head) 
{
    var p=head;
    var q=head;
    
	/*若链表为空，没有环*/
	if(head==null)
		return false;

	/*若链表只有一个节点，没有环*/
	if(head.next==null)
		return false;

	/*若链表只有两个节点，也没有环*/
	/*提交了才想到这个情况，提示输入是[1,2]*/
	if(head.next.next==null)
		return false;

	/*循环判断*/
	/*p不为空的条件是因为p若为空说明p已经走完链表，即没有环*/
    /*p的next不为空：因为p是两个节点一步走的，如果p的下一个为空，但是p不为空也无法往下走*/
    /*p与p的next都不为空的条件保证了p的两步后才是恰好指向最后一个节点之后的null*/
    while(p && p.next)
    {
    	p=p.next.next;
    	q=q.next;


    	/*这个判断必须放在指针后移之后，否则开始p与q都指向head，永远返回true*/
    	if(p==q)
    		return true;
    }
    /*能出循环，则说明没有环*/
   	return false;
};

/*60ms范例*/
var hasCycle = function(head) {
    let fast = head;
    let slow = head;
    while(slow&&fast&&fast.next){
        fast = fast.next.next;
        slow = slow.next;
        if(slow == fast){
            return true;
        }
    }
    return false;
};

/*区别主要在循环条件上。*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* tmp = MiddleNode(head);
        ListNode* pre = tmp;           //链断开，一分为二
        tmp = tmp->next;
        pre->next=NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(tmp);
        return mergeList(l1,l2);
    }
    
    ListNode* MiddleNode(ListNode* head){//快慢指针找中点
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* mergeList(ListNode* l1,ListNode* l2){
        ListNode dummy(-1);
        ListNode* point = &dummy;
        while(l1!=NULL||l2!=NULL){
            if(l1==NULL){
                point->next = l2;
                l2 = l2->next;
            }
            else if(l2==NULL){
                point->next =l1;
                l1 = l1->next;
            }
            else{
                if(l1->val<l2->val){
                    point->next = l1;
                    l1 = l1->next;
                }
                else{
                    point->next = l2;
                    l2 = l2->next;
                }
            }
            point = point->next;
        }
        return dummy.next;
    }
};
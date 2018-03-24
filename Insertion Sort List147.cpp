class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* helper = new ListNode(0);
        ListNode* temp = helper;
        while(head!=NULL){
            ListNode* t = head->next;
            temp = helper;
            while(temp->next && temp->next->val<=head->val){
                temp = temp->next;
            }
            head->next = temp->next;
            temp->next = head;
            head = t;
        }
        return helper->next;
    }
};
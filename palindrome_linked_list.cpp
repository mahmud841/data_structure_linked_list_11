/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
void insert_tail_function(ListNode* &head, ListNode* &tail, int val)
{
    ListNode* newNode= new ListNode(val);
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    tail= tail->next;
}

void reverse_linked_list(ListNode *&head, ListNode* current)
{
    if(current->next == NULL)
    {
        head=current;
        return;
    }
    reverse_linked_list(head, current->next);
    current->next->next=current;
    current->next=NULL;
}

void print_list(ListNode* head)
{
    ListNode* tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
}

    bool isPalindrome(ListNode* head) {
        ListNode* newHead= NULL;
        ListNode* newTail= NULL;
        ListNode* tmp= head;
        while(tmp!=NULL)
        {
            insert_tail_function(newHead, newTail, tmp->val);
            tmp=tmp->next;
        }
        reverse_linked_list(newHead, newHead);
        print_list(newHead);
        tmp=head;
        ListNode* tmp2=newHead;
        while(tmp!=NULL)
        {
            if(tmp->val != tmp2->val)
            {
                return false;
            }
            tmp=tmp->next;
            tmp2=tmp2->next;
        }
        return true;
    }
};
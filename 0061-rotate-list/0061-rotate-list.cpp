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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        vector<int> v;
        ListNode * temp = head;
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp-> next;
        }
        int n = v.size();
         k = k%n;
        vector<int> finalv;
        for(int i = n-k;i<n;i++){
            finalv.push_back(v[i]);
        }
        for(int i=0;i<n-k;i++){
            finalv.push_back(v[i]);
        }
        int i =0;
        temp = head;
        while(i < n){
         temp-> val = finalv[i];
         temp = temp-> next;
         i++;
        }
        return head;
    }
};
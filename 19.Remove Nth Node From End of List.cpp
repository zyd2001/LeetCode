#include <vector>

using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        nodes.push_back(new ListNode(-1));
        nodes[0]->next = head;
        for (ListNode* n = head; n != NULL; n = n->next)
            nodes.push_back(n);
        nodes.push_back(NULL);
        auto size = nodes.size();
        if (size <= 3)
            return NULL;
        nodes[size - n - 2]->next = nodes[size - n];
        return nodes[0]->next;
    }
};
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
void add(ListNode*& head, int N) {
    int j = 0;
    ListNode* current = head;
    while (N > j) {
        int n;
        bool unique;
        do {
            unique = true;
            n = rand() % 2001 - 1000;
            current = head;
            while (current != nullptr) {
                if (current->val == n) {
                    unique = false;
                    break;
                }
                current = current->next;
            }
        } while (!unique);

        ListNode* cur = new ListNode(n);
        cur->next = head->next;
        head->next = cur;
        j++;
    }
}
void show(ListNode* head)
{
	ListNode* current = head;
	while (current != nullptr) {
		cout << current->val << " ";
		current = current->next;
	}
}
ListNode* finding(ListNode* head,int x)
{
	ListNode* current = head;
	while (current != nullptr) {
		if (current->val == x)
			return current;
		current = current->next;
	}
}
void deleteNode(ListNode* node) {
    if (!node || !node->next) {
        return; // Неможливо видалити останній вузол або нульовий вузол
    }
	ListNode* nextNode = node->next; // Зберігаємо наступний вузол
    node->val = nextNode->val; // Копіюємо значення наступного вузла у поточний вузол
    node->next = nextNode->next; // Перенаправляємо вказівник на наступний вузол
    delete nextNode; // Видаляємо наступний вузол
}
int main()
{
	int N = -1, x;
	ListNode* head = new ListNode(1);
	srand(time(NULL));
	do {
		cout << "Count of elements (1<N<10001): ";
		cin >> N;
	} while (N > 10000 || N < 2);
	add(head, N);
	show(head);
	cout << "\nNode with which value should be deleted: ";
	cin >> x;
	deleteNode(finding(head, x));
	show(head);
    return 0;
}
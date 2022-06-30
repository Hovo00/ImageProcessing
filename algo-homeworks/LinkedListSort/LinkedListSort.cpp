#include <iostream>
#include <random>
#include <time.h>

struct linked_list {
	linked_list() : val(0), next(nullptr) { };
	linked_list(int value) : val(value), next(nullptr) {};
	linked_list(int value, linked_list* next_) : val(value), next(next_) {};
	int val;
	linked_list* next;
};

void create_list(linked_list* head, const int count) {
	linked_list* temp = head;
	for (int i = 0; i < count; ++i) {
		temp->next = new linked_list(rand() % 3);
		temp = temp->next;
	}
}

void delete_list(linked_list* head) {
	head = head->next;
	linked_list* prev = nullptr;
	while (head) {
		prev = head;
		head = head->next;
		delete prev;
	}
	if (!prev) delete prev;
}

void print_list(linked_list* head) {
	linked_list* temp = head;

	std::cout << std::endl;
	while (temp) {
		std::cout << temp->val<<" ";
		temp = temp->next;
	}
}

void oNsort(linked_list* head) {
	int counts[3] = { 0 };
	linked_list* temp = head;
	while (temp) {
		++counts[temp->val];
		temp = temp->next;
	}

	temp = head;
	int curr = 0;

	while (temp) {
		temp->val = curr;
		--counts[curr];
		if (counts[curr] == -1) ++curr;
		else temp = temp->next;
	}
}

int main() {
	std::srand(time(0));

	linked_list* head = new linked_list();
	const int count = 4;
	create_list(head, count);

	print_list(head);
	oNsort(head);
	print_list(head);

	delete_list(head);
	delete head;
}

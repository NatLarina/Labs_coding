#include <iostream>
#include <string>

// Структура для элемента списка
struct ListNode {
    std::string str;
    int num;
    double dbl;
    ListNode* next;
    ListNode* prev;

    ListNode(const std::string& s, int n, double d) : str(s), num(n), dbl(d), next(nullptr), prev(nullptr) {}
};

// Структура для списка
struct List {
    ListNode* head;
    ListNode* tail;

    List() : head(nullptr), tail(nullptr) {}

    // Функции для работы со списком
    void addFront(const std::string& s, int n, double d);
    void addBack(const std::string& s, int n, double d);
    void addAfter(ListNode* node, const std::string& s, int n, double d);
    void addBefore(ListNode* node, const std::string& s, int n, double d);
    void removeByName(const std::string& s);
    void print();
};

// Добавление элемента в начало списка
void List::addFront(const std::string& s, int n, double d) {
    ListNode* newNode = new ListNode(s, n, d);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Добавление элемента в конец списка
void List::addBack(const std::string& s, int n, double d) {
    ListNode* newNode = new ListNode(s, n, d);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

// Добавление элемента после заданного элемента
void List::addAfter(ListNode* node, const std::string& s, int n, double d) {
    if (node == nullptr) {
        return;
    }
    ListNode* newNode = new ListNode(s, n, d);
    if (node == tail) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else {
        newNode->prev = node;
        newNode->next = node->next;
        node->next->prev = newNode;
        node->next = newNode;
    }
}

// Добавление элемента перед заданным элементом
void List::addBefore(ListNode* node, const std::string& s, int n, double d) {
    if (node == nullptr) {
        return;
    }
    ListNode* newNode = new ListNode(s, n, d);
    if (node == head) {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    } else {
        newNode->next = node;
        newNode->prev = node->prev;
        node->prev->next = newNode;
        node->prev = newNode;
    }
}

// Удаление из списка элемента с заданным именем
void List::removeByName(const std::string& s) {
    ListNode* current = head;
    while (current != nullptr) {
        if (current->str == s) {
            if (current == head) {
                head = current->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                } else {
                    tail = nullptr;
                }
            } else if (current == tail) {
                tail = current->prev;
                tail->next = nullptr;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
    }
}

// Вывод содержания списка на экран
void List::print() {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << "String: " << current->str << ", Integer: " << current->num << ", Double: " << current->dbl << std::endl;
        current = current->next;
    }
}

int main() {
    List myList;

    // Добавление элементов в список
    myList.addFront("Apple", 5, 3.14);
    myList.addBack("Banana", 10, 2.718);
    myList.addAfter(myList.head, "Orange", 7, 1.618);
    myList.addBefore(myList.tail, "Kiwi", 3, 0.5772);

    // Вывод содержания списка
    std::cout << "List contents:" << std::endl;
    myList.print();

    // Удаление элемента из списка
    myList.removeByName("Orange");

    // Вывод содержания списка после удаления
    std::cout << "List contents after removal:" << std::endl;
    myList.print();

    return 0;
}

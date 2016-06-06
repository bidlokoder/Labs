#include <iostream>
#include <string>
using namespace std;

/**
	\class Класс-контейнер queue типа очередь
*/
class Queue {
public:
	Queue(int _data) : data(_data), next(nullptr) {};
	~Queue() {};

	int		data;
	Queue	*next;
};

class QueueController {
public:
	QueueController() : head(nullptr), tail(nullptr) {};
	~QueueController() {};

	Queue	*head;
	Queue	*tail;
	
	/// \fn Добавление элемента
	void	add(int data) {
		Queue *newElement = new Queue(data);
		if (tail != nullptr) {
			tail->next = newElement;
			tail = tail->next;
		}
		else
			head = tail = newElement;
		return;
	};

	/// \fn Удаление элемента
	void	del(void) {
		if (head != nullptr) {
			Queue *deleted = head;
			head = head->next;
			delete deleted;
		}
		else
			tail = nullptr;
		return;
	};
	
	/// \fn Получение элемента
	int	get(void) {
		return head->data;
	};
};

/**
	\fn Главная функция приложения
*/
int main() {
	size_t n;       ///Number of commands
	string line;    ///Command name
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		cin >> line;
		if (line == "add") {
			cin >> line;
			Move.push(line);
		}
		else if (line == "get")
			Move.get();
		else if (line == "del")
			Move.pop();
		else
			return 1;
	}
	return 0;
}


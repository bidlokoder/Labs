#include <iostream> 
#include <string> 
using namespace std;
 /* Класс-контейнер list типа лист */
class list 
{ 
     list* Next; 
     string Data; 
 public: 
     list(): Next(nullptr), Data("") {}; 
     void add(int i, string data); 
     void get(int i); 
     void del(int i); 
     ~list(){if(Next!= nullptr) delete Next;} 
 }
List; 
 /* Добавляет новый элемент в списке, если элемент по инексу не существует,
 * в противном случае изменяет содержимое существующего.
 * @param i - индекс элемента списка
 * @param data - информация, помещаемая в элемент списка
 */

void list::add(int i, string data) 
 { 
     if(i==0) 
     { 
         Data = data; 
         return; 
     } 
     if(Next== nullptr) 
         Next = new list(); 
     Next->add(i-1, data); 
 } 
 /* Выводит содержимое элемента списка по его индексу, если элемент не существует,
 * то он будет создан и будет возвращено значение по умолчанию
 * @param i - индекс элемента списка
 */
 
 void list::get(int i) 
 { 
     if(i==0) 
     { 
         cout << Data << endl; 
         return; 
     } 
     if(Next== nullptr) 
         Next = new list(); 
     Next->get(i-1); 
 } 
 /* Удаляет элемент списка по его индексу
 * @param i - индекс элемента списка
 */
 
 void list::del(int i) 
 { 
     add(i, ""); 
 } 
 
 
 int main() 
 { 
    size_t n;       
    int ind;        
    string line;    
     cin >> n; 
    for (size_t i = 0; i < n; i++) 
     { 
        cin >> line; 
         if(line=="add") 
        { 
             cin >> ind >> line; 
             List.add(ind, line); 
        } 
         else if(line=="get") 
        { 
             cin >> ind; 
             List.get(ind); 
        } 
         else if(line=="del") 
         { 
             cin >> ind; 
             List.del(ind); 
         } 
         else 
             return 1; 
      } 
    return 0; 
}


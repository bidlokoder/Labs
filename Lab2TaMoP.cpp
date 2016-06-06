#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	bool fOpen = false;				// Открылся комментарий
	bool fClose = false;			// Закрылся ли комментарий 
	bool fFunMult = false;			// Многострочен ли он
	bool oneString = false;			// Или в одну строку
	string sIn;						// Строка для чтения по строке
	string result;					// Строка для однострочного комментария
	string resultMultiline = "";	// Для многострочного комментария
	size_t pos;
	size_t posOp, posCl, posFun;	// Позиции открытия и закрытия комментария
	int k = 0, n = 0, i = 0;		// k - счетчик комментариев
	ifstream f_in("test.txt");		// Открытие файла на чтение
	ofstream f_out("test.txt", fstream::app);	// Открытие файла на добавление
	if (!f_in) {					// Открыт ли файл?
		cout << "Error!";
		return 1;
	}
	f_out << '\n';					// Добавление строки для более красивого вида выходного файла
	while (f_in) {					// Пока не закончился файл
		getline(f_in, sIn);			// Читаем его по строке
		if (fFunMult == false) {		// Если комментарий не многострочен
			posOp = sIn.find("/**");	// То ищем /**
			if (posOp != std::string::npos) {
				fOpen = true;		// И фиксируем открытие комментария
				posCl = sIn.find("*/");	// Если в этой же строку нашелся закрывающий символ
				if (posCl != std::string::npos) {
					fClose = true;	// То фиксируем закрытие комментария
					oneString = true;	// И то, что он в одну строку
					fFunMult = false;
				}
				else
					oneString = false;	// Или не в одну
			}

			if ((oneString == true) && (fOpen == true)) {		// Если все же в одну, то
				posFun = sIn.find("\\func");	// Ищем опознавательный тэг
				if (posFun != std::string::npos) {
					k += 1;			// И увеличиваем количество комментариев на 1
					result = sIn.substr(posFun + 6, posCl - (posFun + 6));	// Записываем содержимое после тэга в
																			// result
					f_out << k << ". " << result << endl;			// И выводим в исходный файл
					i = 0;
				}
				oneString = false;		// Сбрасываем флаг
			}

			else if (fFunMult == false) {		// Если не в одну строку, то
				if (fOpen == true) {
					posFun = sIn.find("\\func");	// Отмечаем позицию начала
					if (posFun != std::string::npos) {
						fFunMult = true;	// И отмечаем флагом
					}
				}
			}
		}
		if (fFunMult == true) {				// Если комментарий многострочен, то
			posCl = sIn.find("*/");			// Ищем закрывающий символ в каждой новой строке
			if (posCl != std::string::npos) {	// Если он нашелся, то
				k += 1;				// Увеличиваем счетчик комментариев на 1
				f_out << k << ". " << resultMultiline << endl;	// И выводим его в файл
				i = 0;
				fFunMult = false;		// 
				fClose = true;			// Сбрасываем флаги
				fOpen = false;			// 
				resultMultiline = "";  		// И строку
			}
			else {
				if (i == 0) {			// Зачем i?.. Не помню. Но так работает
										// Добавляем каждую строку комментария к переменной
					resultMultiline = resultMultiline + sIn.substr(posFun + 6, posCl - (posFun + 6)) + '\n';
					i++;			// Видимо, количество строк комментария
				}
				else
					resultMultiline = resultMultiline + sIn;
			}
		}
	}
	f_in.close();
	return 0;
}


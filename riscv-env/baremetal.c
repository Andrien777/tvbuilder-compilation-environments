#include <stdint.h> //Заголовочный файл, содержащий целочисленные типы данных

// Системные переменные, адреса которых устанавливаются при сборке программы
extern uint32_t SYSCON;
extern uint32_t TIMERL;

int main() { // Главная функция программы, с которой начинается ее выполнение
  volatile uint32_t *in =
      (uint32_t *)(0x11500000); // Адрес, соответствующий регистру со значениями
                                // на входах
  volatile uint32_t *out =
      (uint32_t *)(0x11000000); // Адрес, соответствующий регистру для вывода
                                // значений на ножки
  uint32_t counter =
      0; // Переменная-счетчик беззнакового 32-битного целого типа, равная нулю
  while (1) { // Вечный цикл (операции между {} будут выполняться бесконечно)
    if ((*in) == 0 ||
        counter == (*in) - 1) { // Если значение счетчика на 1 меньше значения
                                // на входе или на входе 0
      counter = 0; // Счетчик равен 0 - переполнение
    } else {       // Иначе
      counter++; // Увеличить значение счетчика на 1
    }
    *out = counter; // Вывод значения счетчика на ножки
  }
  return 0; // Завершение главной функции
}

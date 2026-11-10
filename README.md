# tip-elevator-simulator
ТИП — тема 15. Симулятор работы лифтов: требования, SRS и UML. Исмаилов Полад, ЭФБО-04-25.

## Этап Структура и CMake

Подготовлен собираемый каркас проекта на C++17. Приложение создаёт начальную
конфигурацию здания и выводит состояние двух кабин. Движение, обработка заявок,
рабочие потоки, статистика и автоматические тесты относятся к следующим этапам.

## Структура

```text
app/main.cpp                точка входа консольного приложения
include/elevator/model/     типы Config, Request и начальный класс Elevator
include/elevator/simulation.hpp  каркас координатора Simulation
include/elevator/dispatch/  место для интерфейса Dispatcher
include/elevator/io/        место для ввода-вывода
include/elevator/statistics/ место для статистики
src/                        реализации начальных классов
examples/                   место для сценариев
tests/                      план будущих проверок
docs/                       ссылки на требования
CMakeLists.txt              сборка библиотеки и приложения
CMakePresets.json           конфигурации Debug и Release
```

`elevator_core` — библиотека модели, `elevator_simulator` — консольное приложение.
Threads подключён для будущей многопоточной реализации; рабочие потоки пока не создаются.
Заголовки `.hpp` описывают интерфейсы и типы, файлы `.cpp` содержат реализацию.

## Сборка

Нужны CMake 3.21+, компилятор C++17 и make для presets. Команды выполняются
в корне репозитория:

```sh
cmake --preset debug
cmake --build --preset debug
./build/debug/elevator_simulator
```

Для Release замените `debug` на `release`.
Presets используют Unix Makefiles. Для другого генератора можно собрать без presets:

```sh
cmake -S . -B build/manual
cmake --build build/manual --config Debug
```

Путь к бинарному файлу зависит от генератора; Windows также использует расширение `.exe`.
Файлы сборки и локальные настройки исключены через `.gitignore`.

## Проверка этапа

Каркас собран и запущен локально на macOS arm64 в конфигурациях Debug и Release.
Это проверка структуры и сборки, а не приёмка алгоритмов симуляции.

## Требования проекта

- [PDF с требованиями и UML](TIP_2_Tema_15.pdf)
- [Редактируемая версия Word](TIP_2_Tema_15_ворд.docx)

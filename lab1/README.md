# Отчёт по лабораторной работе №1 по курсу "Объектно-ориентированное программирование"

<b>Студент группы:</b> <ins>М80-208Б-22 Былькова Кристина Алексеевна, № по списку 2</ins> 

<b>Контакты e-mail:</b> <ins>kristina.bilckova@yandex.ru</ins>

## 1. Тема
Первая программа на C++

## 2. Цель работы
- Изучить систему сборки CMake
- Изучить базовые операторы и конструкции C++
- Изучить библиотеку для написания Unit-тестов Google Test
- Научится писать простые программы, использующие ввод/вывод через потоки std::cin и std::cout

## 3. Задание (вариант № 3)
Напишите функцию, которая принимает строку круглых скобок и определяет, является ли порядок скобок правильным. Функция должна возвращать true, если строка допустима, и false, если недопустима.
Все входные данные будут строками, состоящими только из символов ( и ).
Пустые строки считаются сбалансированными (и, следовательно, валидными) и будут проверяться.

## 4. Код программы

```:src/main.cpp
#include <iostream>
#include "solve.hpp"

int main() {

    std::string str;
    std::cin >> str;

    if (bracketsBalance(str)) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }

    return 0;
}
```

```:src/solve.hpp
#pragma once
#include <string>

bool bracketsBalance(std::string & str);
```

```:src/solve.cpp
#include "solve.hpp"

bool bracketsBalance(std::string & str) {
    bool flag = true;
    int count = 0;

    if (str == "") {
        return true;
    }
    
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '(') {
            ++count; 
        } else if (str[i] == ')' && count) {
            --count;
        } else {
            return false;
        }
    }

    if (flag && !count) {
        return true;
    } else {
        return false;
    }
}
```

## 5. Тесты

```:src/tests.cpp
#include <gtest/gtest.h>
#include "solve.hpp"

TEST(test1, brackets) {
    std::string s = "()";
    ASSERT_TRUE(bracketsBalance(s) == true);
}

TEST(test2, brackets) {
    std::string s = ")(()))";
    ASSERT_TRUE(bracketsBalance(s) == false);
}

TEST(test3, brackets) {
    std::string s = "(";
    ASSERT_TRUE(bracketsBalance(s) == false);
}

TEST(test4, brackets) {
    std::string s = "(())((()())())";
    ASSERT_TRUE(bracketsBalance(s) == true);
}

TEST(test5, brackets) {
    std::string s = ")";
    ASSERT_TRUE(bracketsBalance(s) == false);
}

TEST(test6, brackets) {
    std::string s = "(((()";
    ASSERT_TRUE(bracketsBalance(s) == false);
}

TEST(test7, brackets) {
    std::string s = "";
    ASSERT_TRUE(bracketsBalance(s) == true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

## 6. Распечатка протокола 

```
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/VScode/C++/oop/lab1/build$ cmake --build .
Scanning dependencies of target tests
[ 16%] Building CXX object CMakeFiles/tests.dir/tests.cpp.o
[ 33%] Linking CXX executable tests
[ 50%] Built target tests
[100%] Built target task
kristinab@LAPTOP-SFU9B1F4:/mnt/c/Users/Admin/VScode/C++/oop/lab1/build$ ./tests
[==========] Running 7 tests from 7 test suites.
[----------] Global test environment set-up.
[----------] 1 test from test1
[ RUN      ] test1.brackets
[       OK ] test1.brackets (0 ms)
[----------] 1 test from test1 (0 ms total)

[----------] 1 test from test2
[ RUN      ] test2.brackets
[       OK ] test2.brackets (0 ms)
[----------] 1 test from test2 (0 ms total)

[----------] 1 test from test3
[ RUN      ] test3.brackets
[       OK ] test3.brackets (0 ms)
[----------] 1 test from test3 (0 ms total)

[----------] 1 test from test4
[ RUN      ] test4.brackets
[       OK ] test4.brackets (0 ms)
[----------] 1 test from test4 (0 ms total)

[----------] 1 test from test5
[ RUN      ] test5.brackets
[       OK ] test5.brackets (0 ms)
[----------] 1 test from test5 (0 ms total)

[----------] 1 test from test6
[ RUN      ] test6.brackets
[       OK ] test6.brackets (0 ms)
[----------] 1 test from test6 (0 ms total)

[----------] 1 test from test7
[ RUN      ] test7.brackets
[       OK ] test7.brackets (0 ms)
[----------] 1 test from test7 (0 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 7 test suites ran. (0 ms total)
[  PASSED  ] 7 tests.
```
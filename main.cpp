#include <iostream>
#include <iomanip>
#include <windows.h>

#include <list>
#include <vector>
#include <set>
#include <iterator>

#include<random>
#include<algorithm>

#include <chrono>
typedef std::chrono::high_resolution_clock ourClock;

using std::cout;
using std::endl;

using std::list;
using std::set;


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << std::setfill('=') << std::setw(60) << '=' << endl;
    cout << "ЛАБОРАТОРНАЯ РАБОТА №8" << endl; 
    cout << "БИБИЛИОТЕА ШАБЛОННЫХ КЛАССОВ STL" << endl;
    cout << std::setfill('=') <<std::setw(60) << '=' << endl;


    // Итераторы
    list<int>::iterator listIterator;
    set<int>::iterator  setIterator;

    //====== НАСТРАИВАЕМЫЕ ПАРАМЕТРЫ ========== 
    
    // размерность контейнеров
    const size_t containerLen = 1000000;  
    // -------------------------------------------
    
    // точность измерения (кол-во цифр после запятой)

    short precision = 5;

    // генератор случайных чисел - нужны для добавления и поиска случайных элементов
    int seed = time(NULL);   // seed = time(NULL) для разных значений при каждом запуске

    std::mt19937 numGenerator(seed);
    
    // распределение случайных чисел в нужном диапозоне 
    std::uniform_int_distribution <int> dist(1, containerLen);
    // -------------------------------------------

    // добавляемый, удаляемый и искомый элементы.
    // по умолчанию случайные числа в пределах значения containerLen
    const int pushedElement   = dist(numGenerator);
    const int popElement      = dist(numGenerator); 
    const int searchedElement = dist(numGenerator);
    // -------------------------------------------

    // позиция, на которую будет добавлен элемент в список
    enum position {front, middle, back};
    position pushPosition     = middle; // по умолчанию середина

    // ==========================================


    cout << "Создадим список случайных положительных чисел длинной " << containerLen << " элементов." << endl;

    // Создадим вектор с уникальными значениями в случайном порядке.
    // После копируем из него в list
    std::vector <int> buffer;
    buffer.reserve(containerLen);
    for(int i = 1; i <= containerLen; ++i)
        buffer.push_back(i);

    // перемешиваем массив
    std::shuffle(buffer.begin(), buffer.end(), numGenerator);

    // Создаем список и заполняем его из массива
    list<int> ourList;

    for(size_t i = 0; i < containerLen; ++i)
        ourList.push_back(buffer[i]);

        
    listIterator = ourList.begin();
    for(int i = 0; i < 10; ++i, ++listIterator)
    {
        cout << *listIterator << " "; 
    }
    cout << "..." << endl;
    
    // Засекаем время начала работы алгоритма
    auto start = ourClock::now();

    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    cout << "Удаление элемента " << popElement << endl;

    listIterator = ourList.begin();
    
    while(*listIterator != popElement)
        ++listIterator;

    ourList.erase(listIterator);


    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    cout << "Добавление элемента " << pushedElement;
  
    switch (pushPosition)
    {
    case(front):
        cout << " в начало списка" << endl;
        ourList.push_front(pushedElement);
        break;
    
    case(middle):
        cout << " в середину списка" << endl;    

        listIterator = ourList.begin();
        for(size_t i = 0; i < ourList.size()/2; ++i)
            listIterator++;

        ourList.insert(listIterator, pushedElement);
        break;

    case(back):
        cout << " в конец списка" << endl;    
        ourList.push_back(pushedElement);
        break;

    }



    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    cout << "Сортировка списка..." << endl;
    ourList.sort();

    listIterator = ourList.begin();
    for(int i = 0; i < 10; ++i, ++listIterator)
    {
        cout << *listIterator << " "; 
    }
    cout << "..." << endl;

    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    cout << "Поиск элемента..." << endl;

    cout << "Искомый элемент: " << searchedElement << endl;

    listIterator = ourList.begin();

    while(listIterator != ourList.end())
    {
        if(*listIterator == searchedElement)
        {
            cout << "Элемент найден" << endl;
        }

        ++listIterator;
    }

    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    auto finish = ourClock::now();
    auto duration = std::chrono::duration<double>(finish - start).count();
    
    cout << "Время выполнения операций для списка: " << std::fixed << std::setprecision(precision) << duration << " секунд" << endl;



    cout << std::setfill('=') <<std::setw(60) << '=' << endl;


    // ============================================================================================

    cout << "Создадим множество натуральных чисел длинной " << containerLen << " элементов." << endl;

    std::set<int> ourSet;

    setIterator = ourSet.begin();
    for(int i = 1; i <= containerLen; ++i)
    {
        setIterator = ourSet.insert(setIterator, i);
    }

    setIterator = ourSet.begin();  
    for(int i = 0; i < 10; ++i, ++setIterator)
    {
        cout << *setIterator << " "; 
    }
    cout << "..." << endl;
    
    // Засекаем время начала работы алгоритма
    start = ourClock::now();

    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    cout << "Удаление элемента " << popElement << endl;

    ourSet.erase(popElement);


    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    cout << "Добавление элемента " << pushedElement << endl;
  
    ourSet.insert(pushedElement);   
    

    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

   
    cout << "Поиск элемента" << endl;

    cout << "Искомый элемент: " << searchedElement << endl;

    if(ourSet.find(searchedElement) != ourSet.end())
        cout << "Элемент найден" << endl;

    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    finish = ourClock::now();
    duration = std::chrono::duration<double>(finish - start).count();
    
    cout << "Время выполнения операций для множества: " << std::fixed << std::setprecision(precision) << duration << " секунд" << endl;

    cout << std::setfill('=') <<std::setw(60) << '=' << endl;
    
    return 0;
}














// ==================== GIT ШПАРГАЛКА ====================

// 0) Один раз на каждом компе (настройка личности Git):
//    git config --global user.name "Твоё Имя"
//    git config --global user.email "you@mail.com"
//    git config --global core.autocrlf true        # если Windows

// -----------------------------------------------------------------------
// A) Первый запуск на НОВОМ компьютере (когда репо ещё нет локально)

// 1) Клонируем проект:
//    cd C:\Code   (или куда надо)
//    git clone <URL_репозитория>
//    cd <папка_репозитория>

//ИЛИ
// git init
// git remote add origin https://github.com/...


// 2) Проверяем, что всё ок:
//    git status
//    git remote -v

// -----------------------------------------------------------------------
// B) Начинаю работать на ЛЮБОМ компе (каждый раз перед кодингом)

// 1) Перейти в папку проекта
// 2) Забрать свежие изменения:
//    git pull

//    Если ругается на конфликты:
//    - открываешь конфликтующие файлы
//    - правишь вручную (оставляешь правильный вариант)
//    - потом:
//      git add .
//      git commit -m "Resolve merge conflict"
//      git push

// -----------------------------------------------------------------------
// C) В процессе работы (сохраняю прогресс)

// 1) Посмотреть, что изменилось:
//    git status

// 2) Зафиксировать изменения:
//    git add .
//    git commit -m "Коротко что сделал"

// git commit --amend --no-edit
// --amend → «переделай последний коммит»
// --no-edit → «оставь сообщение таким же, не трогай его»

//    Примеры сообщений:
//    - "Lab6: fix input parsing"
//    - "Add Polynomial::operator+"
//    - "Refactor queue memory management"

// 3) Отправить на удалённый репозиторий (чтобы на другом компе было):
//    git push

// -----------------------------------------------------------------------
// D) Перехожу на второй комп

// 1) В папке проекта:
//    git pull

// И всё. Код на месте.

// -----------------------------------------------------------------------
// E) Если забыл закоммитить и надо срочно уйти (временное сохранение)

//    git stash
//    git pull          # если нужно обновиться
//    git stash pop     # вернуть изменения обратно

// (Старайся не жить на stash. Это временный карман.)

// -----------------------------------------------------------------------
// F) Откаты (самое частое)

// 1) Отменить незакоммиченные правки:
//    git restore .

// 2) Убрать файлы из staged (после git add):
//    git restore --staged .

// 3) Убрать последний коммит, НО оставить изменения в файлах:
//    git reset --soft HEAD~1

// 4) Убрать последний коммит И выкинуть изменения:
//    git reset --hard HEAD~1

// 5) Если уже запушил и нужно отменить безопасно:
//    git revert <hash>
//    git push

// -----------------------------------------------------------------------
// G) Быстрые проверки

// - Где я? (корень репо)
//   git rev-parse --show-toplevel

// - Что я изменил?
//   git status

// - Какие коммиты последние?
//   git log --oneline --max-count=10

// -----------------------------------------------------------------------
// H) Золотое правило

// Перед началом работы: git pull
// После завершения работы: git add . && git commit && git push

// =======================================================================

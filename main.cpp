#include <iostream>
#include <iomanip>
#include <windows.h>

#include <list>
#include <vector>
#include <set>
#include <iterator>

#include<random>
#include<algorithm>

using std::cout;
using std::endl;

using std::list;
using std::set;

// почему контейнер, decltype
// добавление, удаление, поиск, сортировка

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << std::setfill('=') << std::setw(60) << '=' << endl;
    cout << "ЛАБОРАТОРНАЯ РАБОТА №8" << endl; 
    cout << "БИБИЛИОТЕА ШАБЛОННЫХ КЛАССОВ STL" << endl;
    cout << std::setfill('=') <<std::setw(60) << '=' << endl;

    // переменные-счетчики времени
    time_t start;
    time_t popTime;
    time_t pushTime;
    time_t sortTime;
    time_t searchTime;
    time_t finish;
    time_t resultForList;
    time_t resultForSet;
    
    // размерность контейнеров
    const size_t containerLen = 10000000;
    size_t actualLen = containerLen;

    // Итераторы
    list<int>::iterator listIterator;
    set<int>::iterator  setIterator;

    // генератор случайных чисел
    std::mt19937 generatorForList(0);
    std::mt19937 generatorForSet(0);
    // распределение случайных чисел в нужном диапозоне 
    std::uniform_int_distribution <int> dist(1, containerLen);

    cout << "Создадим список случайных положительных чисел длинной " << containerLen << " элементов." << endl;

    // Создадим вектор с уникальными значениями в случайном порядке.
    // После копируем из него в list
    std::vector <int> buffer;
    buffer.reserve(containerLen);
    for(int i = 1; i <= containerLen; ++i)
        buffer.push_back(i);

    // перемешиваем массив
    std::shuffle(buffer.begin(), buffer.end(), generatorForList);

    // Создаем список и заполняем его из массива
    list<int> ourList;

    for(size_t i = 0; i < containerLen; ++i)
        ourList.push_back(buffer[i]);

        
    listIterator = ourList.begin();
    for(int i = 0; i < 20; ++i, ++listIterator)
    {
        cout << *listIterator << " "; 
    }
    cout << "..." << endl;
    
    // Засекаем время начала работы алгоритма
    start = time(NULL);

    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    cout << "Удалим и добавим элементы в начало, середину и конец списка." << endl;
    cout << "После, отсортируем список и найдем три добавленных элемента" << endl;

    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    cout << "Удаление первого, среднего и последнего элемента..." << endl;

    // 1-го
    ourList.pop_front(); 
    actualLen--;

    // среднего
    listIterator = ourList.begin();
    // перемещаем итератор до середины списка
    for(int i = 0; i < actualLen/2; ++i)
        listIterator++;
    // удаляем с середины
    ourList.erase(listIterator);
    actualLen--;
    

    // удаление последнего
    ourList.pop_back();
    actualLen--;


    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    cout << "Добавление в начало, середину и конец списка..." << endl;
  
    // в начало
    int pushedFront = dist(generatorForList);
    ourList.push_front(pushedFront);
    actualLen++;
    

    // в середину
    listIterator = ourList.begin();
    // перемещаем итератор до середины списка
    for(int i = 0; i < actualLen/2; ++i)
        listIterator++;

    int pushedMidle = dist(generatorForList);
    ourList.insert(listIterator, pushedMidle);
    actualLen++;
    
    // в конец
    int pushedBack = dist(generatorForList);
    ourList.push_back(pushedBack);
    

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

    cout << "Найдем случайный элемент списка." << endl;

    int searchedElem = dist(generatorForList);
    cout << "Искомый элемент: " << searchedElem << endl;

    listIterator = ourList.begin();

    for(;listIterator != ourList.end(); ++ listIterator)
    {
        if(*listIterator == searchedElem)
            cout << "Элемент найден." << endl;
    }

    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    finish = time(NULL);
    resultForList = finish - start;
    
    cout << "Время выполнения операций для списка: " << resultForList << " секунд" << endl;



    cout << std::setfill('=') <<std::setw(60) << '=' << endl;




    cout << "Создадим множество случайных положительных чисел длинной " << containerLen << " элементов." << endl;

    actualLen = containerLen;
    std::set<int> ourSet;

    setIterator = ourSet.begin();
    for(int i = 1; i <= containerLen; ++i)
    {
        setIterator = ourSet.insert(setIterator, i);
    }

        
    for(int i = 0; i < 20; ++i)
    {
        cout << *setIterator << " "; 
    }
    cout << "..." << endl;
    
    // Засекаем время начала работы алгоритма
    start = time(NULL);

    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    cout << "Удалим и добавим элементы в начало, середину и конец множества." << endl;
    cout << "После найдем три добавленных элемента (сортировать множество не будем - оно остортированно по умолчанию)" << endl;

    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    cout << "Удаление первого, среднего и последнего элемента..." << endl;

    // 1-го
    ourSet.erase(ourSet.begin()); 
    containerLen--;

    // среднего
    ourSet.erase(containerLen/2);
    containerLen--;
    

    // удаление последнего
    ourSet
    containerLen--;


    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    cout << "Добавление в начало, середину и конец списка..." << endl;
  
    // в начало
    int pushedFront = dist(generatorForList);
    ourList.push_front(pushedFront);
    containerLen++;
    

    // в середину
    listIterator = ourList.begin();
    // перемещаем итератор до середины списка
    for(int i = 1; i <= containerLen/2; ++i)
        listIterator++;

    int pushedMidle = dist(generatorForList);
    ourList.insert(listIterator, pushedMidle);
    containerLen++;
    
    // в конец
    int pushedBack = dist(generatorForList);
    ourList.push_back(pushedBack);
    

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

    cout << "Найдем случайный элемент списка." << endl;

    int searchedElem = dist(generatorForList);
    cout << "Искомый элемент: " << searchedElem << endl;

    listIterator = ourList.begin();

    for(;listIterator != ourList.end(); ++ listIterator)
    {
        if(*listIterator == searchedElem)
            cout << "Элемент найден." << endl;
    }

    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    finish = time(NULL);
    resultForList = finish - start;
    
    cout << "Время выполнения операций для списка: " << resultForList << " секунд" << endl;

    
    
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

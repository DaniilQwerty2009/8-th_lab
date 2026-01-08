#include <iostream>
#include <iomanip>
#include <windows.h>

#include <list>
#include <iterator>

#include <time.h>
#include <stdlib.h>

using std::cout;
using std::endl;

using std::list;

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
    time_t finish;
    time_t result;

    // уникальные значения для rand()
    srand(time(NULL));


    cout << "Создадим список случайных положительных чисел длинной 100000000 элементов." << endl;

    size_t containerLens = 1000000;
    list<int> ourList;

    // список из 100000000 случайных элементов в пределах int-допустимых значений
    for(int i = 1; i <= containerLens; ++i)
        ourList.push_back((rand() % INT_MAX - 1) + 1);

    
    list<int>::iterator iter = ourList.begin();
    for(int i = 0; i < 7; ++i, ++iter)
    {
        cout << *iter << " "; 
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
    containerLens--;

    // среднего
    iter = ourList.begin();
    // перемещаем итератор до середины списка
    for(int i = 1; i <= containerLens/2; ++i)
        iter++;
    // удаляем с середины
    ourList.erase(iter);
    containerLens--;
    

    // удаление последнего
    ourList.pop_back();
    containerLens--;

    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    cout << "Добавление первого, среднего и последнего элемента..." << endl;
  
    // в начало
    int pushedFront = rand() % INT_MAX;
    cout << "Первый элемент:" << pushedFront << endl;
    ourList.push_front(pushedFront);
    containerLens++;
    

    // в середину
    iter = ourList.begin();
    // перемещаем итератор до середины списка
    for(int i = 1; i <= containerLens/2; ++i)
        iter++;

    int pushedMidle = rand() % INT_MAX;
    cout << "Средний элемент:" << pushedMidle << endl;
    ourList.insert(iter, pushedMidle);
    containerLens++;


    // в конец
    int pushedBack = rand() % INT_MAX;
    cout << "Последний элемент:" << pushedBack << endl;
    ourList.push_back(pushedBack);
    containerLens++;
    

    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    cout << "Сортировка списка..." << endl;
    ourList.sort();

    iter = ourList.begin();
    for(int i = 0; i < 7; ++i, ++iter)
    {
        cout << *iter << " "; 
    }
    cout << "..." << endl;


    cout << std::setfill('-') <<std::setw(60) << '-' << endl;

    cout << "Поиск трех добавленных элементов..." << endl;

    iter = ourList.begin();

    cout << "Найденны элементы: " << endl;
    for(int findedElementsCounter = 0; iter != ourList.end() && findedElementsCounter != 3; ++iter)
    {
        if(*iter == pushedFront || *iter == pushedMidle || *iter == pushedBack)
        {
            cout << *iter << endl;
            findedElementsCounter++;
        }
    }


    finish = time(NULL);
    result = finish - start;
    cout << result << endl;

    
    
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

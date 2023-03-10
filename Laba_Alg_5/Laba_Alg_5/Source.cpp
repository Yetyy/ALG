#include <iostream>
#include <list>

int main() {
    int n;
    std::cin >> n;
    std::list<int> l; // ??????? ?????? ???? int
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num; // ????????? ??????? ??????
        l.push_back(num); // ????????? ??????? ? ??????
    }
    l.sort(); // ????????? ?????? ?? ???????????

    int res = 0; // ?????????? ??? ???????? ??????????
    while (l.size() > 1) { // ???? ? ?????? ?????? ?????? ????????
        int a = l.front(); // ???????? ??????????? ???????
        l.pop_front(); // ??????? ??????????? ??????? ?? ??????
        int b = l.front(); // ???????? ??????????? ???????
        l.pop_front(); // ??????? ??????????? ??????? ?? ??????
        l.push_back(a + b); // ????????? ????? ??????????? ????????? ? ??????
        l.sort();
        res += a + b; // ????????? ????? ??????????? ????????? ? ??????????
    }
    std::cout << res << std::endl; // ??????? ?????????
    return 0;
}

//#include <iostream>
//#include <set>
//
//int main() {
//    int n;
//    std::cin >> n;
//    std::multiset<int> s; // ??????? ????????? ???? int 
//    for (int i = 0; i < n; i++) {
//        int num;
//        std::cin >> num; // ????????? ??????? ?????????
//        s.insert(num); // ????????? ??????? ? ?????????
//    }
//
//    int res = 0; // ?????????? ??? ???????? ??????????
//    while (s.size() > 1) { // ???? ? ????????? ?????? ?????? ????????
//        int a = *s.begin(); // ???????? ??????????? ???????
//        s.erase(s.begin()); // ??????? ??????????? ??????? ?? ?????????
//        int b = *s.begin(); // ???????? ??????????? ???????
//        s.erase(s.begin()); // ??????? ??????????? ??????? ?? ?????????
//        s.insert(a + b); // ????????? ????? ??????????? ????????? ? ?????????
//        res += a + b; // ????????? ????? ??????????? ????????? ? ??????????
//    }
//
//    std::cout << res << std::endl; // ??????? ?????????
//    return 0;
//}
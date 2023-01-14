#include <iostream>
#include <array>
bool check(char containers[], char type)
{
    bool find = false;
    int i=0;
    for(int i=0;i<3;i++)
    {
        if (containers[i] == type) find = true;
    }
    return find;
}
void add(char cave[], char container)//
{
    int i = 0;
    cave[0] = cave[1];
    cave[1] = cave[2];
    cave[2] = container;
}

int coal(char cave[])//условие когда 1й уникальный контейнер даЄт только 1
{
    int a[3] = {1,1,1};
    if (cave[0] == cave[1] || cave[0]=='0')a[1] = 0;
    if(cave[0] == cave[2] || cave[2] == '0')a[2] = 0;
    if (cave[1] == cave[2] || cave[1] == '0')a[2] = 0;

    return(a[0] + a[1] + a[2]);
}
//int coal(char cave[])//условие когда 1й уникальный контейнер даЄт 3
//{
//    int a[3] = { 1,1,1 };
//    if (cave[0] == cave[1] && cave[0] != '0')a[0] = 0;
//    if (cave[0] == cave[2] && cave[2] != '0')a[2] = 0;
//    if (cave[1] == cave[2] && cave[1] != '0')a[1] = 0;
//
//    return(a[0] + a[1] + a[2]);
//}
int coal_check(char cave[], char container)
{
    int a[3] = { 1,1,1 };
    char cave_tmp[3];
    for (int i = 0; i < 3; i++)
    {
        cave_tmp[i] = cave[i];
    }
    cave_tmp[0] = cave_tmp[1];
    cave_tmp[1] = cave_tmp[2];
    cave_tmp[2] = container;
    int res = coal(cave_tmp);
   
    return(res);
}

int main() {
    char mine[2][3];// ћассив дл€ хранени€ получаемых продуктов
    char cave_1[3];
    char cave_2[3];
    int coal_c[2] = {0}; // ћассив дл€ хранени€ количества добытого угл€
    for (int i = 0; i < 3; i++)
       cave_1[i] = '0';
    for (int i = 0; i < 3; i++)
        cave_2[i] = '0';
    int n,size;
    std::cin >> n;
    std::cin.ignore();
    size = n;
    int count[2] = { 0 };
    char type;//M B F
    char type_arr[6];
    //while (n>0)//
    //    {
    //                std::cin >> type;
    //                --n;
    //                if (coal_check(cave_1, type) >= coal_check(cave_2, type)) { add(cave_1, type); coal_c[0] += coal(cave_1); }
    //                else
    //                    { add(cave_2, type); coal_c[1] += coal(cave_2); }

    //    }
        while (n>0)//
        {
                    std::cin >> type;
                    --n;
                    if(!check(cave_1,type))
                    if (coal_check(cave_1, type) >= coal_check(cave_2, type)) { add(cave_1, type); coal_c[0] += coal(cave_1); }
                    else
                        { add(cave_2, type); coal_c[1] += coal(cave_2); }
                    else if (!check(cave_2, type)) { add(cave_2, type); coal_c[1] += coal(cave_2); }
                        else if (coal_check(cave_1, type) >= coal_check(cave_2, type)) { add(cave_1, type); coal_c[0] += coal(cave_1); }
                        else
                            {
                                add(cave_2, type); coal_c[1] += coal(cave_2);
                            }
        }



    std::cout << coal_c[0] << " " << coal_c[1] << std::endl; // ¬ыводим количество добытого угл€ в каждом руднике
    std::cin.ignore();
    std::cin.get();

    return 0;
}
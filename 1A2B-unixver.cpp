/********************************************************
 * 自主學習C++實作
 * created by SHCH 210 04 宋辰星
 * for Mac&Linux 因為sleep的方式在兩種系統中不一樣，故分成兩種版本。
*********************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

//出題
void question(int A[])
{
    for (int i = 0; i <= 1000; i++) //透過多次交換，將A[]隨機排列
    {
        int x = rand() % 9;
        int y = rand() % 9;
        int Temp = A[x];
        A[x] = A[y];
        A[y] = Temp;
    }
}

//檢查使用者輸入是否正確
int check(int userin, int B[])
{
    if (userin > 9999)
        return 1;
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (B[i] == 0) //userin含有0
                return 1;
            else
                for (int j = i + 1; j < 4; j++)
                {
                    if (B[i] == B[j]) //userin的數字重複
                        return 1;
                }
        }
    }
    return 0;
}

int main()
{
    //intro
    cout << "這是一個叫做「1A2B」的經典猜數字遊戲，" << endl;
    sleep(1);
    cout << "A代表數字及位置皆正確，B代表數字正確但位置錯誤，" << endl;
    sleep(1);
    cout << "我會隨機出題，題目為一組不含0且數字不重複的四位數，" << endl;
    sleep(1);
    cout << "遊戲開始，" << endl;
    sleep(1);
    cout << "請請開始輸入你猜的數字：" << endl;

    srand(time(NULL)); //使用 srand()來設定亂數種子，亂數種子為當前時間，因此每次遊戲的亂數種子都會不一樣。
    int A[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int times = 0; //記錄使用者猜了幾次
    int userin;    //使用者輸入
    question(A);   //出題
    while (true)
    {
        int a = 0, b = 0; //紀錄幾a、幾b
        cin >> userin;
        times++;
        //把userin的四位數切開並存入B陣列中
        int B[] = {userin / 1000, (userin % 1000) / 100, (userin % 100) / 10, userin % 10};
        //檢查userin格式並將check()的回傳值存入result
        int result = check(userin, B);

        if (result == 1)
            cout << "輸入格式錯誤!!!!" << endl;
        else
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (A[i] == B[j] and i != j) //數字對且位置錯
                        b++;
                    else if (A[i] == B[j] and i == j) //數字對且位置對
                        a++;
                }
            }
        }
        cout << ">" << a << "A" << b << "B" << endl;
        if (a == 4)
        {
            cout << "恭喜猜對! \n你總共猜了：" << times << "次" << endl;
            break;
        }
        else
        {
            cout << "再猜猜看：" << endl;
        }
    }
    return 0;
}

#include<iostream>
#include<random>
#define N 3
using namespace std;
int main()
{
    int ans[N];
    int myans;
    int myans1[N];
    int myans2;
    int eat;
    int byte;
    int z;
    int count=0;
    random_device rnd;
    for(int i=0;i<N;i++)
    {
        ans[i]=rnd()%10;
        if(i==1&&ans[i]==ans[i-1])
        {
            i--;
        }
        if(i==2&&ans[i]==ans[i-1]||ans[i]==ans[i-2])
        {
            i--;
        }
    }
    /*for(int i=0;i<N;i++)
    {
        cout << ans[i];
    }*/
    cout << endl;
    cout << "ゲームを始めます.3桁の数字を当ててください.尚,各ビット同じ数字は入れてはいけません.\n";
    cout << "15手以内に当ててください.\n";
    while(eat!=3)
    {
        count++;
        cout << count << "手目\n";
        eat=0;
        byte=0;
        cout << "3桁の数字を入力してください.(2桁の場合は1桁目を0とみなします)\n";
        cin >> myans;
        myans2=myans;
        for(int i=N-1;i>=0;i--)
        {
            myans1[i]=myans2%10;
            myans2=myans2/10;
        }
        while(myans<10||myans>999||myans1[0]==myans1[1]||myans1[0]==myans1[2]||myans1[1]==myans1[2])
        {
            
            cout << "3桁の数字を入力してください.(※各ビット同じ数字を入れてはいけません.)\n";
            cin >> myans;
            myans2=myans;
            for(int i=N-1;i>=0;i--)
            {
                myans1[i]=myans2%10;
                myans2=myans2/10; 
            }
        }
        /*for(int i=0;i<N;i++)
        {
            cout << myans1[i];
        }
        cout << endl;*/
        for(int i=0;i<N;i++)
        {
            if(ans[i]==myans1[i])
            {
                eat++;
            }
            else if(i==0&&ans[i]==myans1[i+1]||ans[i]==myans1[i+2])
            {
                byte++;
            }
            else if(i==1&&ans[i]==myans1[i-1]||ans[i]==myans1[i+1])
            {
                byte++;
            }
            else if(i==2&&ans[i]==myans1[i-1]||ans[i]==myans1[i-2])
            {
                byte++;
            }
        }
        cout << eat << "EAT  " << byte << "BYTE" << endl;
        if(count==15)
        {
            break;
        }
    }
    if(count!=15)
    {
        cout << "Congratulation!!" << endl;
        cout << count << "手でクリアしました.\n";
    }
    else 
    {
        cout << "GAME OVER!!!\n";
    }
    return 0;
}

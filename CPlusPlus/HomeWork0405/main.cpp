

#include <iostream>
#include "HomeWork0405.h"

int main()
{

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


    //¼÷Á¦1, 2
    {
        GameEngineArray Array0(10);


        for (size_t i = 0; i < Array0.Count(); i++)
        {
            Array0[i] = i;
        }

        printf_s("====Long Resize====\n");
        Array0.ReSize(16);
        for (size_t i = 0; i < Array0.Count(); i++)
        {
            printf_s("%d\n", Array0[i]);
        }

        printf_s("====Short Resize====\n");
        Array0.ReSize(8);
        for (size_t i = 0; i < Array0.Count(); i++)
        {
            printf_s("%d\n", Array0[i]);
        }

    }


    //¼÷Á¦3, 4
    {
        GameEngineArray Array0(16);
        GameEngineArray Array1(24);

        for (size_t i = 0; i < Array0.Count(); i++)
        {
            Array0[i] = i;
        }
        for (size_t i = 0; i < Array1.Count(); i++)
        {
            Array1[i] = i;
        }
        
        Array1 = Array0;

        printf_s("====Assignment======\n");
        for (size_t i = 0; i < Array1.Count(); i++)
        {
            printf_s("%d\n", Array1[i]);
        }

    }

}


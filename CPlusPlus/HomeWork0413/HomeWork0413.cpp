

#include <iostream>
#include <list>
#include <crtdbg.h>

typedef int DataType;

class GameEngineList
{
private:
    class ListNode
    {
    public:
        ListNode* Prev = nullptr;
        ListNode* Next = nullptr;
        DataType Value;

    public:
        ~ListNode()
        {
            if (nullptr != Next)
            {
                delete Next;
                Next = nullptr;
            }
        }
    };

private:
    ListNode* StartNode = new ListNode();
    ListNode* EndNode = new ListNode();


public:
    class iterator
    {
        friend GameEngineList;

    public:
        iterator()
        {

        }

        iterator(ListNode* _CurNode)
            : CurNode(_CurNode)
        {

        }

        bool operator !=(const iterator& _Other)
        {
            return CurNode != _Other.CurNode;
        }

        iterator& operator ++()
        {
            CurNode = CurNode->Next;

            return *this;
        }

        DataType& operator*()
        {
            return CurNode->Value;
        }

    private:
        ListNode* CurNode = nullptr;
    };

    GameEngineList()
    {
        StartNode->Next = EndNode;
        EndNode->Prev = StartNode;
    }

    ~GameEngineList()
    {
        if (nullptr != StartNode)
        {
            delete StartNode;
            StartNode = nullptr;
        }
    }

    iterator begin()
    {
        return iterator(StartNode->Next);
    }

    iterator end()
    {
        return iterator(EndNode);
    }

    iterator erase(iterator& _DeleteNode)
    {
        ListNode* DeleteNode = _DeleteNode.CurNode;

        ListNode* PrevNode = DeleteNode->Prev;
        ListNode* NextNode = DeleteNode->Next;

        DeleteNode->Prev = nullptr;
        DeleteNode->Next = nullptr;

        if (nullptr != DeleteNode)
        {
            delete DeleteNode;
            DeleteNode = nullptr;
        }

        PrevNode->Next = NextNode;
        NextNode->Prev = PrevNode;

        return iterator(NextNode);
    }

    void push_back(const DataType& _Data)
    {
        ListNode* NewListNode = new ListNode();
        NewListNode->Value = _Data;

        ListNode* PrevNode = EndNode->Prev;

        PrevNode->Next = NewListNode;
        EndNode->Prev = NewListNode;
        NewListNode->Next = EndNode;
        NewListNode->Prev = PrevNode;
    }

    void push_front(const DataType& _Data)
    {
        ListNode* NewListNode = new ListNode();
        NewListNode->Value = _Data;
        
        ListNode* NextNode = StartNode->Next;
        NextNode->Prev = NewListNode;
        StartNode->Next = NewListNode;
        NewListNode->Prev = StartNode;
        NewListNode->Next = NextNode;

    }
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    {

        GameEngineList NewList;

        NewList.push_back(999);
        NewList.push_back(888);
        NewList.push_back(777);
        NewList.push_back(123156456);

        NewList.push_front(111);
        NewList.push_front(222);
        NewList.push_front(333);
        NewList.push_front(9876);


        //{
        //    GameEngineList::iterator Delete = NewList.begin();
        //    ++Delete;

        //    NewList.erase(Delete);
        //}


        GameEngineList::iterator Start = NewList.begin();
        GameEngineList::iterator End = NewList.end();

        for (; Start != End; ++Start)
        {
            printf_s("%d\n", *Start);
        }

    }

    return 1;

    //{
    //    std::list<int> NewList;

    //    NewList.push_back(999);
    //    NewList.push_back(888);
    //    NewList.push_back(777);
    //    NewList.push_back(123156456);
    //    NewList.push_front(2000);

    //    {
    //        //                    999
    //        std::list<int>::iterator Delete = NewList.begin();
    //        ++Delete; // 888

    //        NewList.erase(Delete);

    //    }


    //    std::list<int>::iterator Start = NewList.begin();
    //    std::list<int>::iterator End = NewList.end();


    //    for (; Start != End; ++Start)
    //    {
    //        printf_s("%d\n", *Start);
    //    }

    //}



}

#include <bits/stdc++.h>

using namespace std;
template <class T>
class Node
{
public:
    T Data;
    Node *Next;
};
template <class T>
class LinkedList : public Node<T>
{
private:
    Node<T> *Head;
    Node<T> *Current;

public:
    LinkedList()
    {
        Head = Current = NULL;
    //    Head->Next = Current->Next = NULL;
    }
    int push_back(T data)
    {
        Node<T> *temp = new Node<T>;
        temp->Next = NULL;
        temp->Data = data;
        if (Head == NULL)
        {
            Head = temp;
            Current = temp;
        }
        else
        {
            Current->Next = temp;
            Current = temp;
        }
        return 0;
    }
    int remove(int index){
        Node<T> *temp = Head;
        Node<T> *temp2 = Head;
        int i = 0;
        while(i < index){
            temp2 = temp;
            temp = temp->Next;
            i++;
        }
        temp2->Next = temp->Next;
        delete temp;
        return 0;
    }
    int at(int index)
    {
        Node<T> *temp = Head;
        int i = 0;
        while (i < index)
        {
            temp = temp->Next;
            i++;
        }
        return temp->Data;
    }
    Node<T> *swap(Node<T> *a1, Node<T> *b1) //BUBBLE SORT
    {
        Node<T> *tmp = b1->Next;
        b1->Next = a1;
        a1->Next = tmp;
        return b1;
    }
    void Remove()
    {
        Node<T> *temp = Head;
        Head = temp->Next;
        cout << "\n"
             << temp->Data << endl;
        delete temp;
    }
  
};

int main(){
    int option;
    cout<<"1. Push Back"<<endl;
    cout<<"2. Remove"<<endl;
    cout<<"3. At"<<endl;
    cout<<"4. information"<<endl;
    cout<<"5. Exit"<<endl;
    cin>>option;
    LinkedList<int> list;
    switch(option){
        case 1:
            int data;
            cout<<"Enter data: ";
            cin>>data;
            list.push_back(data);
            break;
        case 2:
            int index;
            cout<<"Enter index: ";
            cin>>index;
            list.remove(index);
            break;
        case 3:
            int index;
            cout<<"Enter index: ";
            cin>>index;
            cout<<list.at(index)<<endl;
            break;
        case 4:

            break;
        case 5:
            exit(0);
            break;
    }
}
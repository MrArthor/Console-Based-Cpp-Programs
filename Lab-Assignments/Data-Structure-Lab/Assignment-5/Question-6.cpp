#include <iostream>

using namespace std;
class node
{
public:
    int data;
    node *next;
};

class linked_list
{
public:
    node *head;
    int count;

    linked_list()
    {

        head = NULL;
        count = 0;
    }

    node *createNode(int n) //CREATE NODE
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;
        count++;
        return tmp;
    }

    void insert_beg(int n) //INSERT AT THE BEGINNING
    {
        node *temp = createNode(n);

        temp->next = head;
        head = temp;
    }

    void insert_end(int n) //INSERT AT THE END
    {
        node *temp = createNode(n);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = temp;
            count++;
        }
    }

    node *swap(node *a1, node *b1) //BUBBLE SORT
    {
        node *tmp = b1->next;
        b1->next = a1;
        a1->next = tmp;
        return b1;
    }

    void BubleSort(node **head, int c)
    {
        node **h;
        for (int i = 0; i <= c; i++)
        {
            h = head;

            for (int j = 0; j < c - i - 1; j++)
            {

                node *a = *h;
                node *b = a->next;

                if (a->data > b->data)
                {
                    *h = swap(a, b);
                }

                h = &(*h)->next;
            }
        }
    }

    void display() //DISPLAY NODE
    {
        cout << "\nList: ";
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void BubleSorting()
    {
        BubleSort(&head, count);
    }
    void selectionSort(node *head)
    {
        node *temp = head;

        while (temp)
        {
            node *min = temp;
            node *r = temp->next;

            while (r)
            {
                if (min->data > r->data)
                    min = r;

                r = r->next;
            }

            int x = temp->data;
            temp->data = min->data;
            min->data = x;
            temp = temp->next;
        }
    }
    void SelectionSorting()
    {
        selectionSort(head);
    }
    void del_beg() //DELETE FROM BEGINNING
    {
        if (head == NULL)
            cout << "\nList is empty.";
        else
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void InsertionSort();
    void del_end() //DELETE FROM THE END
    {
        if (head == NULL)
            cout << "\nList is empty.";
        else if (head->next == NULL)
            delete head;
        else
        {
            node *temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;

            delete temp->next;
            temp->next = NULL;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    linked_list ll;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        ll.insert_end(temp);
    }
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
        ll.SelectionSorting();
        break;
    case 2:
        ll.BubleSorting();
        break;
    case 3:
        ll.InsertionSort();
        break;
    default:
        cout << "Wrong Option ";
        break;
    }
    cout << "Hie Death ";
    return 0;
}
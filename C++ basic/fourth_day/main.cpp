//简单的仓库进货出货的类练习
#include <iostream>
using namespace std;
class warehouse
{
public:
    warehouse()
    {
        m_w = 0;
        this->next = NULL;
    }
    warehouse(int w)
    {
        m_w = w;
        total_w += w;
        this->next = NULL;
    }
    ~warehouse()
    {
        delete next;
        total_w -= m_w;
    }
    static void show()
    {
        cout<<"Now warehouse weight is "<<total_w<<endl;
    }
    warehouse *next;
private:
    int m_w;//货物重量
    static int total_w;//仓库货物总重量
};
int warehouse::total_w = 0;

void buy( warehouse*& head, int w)
{
    if(head == NULL)
        head = new warehouse(w);
    else
    {
        warehouse* new_head = new warehouse(w);
        new_head->next = head;
        head = new_head;
    }
}

void sell(warehouse*& head)
{
    if(head == NULL)
    {
        cout<<"warehouse is empty"<<endl;
        return;
    }
    warehouse* temp = head;
    head = temp->next;
    delete temp;
}
int main()
{
    int w;
    warehouse* head = NULL;
    int key;
    do {
        cout<<" buy goods: 1        sell goods: 2         exit: 0"<<endl;
        cout<<" please show your choice: ";
        cin>>key;
        switch (key)
        {
            case 1:
                cout<<"the input goods weight is: ";
                cin>>w;
                buy(head,w);
                break;
            case 2:
                sell(head);
                break;
            case 0:
                return 0;
            default:
                return 0;
        }
        warehouse::show();
        cout<<endl<<endl;
    }while(1);

}
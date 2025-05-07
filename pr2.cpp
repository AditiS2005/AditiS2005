#include<iostream>
using namespace std;
#define max 10

class Hash {
    public:
    long int h1[max];

    Hash() {
        for (int i = 0; i < max; i++) {
            h1[i] = -1;
        }
    }

    void insertlp();
    void insertqp();
    int lp(int pos);
    int qp(int pos);
    void display();
    void cleartable();
};

int Hash::lp(int pos) {
    for(int i=1;i<max;i++)
    {
        int newP=(pos+i)%max;
        if(h1[newP]==-1)
        {
            return newP;
        }
    }
    return -1;
}
int Hash::qp(int pos) 
{
    for(int i=1;i<max;i++)
    {
        int newP= (pos+i*i)%max;
        if(h1[newP]==-1)
        {
            return newP;
        }
    }
    return -1;
}
void Hash::insertlp() {
    long int key,index;
    cout<<"\n Enter phone number";
    cin>>key;
    index=key%max;
    if(h1[index]==-1)
    {
        h1[index]=key;
    }
    else
    {
        int newIndex=lp(index);
        if(newIndex!=-1)
        {
            h1[newIndex]=key;
        }
        else
        {
            cout<<"Hash table is full. Cannot insert.\n";
        }
    }
}

void Hash::insertqp() 
{
    long int key, index;
    cout << "\nEnter phone number: ";
    cin >> key;
    index = key % max;
    if (h1[index] == -1) 
    {
        h1[index] = key;
    } 
    else 
    {
        int newIndex = qp(index);
        if (newIndex != -1) 
        {
            h1[newIndex] = key;
        } 
        else 
        {
            cout << "Hash table is full. Cannot insert.\n";
        }
    }
}

void Hash::display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < max; i++) 
    {
        cout << "Index " << i << " : ";
        if (h1[i] == -1) 
        {
            cout << "Empty";
        } 
        else 
        {
            cout << h1[i];
        }
        cout << "\n";
    }
}

void Hash::cleartable() {
    for (int i = 0; i < max; i++) {
        h1[i] = -1;
    }
}

int main() {
    Hash obj;
    int choice, n;

    do {
        cout << "\nMenu:";
        cout << "\n1. Linear Probing";
        cout << "\n2. Quadratic Probing";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\nHow many elements do you want to insert? ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    obj.insertlp();
                }
                obj.display();
                obj.cleartable();
                break;

            case 2:
                cout << "\nHow many elements do you want to insert? ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    obj.insertqp();
                }
                obj.display();
                obj.cleartable();
                break;

            case 3:
                cout << "\nThanks for using this program!\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}

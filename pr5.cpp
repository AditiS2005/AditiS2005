#include <iostream>
using namespace std;

class tnode {
public:
    int data, lbit, rbit;
    tnode *lp, *rp;
};

class tbt {
public:
    tnode *root, *head;

    tbt() {
        root = nullptr;
        head = nullptr;
    }

    void insert();
    void inorder();
    void preorder();
};

void tbt :: insert()
{
    char ans;
    int flag=0;
    tnode *temp, *newnode;
    if(root==nullptr)
    {
        head=new tnode();
        head->lp=head;
        head->rp=head;
        head->lbit=0;
        head->rbit=1;
        head->data=-1;

        root=new tnode();
        root->lp=head;
        root->rp=head;
        root->lbit=0;
        root->rbit=0;

        cout<<"\n Enter root ";
        cin>>root->data;

        head->lp=root;
        head->lbit=1;
    }
    do
    {
        newnode=new tnode();
        newnode->lbit=0;
        newnode->rbit=0;
        cout<<"\n Enter node ";
        cin>>newnode->data;
        temp=root;
        flag=0;
        while(flag==0)
        {
            if(newnode->data < temp->data)
            {
                if(temp->lbit==0)
                {
                    newnode->lp=temp->lp;
                    newnode->rp=temp;
                    temp->lp=newnode;
                    temp->lbit=1;
                    flag=1;
                }
                else{
                    temp=temp->lp;
                }
            }
            else if(newnode->data > temp->data)
            {
                if(temp->rbit==0)
                {
                    newnode->rp=temp->rp;
                    newnode->lp=temp;
                    temp->rp=newnode;
                    temp->rbit=1;
                    flag=1;
                }
                else{
                    temp=temp->rp;
                }
            }
            else{
                cout<<"\n Node already exist";
                break;
            }
            
        }cout<<"\n Do you want to continue (y/n)";
        cin>>ans;
    }while(ans=='Y' || ans=='y');
}

void tbt::inorder() {
    if (root == NULL) {
        cout << "\nTree is empty";
        return;
    }
    tnode *temp = root;
    while (temp->lbit == 1)
        temp = temp->lp;

    while (temp != head) {
        cout << temp->data << " ";

        if (temp->rbit == 1) {
            temp = temp->rp;
            while (temp->lbit == 1)
                temp = temp->lp;
        } else {
            temp = temp->rp;
        }
    }
}

void tbt::preorder() {
    tnode *temp = root;
    int flag=0;
    if (root == NULL) {
        cout << "\nTree is empty";
        return;
    }
    else{
        while(temp!=head)
        {
            if(flag==0)
            {
                cout<<temp->data<<" ";
            }
            if(temp->lbit==1 && flag==0)
            {
                temp=temp->lp;
            }
            else{
                if(temp->rbit==1)
                {
                    temp=temp->rp;
                    flag=0;
                }
                else{
                    temp=temp->rp;
                    flag=1;
                }
            }
        }
    }
}


int main() {
    tbt t;
    int ch;

    do {
        cout << "\n\n** MENU **";
        cout << "\n1. Insert";
        cout << "\n2. Inorder";
        cout << "\n3. Preorder";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                t.insert();
                break;
            case 2:
                cout << "Inorder: ";
                t.inorder();
                break;
            case 3:
                cout << "Preorder: ";
                t.preorder();
                break;
            case 4:
                cout << "End of Program." << endl;
                break;
            default:
                cout << "Invalid choice!!" << endl;
        }
    } while (ch != 4);

    return 0;
}

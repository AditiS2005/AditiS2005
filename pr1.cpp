/*
Assignment 01:
*/

#include<iostream>
using namespace std;
class Set
{
    int a[20],count;
    public:
    Set()
    {
        count=0;
    }
    void insert();
    void del();
    void display();
    void size();
    int search(int val);
    void union1(Set,Set);
    void intersection(Set,Set);
    void difference(Set A,Set B);
    int subset(Set A,Set B);
};
void Set::insert()
{
    int key;
    cout<<"Enter total no of elements of Set : "<<endl;
    cin>>count;
    for(int i=0;i<count;i++)
    {
        cout<<"\nEnter "<<i<<" Element: ";
        cin>>key;
        a[i]=key;
    }
}

void Set::display()
{
    if(count>0)
    {
        cout<<" { ";
        for(int i=0;i<count-1;i++)
        {
            cout<<a[i]<<" , ";
        }
        cout<<a[count-1]<<" } ";
    }
    else
    {
        cout<<"Set is Empty"<<endl;
    }
}
void Set::size()
{
    cout<<"Size of set is: "<<count<<endl;
}

int Set::search(int val)
{
    for(int i=0;i<count;i++)
    {
        if(a[i]==val)
        {
            return i;
        }
    }
    return -1;
}

void Set::del()
{
    int val;
    cout<<"Enter element to delete:  ";
    cin>>val;
    int index=search(val);
    if(index<0)
    {
        cout<<"Element not found "<<endl;
    }
    else
    {
        for(int i=index;i<count-1;i++)
        {
            a[i]=a[i+1];
        }
        count--;
    }
}
void Set::union1(Set A, Set B)
{
    count = 0;

    // Copy all elements from A
    for(int i = 0; i < A.count; i++)
        a[count++] = A.a[i];

    // Add elements from B if not present in A
    for(int i = 0; i < B.count; i++)
        if(A.search(B.a[i]) == -1)
            a[count++] = B.a[i];
}

void Set::intersection(Set A,Set B)
{
    for(int i=0;i<A.count;i++)
    {
        if(B.search(A.a[i])!=-1)
        {
            a[count++]=A.a[i];
        }
    }   
}
void Set::difference(Set A,Set B)
{
    for(int i=0;i<A.count;i++)
    {
        if(B.search(A.a[i])==-1)
        {
            a[count++]=A.a[i];
        }
    }
}
int Set::subset(Set A,Set B)
{
    for(int i=0;i<B.count;i++)
    {
        if(A.search(B.a[i])==-1)
        {
            cout<<"Set is not a Subset "<<endl;
            return 0;
        }
    }
    cout<<"Set is a Subset "<<endl;
    return 1;
}
int main()
{
    Set A,B,C,D,E,F;
    int ch;
    do
    {
        cout<<"\n------------Main Menu-----------"<<endl;
        cout<<"1.Insert Element\n2.Delete Element\n3.Display Elelement\n4.Search\n5.Size\n6.Union\n7.Intersection\n8.difference\n9.subset\n10.Exit\nEnter choice"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                A.insert();
                B.insert();
                break;
            case 2:
                A.del();
                break;
            case 3:
                cout<<"Set A : "<<endl;
                A.display();
                cout<<"\nSet B :"<<endl;
                B.display();
                break;
            case 4:
                int ele,index;
                cout<<"Enter element to search: ";
                cin>>ele;
                index=A.search(ele);
                if(index!=-1)
                {
                    cout<<"Element found at index " <<index;
                }
                else
                {
                    cout<<"Element not found"<<endl;
                }      
                break;
            case 5:
                A.size();
                break;
            case 6:
                C.union1(A,B);
                C.display();
                break;
            case 7:
                D.intersection(A,B);
                D.display();
                break;
            case 8:
                E.difference(A,B);
                E.display();
                break;
            case 9:
                F.subset(A,B);
                F.display();
                break;
            case 10:
                cout<<"Thanks for using "<<endl;
                break;
                default : cout<<"Enter valid choice"<<endl;
                break;
        }
    }
    while(ch!=10);
    return 0;
}


/*
Output:
gescoe@gescoe-OptiPlex-3010:~$ cd Desktop
gescoe@gescoe-OptiPlex-3010:~/Desktop$ cd SEA_47
gescoe@gescoe-OptiPlex-3010:~/Desktop/SEA_47$ g++ pr1.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop/SEA_47$ ./a.out
------------Main Menu-----------
1.Insert Element
2.Delete Element
3.Display Elelement
4.Search
5.Size
6.Union
7.Intersection
8.difference
9.subset
10.Exit
Enter choice: 1
Enter total no of elements of Set : 
3

Enter 0 Element: 1

Enter 1 Element: 2

Enter 2 Element: 3
Enter total no of elements of Set : 
2

Enter 0 Element: 2

Enter 1 Element: 4

------------Main Menu-----------
1.Insert Element
2.Delete Element
3.Display Elelement
4.Search
5.Size
6.Union
7.Intersection
8.difference
9.subset
10.Exit
Enter choice: 3
Set A : 
 { 1 , 2 , 3 } 
Set B :
 { 2 , 4 } 

------------Main Menu-----------
1.Insert Element
2.Delete Element
3.Display Elelement
4.Search
5.Size
6.Union
7.Intersection
8.difference
9.subset
10.Exit
Enter choice: 4
Enter element to search: 3
Element found at index 2

------------Main Menu-----------
1.Insert Element
2.Delete Element
3.Display Elelement
4.Search
5.Size
6.Union
7.Intersection
8.difference
9.subset
10.Exit
Enter choice: 6
 { 1 , 2 , 3 , 4 } 

------------Main Menu-----------
1.Insert Element
2.Delete Element
3.Display Elelement
4.Search
5.Size
6.Union
7.Intersection
8.difference
9.subset
10.Exit
Enter choice: 7
 { 2 } 

------------Main Menu-----------
1.Insert Element
2.Delete Element
3.Display Elelement
4.Search
5.Size
6.Union
7.Intersection
8.difference
9.subset
10.Exit
Enter choice: 8
 { 1 , 3 } 

------------Main Menu-----------
1.Insert Element
2.Delete Element
3.Display Elelement
4.Search
5.Size
6.Union
7.Intersection
8.difference
9.subset
10.Exit
Enter choice: 9
Set is not a Subset

------------Main Menu-----------
1.Insert Element
2.Delete Element
3.Display Elelement
4.Search
5.Size
6.Union
7.Intersection
8.difference
9.subset
10.Exit
Enter choice: 10
Thanks for using
*/
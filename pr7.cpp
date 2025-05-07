#include <iostream>
using namespace std;

class node
{
public:
    char u1, u2;
    int wt;  // Corrected from char to int
};

class test
{
    int n, m, x;
    node a[10], r[10];

public:
    test()
    {
        n = 0;
        m = 1;
    }
    void inputsparse();
    void disparse();
    void bsort();
    void prims();
    void dispmst();
};

void test::inputsparse()
{
    cout << "\nEnter no of edges: ";
    cin >> n;
    cout << "\nEnter no of vertices: ";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter first vertex: ";
        cin >> a[i].u1;
        cout << "Enter second vertex: ";
        cin >> a[i].u2;
        cout << "Enter weight: ";
        cin >> a[i].wt;
    }
    bsort();
}

void test::disparse()
{
    cout << "\nSorted edges by weight:\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i].u1 << " " << a[i].u2 << " " << a[i].wt << endl;
    }
}

void test::bsort()
{
    node temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j].wt > a[j + 1].wt)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void test::prims()
{
    int flag1, flag2;
    m = 1;
    r[0] = a[0]; // Start with the lightest edge
    do
    {
        bool edgeAdded = false;
        for (int i = 1; i < n; i++)
        {
            flag1 = flag2 = 0;
            // Check if either u1 or u2 of a[i] is already in MST
            for (int j = 0; j < m; j++)
            {
                if (a[i].u1 == r[j].u1 || a[i].u1 == r[j].u2)
                    flag1 = 1;
                if (a[i].u2 == r[j].u1 || a[i].u2 == r[j].u2)
                    flag2 = 1;
            }
            // Add edge if it connects to exactly one visited vertex
            if ((flag1 == 1 && flag2 == 0) || (flag1 == 0 && flag2 == 1))
            {
                r[m++] = a[i];
                edgeAdded = true;
                break; // Add one edge per iteration
            }
        }
        cout << "\nCurrent MST edges: ";
        for (int k = 0; k < m; k++)
        {
            cout << "(" << r[k].u1 << ", " << r[k].u2 << ", " << r[k].wt << ") ";
        }
        cout << endl;

        if (!edgeAdded)
        {
            cout << "\nNo more edges can be added to the MST.\n";
            break;
        }

    } while (m < x - 1);
}

void test::dispmst()
{
    int total = 0;
    cout << "\nEdges in MST:\n";
    for (int i = 0; i < m; i++)
    {
        cout << r[i].u1 << " " << r[i].u2 << " " << r[i].wt << endl;
        total += r[i].wt;
    }
    cout << "Total weight of MST: " << total << endl;
}

int main()
{
    test t;
    t.inputsparse();
    t.disparse();
    t.prims();
    cout << "\nResult:";
    t.dispmst();
    return 0;
}


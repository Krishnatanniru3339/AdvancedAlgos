#include <iostream>
using namespace std;

class Node
{
public:
    int matrix_row;
    int matrix_col;
    int data;
    Node *nxt;

    Node(int index_row, int index_col, int x)
    {
        matrix_row = index_row;
        matrix_col = index_col;
        data = x;
        nxt = NULL;
    }
};

void create_new_node(Node **ptr, int index_row, int index_col, int x)
{
    Node *temp = *ptr;
    Node *r;
    if (temp == NULL)
    {
        *ptr = new Node(index_row, index_col, x);
    }
    else
    {
        while (temp->nxt != NULL)
            temp = temp->nxt;

        r = new Node(index_row, index_col, x);
        temp->nxt = r;
    }
}

void print_list(Node *start)
{
    Node *p = start;
    while (p != NULL)
    {
        cout << p->matrix_row << " ";
        p = p->nxt;
    }
    cout << endl;

    p = start;
    while (p != NULL)
    {
        cout << p->matrix_col << " ";
        p = p->nxt;
    }
    cout << endl;
    p = start;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->nxt;
    }
}

int main()
{
    int i = 0;
    int sparse_matrix[4][5] =
        {
            {0, 0, 3, 0, 4},
            {0, 0, 5, 7, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 6, 0, 0}
        };

    Node *start = NULL;
    while (i < 4)
    {
        int j = 0;
        while (j < 5)
        {
            if (sparse_matrix[i][j] != 0)
                create_new_node(&start, i, j, sparse_matrix[i][j]);
            j++;
        }
        i++;
    }
    print_list(start);
}

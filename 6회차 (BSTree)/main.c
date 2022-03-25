#include <stdio.h>
#include "BSTree.h"
#include "vld.h"

int compareInt(Element* e1, Element* e2)
{
    if (*e1 == *e2) return 0;
    else if (*e1 > *e2) return 1;
    else return -1;
}

void Print(Element* e, void* p)
{
    printf("Data: %d\n", *e);
}

//               11(root)
//      3(p1)              17(p3)
//           7(p2)     13(p4)   19(p5)
int main() 
{
    PTreeNode p2 = TreCreateNode(7);
    PTreeNode p1 = TreCreateNode2(3, NULL, p2);
    PTreeNode p4 = TreCreateNode(13);
    PTreeNode p5 = TreCreateNode(19);
    PTreeNode p3 = TreCreateNode2(17, p4, p5);
    PTreeNode root = TreCreateNode2(11, p1, p3);

    printf("Preorder traversal\n");
    TreIterate(root, Print, NULL, TTO_PREORDER);
    printf("Inorder traversal\n");
    TreIterate(root, Print, NULL, TTO_INORDER);
    printf("Postorder traversal\n");
    TreIterate(root, Print, NULL, TTO_POSTORDER);
    TreDestroy(root);

    PTreeNode root2 = NULL;
    root2 = BSTreInsert(root2, 11, compareInt);
    root2 = BSTreInsert(root2, 3, compareInt);
    root2 = BSTreInsert(root2, 17, compareInt);
    root2 = BSTreInsert(root2, 7, compareInt);
    root2 = BSTreInsert(root2, 13, compareInt);
    root2 = BSTreInsert(root2, 19, compareInt);
    printf("Inorder traversal of root2\n");
    TreIterate(root2, Print, NULL, TTO_INORDER);

    root2 = BSTreDelete(root2, 17, compareInt); // case 3
    printf("Inorder traversal of root2 after deleting 17\n");
    TreIterate(root2, Print, NULL, TTO_INORDER);

    root2 = BSTreDelete(root2, 19, compareInt); // case 2
    printf("Inorder traversal of root2 after deleting 19\n");
    TreIterate(root2, Print, NULL, TTO_INORDER);

    root2 = BSTreDelete(root2, 7, compareInt); // case 1
    printf("Inorder traversal of root2 after deleting 7\n");
    TreIterate(root2, Print, NULL, TTO_INORDER);

    TreDestroy(root2);

    return 0;
}
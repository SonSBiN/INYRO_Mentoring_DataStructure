#include <stdio.h>
#include "Tree.h"
//#include "vld.h"

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
    return 0;
}
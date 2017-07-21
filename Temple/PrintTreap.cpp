void Print(Treap* o){//Print A Tree
    printf("%d :",val);
    printf("Lc -> ");
    if(lc == NULL)printf("NULL ");
    else printf("%d ",lc -> v);
    printf("Rc -> ");
    if(rc == NULL)printf("NULL \n");
    else printf("%d \n",rc -> v);
    if(lc != NULL)Print(lc);
    if(rc != NULL)Print(rc);
}

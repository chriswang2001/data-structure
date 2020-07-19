int init_cross_list(PCrossList L, const ElemType *A, int m, int n)
{
    L->rows = m;
    L->cols = n;
    L->nums = 0;

    if(!(L->rowhead = (OLink*)malloc(m*sizeof(OLink))))
        exit(OVERFLOW);
    for(int j = 0; j < m; j++)
        L->rowhead[j] = NULL;
    
    if(!(L->colhead = (OLink*)malloc(n*sizeof(OLink))))
        exit(OVERFLOW);
    for(int k = 0; k < n; k++)
        L->colhead[k] = NULL;

    for(int j = 1; j <= m; j++)
    {
        OLink *x = &(L->rowhead[j-1]);
        for(int k = 1; k <= n; k++)
        {
            if(*A)
            {
                (*x) = (OLink)malloc(sizeof(OLNode));
                (*x)->row = j;
                (*x)->col = k;
                (*x)->value = *A;
                (*x)->right = NULL;
                (*x)->down = NULL;

                OLink y = L->colhead[k-1];
                if(y)
                {
                    while(y->down)
                    y = y->down;        
                    y->down = *x;
                }
                else
                    L->colhead[k-1] = *x;

                x = &((*x)->right);
                A++;
                L->nums++;
            }
            else
                A++;
        }
    }
    return L->nums;    
}
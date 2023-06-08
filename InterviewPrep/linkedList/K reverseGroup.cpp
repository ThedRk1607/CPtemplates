
listnode *reverse (listnode *head, int k)
{
    listnode *current = head, *next = NULL, *prev = NULL;
    int count = 0;   

    while (current != NULL && count < k)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next !=  NULL)
        head->next = reverse(next, k); 

    return prev;
}

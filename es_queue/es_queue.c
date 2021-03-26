void enqueue (Nodo **head, Nodo **tail, Nodo *element){
    if (is_empty(*head))
        *head = element;
    else
        (*tail)->next = element;
    
}
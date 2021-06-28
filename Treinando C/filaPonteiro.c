void inserir ( tree * tree_ptr, int valor )
{
	node * novo_node_ptr = NULL;
	node * next_ptr = NULL;
	node * last_ptr = NULL;

	if ( tree_ptr->raiz == NULL )
	{
		novo_node_ptr = init_node ( valor );
		tree_ptr->raiz = novo_node_ptr;
	}
	else
	{
		next_ptr = tree_ptr->raiz;

		while ( next_ptr != NULL )
		{
			last_ptr = next_ptr;

			if ( valor < next_ptr->valor )
			{
				next_ptr = next_ptr->esq;

			}
			else if ( valor > next_ptr->valor )
			{
				next_ptr = next_ptr->dir;
			}
			else if ( valor == next_ptr->valor )
			{
				return;
			}
		}

		novo_node_ptr = init_node ( valor );

		if ( valor < last_ptr->valor )
			last_ptr->esq = novo_node_ptr;

		if ( valor > last_ptr->valor )
			last_ptr->dir = novo_node_ptr;

	}

	balancear_tree ( tree_ptr );
}

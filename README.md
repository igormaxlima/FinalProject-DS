# FinalProject-DS

## Funções de Manipulação do Arquivo do Estoque e Produtos

- **writeProductToFile:**
  - *Descrição:* Responsável por escrever os dados dos produtos em uma árvore binária em um arquivo CSV chamado "products.csv". Chama a função auxiliar `writeProductToFileHelper` para percorrer a árvore e escrever os dados no arquivo.
  - *Parâmetros:* Recebe a raiz da árvore de produtos.
  - *Retorno:* Não possui retorno.
  - *Exemplo de Uso:*
    ```c
    product *root = readProductsFromFile();
    // Realiza operações para preencher a árvore de produtos
    writeProductToFile(root);
    ```

- **writeProductToFileHelper:**
  - *Descrição:* Função auxiliar para percorrer a árvore binária de produtos e escrever cada nó no arquivo CSV. Chamada pela função `writeProductToFile`.
  - *Parâmetros:* Recebe um ponteiro para o arquivo CSV e a raiz da árvore de produtos.
  - *Retorno:* Não possui retorno.

- **readProductsFromFile:**
  - *Descrição:* Lê os dados dos produtos de um arquivo CSV chamado "products.csv" e os insere em uma árvore binária. Cria a árvore à medida que lê os dados do arquivo.
  - *Parâmetros:* Não possui parâmetros.
  - *Retorno:* Retorna um ponteiro para a raiz da árvore de produtos.
  - *Exemplo de Uso:*
    ```c
    product *root = readProductsFromFile();
    // Utiliza a árvore de produtos carregada a partir do arquivo
    ```

- **createTree:**
  - *Descrição:* Cria uma árvore vazia, retornando um ponteiro nulo.
  - *Parâmetros:* Não possui parâmetros.
  - *Retorno:* Retorna um ponteiro nulo.
  - *Exemplo de Uso:*
    ```c
    product *root = createTree();
    // Inicia uma árvore de produtos vazia
    ```

## Funções de Manipulação da Árvore de Produtos

- **addProduct:**
  - *Descrição:* Adiciona um novo produto à árvore binária de produtos. Insere o produto na posição adequada com base no nome do produto.
  - *Parâmetros:* Recebe a raiz da árvore, o ID, o nome, o preço e a quantidade do produto a ser adicionado.
  - *Retorno:* Retorna um ponteiro para a raiz da árvore atualizada.
  - *Exemplo de Uso:*
    ```c
    product *root = createTree();
    root = addProduct(root, 1, "Produto A", 10.0, 5);
    root = addProduct(root, 2, "Produto B", 15.0, 8);
    ```

- **listProductsAlphabetically:**
  - *Descrição:* Percorre a árvore de produtos em ordem alfabética (in-order) e imprime as informações de cada produto.
  - *Parâmetros:* Recebe a raiz da árvore de produtos.
  - *Retorno:* Não possui retorno.
  - *Exemplo de Uso:*
    ```c
    listProductsAlphabetically(root);
    // Lista os produtos em ordem alfabética
    ```

- **searchProductAlphabetically:**
  - *Descrição:* Procura um produto na árvore com base no nome e o imprime se for encontrado.
  - *Parâmetros:* Recebe a raiz da árvore de produtos e o nome do produto a ser pesquisado.
  - *Retorno:* Retorna um ponteiro para o produto se encontrado, caso contrário, retorna nulo.
  - *Exemplo de Uso:*
    ```c
    product *foundProduct = searchProductAlphabetically(root, "Produto A");
    if (foundProduct != NULL) {
        // Produto encontrado, faça algo com ele
    }
    ```

- **searchProductById:**
  - *Descrição:* Procura um produto na árvore com base no ID e o imprime se for encontrado.
  - *Parâmetros:* Recebe a raiz da árvore de produtos e o ID do produto a ser pesquisado.
  - *Retorno:* Retorna um ponteiro para o produto se encontrado, caso contrário, retorna nulo.
  - *Exemplo de Uso:*
    ```c
    product *foundProduct = searchProductById(root, 1);
    if (foundProduct != NULL) {
        // Produto encontrado, faça algo com ele
    }
    ```

- **deleteProduct:**
  - *Descrição:* Exclui um produto da árvore com base no nome. Ajusta a árvore de acordo com as regras de remoção de nós em uma árvore binária.
  - *Parâmetros:* Recebe a raiz da árvore de produtos e o nome do produto a ser excluído.
  - *Retorno:* Retorna um ponteiro para a raiz da árvore atualizada após a exclusão.
  - *Exemplo de Uso:*
    ```c
    root = deleteProduct(root, "Produto A");
    // Exclui o produto com nome "Produto A" da árvore
    ```

- **minValueNode:**
  - *Descrição:* Função auxiliar para encontrar o nó com o menor valor na subárvore direita de um nó dado. Usada durante a exclusão de um nó.
  - *Parâmetros:* Recebe um ponteiro para o nó da subárvore direita.
  - *Retorno:* Retorna um ponteiro para o nó com o menor valor na subárvore direita.
  - *Exemplo de Uso:*
    ```c
    product *minValue = minValueNode(node->right);
    // Encontra o nó com o menor valor na subárvore direita
    ```

- **updateProductPrice:**
  - *Descrição:* Atualiza o preço de um produto na árvore com base no nome do produto.
  - *Parâmetros:* Recebe a raiz da árvore de produtos, o nome do produto e o novo preço.
  - *Retorno:* Não possui retorno.
  - *Exemplo de Uso:*
    ```c
    updateProductPrice(root, "Produto A", 12.5);
    // Atualiza o preço do produto com nome "Produto A" para 12.5
    ```

- **updateProductQuantity:**
  - *Descrição:* Atualiza a quantidade de um produto na árvore com base no nome do produto.
  - *Parâmetros:* Recebe a raiz da árvore de produtos, o nome do produto e a nova quantidade.
  - *Retorno:* Não possui retorno.
  - *Exemplo de Uso:*
    ```c
    updateProductQuantity(root, "Produto A", 20);
    // Atualiza a quantidade do produto com nome "Produto A" para 20
    ```

- **anyProductsMissing:**
  - *Descrição:* Verifica se há produtos com quantidade igual a zero na árvore e os imprime.
  - *Parâmetros:* Recebe a raiz da árvore de produtos.
  - *Retorno:* Não possui retorno.
  - *Exemplo de Uso:*
    ```c
    anyProductsMissing(root);
    // Verifica e imprime produtos com quantidade zero
    ```

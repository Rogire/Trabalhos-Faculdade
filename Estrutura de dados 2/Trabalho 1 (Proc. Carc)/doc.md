#### registro.hpp:
É a representação das chaves inseridas, com campos de nome, ano e ocorrências para serem manipulados. 
    - As variáveis ano, ocorrencias e posição usam unsigned, e size_t para evitar erros ao manipular grandes números

### tabelahash.cpp:
Código de implementação da tabela
    - hash_function recebe a referência de uma string para calcular um hash dela, e o tamanho da tabela, retornando um size_t (logo o método usado é o hash de string)
    -sondagemDupla recebe como parâmetros a referência de uma string, um inteiro e duas referências de size_t para fazer retornar um size_t usando a fórmula da sondagem dupla
    -insere recebe os valores de uma chave do csv (nome e ano) e os insere na tabela hash na posição vinda da função sondagem dupla

### main:
    -carregar_csv carrega o csv usando as bibliotecas fstream e sstream e o passa para a tabela hash usando a função insere
    -getLinhasCsv retorna um size_t com o tamanho total do csv usando a biblioteca fstream e sstream




# gerando-terrenos

Disciplina:
Práticas de Técnicas de Programação

Autores: 
Jaine Rannow Budke
Mayra Dantas de Azevedo

Sobre o projeto:

    Elementos básicos implementados:
        - Geração da linha de contorno em um arranjo (Jaine e Mayra)
        - Leitura de parâmetros de configuração pela linha de comando (Mayra)
        - Criação de imagem a partir da linha de contorno (Jaine e Mayra)
        
    Elementos adicionais implementados:
        - Diferentes cenários: amanhecer, dia, anoitecer e noite (Mayra)
        - Gradiente para o céu de cada modo da imagem (Mayra)
        - Inclusão da lua (Jaine)
        - Cadeia de montanhas (Jaine)
        
        
Como compilar:

Para compilar o projeto, basta acessar a pasta "sources" pelo terminal e digitar o comando abaixo

    gcc main.c contorno.c imagem.c adicionais.c -lm -o teste
    
Comando para executar o programa
    
    ./teste
    
Para escolher o nome do arquivo, basta passar o parâmetro -o ao executar. Por exemplo

    ./teste -o montanha.ppm
    
Caso o parâmetro -o não seja usado, a imagem será salva como "terreno.ppm".
A imagem será salva na pasta "galeria" do projeto.
Para escolher o fator deslocamento, basta passar o parâmetro -d ao executar. Por exemplo

    ./teste -d 200
    
Caso não haja parâmetro -d, o fator será 128.
Para escolher o cenário da imagem, basta utilizar o parâmetro -m. Por exemplo

    ./teste -m 2
    
Podem ser usados 4 valores: 0(amanhecer), 1(dia), 2(anoitecer) e 3(noite).
Caso seja inserido um valor inválido, o cenário será noite ou amanhecer.
Caso não haja parâmetro -m, o modo será o de amanhecer.
Os parâmetros podem ser passados em qualquer ordem ou quantidade desejadas. Exemplos:

    ./teste -d 250 -o montanha.ppm -m 2
    ./teste -m 1 -d 129
    ./teste -o montanha.ppm -m 3 -d 240
    
Caso fuja desse padrão, será retornado um erro. Exemplos de modos errados de executar:
    
    ./teste -o -d 256 (parâmetros vazios)
    ./teste -d 207 -d 200 (parâmetros repetidos)
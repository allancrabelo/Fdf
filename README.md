# Fdf

Fdf - Fild de Fer (Wireframe model)
É uma forma de representacao esqueletica em 2D ou 3D de um objeto, usando linhas ou curvas para definir uma estrutura sem superficies solidas. 

Lib grafica da escola: MinilibX

Projecao isometrica - 

o programa vai ler .fdf e horizontal (abscissa), vertical (ordenate) e value (altitude)

🧠 Objetivo geral:
Criar um programa em C que leia um arquivo .fdf e exiba uma projeção isométrica interativa do conteúdo 3D em uma janela, usando MiniLibX, respeitando a Norminette, e com boa separação de responsabilidades.

⏱️ Carga horária estimada: 5 a 6h/dia
📅 Período: 07/07/2025 (segunda-feira) até 17/07/2025 (quinta-feira)
Total: 11 dias, com margem segura para revisão, imprevistos e defesa.

🧱 Etapa 1 – Setup e domínio da MiniLibX
📅 Dias 1–2 | 07/07 e 08/07
🎯 Objetivo:
Configurar o projeto, testar a MiniLibX e dominar seu uso básico antes de iniciar o FdF.

✅ Tarefas:
 Criar repositório Git e estrutura inicial:

src/, include/, Makefile, main.c

 Baixar e configurar a MiniLibX (mlx.h, libmlx.a)

 Fazer Makefile compilar com a MiniLibX

 Criar janela simples com mlx_new_window

 Testar eventos:

 Fechar a janela com ESC ou X

 Lidar com mlx_key_hook, mlx_loop_hook

 Testar desenho de pixels com mlx_pixel_put

 Criar função de limpar e atualizar a janela

🔍 Mini challenge: Criar uma função que desenhe um quadrado na tela e mova com as setas.

📥 Etapa 2 – Parsing do mapa
📅 Dia 3 | 09/07
🎯 Objetivo:
Ler e transformar o arquivo .fdf em uma matriz de valores utilizável.

✅ Tarefas:
 Abrir e ler o .fdf linha por linha

 Validar número de colunas por linha (todas devem ter o mesmo comprimento)

 Armazenar os dados em:

c
Copiar código
typedef struct s_point {
    int x;
    int y;
    int z;
    int color; // opcional
} t_point;
 Calcular map_width, map_height

 Criar estrutura t_map ou t_fdf para centralizar os dados

 Testar com mapas de tamanhos diferentes e com/sem cores

🧮 Etapa 3 – Wireframe base (sem projeção ainda)
📅 Dias 4–5 | 10/07 e 11/07
🎯 Objetivo:
Desenhar linhas conectando os pontos da matriz 2D.

✅ Tarefas:
 Implementar algoritmo de Bresenham

 Criar função draw_line(t_point a, t_point b)

 Iterar pelo mapa e conectar:

 Cada ponto com o da direita

 Cada ponto com o de baixo

 Criar função draw_map()

 Desenhar com mlx_pixel_put() ou buffer (ex: mlx_put_image_to_window + pixel buffer)

🔺 Etapa 4 – Projeção isométrica
📅 Dias 6–7 | 12/07 e 13/07
🎯 Objetivo:
Converter os pontos 3D para uma projeção isométrica 2D.

✅ Tarefas:
 Criar função project_iso(x, y, z):

c
Copiar código
x' = (x - y) * cos(θ)
y' = (x + y) * sin(θ) - z
Use θ = 30º ou 0.5236 rad

 Aplicar a projeção antes de desenhar

 Ajustar offset para centralizar o mapa

 Ajustar escala inicial para caber na tela

 Testar com mapas grandes e pequenos

🎮 Etapa 5 – Interação e controles
📅 Dia 8 | 14/07
🎯 Objetivo:
Permitir ao usuário interagir com a visualização via teclado.

✅ Tarefas:
 Zoom in/out (+ / -)

 Mover o mapa (setas ou WASD)

 Resetar posição com R

 Rotação do mapa (opcional)

 Sair com ESC

 Usar mlx_key_hook ou mlx_hook para eventos

🎨 Etapa 6 – Cores (extra valorizado)
📅 Dia 9 | 15/07
🎯 Objetivo:
Adicionar cores com base na altura (z) ou do próprio .fdf.

✅ Tarefas:
 Ler e aplicar cor individual se presente no .fdf

 Gerar cor com base em z se não houver

Ex: degrade do azul ao branco conforme altura

 Criar função get_color(z) ou interpolate_color()

🧹 Etapa 7 – Refatoração e limpeza
📅 Dia 10 | 16/07
🎯 Objetivo:
Organizar o projeto, limpar código, e seguir a norminette.

✅ Tarefas:
 Dividir em arquivos (draw.c, parse.c, utils.c, main.c, etc)

 Verificar norminette

 Testar com valgrind (sem leaks)

 Tratar erros corretamente (malloc fail, etc)

 Adicionar README.md com instruções

 Criar .gitignore

🧪 Etapa 8 – Testes e simulação da defesa
📅 Dia 11 | 17/07
🎯 Objetivo:
Preparar-se para a avaliação e simular a defesa.

✅ Tarefas:
 Testar com diversos arquivos .fdf

 Testar entradas erradas (linhas com tamanhos diferentes, arquivos vazios, etc)

 Explicar:

Parsing do arquivo

Como funciona a projeção isométrica

Algoritmo de Bresenham

Como a MiniLibX é usada

 Fazer backup final e garantir que make, make clean, make fclean, make re funcionam

 Subir para GitHub ou outro repositório remoto


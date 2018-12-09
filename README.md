# Grafo-Jesuitas-e-Canibais-
Algorítimo e estrutura de Dados 2 - UFG
by: Alan Viana do Nascimento

Regras do Jogo!
Existem 3 jesuitas e 3 canibais em uma margem do rio.
Você precisa atravessar os Jesuítas para o outro lado da margem, porém não pode deixar mais canibais que Jesuítas em qualquer uma das margens. O barco comporta dois personagens, e ele precisa de um personagem para dirigir.

O Algoritimo cria um grafo com todas as possibilidades, e mostra o passo a passo para resolver o problema.

O resultado foram 4 maneira com um total de 12 passos cada:
<pre>ACHOOOOOOOOOOOOOOOOOOOUUUU
-------------------(c,j)_____(c,j)
--&gt;PASSO 12	 - (0,0)_____(3,3)
&lt;--PASSO 11	 - (1,1)_____(2,2)
--&gt;PASSO 10	 - (1,0)_____(2,3)
&lt;--PASSO 9	 - (3,0)_____(0,3)
--&gt;PASSO 8	 - (2,0)_____(1,3)
&lt;--PASSO 7	 - (2,2)_____(1,1)
--&gt;PASSO 6	 - (1,1)_____(2,2)
&lt;--PASSO 5	 - (1,3)_____(2,0)
--&gt;PASSO 4	 - (0,3)_____(3,0)
&lt;--PASSO 3	 - (2,3)_____(1,0)
--&gt;PASSO 2	 - (1,3)_____(2,0)
&lt;--PASSO 1	 - (3,3)_____(0,0)
ACHOOOOOOOOOOOOOOOOOOOUUUU
-------------------(c,j)_____(c,j)
--&gt;PASSO 12	 - (0,0)_____(3,3)
&lt;--PASSO 11	 - (2,0)_____(1,3)
--&gt;PASSO 10	 - (1,0)_____(2,3)
&lt;--PASSO 9	 - (3,0)_____(0,3)
--&gt;PASSO 8	 - (2,0)_____(1,3)
&lt;--PASSO 7	 - (2,2)_____(1,1)
--&gt;PASSO 6	 - (1,1)_____(2,2)
&lt;--PASSO 5	 - (1,3)_____(2,0)
--&gt;PASSO 4	 - (0,3)_____(3,0)
&lt;--PASSO 3	 - (2,3)_____(1,0)
--&gt;PASSO 2	 - (1,3)_____(2,0)
&lt;--PASSO 1	 - (3,3)_____(0,0)
ACHOOOOOOOOOOOOOOOOOOOUUUU
-------------------(c,j)_____(c,j)
--&gt;PASSO 12	 - (0,0)_____(3,3)
&lt;--PASSO 11	 - (1,1)_____(2,2)
--&gt;PASSO 10	 - (1,0)_____(2,3)
&lt;--PASSO 9	 - (3,0)_____(0,3)
--&gt;PASSO 8	 - (2,0)_____(1,3)
&lt;--PASSO 7	 - (2,2)_____(1,1)
--&gt;PASSO 6	 - (1,1)_____(2,2)
&lt;--PASSO 5	 - (1,3)_____(2,0)
--&gt;PASSO 4	 - (0,3)_____(3,0)
&lt;--PASSO 3	 - (2,3)_____(1,0)
--&gt;PASSO 2	 - (2,2)_____(1,1)
&lt;--PASSO 1	 - (3,3)_____(0,0)
ACHOOOOOOOOOOOOOOOOOOOUUUU
-------------------(c,j)_____(c,j)
--&gt;PASSO 12	 - (0,0)_____(3,3)
&lt;--PASSO 11	 - (2,0)_____(1,3)
--&gt;PASSO 10	 - (1,0)_____(2,3)
&lt;--PASSO 9	 - (3,0)_____(0,3)
--&gt;PASSO 8	 - (2,0)_____(1,3)
&lt;--PASSO 7	 - (2,2)_____(1,1)
--&gt;PASSO 6	 - (1,1)_____(2,2)
&lt;--PASSO 5	 - (1,3)_____(2,0)
--&gt;PASSO 4	 - (0,3)_____(3,0)
&lt;--PASSO 3	 - (2,3)_____(1,0)
--&gt;PASSO 2	 - (2,2)_____(1,1)
&lt;--PASSO 1	 - (3,3)_____(0,0)

</pre>

Ao rodar o algoritimo é possivel imprimir todas as possibilidades.

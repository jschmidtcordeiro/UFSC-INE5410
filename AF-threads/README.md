<div class="no-overflow"><h3>Exercício 1</h3>
<p>Escreva um programa que receba dois números como argumento na linha de comando (use <em>argc</em> e <em>argv</em> da função <em>main</em>) que representam um número de threads (<span style="font-family: courier new, courier, monospace;"><strong>n_threads</strong></span>) e o número de incrementos (<span><strong>n_loops</strong></span>)&nbsp;que as <strong><span style="font-family: 'courier new', courier, monospace;">n_threads</span></strong> farão em uma variável global. O programa deve criar&nbsp;<span style="font-family: courier new, courier, monospace;"><strong>n_threads</strong></span> threads que paralelamente incrementam <span style="font-family: 'courier new', courier, monospace;"><strong>n_loops</strong></span> vezes, em um laço,<strong> </strong>uma variável global chamada&nbsp;<span style="font-family: courier new, courier, monospace;"><strong>contador_global</strong></span>. Siga essas instruções detalhadas:</p>
<ul>
<li>O programa deve receber os valores de&nbsp;<span style="font-family: courier new, courier, monospace;"><strong>n_threads</strong></span> em <span style="font-family: courier new, courier, monospace;">argv[1]&nbsp;<span style="font-family: arial, helvetica, sans-serif;">e</span>&nbsp;<span><strong>n_loops</strong></span>&nbsp;em&nbsp;<span>argv[2].</span></span>
<ul>
<li>Isso já vem implementado no código inicial!<span style="font-family: courier new, courier, monospace;"></span></li>
</ul>
</li>
<li>A variável global deve se chamar&nbsp;<span style="font-family: courier new, courier, monospace;"><strong>contador_global</strong></span> e deve ser inicializada com 0.</li>
<li>O programa deve criar&nbsp;<span style="font-family: courier new, courier, monospace;"><strong>n_threads</strong></span> threads.</li>
<li>Cada thread deve realizar <span style="font-family: courier new, courier, monospace;"><strong>n_loops</strong></span> incrementos em&nbsp;<span style="font-family: courier new, courier, monospace;"><strong>contador_global.</strong></span>
<ul>
<li><strong><span style="font-family: courier new, courier, monospace;">n_loops</span></strong>&nbsp;incrementos significa fazer <strong><span style="font-family: courier new, courier, monospace;">++contador_global</span></strong> &nbsp;<strong><span style="font-family: courier new, courier, monospace;">n_loops</span></strong> vezes</li>
<li><strong><span style="font-family: courier new, courier, monospace;">n_loops</span></strong>&nbsp;deve ser passado como argumento da função executada pela thread (via <span style="font-family: courier new, courier, monospace;"><a href="http://pubs.opengroup.org/onlinepubs/9699919799/functions/pthread_create.html"><strong>pthread_create</strong>()</a></span>).</li>
<li><span style="color: #ff0000;"><strong>Não</strong></span> crie uma variável global para esse fim!</li>
</ul>
</li>
<li>A thread principal deve esperar o término de todas as outras threads (<span style="font-family: courier new, courier, monospace;"><a href="http://pubs.opengroup.org/onlinepubs/9699919799/functions/pthread_join.html"><strong>pthread_join</strong>()</a></span>).</li>
<li>Após o término das demais, a thread principal deve imprimir o valor do contador e o valor esperado, conforme esse exemplo (<span style="font-family: courier new, courier, monospace;"><strong>n_threads</strong></span>=1, <strong><span style="font-family: courier new, courier, monospace;">n_loops=32023</span></strong>):
<pre>Contador: 32023 <br>Esperado: 32023</pre>
</li>
</ul>
<p>Execute este programa e vá aumentando o número de threads a cada execução (ex.: 2, 5, 10, 20, 30, 40, ...). Observe o que acontece com o valor do <span style="font-family: courier new, courier, monospace;"><strong>contador_global</strong></span> conforme o número de threads aumenta. Observe também o que acontece quando o valor de&nbsp;<strong><span style="font-family: courier new, courier, monospace;">n_loops</span></strong> aumenta. Reflita sobre os seguintes pontos:</p>
<ul>
<li>Qual a relação entre&nbsp;<span style="font-family: courier new, courier, monospace;"><strong>n_threads</strong></span> e a diferença entre "Contador" e "Esperado"?</li>
<li>Qual a relação entre&nbsp;<span style="font-family: courier new, courier, monospace;"><strong>n_loops</strong></span> e a diferença entre "Contador" e "Esperado"?</li>
<li>Existe alguma <strong>regra ou padrão</strong> na diferença entre "Contador" e "Esperado"?</li>
</ul>
<h3>Exercício 2</h3>
<p>Paralelize o programa dado, que realiza a soma de dois vetores. Esse programa recebe dois vetores em arquivos e mostra o resultado na saída:</p>
<pre><strong>./program 1 a b</strong> <br>12 7 5 5 14 16 11 14 11 15</pre>
<p>O primeiro argumento ("1" no exemplo acima) é o número de threads, e os dois últimos argumentos são os nomes dos arquivos que contém os vetores. O programador original implementou a leitura dos argumentos e a leitura dos vetores, mas desapareceu misteriosamente antes de efetivamente usar threads. Sua implementação deve criar o número de threads indicado na variável <span style="font-family: courier new, courier, monospace;">n_threads</span> e deve distribuir as operações <span style="font-family: courier new, courier, monospace;">c[i] = a[i] + b[i]</span> entre essas threads. Dicas:</p>
<ul>
<li>Evite variáveis globais. Use o último argumento de <span style="font-family: courier new, courier, monospace;"><a href="http://pubs.opengroup.org/onlinepubs/9699919799/functions/pthread_create.html"><strong>pthread_create</strong>()</a></span> para que cada <em>worker thread</em> receba um ponteiro cujo <strong><span style="font-family: courier new, courier, monospace;"><a href="http://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Structs.html">struct</a></span></strong> apontado contém as informações relevantes para aquela thread.</li>
<li>Os arquivos <span style="font-family: courier new, courier, monospace;"><strong>a</strong></span> e <span style="font-family: courier new, courier, monospace;"><strong>b</strong></span> do exemplo acima, assim como o resultado (arquivo <strong>c</strong>) estão no esqueleto fornecido.</li>
<li>Você não deve gerar mais threads do que elementos! Se o usuário <strong>solicitar 20 threads</strong>, e os vetores possuírem <strong>apenas 10 elementos</strong>, então <strong>apenas 10 threads deverão ser criadas</strong></li>
<li>É possível gerar vetores aleatórios com um tamanho especifico usando uma sintaxe especial:
<pre><strong>./program 1 gen:2000000 gen:2000000</strong></pre>
</li>
<li><strong>Cuidado</strong> para não criar vetores grandes demais e travar a sua máquina!</li>
</ul>
<p>Execute o programa com várias escolhas para o número de threads e meça o <em>speedup</em>.&nbsp;Reflita sobre os seguintes pontos:</p>
<ul>
<li>O <em>speedup</em> obtido está proximo do <em>speedup</em> ideal?</li>
<li>O programa escala, ou seja, o <em>speedup</em> aumenta se aumentarmos o número de threads?</li>
</ul>
<h3>Exercício 3</h3>
<p>Em outro caso de programador desaparecido, você deve paralelizar um programa que calcula o produto escalar de dois vetores:</p>
<pre><strong>./program 1 a b</strong> <br>Produto escalar: -9</pre>
<p>O primeiro argumento ("1" é o número de threads a serem usadas para computação. Assim como no exercício 2, a sintaxe gen:N pode ser usada para testar sua implementação com vetores aleatórios grandes. Lembre que:</p>
<ul>
<li>O produto escalar é o somatório dos produtos entre os elementos pareados dos vetores, ou seja, <span style="font-family: courier new, courier, monospace;"><strong>sum += a[i] * b[i]</strong><span style="font-family: arial, helvetica, sans-serif;">, para todo elemento</span> <strong>i</strong> <span style="font-family: arial, helvetica, sans-serif;">dos vetores</span> <strong>a</strong> <span style="font-family: arial, helvetica, sans-serif;">e</span> <strong>b</strong>.</span></li>
<li>Os arquivos <strong><span style="font-family: courier new, courier, monospace;">a</span></strong> e <span style="font-family: courier new, courier, monospace;"><strong>b</strong></span>, com vetores pequenos, estão incluídos no esqueleto fornecido.</li>
<li>Evite usar variáveis globais sempre que possível.</li>
</ul>
<h3>Dicas</h3>
<ul>
<li>&nbsp;Você vai precisar das seguintes bibliotecas:</li>
</ul>
<p style="margin-left: 30px;"><span style="font-family: courier new, courier, monospace;"><span style="color: #800080;"><strong>#include</strong></span> <strong>&lt;</strong>stdlib.h<strong>&gt;</strong></span><br><span style="font-family: courier new, courier, monospace;"><span style="font-family: courier new, courier, monospace;"><span style="color: #800080;"><strong>#include</strong></span></span> <strong>&lt;</strong>unistd.h<strong>&gt;</strong></span><br><span style="font-family: courier new, courier, monospace;"><span style="font-family: courier new, courier, monospace;"><span style="color: #800080;"><strong>#include</strong></span></span> <strong>&lt;</strong>sys/types.h<strong>&gt;</strong></span><br><span style="font-family: courier new, courier, monospace;"><span style="font-family: courier new, courier, monospace;"><span style="color: #800080;"><strong>#include</strong></span></span> <strong>&lt;</strong>stdio.h<strong>&gt;</strong></span><br><span style="font-family: courier new, courier, monospace; background-color: #ccffcc;"><span style="font-family: courier new, courier, monospace;"><span style="color: #800080;"><strong>#include</strong></span></span> <strong>&lt;</strong>pthread.h<strong>&gt;</strong></span></p>
</div>
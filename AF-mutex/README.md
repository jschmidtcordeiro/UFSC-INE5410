<div class="no-overflow"><h3>Exercício 1</h3>
<p>Utilize um <span style="font-family: courier new, courier, monospace;"><a href="http://pubs.opengroup.org/onlinepubs/9699919799/functions/pthread_mutex_lock.html">pthread_<strong>mutex</strong>_t</a></span> para proteger a região crítica do código do Exercício 1 da atividade prática anterior, em que um contador era acessado concorrentemente por várias threads, resultando em um valor inconsistente. O <strong>mutex</strong> deve ser utilizado de modo a controlar a concorrência entre as threads, fazendo com que o programa apresente o resultado esperado.&nbsp;</p>
<p>Você precisará das seguintes funções:</p>
<ul>
<li><span style="font-family: courier new, courier, monospace;"><a href="http://pubs.opengroup.org/onlinepubs/9699919799/functions/pthread_mutex_lock.html">pthread_mutex_lock() e pthread_mutex_unlock()</a></span></li>
<li><span style="font-family: courier new, courier, monospace;"><a href="http://pubs.opengroup.org/onlinepubs/9699919799/functions/pthread_mutex_init.html">pthread_mutex_init()</a></span></li>
<li><span style="font-family: courier new, courier, monospace;"><a href="http://pubs.opengroup.org/onlinepubs/9699919799/functions/pthread_mutex_destroy.html">pthread_mutex_destroy()</a></span></li>
</ul>
<h3>Exercício 2</h3>
<p>Um estagiário escreveu um programa paralelo de multiplicação de matrizes. Para gerar e multiplicar 2 matrizes 40 x 40 usando 2 threads, o programa é chamado assim:</p>
<pre><span style="font-family: courier new, courier, monospace;">./program 40 2</span></pre>
<p>Quando o programa é executado com uma thread apenas, tudo funciona. Mas quando o programa é chamado com 2 threads ou mais, há erros no resultado.</p>
<p>O estagiário não teve disciplina de programação concorrente antes, e por isso não usou nenhum mutex. Conserte o código do estagiário inserindo um mutex e o utilizando nos pontos adequados do arquivo <span style="font-family: 'courier new', courier, monospace;"><strong>main.c </strong></span>e no arquivo&nbsp;<span style="font-family: 'courier new', courier, monospace;"><strong>thread.c</strong></span>. <span style="color: #ff0000;"><strong>Preserve ao máximo o paralelismo!</strong></span></p>
<p><strong>Importante</strong>:</p>
<ul>
<li>A seção crítica que precisa ser sincronizada está na função&nbsp;<span style="font-family: courier new, courier, monospace;"><strong>matrix_mult_worker</strong></span> (em <span style="font-family: courier new, courier, monospace;"><strong>thread.c</strong></span>).</li>
<li><a href="http://pubs.opengroup.org/onlinepubs/9699919799/functions/pthread_mutex_init.html">Inicialize e destrua</a> o mutex na função <span style="font-family: courier new, courier, monospace;"><strong>main</strong></span> (em <span style="font-family: courier new, courier, monospace;"><strong>main.c</strong></span>).</li>
<li>O arquivo&nbsp;<span style="font-family: courier new, courier, monospace;"><strong>helper.c</strong></span> não poderá ser alterado.</li>
</ul>
<h3>Exercício 3</h3>
<p>Um engenheiro fez um programa que funcionava em um computador antigo que, infelizmente, queimou. Ao rodar o programa em um computador moderno, o programa apenas trava e não faz nada. Arqueólogos&nbsp; e outros estudiosos se debruçaram sobre o código-fonte e observaram o seguinte:</p>
<ul>
<li>O programa recebe como primeiro argumento um número de threads. Os argumentos subsequentes são argumentos da função <strong>compute</strong>, a ser executada por cada uma das threads com o argumento correspondente.</li>
<li>O programa faz uso de mutex e sincroniza o acesso a uma variável global chamada <strong><span style="font-family: courier new, courier, monospace;">gValue</span>.</strong></li>
<li>Quando executado, o programa fica travado para sempre.</li>
<li>De acordo com o código-fonte, a intenção do engenheiro seria de que, ao ser chamado com os argumentos 2 16 17, o programa produzisse o seguinte resultado:<br>
<pre><span style="font-family: courier new, courier, monospace;"><strong>$ ./program 2 16 17</strong></span><br><span style="font-family: courier new, courier, monospace;">results[0]: 987 </span><br><span style="font-family: courier new, courier, monospace;">results[1]: 1597</span></pre>
</li>
<li>Estudiosos determinaram que os cálculos feitos pelo programa estão corretos, mas há um <strong>erro no uso do mutex <span style="font-family: courier new, courier, monospace;">gMtx</span></strong>.</li>
</ul>
<p>Encontre esse erro e o corrija.</p>
<p><strong>Importante</strong>:</p>
<ul>
<li>O arquivo&nbsp;<span style="font-family: courier new, courier, monospace;"><strong>helper.c</strong></span> não poderá ser alterado.</li>
<li>Hás três abordagens possíveis para solucionar o problema:
<ul>
<li>Você pode alterar a forma como o mutex é usado, de modo que o programa não trave. Essa solução resolve o problema, mas é questionável. Se a adotar, pense nas consequências.</li>
<li>Outra opção é usar um mutex recursivo. Este tipo de mutex permite que uma thread que já é dona do mutex&nbsp; faça um segundo lock sem travar. Para liberar o mutex, a thread deve fazer um unlock para cada lock feito. <br>
<ul>
<li>Essa é a solução mais "fácil".</li>
<li>Para criar um mutex recursivo, use o argumento <span style="font-family: courier new, courier, monospace;">pthread_mutexattr_t attr</span> no <span style="font-family: courier new, courier, monospace;">pthread_mutex_init()</span>.
<ul>
<li><span>Aloque uma variável&nbsp;<span><strong>attrs</strong></span>&nbsp;do tipo&nbsp;<span><strong>pthread_mutexattr_t</strong></span>;&nbsp;</span></li>
<li><span>Inicialize&nbsp;<span><strong>attrs</strong></span>&nbsp;usando&nbsp;<span><a href="http://pubs.opengroup.org/onlinepubs/9699919799/functions/pthread_mutexattr_destroy.html"><span>pthread_mutexattr_init(&amp;attrs)</span></a></span>;&nbsp;</span></li>
<li><span>Sete o tipo do mutex para&nbsp;<span>PTHREAD_MUTEX_RECURSIVE</span>&nbsp;usando&nbsp;<span><span><a href="http://pubs.opengroup.org/onlinepubs/9699919799/functions/pthread_mutexattr_settype.html">pthread_mutexattr_settype()</a>&nbsp;(se tiver dificuldades para fazê-lo, consulte&nbsp;<a href="http://pubs.opengroup.org/onlinepubs/9699919799/functions/pthread_mutexattr_init.html">essa página</a>&nbsp;e&nbsp;<a href="http://pubs.opengroup.org/onlinepubs/9699919799/functions/pthread_mutexattr_settype.html">essa outra</a>)</span></span>;&nbsp;</span></li>
<li><span>Inicialize o mutex com os atributes em&nbsp;<span><strong>attrs</strong></span>&nbsp;usando&nbsp;<span><a href="http://pubs.opengroup.org/onlinepubs/9699919799/functions/pthread_mutex_init.html"><span>pthread_mutex_init()</span></a></span>;&nbsp;</span></li>
<li><span>Por fim, destrua&nbsp;<span><strong>attrs</strong></span>&nbsp;usando&nbsp;<span><a href="http://pubs.opengroup.org/onlinepubs/9699919799/functions/pthread_mutexattr_destroy.html"><span>pthread_mutexattr_destroy().</span></a></span></span></li>
</ul>
</li>
</ul>
</li>
<li>A função <span style="font-family: 'courier new', courier, monospace;">compute()</span> pode ser reescrita de modo que nenhum mutex seja necessário no programa. Essa solução aproveita melhor o paralelismo!</li>
</ul>
</li>
</ul>
<p></p>
<p></p></div>
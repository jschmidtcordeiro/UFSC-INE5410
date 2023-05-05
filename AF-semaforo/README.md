<div class="no-overflow"><h3><span style="font-family: inherit;">Exercício 1</span></h3>
<p>O programa dado no esqueleto cria duas <em>threads</em>, uma para imprimir letras A e outra para imprimir letras B em um arquivo chamado <span style="font-family: courier new, courier, monospace;">results.txt</span>. Ao ser invocado o comando abaixo, no qual <strong>5</strong> é o número de letras A e letras B:</p>
<pre><strong>./program 5</strong></pre>
<p>Seria gerado algo assim no arquivo result.txt:</p>
<pre>AAAAABBBBB</pre>
<p>Utilize semáforos para que as <em>threads</em> executem em paralelo, mas <strong>garantindo</strong> que em qualquer posição <span style="font-family: 'courier new', courier, monospace;">i</span> da string, a<span style="text-decoration: underline;"> diferença entre o número de A's e de B's seja menor ou igual a 1</span>. Veja alguns exemplos de saídas válidas ou inválidas com 3 ocorrências de cada letra:</p>
<ul>
<li>Válidas:&nbsp;
<ul>
<li><span style="color: #003300;">ABABAB</span></li>
<li><span style="color: #003300;">ABBAAB</span></li>
<li><span style="color: #003300;">BAABAB</span></li>
</ul>
</li>
<li>Inválidas:
<ul>
<li><span style="color: #ff0000;">A<span style="background-color: #ffcc00;"><strong>A</strong></span>BBAB<span style="color: #000000;"> (posição <span style="font-family: 'courier new', courier, monospace;">i</span>=1: #A=2, #B=0)</span><br></span></li>
<li><span style="color: #ff0000;">ABB<span style="background-color: #ffcc00;"><strong>B</strong></span>AB<span style="color: #000000;"> (posição <span style="color: #ff0000;"><span style="color: #000000;"><span style="font-family: 'courier new', courier, monospace;">i</span>=</span></span>3: #A=1, #B=3)</span><br></span></li>
<li><span style="color: #ff0000;">B<span style="background-color: #ffcc00;"><strong>B</strong></span>BAAA <span style="color: #000000;">(posição <span style="color: #ff0000;"><span style="color: #000000;"><span style="font-family: 'courier new', courier, monospace;">i</span>=</span></span>1: #A=0, #B=2)</span></span></li>
</ul>
</li>
</ul>
<h3>Exercício 2</h3>
<p>Em 2099, após um ataque terrorista, as pontes&nbsp;Pontes Pedro Ivo e Colombo Salles&nbsp;caíram, restando apenas a ponte Hercílio Luz. Como a Hercílio Luz estava novamente reforma, ela não podia suportar tráfego com segurança. No entanto, dada a excepcionalidade da situação, as autoridades liberaram a passagem de até <span style="font-family: 'courier new', courier, monospace;"><strong>veiculos_turno</strong></span>&nbsp;veículos de passeio por vez, em mão única. Sua empresa venceu uma licitação para implementar o controle de tráfego na ponte. A ponte deve alternar o sentido de passagem dos veículos, permitindo a passagem de <span style="font-family: 'courier new', courier, monospace;"><strong>veiculos_turno</strong></span>&nbsp;veículos em cada direção, iniciando pela direção <strong>CONTINENTE → ILHA</strong>.</p>
<p>Cada veículo é representado por uma estrutura do tipo <span style="font-family: 'courier new', courier, monospace;"><strong>veiculo_t</strong></span>, que contém como atributos um identificador único (<span style="font-family: 'courier new', courier, monospace;"><strong>id</strong></span>), a próxima cabeceira da ponte pela qual ele vai passar (<span style="font-family: 'courier new', courier, monospace;"><strong>cabeceira</strong></span>) e sua thread (<span style="font-family: 'courier new', courier, monospace;"><strong>thread</strong></span>), e seu comportamento básico já foi implementado na função&nbsp;<span style="font-family: 'courier new', courier, monospace;"><strong>veiculo_executa(void *arg)</strong></span>. Porém, as principais funções de controle de acesso à ponte não foram implementadas. Uma breve descrição do funcionamento destas funções é mostrada abaixo:</p>
<ul>
<li><span style="font-family: 'courier new', courier, monospace;"><strong>ponte_inicializar()</strong></span>: Função executada no início do programa para inicializar o controle da ponte. É invocada uma única vez pela função <span style="font-family: 'courier new', courier, monospace;"><strong>main()</strong></span><span style="font-family: arial, helvetica, sans-serif;">.</span></li>
<li><span style="font-family: 'courier new', courier, monospace;"><strong>ponte_entrar(veiculo_t *v)</strong></span>: Função invocada pelo veículo (<span style="font-family: 'courier new', courier, monospace;"><strong>v</strong></span>) para indicar que o veículo está querendo entrar em uma cabeceira da ponte.</li>
<li><span style="font-family: 'courier new', courier, monospace;"><strong>void ponte_sair(veiculo_t *v)</strong></span>: Função invocada pelo&nbsp;veículo (<span><strong>v</strong></span>) para indicar que o veículo está querendo sair em uma cabeceira da ponte.</li>
<li><span style="font-family: 'courier new', courier, monospace;"><strong>ponte_finalizar()</strong></span>: Função executada no final do programa para finalizar o controle da ponte. É invocada uma única vez pela&nbsp;função&nbsp;<span style="font-family: 'courier new', courier, monospace;"><strong>main()</strong></span>.</li>
</ul>
<p>Nenhum veículo tentará sair pela mesma cabeceira que entrou. Apenas após <span style="font-family: 'courier new', courier, monospace;"><strong>veiculos_turno</strong></span>&nbsp;veículos concluirem a travessia em um sentido é que travessias no sentido oposto serão permitidas (novamente limitadas a <span style="font-family: 'courier new', courier, monospace;"><strong>veiculos_turno</strong></span> veículos). Abaixo é mostrada uma possível saída esperada para uma execução com <strong>16 veículos</strong> e <strong>4 veículos por turno</strong> <span style="font-family: arial, helvetica, sans-serif;">(</span><span style="font-family: 'courier new', courier, monospace;"><strong>./program 16 4</strong></span><span style="font-family: arial, helvetica, sans-serif;">):</span></p>
<pre><strong>[PONTE] *** Novo sentido da travessia: CONTINENTE -&gt; ILHA. ***</strong>

[Veiculo   0] Aguardando para entrar na ponte pelo(a) CONTINENTE.
<span style="color: #0000ff;">[Veiculo   0] ENTROU na ponte pelo(a) CONTINENTE.</span>
<span style="color: #ff0000;">[Veiculo   1] Aguardando para entrar na ponte pelo(a) ILHA.</span>
[Veiculo   2] Aguardando para entrar na ponte pelo(a) CONTINENTE.
<span style="color: #0000ff;">[Veiculo   2] ENTROU na ponte pelo(a) CONTINENTE.</span>
<span style="color: #ff0000;">[Veiculo   3] Aguardando para entrar na ponte pelo(a) ILHA.</span>
[Veiculo   4] Aguardando para entrar na ponte pelo(a) CONTINENTE.
<span style="color: #0000ff;">[Veiculo   4] ENTROU na ponte pelo(a) CONTINENTE.</span>
<span style="color: #ff0000;">[Veiculo   5] Aguardando para entrar na ponte pelo(a) ILHA.</span>
[Veiculo   6] Aguardando para entrar na ponte pelo(a) CONTINENTE.
<span style="color: #0000ff;">[Veiculo   6] ENTROU na ponte pelo(a) CONTINENTE.</span>
<span style="color: #ff0000;">[Veiculo   7] Aguardando para entrar na ponte pelo(a) ILHA.</span>
[Veiculo   8] Aguardando para entrar na ponte pelo(a) CONTINENTE.
[Veiculo   9] Aguardando para entrar na ponte pelo(a) ILHA.
[Veiculo  10] Aguardando para entrar na ponte pelo(a) CONTINENTE.
[Veiculo  11] Aguardando para entrar na ponte pelo(a) ILHA.
[Veiculo  12] Aguardando para entrar na ponte pelo(a) CONTINENTE.
[Veiculo  13] Aguardando para entrar na ponte pelo(a) ILHA.
[Veiculo  14] Aguardando para entrar na ponte pelo(a) CONTINENTE.
[Veiculo  15] Aguardando para entrar na ponte pelo(a) ILHA.
<span style="color: #0000ff;">[Veiculo   0] SAIU da ponte pelo(a) ILHA.</span>
<span style="color: #0000ff;">[Veiculo   2] SAIU da ponte pelo(a) ILHA.</span>
<span style="color: #0000ff;">[Veiculo   4] SAIU da ponte pelo(a) ILHA.</span>
<span style="color: #0000ff;">[Veiculo   6] SAIU da ponte pelo(a) ILHA.</span>

<strong>[PONTE] *** Novo sentido da travessia: ILHA -&gt; CONTINENTE. ***</strong>

[Veiculo   1] ENTROU na ponte pelo(a) ILHA.
[Veiculo   3] ENTROU na ponte pelo(a) ILHA.
[Veiculo   5] ENTROU na ponte pelo(a) ILHA.
[Veiculo   7] ENTROU na ponte pelo(a) ILHA.
[Veiculo   5] SAIU da ponte pelo(a) CONTINENTE.
[Veiculo   7] SAIU da ponte pelo(a) CONTINENTE.
[Veiculo   3] SAIU da ponte pelo(a) CONTINENTE.
[Veiculo   1] SAIU da ponte pelo(a) CONTINENTE.

<strong>[PONTE] *** Novo sentido da travessia: CONTINENTE -&gt; ILHA. ***</strong>

[Veiculo   8] ENTROU na ponte pelo(a) CONTINENTE.
[Veiculo  10] ENTROU na ponte pelo(a) CONTINENTE.
[Veiculo  12] ENTROU na ponte pelo(a) CONTINENTE.
[Veiculo  14] ENTROU na ponte pelo(a) CONTINENTE.
[Veiculo   8] SAIU da ponte pelo(a) ILHA.
[Veiculo  10] SAIU da ponte pelo(a) ILHA.
[Veiculo  12] SAIU da ponte pelo(a) ILHA.
[Veiculo  14] SAIU da ponte pelo(a) ILHA.

<strong>[PONTE] *** Novo sentido da travessia: ILHA -&gt; CONTINENTE. ***</strong>

[Veiculo   9] ENTROU na ponte pelo(a) ILHA.
[Veiculo  11] ENTROU na ponte pelo(a) ILHA.
[Veiculo  13] ENTROU na ponte pelo(a) ILHA.
[Veiculo  15] ENTROU na ponte pelo(a) ILHA.
[Veiculo   9] SAIU da ponte pelo(a) CONTINENTE.
[Veiculo  13] SAIU da ponte pelo(a) CONTINENTE.
[Veiculo  11] SAIU da ponte pelo(a) CONTINENTE.
[Veiculo  15] SAIU da ponte pelo(a) CONTINENTE.

<strong>[PONTE] *** Novo sentido da travessia: CONTINENTE -&gt; ILHA. ***</strong>

[PONTE] FIM!
</pre>
<p>No exemplo de saída acima, são criados <strong>8 veículos do lado do CONTINENTE</strong> e <strong>8 veículos do lado da ILHA</strong> (<strong>16 no total</strong>). Como o número de veículos permitidos a trafegar por turno (<span style="font-family: 'courier new', courier, monospace;"><strong>veiculos_turno</strong></span>) é <strong>4</strong>, são necessários <strong>4 turnos para que todos os 16 veículos atravessem a ponte</strong>.</p>
<p>Inicialmente, os <strong>veículos 0, 2, 4 e 6</strong> (em <span style="color: #0000ff;"><strong>azul</strong></span>) foram liberados para fazer a travessia, pois a direção inicial de travessia era <strong>CONTINENTE →&nbsp;ILHA</strong>. Por outro lado, os <strong>veículos 1, 3, 5 e 7</strong> (em <span style="color: #ff0000;"><strong>vermelho</strong></span>) aguardavam no outro lado da ponte até que o sentido da travessia fosse invertido (esses veículos desejam fazer a travessia no sentido&nbsp;<strong>ILHA&nbsp;→&nbsp;CONTINENTE</strong>). Quando todos os veículos do primeiro turno saíram da ponte, o sentido de travessia da ponte foi invertido, liberando assim os veículos do próximo turno (1, 3, 5 e 7) para fazerem a travessia. A mesma lógica é aplicada para os demais veículos da execução: em cada turno, 4 veículos são liberados e quando os mesmos saem da ponte o sentido da travessia é invertido. A simulação acaba após todos os 16 veículos terem terminado.</p>
<p>Você <strong>poderá declarar variáveis globais</strong> (fora das funções), mas&nbsp;<strong>não poderá alterar a função <span style="font-family: 'courier new', courier, monospace;">main()</span> e nem remover ou adicionar <span style="font-family: 'courier new', courier, monospace;">printf()</span>.&nbsp;</strong>Adicione o código necessário de forma a realizar o controle correto de acesso dos veículos à ponte.</p>
<p></p></div>
program falsa_posicao_modificado

implicit none

real xi, xs ! intervalo inferior e superior
real xi1, xs1 ! intervalos inferior e superior na iteração anterior
real xm, xm1 ! ponto médio atual e ponto médio antes da atualização
real f1 , f2, f3 ! função que desejamos minimizar nos pontos mínimo, máximo e médio
real produto ! produto f(xi)*f(xs)
real erro ! erro relativo
real tol ! tolerancia desejada
real delta ! kick usado para desprender uma das extremidades;
integer iter ! número da iteração
integer opcao ! opcao de metodo desejado
integer contador1 ! contador que vai contar o número de vezes que xi se repete
integer contador2 ! contador que vai contar o número de vezes que xs se repete

print *, '================================================================================'
print *, '*                                                                              *'
print *, '*                   L2C : SOLUÇÕES EM COMPUTAÇÃO CIENTÍFICA                    *'
print *, '*                                                                              *'
print *, '================================================================================'
print *, '* Programa: RAÍZES DE EQUAÇÕES – FALSA POSIÇÃO MODIFICADO                      *'
print *, '* Capítulo: 02 | Exemplo: 02                                                   *'
print *, '*                                                                              *'
print *, '* Repositório: Manual de Cálculo Numérico – Códigos de Apoio (L2C)             *'
print *, '* Curso: Do Cálculo à Simulação Computacional                                  *'
print *, '* Autor: Prof. Rafael Gabler Gontijo, PhD                                      *'
print *, '*                                                                              *'
print *, '*        https://github.com/l2c-dev/manual-calculo-numerico.git                *'
print *, '================================================================================'
print *, ''
print *, '================================================================================'
print *, '*                                                                              *'
print *, '* Esse programa resolve a equação algébrica x**10 - 1.0.                       *'
print *, '* Nesse caso, a solução exata é dada por x = 1.                                *'
print *, '* A ideia é mostrar como o método da falsa posição pode ficar preso em uma das *' 
print *, '* extremidades dependendo da cara da função, cujo zero estamos buscando.       *'
print *, '* Teste usar o seguinte intervalo de busca inicial=[0,1.8].                    *' 
print *, '* Compare o desempenho do método da bissecção com o método da falsa posição.   *'
print *, '* Em seguida, teste o método da falsa posição modificado com um kick = 0.06    *'
print *, '*                                                                              *'
print *, '* Quais são suas conclusões?                                                   *'
print *, '================================================================================'
print *, ''
print *, '================================================================================'
print *, '*                           SELEÇÃO DE MÉTODO                                  *'
print *, '================================================================================'
print *, '* Escolha agora o método a ser utilizado:                                      *'
print *, '*                                                                              *'
print *, '*   [1] Método da bissecção                                                    *'
print *, '*   [2] Método da falsa posição                                                *'
print *, '*   [3] Método da falsa posição modificado                                     *'
print *, '*                                                                              *'
print *, '================================================================================'
print *, 'Digite o número do método desejado: '
read*,opcao
print *, ''
print *, '================================================================================'
print *, '*                 INTERVALO INICIAL DE BUSCA                                   *'
print *, '================================================================================'
print *, 'Digite agora o extremo inferior do intervalo inicial de busca (xi):'; read *, xi
print *, 'Digite agora o extremo superior do intervalo inicial de busca (xs):'; read *, xs
print *, '*                                                                              *'
if(opcao.eq.3) then
write(*,*) '*Digite a intensidade do kick utilizado para desprender extremidades:        *'
read*,delta
end if
print *, '================================================================================'
print *, ''
select case (opcao)
case (1)
   write(*,'(A)') 'O método escolhido é o método da bisecção'
case (2)
   write(*,'(A)') 'O método escolhido é o método da falsa posição'
case (3)
   write(*,'(A)') 'O método escolhido é o método da falsa posição modificado'
case default
   write(*,'(A)') 'Opção inválida.'
end select
print *, ''
print *, '================================================================================'
print *, '*         IMPRIMINDO VARIÁVEIS DE MONITORAMENTO: iter, xi, xs, xr, erro        *'
print *, '================================================================================'


erro = abs(xi-xs)
tol = 1.0e-06
iter = 0
contador1 = 1
contador2 = 1

do while (erro.gt.tol) 

! Imprimindo na tela as variáveis de monitoramento abaixo

write(*,'(I4,5X,F13.9,5X,F13.9,5X,F13.9,5X,F13.9)') iter, xi, xs, xm, erro
xm1=xm
! Avaliando inicialmente a função f em cada ponto do intervalo

f1 = xi**(10.0) - 1.0 ! f(xi)
f2 = xs**(10.0) - 1.0 ! f(xs)

! Calculando o produto entre a função nos extermos do intervalo

produto = f1*f2

! Checando se houve mudança de sinal nesse intervalo
if (produto.lt.0.0) then

if(opcao.eq.1) then 
! Utiliza-se a fórmula para estimativa da raiz via método da bisecção
xm = (xi+xs)/2
end if

if(opcao.eq.2) then
! Utiliza-se a fórmula para estimativa da raiz via falsa-posicao
xm = xs - (f2*(xi-xs)/(f1-f2))
end if

if(opcao.eq.3) then
xi1 = xi
xs1 = xs
! Verificando se existe uma extremidade presa e agindo caso haja
if(contador1.eq.2) then
xi=xi+delta
contador1=1
end if
if(contador2.eq.2) then
xs=xs-delta
contador2=1
end if
! Utilizando a fórmula para estimativa da raiz via falsa-posicao
xm = xs - (f2*(xi-xs)/(f1-f2))
end if
! Estimando a função no ponto corrigido entre o intervalo
f3 = xm**(10.0) - 1.0 ! f(xm)

! Calculando o produto para o novo intervalo
produto = f1*f3

! Atualizando os intervalos em função do novo teste de sinal
if (produto.lt.0.0) then
xs=xm
else
xi=xm
end if
end if

if(opcao.eq.3) then
! Atualizando o contador para verificar quantas vezes uma extremidade se repete

if(xi1.eq.xi) then
contador1 = contador1 + 1
end if

if(xs1.eq.xs) then
contador2 = contador2 + 1
end if
end if

erro = abs(xm1-xm)
iter = iter + 1

end do 

end program falsa_posicao_modificado

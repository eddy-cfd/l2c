program bissecao_exemplo

! Desejamos escrever um programa que resolva a raiz da seguinte equação:
! f(x) = (667.38/x)*(1.0 - exp(-0.146843*x)) - 40.0
! O método a ser utilizado é o método da bissecção

! Primeiro, vamos declarar nossas variáveis

real xi, xs	! limite inferior e superior do intervalo de busca
real xm, xmd	! valor médio do intervalo (xm) e valor médio depois de um passo (xmd)
real fi, fs, fm	! valores da função f em xi, xs e xm
real tol	! tolerância para avaliação de convergência numérica
real erro	! erro numérico
integer iter	! número de iterações

! Temos que definir um intervalo de busca

xi=12.0
xs=16.0

tol = 1.0e-05
erro= xs - xi
iter = 0

do while(erro.gt.tol)

! Avaliando os valores da função nos intervalos xi e xs
fi = funcao(xi)
fs = funcao(xs)

! Averiguando se a função muda de sinal no intervalo [xi,xs]

if((fi*fs).lt.0.0) then

xm = (xi+xs)/2.0 ! Valor da raiz antes da atualização do intervalo

! Verificando se a mudança ocorre entre [xi,xm] ou [xm,xs]
fm = funcao(xm)

if((fi*fm).lt.0.0) then
xs = xm
else
xi = xm
end if

xmd =(xi+xs)/2.0 ! Valor novo da raiz após atualização do intervalo
erro=abs(xm-xmd)
iter=iter+1

write(*,*) iter, xi, xs, xmd, erro

else
write(*,*) 'A raiz não se encontra nesse intervalo'
exit
end if
end do


! Definindo a função f(x)

contains

function funcao(x) result(f)
   real, intent(in) :: x
   real f
   f = (667.38/x)*(1.0 - exp(-0.146843*x)) - 40.0
end function funcao


end program bissecao_exemplo



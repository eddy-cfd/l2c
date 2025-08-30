program temperatura_agua_exemplo

! Desejamos escrever um programa que resolva a raiz da seguinte equação:
! f(x) = (1.575701E+05/x) - (6.642308E+07/(x**2.0)) + (1.2438E+10/(x**3.0)) - (8.621949E+11/(x**4.0)) - 139.344111 - log(Os)

! O método a ser utilizado é o método da bissecção

! Primeiro, vamos declarar nossas variáveis

real xi, xs	! limite inferior e superior do intervalo de busca
real xm, xmd	! valor médio do intervalo (xm) e valor médio depois de um passo (xmd)
real fi, fs, fm	! valores da função f em xi, xs e xm
real tol	! tolerância para avaliação de convergência numérica
real erro	! erro numérico
integer iter	! número de iterações
real Os		! saturação de oxigênio
real T		! temperatura em graus Celsius

! Temos que definir um intervalo de busca

xi= 273.15
xs= 273.15 + 40.0

tol = 1.0e-02
erro= xs - xi
iter = 0

write(*,*) 'Digite o valor da saturação'
read*, Os

do while(erro.gt.tol)

! Avaliando os valores da função nos intervalos xi e xs
fi = funcao(xi, Os)
fs = funcao(xs, Os)

! Averiguando se a função muda de sinal no intervalo [xi,xs]

if((fi*fs).lt.0.0) then

xm = (xi+xs)/2.0 ! Valor da raiz antes da atualização do intervalo

! Verificando se a mudança ocorre entre [xi,xm] ou [xm,xs]
fm = funcao(xm, Os)

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

T = xm - 273.15

write(*,*) 'A temperatura da água é de:', T

! Definindo a função f(x)

contains

function funcao(x, saturacao) result(f)
   real, intent(in) :: x
   real f
   f = (1.575701E+05/x) - (6.642308E+07/(x**2.0)) + (1.2438E+10/(x**3.0)) - (8.621949E+11/(x**4.0)) - 139.344111 - log(saturacao)
end function funcao


end program temperatura_agua_exemplo



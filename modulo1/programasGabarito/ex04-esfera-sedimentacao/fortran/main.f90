program sedimentacao

!******************************************************************
!								  *
!                     Declaração de variáveis                     *
!								  *
!******************************************************************

integer i,j,k               ! i,j,k = variáveis inteiras para loops
real U 			    ! Velocidade numérica em z 
real Ue 		    ! Velocidade exata em z 
real, allocatable :: T(:)   ! Vetor tempo
real dt	 	            ! Passo de tempo
integer npast	            ! Número de passos de tempo
real St                     ! Número de Stokes
real Re                     ! Número de Reynolds
real v_star, Q, P, eps	    ! Variáveis para montar a solução exata


!******************************************************************
!								  *
!           Coletando os parâmetros físicos do usuário            *
!								  *
!******************************************************************

! Parâmetros físicos
write(*,*) 'Qual o valor do número de Stokes?'
read*,St

write(*,*) 'Qual o valor do número de Reynolds?'
read*,Re


! Número de passos de tempo, passo de tempo e eps

npast=1000*St
dt=St/10
eps = 3.0*Re/8.0

! Alocando variáveis na memória

allocate(T(npast+1))

! Velocidade inicial da partícula

U = 0.0
Ue = 0.0
T(1) = 0.0


!******************************************************************
!								  *
!         Escrevendo a solução analítica para comparação          *
!								  *
!******************************************************************

open (2,file='solucao_analitica.dat')
write(2,*) 'Variables="U","t"'
write(2,'(A30)') 'zone t="Solução Analítica"'

do k=1,npast-1
if(Re.eq.0.0) then
  Ue = 1.0 - exp(-T(k)/St)
else
  v_star = (-1.0 + sqrt(1.0 + (3.0/2.0)*Re)) / (0.75*Re)   
  P = -(0.75/St)*Re*v_star - 1.0/St                     
  Q = (3.0/8.0)*(Re/St)                               
  Ue = v_star + 1.0 / (Q/P + (-1.0/v_star - Q/P)*exp(-P*T(k)))
end if
T(k+1)=T(k)+dt
write(2,'(F20.4,F20.4)') Ue, T(k)
end do

!******************************************************************
!								  *
!                  Obtendo a solução numérica                     *
!								  *
!******************************************************************


open (3,file='solucao_numerica.dat')
write(3,*) 'Variables="U","t"'
write(3,'(A30)') 'zone t="Solução Numérica"'

! Calculando a velocidade da partícula 

do k=1,npast-1
call rk4(U, T(k), dt, St, Re) ! Runge-Kutta de 4° ordem
T(k+1)=T(k)+dt
write(3,'(F20.4,F20.4)') U,T(k)
end do

!******************************************************************
!								  *
!                        Pós-processamento                        *
!								  *
!******************************************************************

! Abre script 'plot.gnu' com gnuplot via terminal
call system('gnuplot plot.gnu') 
! Abre PDF com gráfico de saída via terminal
call system('xdg-open grafico_sedimentacao.pdf')

end program

!******************************************************************
!								  *
!                     Função que monta a EDO                      *
!								  *
!******************************************************************

function dvdt(v, St, Re) result(dv)
    real, intent(in) :: v, St, Re
    real dv
    dv = (1.0 - v - (3.0/8.0)*Re*v**2) / St
end function dvdt

!******************************************************************
!								  *
!       Sub-rotina que aplica o R.K. de ordem 4 sobre a EDO       *
!								  *
!******************************************************************

subroutine rk4(v, t, dt, St,Re)
    real, intent(inout) :: v  
    real, intent(in) :: t, dt, St,Re
    real :: k1, k2, k3, k4

    k1 = dt * dvdt(v, St, Re)
    k2 = dt * dvdt(v + 0.5 * k1, St, Re)
    k3 = dt * dvdt(v + 0.5 * k2, St, Re)
    k4 = dt * dvdt(v + k3, St, Re)

    v = v + (k1 + 2.0d0*k2 + 2.0d0*k3 + k4) / 6.0d0
end subroutine rk4

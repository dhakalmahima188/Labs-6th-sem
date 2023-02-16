DOMAINS
int_list=integer*
PREDICATES solution(int_list)
NONDETERM member(integer,int_list)
CLAUSES solution([]). solution([F,O,R,T,Y,S,I,X,E,N]):-C4=1, member(C1,[0,1,2]), member(C2,[0,1,2]), member(C3,[0,1,2]),
member(F,[0,1,2,3,4,5,6,7,8,9]), 
member(O,[0,1,2,3,4,5,6,7,8,9]),
member(R,[0,1,2,3,4,5,6,7,8,9]),
member(T,[0,1,2,3,4,5,6,7,8,9]),
member(Y,[0,1,2,3,4,5,6,7,8,9]),
member(E,[0,1,2,3,4,5,6,7,8,9]),
member(S,[0,1,2,3,4,5,6,7,8,9]),
member(I,[0,1,2,3,4,5,6,7,8,9]),
member(X,[0,1,2,3,4,5,6,7,8,9]),
N=0,
F<>O, F<>R, F<>T, F<>Y, F<>E, F<>N, F<>S,F<>I,F<>X, O<>R, O<>T, O<>Y, O<>E, O<>N, O<>S, O<>I, O<>X, R<>T, R<>Y, R<>E, R<>N, R<>S, R<>I, R<>X,
T<>Y, T<>E, T<>N, T<>S, T<>I, T<>X, Y<>E, Y<>N, Y<>S, Y<>I, Y<>X, E<>N, E<>S, E<>I, E<>X, N<>S, N<>I, N<>X,
S<>I, S<>X,
I<>X,
Y+N+N=Y+10*C1,
C1+T+E+E=T+10*C2,
C2+R+T+T=X+10*C3,
C3+O=I+10*C4,
C4+F=S.
member(X, [X|_]).
member(X, [_|Z]):-
member(X,Z).
GOAL
solution([F,O,R,T,Y,S,I,X,E,N]).

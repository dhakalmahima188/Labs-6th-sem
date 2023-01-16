DOMAINS
list1 = integer*

PREDICATES
length(list1, integer)

CLAUSES
length([],0).
length([H|T],L):-length(T,L1), L=L1+1.

GOAL
length([0,1,2,3,4,5],X).
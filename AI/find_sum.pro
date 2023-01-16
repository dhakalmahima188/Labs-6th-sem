DOMAINS
int_list = integer*

PREDICATES
sum(int_list, integer)

CLAUSES
sum([],0).
sum([H|T], X):-
sum(T,Y), X=H+Y.

GOAL
sum([3,4],Z).
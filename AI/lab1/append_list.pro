DOMAINS
list = integer*
PREDICATES
append (list,list,list)
CLAUSES
append ([],L2,L2).
append (L1,[],L1).
append ([H|T],L2,[H|R]) :-
append (T,L2,R).
GOAL
append ([1,2,3,4,5] , [8,9,10],X).
PREDICATES
nondeterm can_do(STRING,STRING)
nondeterm member(STRING,STRING)
nondeterm parent(STRING,STRING)
nondeterm cant_do(STRING,STRING)

CLAUSES
member("dave","dancingclub").
member("fred","dancingclub").

cant_do("freddad","waltz").

cant_do(X,Y):-
parent(Z,X),cant_do(Z,Y).

cant_do(X,"waltz"):-
member(X,"dancingclub"),can_do(X,"jive").

cant_do(X,"jive"):-
member(X,"dancingclub"),can_do(X,"waltz").

can_do("dave",X):-
cant_do("fred",X).

parent("freddad","fred").

GOAL
member(X,"dancingclub"),cant_do(X,"jive").


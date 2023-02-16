PREDICATES
horse(STRING)
mammal(STRING)
cow(STRING)
pig(STRING)
is_offspring(STRING,STRING)
is_parent(STRING, STRING)

CLAUSES
mammal(X):-
	horse(X),
	cow(X),
	pig (X),
	is_parent(_,X).

horse(Y):-
	is_parent(X,Y),horse(X).

horse("Bluebeard").

is_offspring(X,Y):-
	is_parent(Y,X).

is_parent("Bluebeard","Charlie").

cow("?").
pig("?").

GOAL
horse("Charlie").
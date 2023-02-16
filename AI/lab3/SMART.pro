PREDICATES
not_poor (STRING) smart (STRING) happy (STRING)
not_stupid (STRING)
read(STRING)
wealthy (STRING)
exciting_life(STRING)

CLAUSES
exciting_life(X):-
	happy (X) .
	
happy (X):-
	not_poor(X),smart(X).

smart(X):-
	not_stupid(X).
	
not_stupid(X):-
	read(X).

not_poor(X):-
	wealthy(X).

read("John").
wealthy( "John").

GOAL 
exciting_life("John").
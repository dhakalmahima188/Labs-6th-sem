PREDICATES
nondeterm likes(STRING,STRING) 
nondeterm food(STRING)
nondeterm eats(STRING,STRING) 
nondeterm kills(STRING, STRING)

CLAUSES
food("orange").
food("chicken").

food(X):-
likes(Y,X), 
not(kills(X,Y)).

eats("sailendra",Y):- eats("bhogendra",Y).  
eats(X,Y):-likes(X,Y),food(Y).

likes("bhogendra",X):-
food(X). 
kills(_,_).

GOAL
likes("sailendra","chicken").
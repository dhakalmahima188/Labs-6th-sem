PREDICATES

pompeian(symbol)
nondeterm roman(symbol)
nondeterm loyal(symbol,symbol) 
nondeterm hate(symbol,symbol)
nondeterm assasinate(symbol,symbol) 
nondeterm not_loyal(symbol,symbol)

CLAUSES
roman(X):- pompeian(X).
assasinate(marcus,ceasar). 
pompeian(marcus).

hate(X,ceasar):- roman(X),not_loyal(X,ceasar).

loyal(X,ceasar):- roman(X),not(hate(X,ceasar)). 
not_loyal (X, Y):- assasinate(X, Y).

GOAL
hate(marcus,ceasar).
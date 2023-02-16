PREDICATES
hcf(integer,integer,integer)

CLAUSES
hcf(X,Y,Z) :- X>=Y,X mod Y=0,Z=Y.
hcf(X,Y,Z) :- X>=Y,T= X mod Y,T<>0,hcf(Y,T,Z).
hcf(X,Y,Z):- X<Y, hcf(Y,X,Z).

GOAL
hcf(12,4,X).
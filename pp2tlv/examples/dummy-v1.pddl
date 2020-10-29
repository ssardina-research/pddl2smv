(define (domain blocksworld)
(:requirements :strips)
(:predicates (clear ?x)
             (on-table ?x)
             (arm-empty)
             (holding ?x)
             (on ?x ?y)
             (ftrue)
)

 
(:action pickup
  :parameters (?ob)
  :precondition (and (clear ?ob) (on-table ?ob) (arm-empty))
  :effect (and (holding ?ob) (not (clear ?ob)) (not (on-table ?ob)) 
               (not (arm-empty))))

(:action putdown
  :parameters  (?ob)
  :precondition (and (holding ?ob))
  :effect (and (clear ?ob) (arm-empty) (on-table ?ob) 
               (not (holding ?ob))))

(:action stack
  :parameters  (?ob ?underob)
  :precondition (and (clear ?underob) (holding ?ob))
  :effect (and (arm-empty) (clear ?ob) (on ?ob ?underob)
               (not (clear ?underob)) (not (holding ?ob))))

(:action unstack
  :parameters  (?ob ?underob)
  :precondition (and (on ?ob ?underob) (clear ?ob) (arm-empty))
  :effect (and (holding ?ob) (clear ?underob)
               (not (on ?ob ?underob)) (not (clear ?ob)) (not (arm-empty))))
)

(define 
	(planprog acyclic-complete-6) 
	(:domain blocksworld) 
	(:objects b1 b2) 
	(:init 
		(arm-empty)
		(on-table b1)
		(on-table b2)
		(clear b1)
		(clear b2)
		(ftrue)
	)
	(:initnode n0) 
	(:transitions 
		(n0 n1 (on b1 b2))
		(n0 n2 (on b2 b1))
		(n1 n2 (and (on-table b1) (on-table b2)))
		(n2 n0 (arm-empty))
	)
)